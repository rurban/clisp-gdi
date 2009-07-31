#line 2 "funcs-prob.c"

/* functions that have been hand edited */

// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:AddFontResourceA, lpcstr)
{
  object arg;
  int int0;
  LPCSTR lpcstr;
  arg = popSTACK();
  if(!stringp(arg))invalid_argument(arg);
  with_string_0(arg,encoding, lpcstr, {
    begin_system_call();
    int0 = AddFontResourceA(lpcstr);
    end_system_call();
    if(0 <=int0){
      do_GDI_ERROR("AddFontResourceA");
    }
    else
    {
      VALUES1(sint32_to_I(int0));
    }
  });
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:AddFontResourceW, lpcwstr)
{
  object arg;
  int int0;
  LPCWSTR lpcwstr;
  arg = popSTACK();
  if(!stringp(arg))invalid_argument(arg);
  lpcwstr = WIDECHAR(arg,encoding);
  begin_system_call();
  int0 = AddFontResourceW(lpcwstr);
  end_system_call();
  if(0 <=int0){
    do_GDI_ERROR("AddFontResourceW");
  }
  else
  {
    VALUES1(sint32_to_I(int0));
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:CopyEnhMetaFileA, henhmetafile lpcstr)
{
  object arg;
  HENHMETAFILE henhmetafile0;
  HENHMETAFILE henhmetafile;
  LPCSTR lpcstr;
  arg = popSTACK();
  if(!stringp(arg))invalid_argument(arg);
  with_string_0(arg,encoding, lpcstr, {
    arg = popSTACK();
    if(!fpointerp(arg))invalid_argument(arg);
    henhmetafile = TheFpointer(arg)->fp_pointer;
    begin_system_call();
    henhmetafile0 = CopyEnhMetaFileA(henhmetafile,lpcstr);
    end_system_call();
    if(NULL ==henhmetafile0){
      do_GDI_ERROR("CopyEnhMetaFileA");
    }
    else
    {
      VALUES1(allocate_fpointer((FOREIGN)henhmetafile0));
    }
  });
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:CopyEnhMetaFileW, henhmetafile lpcwstr)
{
  object arg;
  HENHMETAFILE henhmetafile0;
  HENHMETAFILE henhmetafile;
  LPCWSTR lpcwstr;
  arg = popSTACK();
  if(!stringp(arg))invalid_argument(arg);
  lpcwstr = 0; //WIDECHAR(arg,encoding);
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  henhmetafile = TheFpointer(arg)->fp_pointer;
  begin_system_call();
  henhmetafile0 = CopyEnhMetaFileW(henhmetafile,lpcwstr);
  end_system_call();
  if(NULL ==henhmetafile0){
    do_GDI_ERROR("CopyEnhMetaFileW");
  }
  else
  {
    VALUES1(allocate_fpointer((FOREIGN)henhmetafile0));
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:CopyMetaFileA, hmetafile lpcstr)
{
  object arg;
  HMETAFILE hmetafile0;
  HMETAFILE hmetafile;
  LPCSTR lpcstr;
  arg = popSTACK();
  if(!stringp(arg))invalid_argument(arg);
  with_string_0(arg,encoding, lpcstr, {
    arg = popSTACK();
    if(!fpointerp(arg))invalid_argument(arg);
    hmetafile = TheFpointer(arg)->fp_pointer;
    begin_system_call();
    hmetafile0 = CopyMetaFileA(hmetafile,lpcstr);
    end_system_call();
    if(NULL ==hmetafile0){
      do_GDI_ERROR("CopyMetaFileA");
    }
    else
    {
      VALUES1(allocate_fpointer((FOREIGN)hmetafile0));
    }
  });
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:CopyMetaFileW, hmetafile lpcwstr)
{
  object arg;
  HMETAFILE hmetafile0;
  HMETAFILE hmetafile;
  LPCWSTR lpcwstr;
  arg = popSTACK();
  if(!stringp(arg))invalid_argument(arg);
  lpcwstr = WIDECHAR(arg,encoding);
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hmetafile = TheFpointer(arg)->fp_pointer;
  begin_system_call();
  hmetafile0 = CopyMetaFileW(hmetafile,lpcwstr);
  end_system_call();
  if(NULL ==hmetafile0){
    do_GDI_ERROR("CopyMetaFileW");
  }
  else
  {
    VALUES1(allocate_fpointer((FOREIGN)hmetafile0));
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:CreateBitmapIndirect, bitmap_p)
{
  object arg;
  HBITMAP hbitmap;
  BITMAP* bitmap_p = alloca(sizeof(BITMAP));
  object arg0;
  arg0 = popSTACK();
  processBITMAP(bitmap_p,arg0);
  begin_system_call();
  hbitmap = CreateBitmapIndirect(bitmap_p);
  end_system_call();
  if(NULL ==hbitmap){
    do_GDI_ERROR("CreateBitmapIndirect");
  }
  else
  {
    VALUES1(allocate_fpointer((FOREIGN)hbitmap));
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:CreateBrushIndirect, logbrush_p)
{
  object arg;
  HBRUSH hbrush;
  LOGBRUSH* logbrush_p = alloca(sizeof(LOGBRUSH));
  object arg0;
  arg0 = popSTACK();
  processLOGBRUSH(logbrush_p,arg0);
  begin_system_call();
  hbrush = CreateBrushIndirect(logbrush_p);
  end_system_call();
  if(NULL ==hbrush){
    do_GDI_ERROR("CreateBrushIndirect");
  }
  else
  {
    VALUES1(allocate_fpointer((FOREIGN)hbrush));
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:CreateColorSpaceA, lplogcolorspacea)
{
  object arg;
  HCOLORSPACE hcolorspace;
  LOGCOLORSPACEA* lplogcolorspacea;
  object arg0;
  arg0 = popSTACK();
  processFPTYPE(LOGCOLORSPACEA*,lplogcolorspacea,arg0);
  begin_system_call();
  hcolorspace = CreateColorSpaceA(lplogcolorspacea);
  end_system_call();
  if(NULL ==hcolorspace){
    do_GDI_ERROR("CreateColorSpaceA");
  }
  else
  {
    VALUES1(allocate_fpointer((FOREIGN)hcolorspace));
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:CreateColorSpaceW, lplogcolorspacew)
{
  object arg;
  HCOLORSPACE hcolorspace;
  LOGCOLORSPACEW* lplogcolorspacew;
  object arg0;
  arg0 = popSTACK();
  processFPTYPE(LOGCOLORSPACEW*,lplogcolorspacew,arg0);
  begin_system_call();
  hcolorspace = CreateColorSpaceW(lplogcolorspacew);
  end_system_call();
  if(NULL ==hcolorspace){
    do_GDI_ERROR("CreateColorSpaceW");
  }
  else
  {
    VALUES1(allocate_fpointer((FOREIGN)hcolorspace));
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:CreateDCA, lpcstr lpcstr0 lpcstr1 devmodea_p)
{
  object arg;
  HDC hdc;
  LPCSTR lpcstr;
  LPCSTR lpcstr0;
  LPCSTR lpcstr1;
  DEVMODEA* devmodea_p;
  object arg0;
  arg0 = popSTACK();
  processFPTYPE(DEVMODEA*,devmodea_p,arg0);
  arg = popSTACK();
  if(!stringp(arg))invalid_argument(arg);
  with_string_0(arg,encoding, lpcstr1, {
    arg = popSTACK();
    if(!stringp(arg))invalid_argument(arg);
    with_string_0(arg,encoding, lpcstr0, {
      arg = popSTACK();
      if(!stringp(arg))invalid_argument(arg);
      with_string_0(arg,encoding, lpcstr, {
        processFPTYPE(DEVMODEA*,devmodea_p,arg0);
        begin_system_call();
        hdc = CreateDCA(lpcstr,lpcstr0,lpcstr1,devmodea_p);
        end_system_call();
        if(NULL ==hdc){
          do_GDI_ERROR("CreateDCA");
        }
        else
        {
          VALUES1(allocate_fpointer((FOREIGN)hdc));
        }
      });
    });
  });
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:CreateDCW, lpcwstr lpcwstr0 lpcwstr1 devmodew_p)
{
  object arg;
  HDC hdc;
  LPCWSTR lpcwstr;
  LPCWSTR lpcwstr0;
  LPCWSTR lpcwstr1;
  DEVMODEW* devmodew_p;
  object arg0;
  arg0 = popSTACK();
  processFPTYPE(DEVMODEW*,devmodew_p,arg0);
  arg = popSTACK();
  if(!stringp(arg))invalid_argument(arg);
  lpcwstr1 = WIDECHAR(arg,encoding);
  arg = popSTACK();
  if(!stringp(arg))invalid_argument(arg);
  lpcwstr0 = WIDECHAR(arg,encoding);
  arg = popSTACK();
  if(!stringp(arg))invalid_argument(arg);
  lpcwstr = WIDECHAR(arg,encoding);

  begin_system_call();
  hdc = CreateDCW(lpcwstr,lpcwstr0,lpcwstr1,devmodew_p);
  end_system_call();
  if(NULL ==hdc){
    do_GDI_ERROR("CreateDCW");
  }
  else
  {
    VALUES1(allocate_fpointer((FOREIGN)hdc));
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:CreateEllipticRgnIndirect, lpcrect)
{
  object arg;
  HRGN hrgn;
  RECT* lpcrect = alloca(sizeof(RECT));
  object arg0;
  arg0 = popSTACK();
  processRECT(lpcrect,arg0);
  begin_system_call();
  hrgn = CreateEllipticRgnIndirect(lpcrect);
  end_system_call();
  if(NULL ==hrgn){
    do_GDI_ERROR("CreateEllipticRgnIndirect");
  }
  else
  {
    VALUES1(allocate_fpointer((FOREIGN)hrgn));
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:CreateEnhMetaFileA, hdc lpcstr lpcrect lpcstr0)
{
  object arg;
  HDC hdc0;
  HDC hdc;
  LPCSTR lpcstr;
  RECT* lpcrect = alloca(sizeof(RECT));
  object arg0;
  LPCSTR lpcstr0;
  arg = popSTACK();
  if(!stringp(arg))invalid_argument(arg);
  with_string_0(arg,encoding, lpcstr0, {
    arg0 = popSTACK();
    processRECT(lpcrect,arg0);
    arg = popSTACK();
    if(!stringp(arg))invalid_argument(arg);
    with_string_0(arg,encoding, lpcstr, {
      arg = popSTACK();
      if(!fpointerp(arg))invalid_argument(arg);
      hdc = TheFpointer(arg)->fp_pointer;
      processRECT(lpcrect,arg0);
      begin_system_call();
      hdc0 = CreateEnhMetaFileA(hdc,lpcstr,lpcrect,lpcstr0);
      end_system_call();
      if(NULL ==hdc0){
        do_GDI_ERROR("CreateEnhMetaFileA");
      }
      else
      {
        VALUES1(allocate_fpointer((FOREIGN)hdc0));
      }
    });
  });
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:CreateEnhMetaFileW, hdc lpcwstr lpcrect lpcwstr0)
{
  object arg;
  HDC hdc0;
  HDC hdc;
  LPCWSTR lpcwstr;
  RECT* lpcrect = alloca(sizeof(RECT));
  object arg0;
  LPCWSTR lpcwstr0;
  arg = popSTACK();
  if(!stringp(arg))invalid_argument(arg);
  lpcwstr0 = WIDECHAR(arg,encoding);
  arg0 = popSTACK();
  processRECT(lpcrect,arg0);
  arg = popSTACK();
  if(!stringp(arg))invalid_argument(arg);
  lpcwstr = WIDECHAR(arg,encoding);
  getHDC(hdc,arg);

  begin_system_call();
  hdc0 = CreateEnhMetaFileW(hdc,lpcwstr,lpcrect,lpcwstr0);
  end_system_call();
  if(NULL ==hdc0){
    do_GDI_ERROR("CreateEnhMetaFileW");
  }
  else
  {
    
      VALUES1(allocate_fpointer((FOREIGN)hdc0));
  }
  return;
}
// tested in p1.lisp
DEFUN( GDI:CreateFontIndirectA, logfonta_p)
{
  object arg;
  HFONT hfont;
  LOGFONTA* logfonta_p = alloca(sizeof(LOGFONTA));
  object arg0;
  arg0 = popSTACK();
  processLOGFONTA(logfonta_p,arg0);
  begin_system_call();
  hfont = CreateFontIndirectA(logfonta_p);
  end_system_call();
  if(NULL ==hfont){
    do_GDI_ERROR("CreateFontIndirectA");
  }
  else
  {
    VALUES1(allocate_fpointer((FOREIGN)hfont));
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:CreateFontIndirectW, logfontw_p)
{
  object arg;
  HFONT hfont;
  LOGFONTW* logfontw_p = alloca(sizeof(LOGFONTW));
  object arg0;
  arg0 = popSTACK();
  processLOGFONTW(logfontw_p,arg0);
  begin_system_call();
  hfont = CreateFontIndirectW(logfontw_p);
  end_system_call();
  if(NULL ==hfont){
    do_GDI_ERROR("CreateFontIndirectW");
  }
  else
  {
    VALUES1(allocate_fpointer((FOREIGN)hfont));
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:CreateICA, lpcstr lpcstr0 lpcstr1 devmodea_p)
{
  object arg;
  HDC hdc;
  LPCSTR lpcstr;
  LPCSTR lpcstr0;
  LPCSTR lpcstr1;
  DEVMODEA* devmodea_p;
  object arg0;
  arg0 = popSTACK();
  processFPTYPE(DEVMODEA*,devmodea_p,arg0);
  arg = popSTACK();
  if(!stringp(arg))invalid_argument(arg);
  with_string_0(arg,encoding, lpcstr1, {
    arg = popSTACK();
    if(!stringp(arg))invalid_argument(arg);
    with_string_0(arg,encoding, lpcstr0, {
      arg = popSTACK();
      if(!stringp(arg))invalid_argument(arg);
      with_string_0(arg,encoding, lpcstr, {
        processFPTYPE(DEVMODEA*,devmodea_p,arg0);
        begin_system_call();
        hdc = CreateICA(lpcstr,lpcstr0,lpcstr1,devmodea_p);
        end_system_call();
        if(NULL ==hdc){
            do_GDI_ERROR("CreateICA");
        }
        else
        {
          VALUES1(allocate_fpointer((FOREIGN)hdc));
        }
      });
    });
  });
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:CreateICW, lpcwstr lpcwstr0 lpcwstr1 devmodew_p)
{
  object arg;
  HDC hdc;
  LPCWSTR lpcwstr;
  LPCWSTR lpcwstr0;
  LPCWSTR lpcwstr1;
  DEVMODEW* devmodew_p;
  object arg0;
  arg0 = popSTACK();
  processFPTYPE(DEVMODEW*,devmodew_p,arg0);
  arg = popSTACK();
  if(!stringp(arg))invalid_argument(arg);
  lpcwstr1 = WIDECHAR(arg,encoding);
  arg = popSTACK();
  if(!stringp(arg))invalid_argument(arg);
  lpcwstr0 = WIDECHAR(arg,encoding);
  arg = popSTACK();
  if(!stringp(arg))invalid_argument(arg);
  lpcwstr = WIDECHAR(arg,encoding);

  begin_system_call();
  hdc = CreateICW(lpcwstr,lpcwstr0,lpcwstr1,devmodew_p);
  end_system_call();
  if(NULL ==hdc){
    do_GDI_ERROR("CreateICW");
  }
  else
  {
    VALUES1(allocate_fpointer((FOREIGN)hdc));
  }
  return;
}
// untested - was never called
DEFUN( GDI:CreateIconFromResource, presbits dwResSize fIcon dwVer)
/**
 * presbits - Buffer containing the icon or cursor resource bits. 
 *          These bits are typically loaded by calls to the LookupIconIdFromDirectory 
 *          (in Windows 95 you can also call LookupIconIdFromDirectoryEx) and 
 *          LoadResource functions. 
 * The return value is the foreign-pointer to the handle to the icon or cursor.
 */
{
  object arg;
  object arg0;
  HICON hicon;
  PBYTE presbits;
  DWORD dwResSize;
  BOOL fIcon;
  DWORD dwVer;
  dwVer = I_to_uint32(check_uint(popSTACK()));
  arg0 = popSTACK();
  processBOOL(&fIcon,arg0);
  dwResSize = I_to_uint32(check_uint(popSTACK()));
  arg = popSTACK();
  processPBYTE(presbits,arg); // TODO

  begin_system_call();
  hicon = CreateIconFromResource(presbits,dwResSize,fIcon,dwVer);
  end_system_call();
  if(NULL ==hicon){
    do_GDI_ERROR("CreateIconFromResource");
  }
  else
  {
    VALUES1(allocate_fpointer((FOREIGN)hicon));
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:CreateIconIndirect, piconinfo)
{
  object arg;
  HICON hicon;
  ICONINFO iconinfo;
  arg = popSTACK();
  processICONINFO(&iconinfo,arg);
  begin_system_call();
  hicon = CreateIconIndirect(&iconinfo);
  end_system_call();
  if(NULL ==hicon){
    do_GDI_ERROR("CreateIconIndirect");
  }
  else
  {
    VALUES1(allocate_fpointer((FOREIGN)hicon));
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:CreateMetaFileA, lpcstr)
{
  object arg;
  HDC hdc;
  LPCSTR lpcstr;
  arg = popSTACK();
  if(!stringp(arg))invalid_argument(arg);
  with_string_0(arg,encoding, lpcstr, {
    begin_system_call();
    hdc = CreateMetaFileA(lpcstr);
    end_system_call();
    if(NULL ==hdc){
      do_GDI_ERROR("CreateMetaFileA");
    }
    else
    {
      VALUES1(allocate_fpointer((FOREIGN)hdc));
    }
  });
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:CreateMetaFileW, lpcwstr)
{
  object arg;
  HDC hdc;
  LPCWSTR lpcwstr;
  arg = popSTACK();
  if(!stringp(arg))invalid_argument(arg);
  lpcwstr = WIDECHAR(arg,encoding);
  begin_system_call();
  hdc = CreateMetaFileW(lpcwstr);
  end_system_call();
  if(NULL ==hdc){
    do_GDI_ERROR("CreateMetaFileW");
  }
  else
  {
    VALUES1(allocate_fpointer((FOREIGN)hdc));
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:CreatePalette, logpalette_p)
{
  object arg;
  HPALETTE hpalette;
  LOGPALETTE* logpalette_p;
  object arg0;
  arg0 = popSTACK();
  processFPTYPE(LOGPALETTE*,logpalette_p,arg0);

  begin_system_call();
  hpalette = CreatePalette(logpalette_p);
  end_system_call();
  if(NULL ==hpalette){
    do_GDI_ERROR("CreatePalette");
  }
  else
  {
    VALUES1(allocate_fpointer((FOREIGN)hpalette));
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:CreatePenIndirect, logpen_p)
{
  object arg;
  HPEN hpen;
  LOGPEN* logpen_p;
  object arg0;
  arg0 = popSTACK();
  processFPTYPE(LOGPEN*,logpen_p,arg0);

  begin_system_call();
  hpen = CreatePenIndirect(logpen_p);
  end_system_call();
  if(NULL ==hpen){
    do_GDI_ERROR("CreatePenIndirect");
  }
  else
  {
    VALUES1(allocate_fpointer((FOREIGN)hpen));
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:CreateRectRgnIndirect, lpcrect)
{
  object arg;
  HRGN hrgn;
  RECT* lpcrect = alloca(sizeof(RECT));
  object arg0;
  arg0 = popSTACK();
  processRECT(lpcrect,arg0);

  begin_system_call();
  hrgn = CreateRectRgnIndirect(lpcrect);
  end_system_call();
  if(NULL ==hrgn){
    do_GDI_ERROR("CreateRectRgnIndirect");
  }
  else
  {
    VALUES1(allocate_fpointer((FOREIGN)hrgn));
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:CreateWindowIndirectA, cs)
{
  object arg;
  HWND hwnd;
  CREATESTRUCT* p = alloca(sizeof(CREATESTRUCT));
  object arg0;
//asm("int3");
  arg0 = popSTACK();
  processCREATESTRUCTA(p,arg0);
  begin_system_call();
  hwnd = CreateWindowEx(p->dwExStyle, p->lpszClass, p->lpszName, p->style,
    p->x, p->y, p->cx, p->cy, p->hwndParent, p->hMenu, p->hInstance,
    p->lpCreateParams);
  end_system_call();
  if(NULL ==hwnd){
    do_GDI_ERROR("CreateWindowEx");
  }
  else
  {
    VALUES1(allocate_fpointer((FOREIGN)hwnd));
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:FillRect, hdc lpcrect hbrush)
{
  object arg;
  BOOL bool0;
  HDC hdc;
  RECT* lpcrect = alloca(sizeof(RECT));
  object arg0;
  HBRUSH hbrush;
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hbrush = TheFpointer(arg)->fp_pointer;
  arg0 = popSTACK();
  processRECT(lpcrect,arg0);
  getHDC(hdc,arg);

  begin_system_call();
  bool0 = FillRect(hdc,lpcrect,hbrush);
  end_system_call();
  if(!bool0){
    do_GDI_ERROR("FillRect");
  }
  else
  {
    VALUES1(T);
  }
  return;
}
DEFUN(GDI:GetDC, hwnd)
{
  object arg = popSTACK();
  DWORD e = 0;
  HWND h = (nullp(arg))?0:(TheFpointer(arg)->fp_pointer);
  HDC h0;
  begin_system_call();
  h0 = GetDC(h);
  end_system_call();
  if(NULL == h0){
    do_GDI_ERROR("GetDC");
  }
  else
  {
    VALUES1(allocate_fpointer((FOREIGN)h0));
  }
  return;
}
// Nothing in the docs indicates that this function can return a error code.
// tested ok
DEFUN( GDI:GetDeviceCaps, hdc int0)
{
  object arg;
  int int1;
  HDC hdc;
  int int0;
  int0 = I_to_sint32(check_sint(popSTACK()));
  getHDC(hdc,arg);
  begin_system_call();
  int1 = GetDeviceCaps(hdc,int0);
  end_system_call();
  if(int1 <= 0){
    do_GDI_ERROR("GetDeviceCaps");
  }
  else
  {
    VALUES1(sint32_to_I(int1));
  }
  return;
}
// tested
DEFUN( GDI:GetSystemMetrics, int0)
{
  object arg;
  int int1;
  int int0;
  arg = popSTACK();
  int0 = I_to_sint32(arg);
  begin_system_call();
  int1 = GetSystemMetrics(int0);
  end_system_call();
  VALUES1(sint32_to_I(int1));
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:LoadCursorA, hinstance lpcstr)
{
  object arg;
  HCURSOR hcursor;
  HINSTANCE hinstance;
  void* lpcstr;
  arg = popSTACK();

  if(stringp(arg))
  {
     lpcstr = TheAsciz(string_to_asciz(arg,encoding));
  }
  else if(fpointerp(arg))
  {
     lpcstr = TheFpointer(arg)->fp_pointer;
  }
  else invalid_argument(arg);
  arg = popSTACK();
  if(nullp(arg))
  {
     hinstance = NULL;
  }
  else if(fpointerp(arg))
  {
     hinstance = TheFpointer(arg)->fp_pointer;
  }
  else invalid_argument(arg);
  begin_system_call();
  hcursor = LoadCursorA(hinstance,lpcstr);
  end_system_call();
  if(NULL ==hcursor){
    do_GDI_ERROR("LoadCursorA");
  }
  else
  {
    VALUES1(allocate_fpointer((FOREIGN)hcursor));
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:LoadCursorW, hinstance lpcwstr)
{
  object arg;
  HCURSOR hcursor;
  HINSTANCE hinstance;
  LPCWSTR lpcwstr;
  arg = popSTACK();
  if(!stringp(arg))invalid_argument(arg);
  lpcwstr = WIDECHAR(arg,encoding);
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hinstance = TheFpointer(arg)->fp_pointer;
  begin_system_call();
  hcursor = LoadCursorW(hinstance,lpcwstr);
  end_system_call();
  if(NULL ==hcursor){
    do_GDI_ERROR("LoadCursorW");
  }
  else
  {
    VALUES1(allocate_fpointer((FOREIGN)hcursor));
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:PlayEnhMetaFile, hdc henhmetafile lpcrect)
{
  object arg;
  BOOL bool0;
  HDC hdc;
  HENHMETAFILE henhmetafile;
  RECT* lpcrect = alloca(sizeof(RECT));
  object arg0;
  arg0 = popSTACK();
  processRECT(lpcrect,arg0);
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  henhmetafile = TheFpointer(arg)->fp_pointer;
  getHDC(hdc,arg);

  begin_system_call();
  bool0 = PlayEnhMetaFile(hdc,henhmetafile,lpcrect);
  end_system_call();
  if(!bool0){
    do_GDI_ERROR("PlayEnhMetaFile");
  }
  else
  {
    VALUES1(T);
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:RectInRegion, hrgn lpcrect)
{
  object arg;
  BOOL bool0;
  HRGN hrgn;
  RECT* lpcrect = alloca(sizeof(RECT));
  object arg0;
  arg0 = popSTACK();
  processRECT(lpcrect,arg0);
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hrgn = TheFpointer(arg)->fp_pointer;

  begin_system_call();
  bool0 = RectInRegion(hrgn,lpcrect);
  end_system_call();
  if(!bool0){
    do_GDI_ERROR("RectInRegion");
  }
  else
  {
    VALUES1(T);
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:RectVisible, hdc lpcrect)
{
  object arg;
  BOOL bool0;
  HDC hdc;
  RECT* lpcrect = alloca(sizeof(RECT));
  object arg0;
  arg0 = popSTACK();
  processRECT(lpcrect,arg0);
  getHDC(hdc,arg);

  begin_system_call();
  bool0 = RectVisible(hdc,lpcrect);
  end_system_call();
  if(!bool0){
    do_GDI_ERROR("RectVisible");
  }
  else
  {
    VALUES1(T);
  }
  return;
}
// untested - was never called
// inspected - changed ATOM from fp to int
DEFUN( GDI:RegisterClassA, wndclassa_p)
{
  object arg;
  ATOM atom;
  WNDCLASSA* wndclassa_p = alloca(sizeof(WNDCLASSA));
  object arg0;
  arg0 = popSTACK();
//asm("int3");
  processWNDCLASSA(wndclassa_p,arg0);
  begin_system_call();
  atom = RegisterClassA(wndclassa_p);
  end_system_call();
  if(!atom){
    do_GDI_ERROR("RegisterClassA");
  }
  else
  {
    //value1 = allocate_fpointer((FOREIGN)atom);
    VALUES1(uint32_to_I(atom));
  }
  return;
}
// untested - was never called
// inspected - changed ATOM from fp to int
DEFUN( GDI:RegisterClassW, wndclassw_p)
{
  object arg;
  ATOM atom;
  WNDCLASSW* wndclassw_p = alloca(sizeof(WNDCLASSW));
  object arg0;
  arg0 = popSTACK();
  processWNDCLASSW(wndclassw_p,arg0);
  begin_system_call();
  atom = RegisterClassW(wndclassw_p);
  end_system_call();
  if(!atom){
    do_GDI_ERROR("RegisterClassW");
  }
  else
  {
    //value2 = allocate_fpointer((FOREIGN)atom);
    VALUES1(uint32_to_I(atom));
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:RemoveFontResourceA, lpcstr)
{
  object arg;
  BOOL bool0;
  LPCSTR lpcstr;
  arg = popSTACK();
  if(!stringp(arg))invalid_argument(arg);
  lpcstr = TheAsciz(string_to_asciz(arg,encoding));
  begin_system_call();
  bool0 = RemoveFontResourceA(lpcstr);
  end_system_call();
  if(!bool0){
    do_GDI_ERROR("RemoveFontResourceA");
  }
  else
  {
    VALUES1(T);
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:RemoveFontResourceW, lpcwstr)
{
  object arg;
  BOOL bool0;
  LPCWSTR lpcwstr;
  arg = popSTACK();
  if(!stringp(arg))invalid_argument(arg);
  lpcwstr = WIDECHAR(arg,encoding);
  begin_system_call();
  bool0 = RemoveFontResourceW(lpcwstr);
  end_system_call();
  if(!bool0){
    do_GDI_ERROR("RemoveFontResourceW");
  }
  else
  {
    VALUES1(T);
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:ResetDCA, hdc devmodea_p)
{
  object arg;
  HDC hdc0;
  HDC hdc;
  DEVMODEA* devmodea_p;
  object arg0;
  arg0 = popSTACK();
  processFPTYPE(DEVMODEA*,devmodea_p,arg0);
  getHDC(hdc,arg);

  begin_system_call();
  hdc0 = ResetDCA(hdc,devmodea_p);
  end_system_call();
  if(NULL ==hdc0){
    do_GDI_ERROR("ResetDCA");
  }
  else
  {
    VALUES1(allocate_fpointer((FOREIGN)hdc0));
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:ResetDCW, hdc devmodew_p)
{
  object arg;
  HDC hdc0;
  HDC hdc;
  DEVMODEW* devmodew_p;
  object arg0;
  arg0 = popSTACK();
  processFPTYPE(DEVMODEW*,devmodew_p,arg0);
  getHDC(hdc,arg);

  begin_system_call();
  hdc0 = ResetDCW(hdc,devmodew_p);
  end_system_call();
  if(NULL ==hdc0){
    do_GDI_ERROR("ResetDCW");
  }
  else
  {
    VALUES1(allocate_fpointer((FOREIGN)hdc0));
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:SelectPalette, hdc hpalette bool0)
{
  object arg;
  HPALETTE hpalette0;
  HDC hdc;
  HPALETTE hpalette;
  BOOL bool0;
  arg = popSTACK();
  bool0 = nullp(arg);
  arg = popSTACK();
  processFPTYPE(HPALETTE,hpalette,arg);
  getHDC(hdc,arg);
  begin_system_call();
  hpalette0 = SelectPalette(hdc,hpalette,bool0);
  end_system_call();
  if(NULL ==hpalette0){
    do_GDI_ERROR("SelectPalette");
  }
  else
  {
    VALUES1(allocate_fpointer((FOREIGN)hpalette0));
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:SetColorAdjustment, hdc coloradjustment_p)
{
  object arg;
  BOOL bool0;
  HDC hdc;
  COLORADJUSTMENT* coloradjustment_p = alloca(sizeof(COLORADJUSTMENT));
  object arg0;
  arg0 = popSTACK();
  processCOLORADJUSTMENT(coloradjustment_p,arg0);
  getHDC(hdc,arg);

  begin_system_call();
  bool0 = SetColorAdjustment(hdc,coloradjustment_p);
  end_system_call();
  if(!bool0){
    do_GDI_ERROR("SetColorAdjustment");
  }
  else
  {
    VALUES1(T);
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:SetDeviceGammaRamp, hdc pvoid)
{
  object arg;
  BOOL bool0;
  HDC hdc;
  void* pvoid;
  arg = popSTACK();
  if(!simple_bit_vector_p(Atype_8Bit,arg))invalid_argument(arg);
  pvoid = &(TheSbvector(arg)->data);
  getHDC(hdc,arg);
  begin_system_call();
  bool0 = SetDeviceGammaRamp(hdc,pvoid);
  end_system_call();
  if(!bool0){
    do_GDI_ERROR("SetDeviceGammaRamp");
  }
  else
  {
    VALUES1(T);
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:SetICMProfileA, hdc lpstr)
{
  object arg;
  BOOL bool0;
  HDC hdc;
  LPSTR lpstr;
  arg = popSTACK();
  if(!stringp(arg))invalid_argument(arg);
  lpstr = TheAsciz(string_to_asciz(arg,encoding));
  getHDC(hdc,arg);
  begin_system_call();
  bool0 = SetICMProfileA(hdc,lpstr);
  end_system_call();
  if(!bool0){
    do_GDI_ERROR("SetICMProfileA");
  }
  else
  {
    VALUES1(T);
  }
  return;
}
// untested - was never called
// requires a S16string object as lpwstr
DEFUN( GDI:SetICMProfileW, hdc lpwstr)
{
  object arg;
  BOOL bool0;
  HDC hdc;
  LPWSTR lpwstr;
  arg = popSTACK();
  if(!stringp(arg))invalid_argument(arg);
  lpwstr = WIDECHAR(arg,encoding);
  getHDC(hdc,arg);
  begin_system_call();
  bool0 = SetICMProfileW(hdc,lpwstr);
  end_system_call();
  if(!bool0){
    do_GDI_ERROR("SetICMProfileW");
  }
  else
  {
    VALUES1(T);
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:SetPixel, hdc int0 int1 colorref)
{
  object arg;
  COLORREF colorref0;
  HDC hdc;
  int int0;
  int int1;
  COLORREF colorref;
  arg = popSTACK();
  colorref = processCOLORREF(arg);
  int1 = I_to_sint32(check_sint(popSTACK()));
  int0 = I_to_sint32(check_sint(popSTACK()));
  getHDC(hdc,arg);
  begin_system_call();
  colorref0 = SetPixel(hdc,int0,int1,colorref);
  end_system_call();
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:SetPixelV, hdc int0 int1 colorref)
{
  object arg;
  BOOL bool0;
  HDC hdc;
  int int0;
  int int1;
  COLORREF colorref;
  arg = popSTACK();
  colorref = processCOLORREF(arg);
  int1 = I_to_sint32(check_sint(popSTACK()));
  int0 = I_to_sint32(check_sint(popSTACK()));
  getHDC(hdc,arg);
  begin_system_call();
  bool0 = SetPixelV(hdc,int0,int1,colorref);
  end_system_call();
  if(!bool0){
    do_GDI_ERROR("SetPixelV");
  }
  else
  {
    VALUES1(T);
  }
  return;
}
// untested - was never called
DEFUN( GDI:SetTextColor, hdc colorref)
{
  object arg;
  COLORREF colorref0;
  HDC hdc;
  COLORREF colorref;
  arg = popSTACK();
  colorref = processCOLORREF(arg);
  getHDC(hdc,arg);
  begin_system_call();
  colorref0 = SetTextColor(hdc,colorref);
  end_system_call();
  if(CLR_INVALID == colorref0){
    do_GDI_ERROR("SetTextColor");
  }
  else
  {
    VALUES1(fixnum(colorref0)); // or make-rgb
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:SetWorldTransform, hdc xform_p)
{
  object arg;
  BOOL bool0;
  HDC hdc;
  XFORM* xform_p = alloca(sizeof(XFORM));
  object arg0;
  arg0 = popSTACK();
  processXFORM(xform_p,arg0);
  getHDC(hdc,arg);

  begin_system_call();
  bool0 = SetWorldTransform(hdc,xform_p);
  end_system_call();
  if(!bool0){
    do_GDI_ERROR("SetWorldTransform");
  }
  else
  {
    VALUES1(T);
  }
  return;
}

// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:DestroyCursor, hcursor)
{
  object arg;
  BOOL bool0;
  HCURSOR hcursor;
  object arg0;
  arg = popSTACK();
  processFPTYPE(HCURSOR,hcursor,arg);
  begin_system_call();
  bool0 = DestroyCursor(hcursor);
  end_system_call();
  if(!bool0){
    do_GDI_ERROR("DestroyCursor");
  }
  else
  {
    VALUES1(T);
  }
  return;
}
// untested - was never called
// written by hand
DEFUN( GDI:SetCursor, hcursor)
{
  object arg;
  BOOL bool0;
  HCURSOR hcursor, hcursor0;
  arg = popSTACK();
  processFPTYPE(HCURSOR,hcursor,arg);
  begin_system_call();
  hcursor0 = SetCursor(hcursor);
  end_system_call();
  if(!bool0){
    do_GDI_ERROR("SetCursor");
  }
  else
  {
    VALUES1(allocate_fpointer((FOREIGN)hcursor0));
  }
  return;
}
// untested - was never called
// written by hand
DEFUN( GDI:GetCursor,)
{
  HCURSOR hcursor;
  begin_system_call();
  hcursor = GetCursor();
  end_system_call();
  if(!hcursor){
    do_GDI_ERROR("GetCursor");
  }
  else
  {
    VALUES1(allocate_fpointer((FOREIGN)hcursor));
  }
  return;
}
// untested - was never called
// written by hand. Idea from perl Win32::GDI
DEFUN( GDI:ChangeCursor, hwnd hcursor0)
{
  object arg;
  HWND hwnd;
  HCURSOR hcursor0, hcursor;
  object arg0;
  arg = popSTACK();
  processFPTYPE(HCURSOR,hcursor0,arg);
  arg0 = popSTACK();
  processFPTYPE(HWND,hwnd,arg0);
  begin_system_call();
  hcursor = (HCURSOR)SetClassLong(hwnd, GCL_HCURSOR, (LONG) hcursor0);
  end_system_call();
  if(!hcursor){
    do_GDI_ERROR("SetClassLong");
  }
  else
  {
    VALUES1(allocate_fpointer((FOREIGN)hcursor));
  }
  return;
}
// untested - was never called
// written by hand
DEFUN( GDI:GetCursorPos,lppoint)
{
  BOOL bool0;
  POINT *lppoint = alloca(sizeof(POINT));
  object arg0; 
  arg0 = popSTACK();
  processPOINT(lppoint,arg0); 
  begin_system_call();
  bool0 = GetCursorPos(lppoint);
  end_system_call();
  if(!bool0){
    do_GDI_ERROR("GetCursorPos");
  }
  else
  {
    value1 = sint32_to_I(lppoint->x);
    value2 = sint32_to_I(lppoint->y);
    mv_count=2;
  }
  return;
}
// untested - was never called
// written by hand
DEFUN( GDI:SetCursorPos, int0 int1)
{
  BOOL bool0;
  int int0, int1;
  object arg; 
  int1 = I_to_sint32(check_sint(popSTACK()));
  int0 = I_to_sint32(check_sint(popSTACK()));
  begin_system_call();
  bool0 = SetCursorPos(int0, int1);
  end_system_call();
  if(!bool0){
    do_GDI_ERROR("SetCursorPos");
  }
  else
  {
    VALUES1(T);
  }
  return;
}
// untested - was never called
// written by hand
DEFUN( GDI:GetCursorInfo, cursorinfo)
{
  BOOL bool0;
  CURSORINFO cursorinfo;
  object arg0; 
  arg0 = popSTACK();
  processCURSORINFO(&cursorinfo,arg0); 
  begin_system_call();
  bool0 = GetCursorInfo(&cursorinfo);
  end_system_call();
  if(!bool0){
    do_GDI_ERROR("GetCursorInfo");
  }
  else
  {
    VALUES1(outputCURSORINFO(&cursorinfo));
  }
  return;
}

// untested - was never called
// written by hand
DEFUN( GDI:SetDCPenColor, hdc colorref)
{
  object arg;
  COLORREF colorref0;
  HDC hdc;
  COLORREF colorref;
  arg = popSTACK();
  colorref = processCOLORREF(arg);
  getHDC(hdc,arg);
  begin_system_call();
  colorref0 = SetDCPenColor(hdc,colorref);
  end_system_call();
  if(CLR_INVALID == colorref0){
    do_GDI_ERROR("SetDCPenColor");
  }
  else
  {
    VALUES1(fixnum(colorref0));
  }
  return;
}
// cygwin w32api error: linked to msimg32, but defined in gdi32
// written by hand
/*
*/
// untested - was never called
// written by hand
DEFUN( GDI:SetDCBrushColor, hdc colorref)
{
  object arg;
  COLORREF colorref0;
  HDC hdc;
  COLORREF colorref;
  arg = popSTACK();
  colorref = processCOLORREF(arg);
  getHDC(hdc,arg);
  begin_system_call();
  colorref0 = SetDCBrushColor(hdc,colorref);
  end_system_call();
  if(CLR_INVALID == colorref0){
    do_GDI_ERROR("SetDCBrushColor");
  }
  else
  {
    VALUES1(fixnum(colorref0));
  }
  return;
}
// untested - was never called
// written by hand
DEFUN(GDI:GetDCEx, hwnd hrgnClip flags)
{
  object arg = popSTACK();
  DWORD e = 0;
  HDC h0;
  DWORD flags = I_to_uint32(check_uint(popSTACK()));
  HRGN hrgnClip = (nullp(arg))?0:(TheFpointer(arg)->fp_pointer);
  HWND hwnd = (nullp(arg))?0:(TheFpointer(arg)->fp_pointer);
  begin_system_call();
  h0 = GetDCEx(hwnd, hrgnClip, flags);
  end_system_call();
  if(NULL == h0){
    do_GDI_ERROR("GetDCEx");
  }
  else
  {
    VALUES1(allocate_fpointer((FOREIGN)h0));
  }
  return;
}
// untested - was never called
// written by hand
DEFUN(GDI:GetWindowDC, hwnd)
{
  object arg = popSTACK();
  DWORD e = 0;
  HDC h0;
  HWND hwnd = (nullp(arg))?0:(TheFpointer(arg)->fp_pointer);
  begin_system_call();
  h0 = GetWindowDC(hwnd);
  end_system_call();
  if(NULL == h0){
    do_GDI_ERROR("GetWindowDC");
  }
  else
  {
    VALUES1(allocate_fpointer((FOREIGN)h0));
  }
  return;
}

DEFUN( GDI:GetKeyState, int0)
/* Retrieve the status of the specified virtual key at the time the last
 * keyboard message was retrieved from the message queue.
 */
{
  object arg;
  int int0, int1;
  int0 = I_to_sint32(check_sint(popSTACK()));
  begin_system_call();
  int1 = GetKeyState(int0);
  end_system_call();
  value1 = ((int1 & 0x8000) >> 15) ? T :  NIL;   // up or down
  value2 = (int1 & 0x0001) ? T : NIL;            // toggled or not
  value3 = sint32_to_I(int1);                    // the whole
  mv_count=3;
  return;
}

// from array.d
extern object allocate_bit_vector_0 (uintL len);

DEFUN( GDI:GetKeyboardState,)
/* Returns bivector of size 256 with the status of the 256 virtual keys.
 * The index in the array is the virtual key code. If the value 
 * is true, that key is pressed.
 */
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

// untested - was never called
DEFUN( GDI:AddFontMemResourceEx, pbFont cbFont pdv pcFonts)
/* pdv is ignored and set to 0 */
{
  object arg;
  HANDLE handle;
  void* pbFont;
  DWORD cbFont;
  void* pdv;
  DWORD* pcFonts;// = alloca(sizeof(DWORD));
  processFPTYPE_fn(DWORD*,pcFonts,popSTACK());
  arg = popSTACK();
  pdv = (void*)0;
  cbFont = I_to_uint32(check_uint(popSTACK()));
  processFPTYPE_fn(void*,pbFont,popSTACK());
  begin_call();
  handle = AddFontMemResourceEx(pbFont,cbFont,pdv,pcFonts);
  end_call();
  if(NULL ==handle){
    do_GDI_ERROR("AddFontMemResourceEx");
  }
  else
  {
    value1 = allocate_fpointer((FOREIGN)handle);
    mv_count=1;
  }
  return;
}
// untested - was never called
DEFUN( GDI:AddFontResourceExA, lpcFilename fl pdv)
/* pdv is ignored and set to 0 */
{
  object arg;
  int int0;
  LPCSTR lpcFilename;
  DWORD fl;
  void* pdv;
  arg = popSTACK();
  pdv = (void*)0;
  fl = I_to_uint32(check_uint(popSTACK()));
  arg = popSTACK();
  if(!stringp(arg))invalid_argument(arg);
  lpcFilename = TheAsciz(string_to_asciz(arg,encoding));
  begin_call();
  int0 = AddFontResourceExA(lpcFilename,fl,pdv);
  end_call();
  if(0 <=int0){
    do_GDI_ERROR("AddFontResourceExA");
  }
  else
  {
    value1 = sint32_to_I(int0);
    mv_count=1;
  }
  return;
}
// untested - was never called
DEFUN( GDI:AddFontResourceExW, lpcwFilename fl pdv)
/* pdv is ignored and set to 0 */
{
  object arg;
  int int0;
  LPCWSTR lpcwFilename;
  DWORD fl;
  void* pdv;
  arg = popSTACK();
  pdv = (void*)0;
  fl = I_to_uint32(check_uint(popSTACK()));
  arg = popSTACK();
  if(!stringp(arg))invalid_argument(arg);
  lpcwFilename = WIDECHAR(arg,encoding);
  begin_call();
  int0 = AddFontResourceExW(lpcwFilename,fl,pdv);
  end_call();
  if(0 <=int0){
    do_GDI_ERROR("AddFontResourceExW");
  }
  else
  {
    value1 = sint32_to_I(int0);
    mv_count=1;
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:ColorCorrectPalette, hdc hpalette dword dword0)
{
  object arg;
  BOOL bool0;
  HDC hdc;
  HPALETTE hpalette;
  DWORD dword;
  DWORD dword0;
  dword0 = I_to_uint32(check_uint(popSTACK()));
  dword = I_to_uint32(check_uint(popSTACK()));
  arg = popSTACK();
  processFPTYPE(HPALETTE,hpalette,arg);
  arg = popSTACK();
  processFPTYPE(HDC,hdc,arg);
  begin_call();
  bool0 = ColorCorrectPalette(hdc,hpalette,dword,dword0);
  end_call();
  if(!bool0){
    do_GDI_ERROR("ColorCorrectPalette");
  }
  else
  {
    value1 = T;
    mv_count=1;
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:GetEnhMetaFileBits, henhmetafile uint lpbyte)
{
  object arg;
  UINT uint0;
  HENHMETAFILE henhmetafile;
  UINT uint;
  BYTE* lpbyte;// = alloca(sizeof(BYTE));
  processBYTE(lpbyte,popSTACK());
  uint = I_to_uint32(check_uint(popSTACK()));
  arg = popSTACK();
  processFPTYPE(HENHMETAFILE,henhmetafile,arg);
  begin_call();
  uint0 = GetEnhMetaFileBits(henhmetafile,uint,lpbyte);
  end_call();
  if(!uint0){
    do_GDI_ERROR("GetEnhMetaFileBits");
  }
  else
  {
    value1 = uint32_to_I(uint0);
    mv_count=1;
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:GetFontUnicodeRanges, hdc lpglyphset)
{
  object arg;
  DWORD dword;
  HDC hdc;
  GLYPHSET* lpglyphset;// = alloca(sizeof(GLYPHSET));
  processFPTYPE(GLYPHSET*,lpglyphset,popSTACK());
  arg = popSTACK();
  processFPTYPE(HDC,hdc,arg);
  begin_call();
  dword = GetFontUnicodeRanges(hdc,lpglyphset);
  end_call();
  if(!dword){
    do_GDI_ERROR("GetFontUnicodeRanges");
  }
  else
  {
    value1 = uint32_to_I(dword);
    mv_count=1;
  }
  return;
}
// untested - was never called
DEFUN( GDI:GetGlyphIndicesA, hdc lpcstr c pgi fl)
/* pgi int-bitvector of length c*/
{
  object arg;
  DWORD dword0;
  HDC hdc;
  LPCSTR lpcstr;
  int c;
  WORD* pgi;
  DWORD fl;
  fl = I_to_uint32(check_uint(popSTACK()));
  arg = popSTACK();
  if(!simple_bit_vector_p(Atype_32Bit,arg))invalid_argument(arg);
  pgi = (WORD*)&(TheSbvector(arg)->data);
  c = I_to_sint32(check_sint(popSTACK()));
  arg = popSTACK();
  if(!stringp(arg))invalid_argument(arg);
  lpcstr = TheAsciz(string_to_asciz(arg,encoding));
  arg = popSTACK();
  processFPTYPE(HDC,hdc,arg);
  begin_call();
  dword0 = GetGlyphIndicesA(hdc,lpcstr,c,pgi,fl);
  end_call();
  if(!dword0){
    do_GDI_ERROR("GetGlyphIndicesA");
  }
  else
  {
    value1 = uint32_to_I(dword0);
    mv_count=1;
  }
  return;
}
// untested - was never called
DEFUN( GDI:GetGlyphIndicesW, hdc lpcwstr c pgi fl)
/* pgi int-bitvector of length c*/
{
  object arg;
  DWORD dword0;
  HDC hdc;
  LPCWSTR lpcwstr;
  int c;
  WORD* pgi;
  DWORD fl;
  fl = I_to_uint32(check_uint(popSTACK()));
  arg = popSTACK();
  if(!simple_bit_vector_p(Atype_32Bit,arg))invalid_argument(arg);
  pgi = (WORD*)&(TheSbvector(arg)->data);
  c = I_to_sint32(check_sint(popSTACK()));
  arg = popSTACK();
  if(!stringp(arg))invalid_argument(arg);
  lpcwstr = WIDECHAR(arg,encoding);
  arg = popSTACK();
  processFPTYPE(HDC,hdc,arg);
  begin_call();
  dword0 = GetGlyphIndicesW(hdc,lpcwstr,c,pgi,fl);
  end_call();
  if(!dword0){
    do_GDI_ERROR("GetGlyphIndicesW");
  }
  else
  {
    value1 = uint32_to_I(dword0);
    mv_count=1;
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:GetGlyphOutlineA,&rest r)
{
  object arg;
  DWORD dword0;
  HDC hdc;
  UINT uint;
  UINT uint0;
  GLYPHMETRICS* lpglyphmetrics;// = alloca(sizeof(GLYPHMETRICS));
  DWORD dword;
  void* pvoid;
  MAT2* lpmat2;// = alloca(sizeof(MAT2));
  processMAT2(lpmat2,popSTACK());
  arg = popSTACK();
  if(!simple_bit_vector_p(Atype_8Bit,arg))invalid_argument(arg);
  pvoid = (void*)&(TheSbvector(arg)->data);
  dword = I_to_uint32(check_uint(popSTACK()));
  processFPTYPE(GLYPHMETRICS*,lpglyphmetrics,popSTACK());
  uint0 = I_to_uint32(check_uint(popSTACK()));
  uint = I_to_uint32(check_uint(popSTACK()));
  arg = popSTACK();
  processFPTYPE(HDC,hdc,arg);
  begin_call();
  dword0 = GetGlyphOutlineA(hdc,uint,uint0,lpglyphmetrics,dword,pvoid,lpmat2);
  end_call();
  if(!dword0){
    do_GDI_ERROR("GetGlyphOutlineA");
  }
  else
  {
    value1 = uint32_to_I(dword0);
    mv_count=1;
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:GetGlyphOutlineW,&rest r)
{
  object arg;
  DWORD dword0;
  HDC hdc;
  UINT uint;
  UINT uint0;
  GLYPHMETRICS* lpglyphmetrics;// = alloca(sizeof(GLYPHMETRICS));
  DWORD dword;
  void* pvoid;
  MAT2* lpmat2;// = alloca(sizeof(MAT2));
  processMAT2(lpmat2,popSTACK());
  arg = popSTACK();
  if(!simple_bit_vector_p(Atype_8Bit,arg))invalid_argument(arg);
  pvoid = (void*)&(TheSbvector(arg)->data);
  dword = I_to_uint32(check_uint(popSTACK()));
  processFPTYPE(GLYPHMETRICS*,lpglyphmetrics,popSTACK());
  uint0 = I_to_uint32(check_uint(popSTACK()));
  uint = I_to_uint32(check_uint(popSTACK()));
  arg = popSTACK();
  processFPTYPE(HDC,hdc,arg);
  begin_call();
  dword0 = GetGlyphOutlineW(hdc,uint,uint0,lpglyphmetrics,dword,pvoid,lpmat2);
  end_call();
  if(!dword0){
    do_GDI_ERROR("GetGlyphOutlineW");
  }
  else
  {
    value1 = uint32_to_I(dword0);
    mv_count=1;
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:GetRandomRgn, hdc hrgn int0)
{
  object arg;
  int int1;
  HDC hdc;
  HRGN hrgn;
  INT int0;
  int0 = I_to_sint32(check_sint(popSTACK()));
  arg = popSTACK();
  processFPTYPE(HRGN,hrgn,arg);
  arg = popSTACK();
  processFPTYPE(HDC,hdc,arg);
  begin_call();
  int1 = GetRandomRgn(hdc,hrgn,int0);
  end_call();
  if(0 <=int1){
    do_GDI_ERROR("GetRandomRgn");
  }
  else
  {
    value1 = sint32_to_I(int1);
    mv_count=1;
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:RemoveFontMemResourceEx, handle)
{
  object arg;
  BOOL bool0;
  HANDLE handle;
  arg = popSTACK();
  processFPTYPE(HANDLE,handle,arg);
  begin_call();
  bool0 = RemoveFontMemResourceEx(handle);
  end_call();
  if(!bool0){
    do_GDI_ERROR("RemoveFontMemResourceEx");
  }
  else
  {
    value1 = T;
    mv_count=1;
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:RemoveFontResourceExA, lpcstr dword pvoid)
{
  object arg;
  BOOL bool0;
  LPCSTR lpcstr;
  DWORD dword;
  void* pvoid;
  arg = popSTACK();
  if(!simple_bit_vector_p(Atype_8Bit,arg))invalid_argument(arg);
  pvoid = (void*)&(TheSbvector(arg)->data);
  dword = I_to_uint32(check_uint(popSTACK()));
  arg = popSTACK();
  if(!stringp(arg))invalid_argument(arg);
  lpcstr = TheAsciz(string_to_asciz(arg,encoding));
  begin_call();
  bool0 = RemoveFontResourceExA(lpcstr,dword,pvoid);
  end_call();
  if(!bool0){
    do_GDI_ERROR("RemoveFontResourceExA");
  }
  else
  {
    value1 = T;
    mv_count=1;
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:RemoveFontResourceExW, lpcwstr dword pvoid)
{
  object arg;
  BOOL bool0;
  LPCWSTR lpcwstr;
  DWORD dword;
  void* pvoid;
  arg = popSTACK();
  if(!simple_bit_vector_p(Atype_8Bit,arg))invalid_argument(arg);
  pvoid = (void*)&(TheSbvector(arg)->data);
  dword = I_to_uint32(check_uint(popSTACK()));
  arg = popSTACK();
  if(!stringp(arg))invalid_argument(arg);
  lpcwstr = WIDECHAR(arg,encoding);
  begin_call();
  bool0 = RemoveFontResourceExW(lpcwstr,dword,pvoid);
  end_call();
  if(!bool0){
    do_GDI_ERROR("RemoveFontResourceExW");
  }
  else
  {
    value1 = T;
    mv_count=1;
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:SetLayout, hdc dword)
{
  object arg;
  DWORD dword0;
  HDC hdc;
  DWORD dword;
  dword = I_to_uint32(check_uint(popSTACK()));
  arg = popSTACK();
  processFPTYPE(HDC,hdc,arg);
  begin_call();
  dword0 = SetLayout(hdc,dword);
  end_call();
  if(!dword0){
    do_GDI_ERROR("SetLayout");
  }
  else
  {
    value1 = uint32_to_I(dword0);
    mv_count=1;
  }
  return;
}

#if 0
// not declared in w32api headers
BOOL         GetTextExtentExPointI(HDC,LPWORD,int,int,LPINT,LPINT,LPSIZE);
int  	     DeviceCapabilitiesExA(LPCSTR,LPCSTR,WORD,LPSTR,DEVMODEA*);
int  	     DeviceCapabilitiesExW(LPCWSTR,LPCWSTR,WORD,LPWSTR,DEVMODEW*);
int 	     GetRelAbs(HDC,DWORD);
int	     SetRelAbs(HDC,int);
HBRUSH       SelectBrushLocal(HBRUSH,HBRUSH);
HFONT        SelectFontLocal(HFONT,HFONT);
BOOL 	     GetFontResourceInfo(LPCTSTR,LPDWORD,LPVOID,DWORD);
BOOL 	     GetFontResourceInfoW(LPCWSTR,LPDWORD,LPVOID,DWORD);

// untested - was never called
DEFUN( GDI:GetTextExtentExPointI, hdc pgiIn cgi nMaxExtent lpnFit alpDx lpsize)
/* alpDx and lpsize are outargs
   lpnFit, pgiIn and alpDx are int-bitvectors 
 */
{
  object arg, arg1, arg2;
  BOOL bool0;
  HDC hdc;
  WORD* pgiIn;// = alloca(sizeof(WORD));
  int cgi;
  int nMaxExtent;
  int* lpnFit;
  int* alpDx;
  SIZE size;
  arg2 = popSTACK();
  processLPSIZE(&size,arg2);
  arg1 = popSTACK();
  if(!simple_bit_vector_p(Atype_32Bit,arg1))invalid_argument(arg1);
  alpDx = (INT*)&(TheSbvector(arg1)->data);
  arg = popSTACK();
  if(!simple_bit_vector_p(Atype_32Bit,arg))invalid_argument(arg);
  lpnFit = (INT*)&(TheSbvector(arg)->data);
  nMaxExtent = I_to_sint32(check_sint(popSTACK()));
  cgi = I_to_sint32(check_sint(popSTACK()));
  arg = popSTACK();
  if(!simple_bit_vector_p(Atype_32Bit,arg))invalid_argument(arg);
  pgiIn = (WORD*)&(TheSbvector(arg)->data);
  arg = popSTACK();
  processFPTYPE(HDC,hdc,arg);
  begin_call();
  bool0 = GetTextExtentExPointI(hdc,pgiIn,cgi,nMaxExtent,lpnFit,alpDx,&size);
  end_call();
  if(!bool0){
    do_GDI_ERROR("GetTextExtentExPointI");
  }
  else
  {
    VALUES2(arg1,arg2);
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:DeviceCapabilitiesExA, lpcstr lpcstr0 word lpstr devmodea_p)
{
  object arg, arg0;
  int int0;
  LPCSTR lpcstr;
  LPCSTR lpcstr0;
  WORD word;
  LPSTR lpstr;
  DEVMODEA* devmodea_p;// = alloca(sizeof(DEVMODEA));
  arg0 = popSTACK();
  processFPTYPE(DEVMODEA*,devmodea_p,arg0);
  arg = popSTACK();
  if(!stringp(arg))invalid_argument(arg);
  lpstr = TheAsciz(string_to_asciz(arg,encoding));
  word = I_to_sint32(check_sint(popSTACK()));
  arg = popSTACK();
  if(!stringp(arg))invalid_argument(arg);
  lpcstr0 = TheAsciz(string_to_asciz(arg,encoding));
  arg = popSTACK();
  if(!stringp(arg))invalid_argument(arg);
  lpcstr = TheAsciz(string_to_asciz(arg,encoding));
  begin_call();
  int0 = DeviceCapabilitiesExA(lpcstr,lpcstr0,word,lpstr,devmodea_p);
  end_call();
  if(0 <=int0){
    do_GDI_ERROR("DeviceCapabilitiesExA");
  }
  else
  {
    value1 = sint32_to_I(int0);
    mv_count=1;
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:DeviceCapabilitiesExW, lpcwstr lpcwstr0 word lpwstr devmodew_p)
{
  object arg, arg0;
  int int0;
  LPCWSTR lpcwstr;
  LPCWSTR lpcwstr0;
  WORD word;
  LPWSTR lpwstr;
  DEVMODEW* devmodew_p;// = alloca(sizeof(DEVMODEW));
  arg0 = popSTACK();
  processFPTYPE(DEVMODEW*,devmodew_p,arg0);
  arg = popSTACK();
  if(!stringp(arg))invalid_argument(arg);
  lpwstr = WIDECHAR(arg,encoding);
  word = I_to_sint32(check_sint(popSTACK()));
  arg = popSTACK();
  if(!stringp(arg))invalid_argument(arg);
  lpcwstr0 = WIDECHAR(arg,encoding);
  arg = popSTACK();
  if(!stringp(arg))invalid_argument(arg);
  lpcwstr = WIDECHAR(arg,encoding);
  begin_call();
  int0 = DeviceCapabilitiesExW(lpcwstr,lpcwstr0,word,lpwstr,devmodew_p);
  end_call();
  if(0 <=int0){
    do_GDI_ERROR("DeviceCapabilitiesExW");
  }
  else
  {
    value1 = sint32_to_I(int0);
    mv_count=1;
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:GetRelAbs, hdc dword)
{
  object arg;
  int int0;
  HDC hdc;
  DWORD dword;
  dword = I_to_uint32(check_uint(popSTACK()));
  arg = popSTACK();
  processFPTYPE(HDC,hdc,arg);
  begin_call();
  int0 = GetRelAbs(hdc,dword);
  end_call();
  if(0 <=int0){
    do_GDI_ERROR("GetRelAbs");
  }
  else
  {
    value1 = sint32_to_I(int0);
    mv_count=1;
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:SelectBrushLocal, hbrush hbrush0)
{
  object arg;
  HBRUSH hbrush1;
  HBRUSH hbrush;
  HBRUSH hbrush0;
  arg = popSTACK();
  processFPTYPE(HBRUSH,hbrush0,arg);
  arg = popSTACK();
  processFPTYPE(HBRUSH,hbrush,arg);
  begin_call();
  hbrush1 = SelectBrushLocal(hbrush,hbrush0);
  end_call();
  if(NULL ==hbrush1){
    do_GDI_ERROR("SelectBrushLocal");
  }
  else
  {
    value1 = allocate_fpointer((FOREIGN)hbrush1);
    mv_count=1;
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:SelectFontLocal, hfont hfont0)
{
  object arg;
  HFONT hfont1;
  HFONT hfont;
  HFONT hfont0;
  arg = popSTACK();
  processFPTYPE(HFONT,hfont0,arg);
  arg = popSTACK();
  processFPTYPE(HFONT,hfont,arg);
  begin_call();
  hfont1 = SelectFontLocal(hfont,hfont0);
  end_call();
  if(NULL ==hfont1){
    do_GDI_ERROR("SelectFontLocal");
  }
  else
  {
    value1 = allocate_fpointer((FOREIGN)hfont1);
    mv_count=1;
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:SetRelAbs, hdc int0)
{
  object arg;
  int int1;
  HDC hdc;
  int int0;
  int0 = I_to_sint32(check_sint(popSTACK()));
  arg = popSTACK();
  processFPTYPE(HDC,hdc,arg);
  begin_call();
  int1 = SetRelAbs(hdc,int0);
  end_call();
  if(0 <=int1){
    do_GDI_ERROR("SetRelAbs");
  }
  else
  {
    value1 = sint32_to_I(int1);
    mv_count=1;
  }
  return;
}
// untested - was never called
DEFUN( GDI:GetFontResourceInfo, lpszFilename cbBuffer lpvoid dwQueryType)
{
  object arg, arg1;
  BOOL bool0;
  LPCTSTR lpszFilename;
  DWORD cbBuffer;
  VOID* lpvoid;
  DWORD dwQueryType;
  dwQueryType = I_to_uint32(check_uint(popSTACK()));
  arg1 = popSTACK();
  processFPTYPE(void*,lpvoid,arg1);
  cbBuffer = I_to_uint32(check_uint(popSTACK()));
  arg = popSTACK();
  if(!stringp(arg))invalid_argument(arg);
  with_string_0(arg,encoding, lpszFilename, {
    begin_call();
    bool0 = GetFontResourceInfo(lpszFilename,&cbBuffer,lpvoid,dwQueryType);
    end_call();
    if(!bool0){
      do_GDI_ERROR("GetFontResourceInfo");
    }
    else
    {
      VALUES2(uint32_to_I(cbBuffer), arg1);
    }
  });
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:GetFontResourceInfoW, lpcwstr cbBuffer lpvoid dwQueryType)
{
  object arg, arg1;
  BOOL bool0;
  LPCWSTR lpcwstr;
  DWORD cbBuffer;
  VOID* lpvoid;
  DWORD dwQueryType;
  dwQueryType = I_to_uint32(check_uint(popSTACK()));
  arg1 = popSTACK();
  processFPTYPE(void*,lpvoid,arg1);
  cbBuffer = I_to_uint32(check_uint(popSTACK()));
  arg = popSTACK();
  if(!stringp(arg))invalid_argument(arg);
  lpcwstr = WIDECHAR(arg,encoding);
  begin_call();
  bool0 = GetFontResourceInfoW(lpcwstr,&cbBuffer,lpvoid,dwQueryType);
  end_call();
  if(!bool0){
    do_GDI_ERROR("GetFontResourceInfoW");
  }
  else
  {
    VALUES2(uint32_to_I(cbBuffer), arg1);
  }
  return;
}
#endif
