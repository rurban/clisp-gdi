#line 1 "gdi.m"  /* -*- C -*- */
/*
   The basic idea of this module is to create lisp callable functions
   for the T symbols in the w32api library libgdi32.a. To do this, I
   used a awk program which parsed the function headers, and created
   the functions here. So most of them are not tested.
   Once a function is tested remove the untested comment from the function.
   This file is LGPL'd, and copyright assigned to the FSF.
     Dan Stanger 4/9/02
   Changed to MODERN (case sensitive) and make it work under clisp-2.39
     Reini Urban 2006-08-13
   Checked all compiler warnings, modprep fixes (cs-modprep.patch), several 
   new functions and added documentation
     Reini Urban 2009-07-14

  ../src/lndir ../modules/gdi gdi; make all -C gdi; rm -rf full+gdi; CLISP_LINKKIT=. MAKE=make ./clisp-link add base full+gdi gdi
*/
#define NO_STRICT
#define WIN32_LEAN_AND_MEAN
/* for the new msimg32 functions: GetDCPenColor, ... */
#define WINVER 0x0501
#include <stdio.h>
#include <windows.h>
#include <assert.h>

#include "clisp.h"
#undef  DEFMODULE
#define DEFMODULE(a,b,c)
#define DEFUN(funname,lambdalist,signature) LISPFUN signature
#define DEFVAR(varname)
#define WIDECHAR(o,e)  &TheS16string(o)->data[0]
#define memclr(p,n) memset(p,0,n)
#define encoding GLO(misc_encoding)
DEFMODULE(GDI,"GDI",(:modern t))

static object lookupHash(HWND hwnd, int message);

LRESULT CALLBACK WindowProc(HWND hWnd,UINT message,WPARAM wParam,LPARAM lParam);
LRESULT CALLBACK WindowProc(HWND hWnd,UINT message,WPARAM wParam,LPARAM lParam)
{
#ifdef DEBUG_OS_ERROR
  printf("HWND %x UINT %d WPARAM %d LPARAM %d\n",hWnd,message,wParam,lParam);
#endif
  switch (message) {
   // When window is created, the callback gets done before the createwindow
   // returns with a handle.  To get around this, and this is NOT thread
   // safe, store a alist of messages and functions.  Then call a
   // lisp function with the window handle and the alist, and store
   // the new list in the hash table.
   case WM_NCCREATE:
   {
     object p;
     begin_callback();
     p = allocate_fpointer((FOREIGN)hWnd);
     pushSTACK(p);
     funcall(O(onCreate),1);
     end_callback();
     return TRUE;
   }
   case WM_CREATE:
   {
      break;
   }
   case WM_PAINT:
   {
     PAINTSTRUCT paintStruct;
     object func;
//asm("int3");
     BeginPaint(hWnd,&paintStruct);
     begin_callback();
     func = lookupHash(hWnd, message);
     if(!nullp(func))
     {
        pushSTACK(allocate_fpointer((FOREIGN)paintStruct.hdc));
        funcall(func,1);
     }
     end_callback();
     EndPaint(hWnd,&paintStruct);
     break;
   }
   case WM_CLOSE:
   {
     object func;
//asm("int3");
     begin_callback();
     func = lookupHash(hWnd, message);
     if(!nullp(func))
     {
        pushSTACK(allocate_fpointer((FOREIGN)hWnd));
        funcall(func,1);
        end_callback();
     }
     else
     {
        end_callback();
        return (DefWindowProc(hWnd, message, wParam, lParam));
     }
     break;
   }
   case WM_KEYDOWN:
     switch (wParam)
     {
       case VK_CANCEL:
       case VK_CLEAR:
       case VK_PAUSE:
       case VK_PRIOR:
       case VK_NEXT:
       case VK_END:
       case VK_HOME:
       case VK_LEFT:
       case VK_UP:
       case VK_RIGHT:
       case VK_DOWN:
       case VK_SELECT:
       case VK_PRINT:
       case VK_EXECUTE:
       case VK_INSERT:
       case VK_DELETE:
       case VK_HELP:
       case VK_NUMLOCK:
       case VK_SCROLL:
       case VK_F1:
       case VK_F2:
       case VK_F3:
       case VK_F4:
       case VK_F5:
       case VK_F6:
       case VK_F7:
       case VK_F8:
       case VK_F9:
       case VK_F10:
       case VK_F11:
       case VK_F12:
       default:
       {
         begin_callback();
         object func = lookupHash(hWnd, message);
         if(!nullp(func))
         {
            /* This cast assumes that sizeof(void*)==sizeof(LPARAM) */
            pushSTACK(allocate_fpointer((FOREIGN)lParam));
            pushSTACK(fixnum(wParam));
            funcall(func,2);
         }
         end_callback();
         break;
       }
     }
     break;
   case WM_LBUTTONDOWN:
   case WM_MBUTTONDOWN:
   case WM_RBUTTONDOWN:
   case WM_MBUTTONUP:
   case WM_LBUTTONUP:
   case WM_RBUTTONUP:
   case WM_MOUSEMOVE:
   case WM_MOUSEWHEEL:
   case WM_ERASEBKGND:
   case WM_KILLFOCUS:
   case WM_SETFOCUS:
   case WM_QUIT:
   case WM_DESTROY:
   case WM_SYSCHAR: /* alt-keys go here */
   case WM_CHAR:
   case WM_LBUTTONDBLCLK:
   case WM_MBUTTONDBLCLK:
   case WM_RBUTTONDBLCLK:
   case WM_MOVE:	
   case WM_SIZE:			
   case WM_DESTROYCLIPBOARD:
   default:        /* Passes it on if unproccessed    */
     return (DefWindowProc(hWnd, message, wParam, lParam));
    }
    return 0L;
}

static object lookupHash(HWND hwnd, int message){
#ifdef DEBUG_OS_ERROR
   printf("lookupHash hwnd %x message %d\n",hwnd,message);
#endif
   Car(O(localCons)) = allocate_fpointer((FOREIGN)hwnd);
   Cdr(O(localCons)) = fixnum(message);
   pushSTACK(O(localCons));
   pushSTACK(O(functions));
   funcall(S(gethash),2);
   return value1;
}

DEFVAR(functions,`NIL`)
DEFVAR(localCons,`NIL`)
DEFVAR(onCreate,`NIL`)
DEFVAR(fp_zero,`NIL`)
/* TODO: on case-sensitive T change to GDI:InitC */
DEFUN( GDI:initc, h f)
{
  O(localCons) = allocate_cons();
  O(onCreate) = popSTACK();
  O(functions) = popSTACK();
  O(fp_zero) = allocate_fpointer((FOREIGN)0);
  value1 = allocate_fpointer((FOREIGN)GetModuleHandle(0));
  mv_count=1;
  return;
}
static LPSTR idc[] ={
   0,
   (LPSTR)IDC_ARROW,
   (LPSTR)IDC_IBEAM,
   (LPSTR)IDC_WAIT,
   (LPSTR)IDC_CROSS,
   (LPSTR)IDC_UPARROW,
   (LPSTR)IDC_SIZENWSE,
   (LPSTR)IDC_SIZENESW,
   (LPSTR)IDC_SIZEWE,
   (LPSTR)IDC_SIZENS,
   (LPSTR)IDC_SIZEALL,
   (LPSTR)IDC_NO,
   (LPSTR)IDC_HAND,
   (LPSTR)IDC_APPSTARTING,
   (LPSTR)IDC_HELP,
   (LPSTR)IDC_ICON,
   (LPSTR)IDC_SIZE
};
DEFUN( GDI:GetIDC, h)
{
  object arg = popSTACK();
  check_uint32(arg);
  value1 = allocate_fpointer((FOREIGN)idc[I_to_uint32(arg)]);
  mv_count=1;
  return;
}
 
DEFUN( GDI:MakeFPointer, h)
{
  /* This cast assumes that sizeof(void*)==sizeof(uint32) */
  value1 = allocate_fpointer((FOREIGN)I_to_uint32(popSTACK()));
  mv_count=1;
  return;
}
DEFUN( GDI:MessageLoop,)
{
  MSG m;
  while (GetMessage(&m, (HWND) NULL, 0, 0)) { 
    TranslateMessage(&m); 
    DispatchMessage(&m); 
  } 
  value1 = fixnum(m.wParam);
  mv_count=1;
  return;
}

// Retrieve the status of the specified virtual key at the time the last
// keyboard message was retrieved from the message queue.
DEFUN( GDI:GetKeyState, int0)
{
  object arg;
  int int0, int1;
  arg = popSTACK();
  check_sint(arg);
  int0 = I_to_sint32(arg);
  begin_system_call();
  int1 = GetKeyState(int0);
  end_system_call();
  value1 = ((int1 & 0x8000) >> 15) ? T :  NIL;   // up or down
  value2 = (int1 & 0x0001) ? T : NIL;            // toggled or not
  value3 = sint32_to_I(int1);                    // the whole
  mv_count=3;
  return;
}
// from array.c
extern object allocate_bit_vector_0 (uintL len);
// Returns bivector of size 256 with the status of the 256 virtual keys.
// The index in the array is the virtual key code. If the value 
// is true, that key is pressed.
DEFUN( GDI:GetKeyboardState,)
{
  int i;
  BYTE keys[256];
  object newvec;
  begin_system_call();
  GetKeyboardState(keys);
  end_system_call();
  newvec = allocate_bit_vector_0(256);
  for (i=0; i < 256; i++) {
      if (keys[i] & 128)
          TheSbvector(newvec)->data[i/8] |= bit((~i) % 8);
  }
  VALUES1(newvec);
  return;
}
