#line 2 "funcs-rest.c"

/* functions that have more than 5 parameters, has been hand edited */

// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:AngleArc,&rest r)
{
  object arg;
  BOOL bool0;
  HDC hdc;
  int int0;
  int int1;
  DWORD dword;
  FLOAT float0;
  FLOAT float1;
  ffloatjanus jfloat;
  FF_to_c_float(check_ffloat(popSTACK()),&jfloat);
  float1 = (float)(jfloat.eksplicit);
  FF_to_c_float(check_ffloat(popSTACK()),&jfloat);
  float0 = (float)(jfloat.eksplicit);
  dword = I_to_uint32(check_uint(popSTACK()));
  int1 = I_to_sint32(check_sint(popSTACK()));
  int0 = I_to_sint32(check_sint(popSTACK()));
  getHDC(hdc,arg);
  begin_system_call();
  bool0 = AngleArc(hdc,int0,int1,dword,float0,float1);
  end_system_call();
  if(!bool0){
    do_GDI_ERROR("AngleArc");
  }
  else
  {
    VALUES1(T);
  }
  return;
}
/* This must be lowercase, because used in gdi.lisp.
   modern package bootstrapping problem within modprep
*/
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:Arc,&rest r)
{
  object arg;
  BOOL bool0;
  HDC hdc;
  int int0;
  int int1;
  int int2;
  int int3;
  int int4;
  int int5;
  int int6;
  int int7;
  int7 = I_to_sint32(check_sint(popSTACK()));
  int6 = I_to_sint32(check_sint(popSTACK()));
  int5 = I_to_sint32(check_sint(popSTACK()));
  int4 = I_to_sint32(check_sint(popSTACK()));
  int3 = I_to_sint32(check_sint(popSTACK()));
  int2 = I_to_sint32(check_sint(popSTACK()));
  int1 = I_to_sint32(check_sint(popSTACK()));
  int0 = I_to_sint32(check_sint(popSTACK()));
  getHDC(hdc,arg);
  begin_system_call();
  bool0 = Arc(hdc,int0,int1,int2,int3,int4,int5,int6,int7);
  end_system_call();
  if(!bool0){
    do_GDI_ERROR("Arc");
  }
  else
  {
    VALUES1(T);
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:ArcTo,&rest r)
{
  object arg;
  BOOL bool0;
  HDC hdc;
  int int0;
  int int1;
  int int2;
  int int3;
  int int4;
  int int5;
  int int6;
  int int7;
  int7 = I_to_sint32(check_sint(popSTACK()));
  int6 = I_to_sint32(check_sint(popSTACK()));
  int5 = I_to_sint32(check_sint(popSTACK()));
  int4 = I_to_sint32(check_sint(popSTACK()));
  int3 = I_to_sint32(check_sint(popSTACK()));
  int2 = I_to_sint32(check_sint(popSTACK()));
  int1 = I_to_sint32(check_sint(popSTACK()));
  int0 = I_to_sint32(check_sint(popSTACK()));
  getHDC(hdc,arg);
  begin_system_call();
  bool0 = ArcTo(hdc,int0,int1,int2,int3,int4,int5,int6,int7);
  end_system_call();
  if(!bool0){
    do_GDI_ERROR("ArcTo");
  }
  else
  {
    VALUES1(T);
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:BitBlt,&rest r)
{
  object arg;
  BOOL bool0;
  HDC hdc;
  int int0;
  int int1;
  int int2;
  int int3;
  HDC hdc0;
  int int4;
  int int5;
  DWORD dword;
  dword = I_to_uint32(check_uint(popSTACK()));
  int5 = I_to_sint32(check_sint(popSTACK()));
  int4 = I_to_sint32(check_sint(popSTACK()));
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hdc0 = TheFpointer(arg)->fp_pointer;
  int3 = I_to_sint32(check_sint(popSTACK()));
  int2 = I_to_sint32(check_sint(popSTACK()));
  int1 = I_to_sint32(check_sint(popSTACK()));
  int0 = I_to_sint32(check_sint(popSTACK()));
  getHDC(hdc,arg);
  begin_system_call();
  bool0 = BitBlt(hdc,int0,int1,int2,int3,hdc0,int4,int5,dword);
  end_system_call();
  if(!bool0){
    do_GDI_ERROR("BitBlt");
  }
  else
  {
    VALUES1(T);
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:Chord,&rest r)
{
  object arg;
  BOOL bool0;
  HDC hdc;
  int int0;
  int int1;
  int int2;
  int int3;
  int int4;
  int int5;
  int int6;
  int int7;
  int7 = I_to_sint32(check_sint(popSTACK()));
  int6 = I_to_sint32(check_sint(popSTACK()));
  int5 = I_to_sint32(check_sint(popSTACK()));
  int4 = I_to_sint32(check_sint(popSTACK()));
  int3 = I_to_sint32(check_sint(popSTACK()));
  int2 = I_to_sint32(check_sint(popSTACK()));
  int1 = I_to_sint32(check_sint(popSTACK()));
  int0 = I_to_sint32(check_sint(popSTACK()));
  getHDC(hdc,arg);
  begin_system_call();
  bool0 = Chord(hdc,int0,int1,int2,int3,int4,int5,int6,int7);
  end_system_call();
  if(!bool0){
    do_GDI_ERROR("Chord");
  }
  else
  {
    VALUES1(T);
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:CreateDIBitmap,&rest r)
{
  object arg;
  HBITMAP hbitmap;
  HDC hdc;
  BITMAPINFOHEADER* bitmapinfoheader_p = alloca(sizeof(BITMAPINFOHEADER));
  object arg0;
  DWORD dword;
  void* pcvoid;
  BITMAPINFO* bitmapinfo_p = alloca(sizeof(BITMAPINFO));
  UINT uint;
  uint = I_to_uint32(check_uint(popSTACK()));
  arg0 = popSTACK();
  processFPTYPE(BITMAPINFO*,bitmapinfo_p,arg0);
  arg = popSTACK();
  if(!simple_bit_vector_p(Atype_8Bit,arg))invalid_argument(arg);
  pcvoid = &(TheSbvector(arg)->data);
  dword = I_to_uint32(check_uint(popSTACK()));
  arg0 = popSTACK();
  processFPTYPE(BITMAPINFOHEADER*,bitmapinfoheader_p,arg0);
  getHDC(hdc,arg);

  begin_system_call();
  hbitmap = CreateDIBitmap(hdc,bitmapinfoheader_p,dword,pcvoid,bitmapinfo_p,uint);
  end_system_call();
  if(NULL ==hbitmap){
    do_GDI_ERROR("CreateDIBitmap");
  }
  else
  {
    VALUES1(allocate_fpointer((FOREIGN)hbitmap));
  }
  return;
}
// tested ok
DEFUN( GDI:CreateFontA,&rest r)
{
  object arg;
  HFONT hfont;
  int int0;
  int int1;
  int int2;
  int int3;
  int int4;
  DWORD dword;
  DWORD dword0;
  DWORD dword1;
  DWORD dword2;
  DWORD dword3;
  DWORD dword4;
  DWORD dword5;
  DWORD dword6;
  arg = popSTACK();
  if(!stringp(arg))invalid_argument(arg);
  with_string_0(arg,encoding, lpcstr, {
     dword6 = I_to_uint32(check_uint(popSTACK()));
     dword5 = I_to_uint32(check_uint(popSTACK()));
     dword4 = I_to_uint32(check_uint(popSTACK()));
     dword3 = I_to_uint32(check_uint(popSTACK()));
     dword2 = I_to_uint32(check_uint(popSTACK()));
     dword1 = I_to_uint32(check_uint(popSTACK()));
     dword0 = I_to_uint32(check_uint(popSTACK()));
     dword = I_to_uint32(check_uint(popSTACK()));
     arg = popSTACK();
     check_sint(arg);
     int4 = I_to_sint32(arg);
     arg = popSTACK();
     check_sint(arg);
     int3 = I_to_sint32(arg);
     arg = popSTACK();
     check_sint(arg);
     int2 = I_to_sint32(arg);
     arg = popSTACK();
     check_sint(arg);
     int1 = I_to_sint32(arg);
     arg = popSTACK();
     check_sint(arg);
     int0 = I_to_sint32(arg);
     begin_system_call();
     hfont = CreateFontA(int0,int1,int2,int3,int4,dword,dword0,dword1,dword2,dword3,dword4,dword5,dword6,lpcstr);
     end_system_call();
  });
  if(NULL ==hfont){
    do_GDI_ERROR("CreateFontA");
  }
  else
  {
    VALUES1(allocate_fpointer((FOREIGN)hfont));
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:CreateFontW,&rest r)
{
  object arg;
  HFONT hfont;
  int int0;
  int int1;
  int int2;
  int int3;
  int int4;
  DWORD dword;
  DWORD dword0;
  DWORD dword1;
  DWORD dword2;
  DWORD dword3;
  DWORD dword4;
  DWORD dword5;
  DWORD dword6;
  LPCWSTR lpcwstr;
  arg = popSTACK();
  if(!stringp(arg))invalid_argument(arg);
  lpcwstr = WIDECHAR(arg,encoding);
  dword6 = I_to_uint32(check_uint(popSTACK()));
  dword5 = I_to_uint32(check_uint(popSTACK()));
  dword4 = I_to_uint32(check_uint(popSTACK()));
  dword3 = I_to_uint32(check_uint(popSTACK()));
  dword2 = I_to_uint32(check_uint(popSTACK()));
  dword1 = I_to_uint32(check_uint(popSTACK()));
  dword0 = I_to_uint32(check_uint(popSTACK()));
  dword = I_to_uint32(check_uint(popSTACK()));
  int4 = I_to_sint32(check_sint(popSTACK()));
  int3 = I_to_sint32(check_sint(popSTACK()));
  int2 = I_to_sint32(check_sint(popSTACK()));
  int1 = I_to_sint32(check_sint(popSTACK()));
  int0 = I_to_sint32(check_sint(popSTACK()));
  begin_system_call();
  hfont = CreateFontW(int0,int1,int2,int3,int4,dword,dword0,dword1,dword2,dword3,dword4,dword5,dword6,lpcwstr);
  end_system_call();
  if(NULL ==hfont){
    do_GDI_ERROR("CreateFontW");
  }
  else
  {
    VALUES1(allocate_fpointer((FOREIGN)hfont));
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:CreateIcon,&rest r)
{
  object arg;
  object arg0;
  HICON hicon;
  HINSTANCE hinstance;
  int int0;
  int int1;
  BYTE byte;
  BYTE byte0;
  PBYTE pbyte;
  PBYTE pbyte0;
  arg0 = popSTACK();
  processPBYTE(pbyte0,arg0);
  arg0 = popSTACK();
  processPBYTE(pbyte,arg0);
  arg0 = popSTACK();
  processBYTE(&byte0,arg0);
  arg0 = popSTACK();
  processBYTE(&byte,arg0);
  int1 = I_to_sint32(check_sint(popSTACK()));
  int0 = I_to_sint32(check_sint(popSTACK()));
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hinstance = TheFpointer(arg)->fp_pointer;
  begin_system_call();
  hicon = CreateIcon(hinstance,int0,int1,byte,byte0,pbyte,pbyte0);
  end_system_call();
  if(NULL ==hicon){
    do_GDI_ERROR("CreateIcon");
  }
  else
  {
    VALUES1(allocate_fpointer((FOREIGN)hicon));
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:CreateIconFromResourceEx,&rest r)
{
  object arg;
  object arg0;
  HICON hicon;
  PBYTE pbyte;
  DWORD dword;
  BOOL bool0;
  DWORD dword0;
  int int0;
  int int1;
  UINT uint;
  uint = I_to_uint32(check_uint(popSTACK()));;
  int1 = I_to_sint32(check_sint(popSTACK()));
  int0 = I_to_sint32(check_sint(popSTACK()));
  dword0 = I_to_uint32(check_uint(popSTACK()));
  arg0 = popSTACK();
  processBOOL(&bool0,arg0);
  dword = I_to_uint32(check_uint(popSTACK()));
  arg0 = popSTACK();
  processPBYTE(pbyte,arg0);
  begin_system_call();
  hicon = CreateIconFromResourceEx(pbyte,dword,bool0,dword0,int0,int1,uint);
  end_system_call();
  if(NULL ==hicon){
    do_GDI_ERROR("CreateIconFromResourceEx");
  }
  else
  {
    VALUES1(allocate_fpointer((FOREIGN)hicon));
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:CreateRoundRectRgn,&rest r)
{
  object arg;
  HRGN hrgn;
  int int0;
  int int1;
  int int2;
  int int3;
  int int4;
  int int5;
  int5 = I_to_sint32(check_sint(popSTACK()));
  int4 = I_to_sint32(check_sint(popSTACK()));
  int3 = I_to_sint32(check_sint(popSTACK()));
  int2 = I_to_sint32(check_sint(popSTACK()));
  int1 = I_to_sint32(check_sint(popSTACK()));
  int0 = I_to_sint32(check_sint(popSTACK()));
  begin_system_call();
  hrgn = CreateRoundRectRgn(int0,int1,int2,int3,int4,int5);
  end_system_call();
  if(NULL ==hrgn){
    do_GDI_ERROR("CreateRoundRectRgn");
  }
  else
  {
    VALUES1(allocate_fpointer((FOREIGN)hrgn));
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:CreateWindowExA,&rest r)
{
  object arg;
  HWND hwnd0;
  DWORD dword;
  LPCSTR lpcstr;
  LPCSTR lpcstr0;
  DWORD dword0;
  int int0;
  int int1;
  int int2;
  int int3;
  HWND hwnd;
  HMENU hmenu;
  HINSTANCE hinstance;
  void* lpvoid = alloca(sizeof(long));
  object arg0;
  arg0 = popSTACK();
  arg = popSTACK();
  processvoid(lpvoid,arg0);
  if(!fpointerp(arg))invalid_argument(arg);
  hinstance = TheFpointer(arg)->fp_pointer;
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hmenu = TheFpointer(arg)->fp_pointer;
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hwnd = TheFpointer(arg)->fp_pointer;
  int3 = I_to_sint32(check_sint(popSTACK()));
  int2 = I_to_sint32(check_sint(popSTACK()));
  int1 = I_to_sint32(check_sint(popSTACK()));
  int0 = I_to_sint32(check_sint(popSTACK()));
  dword0 = I_to_uint32(check_uint(popSTACK()));
  arg = popSTACK();
  if(!stringp(arg))invalid_argument(arg);
  with_string_0(arg,encoding,lpcstr0, {
    arg = popSTACK();
    if(!stringp(arg))invalid_argument(arg);
    with_string_0(arg,encoding, lpcstr,{
      dword = I_to_uint32(check_uint(popSTACK()));
      begin_system_call();
      hwnd0 = CreateWindowExA(dword,lpcstr,lpcstr0,dword0,int0,int1,int2,int3,hwnd,hmenu,hinstance,lpvoid);
      end_system_call();
      if(NULL ==hwnd0){
          do_GDI_ERROR("CreateWindowExA");
      }
      else
      {
          VALUES1(allocate_fpointer((FOREIGN)hwnd0));
      }
      return;
    });
  });
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:CreateWindowExW,&rest r)
{
  object arg;
  HWND hwnd0;
  DWORD dword;
  LPCWSTR lpcwstr;
  LPCWSTR lpcwstr0;
  DWORD dword0;
  int int0;
  int int1;
  int int2;
  int int3;
  HWND hwnd;
  HMENU hmenu;
  HINSTANCE hinstance;
  void* lpvoid = alloca(sizeof(long));
  object arg0;
  arg0 = popSTACK();
  processvoid(lpvoid,arg0);
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hinstance = TheFpointer(arg)->fp_pointer;
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hmenu = TheFpointer(arg)->fp_pointer;
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hwnd = TheFpointer(arg)->fp_pointer;
  int3 = I_to_sint32(check_sint(popSTACK()));
  int2 = I_to_sint32(check_sint(popSTACK()));
  int1 = I_to_sint32(check_sint(popSTACK()));
  int0 = I_to_sint32(check_sint(popSTACK()));
  dword0 = I_to_uint32(check_uint(popSTACK()));
  arg = popSTACK();
  if(!stringp(arg))invalid_argument(arg);
  lpcwstr0 = 0; //(WIDECHAR(arg,encoding));
  arg = popSTACK();
  if(!stringp(arg))invalid_argument(arg);
  lpcwstr = 0; //(WIDECHAR(arg,encoding));
  dword = I_to_uint32(check_uint(popSTACK()));

  begin_system_call();
  hwnd0 = CreateWindowExW(dword,lpcwstr,lpcwstr0,dword0,int0,int1,int2,int3,hwnd,hmenu,hinstance,lpvoid);
  end_system_call();
  if(NULL ==hwnd0){
    do_GDI_ERROR("CreateWindowExW");
  }
  else
  {
    VALUES1(allocate_fpointer((FOREIGN)hwnd0));
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:ExtEscape,&rest r)
{
  object arg;
  int int3;
  HDC hdc;
  int int0;
  int int1;
  LPCSTR lpcstr;
  int int2;
  LPSTR lpstr;
  arg = popSTACK();
  if(!stringp(arg))invalid_argument(arg);
  with_string_0(arg,encoding, lpstr, {
    arg = popSTACK();
    check_sint(arg);
    int2 = I_to_sint32(arg);
    arg = popSTACK();
    if(!stringp(arg))invalid_argument(arg);
    with_string_0(arg,encoding, lpcstr, {
      arg = popSTACK();
      check_sint(arg);
      int1 = I_to_sint32(arg);
      arg = popSTACK();
      check_sint(arg);
      int0 = I_to_sint32(arg);
      arg = popSTACK();
      if(!fpointerp(arg))invalid_argument(arg);
      hdc = TheFpointer(arg)->fp_pointer;
      begin_system_call();
      int3 = ExtEscape(hdc,int0,int1,lpcstr,int2,lpstr);
      end_system_call();
      if(0 <=int3){
          do_GDI_ERROR("ExtEscape");
      }
      else
      {
          VALUES1(sint32_to_I(int3));
      }
    });
  });
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:ExtTextOutA,&rest r)
{
  object arg;
  BOOL bool0;
  HDC hdc;
  int int0;
  int int1;
  UINT uint;
  RECT* lpcrect = alloca(sizeof(RECT));
  object arg0;
  LPCSTR lpcstr;
  UINT uint0;
  PINT pint;
  arg0 = popSTACK();
  processPINT(pint,arg0);
  uint0 = I_to_uint32(check_uint(popSTACK()));
  arg = popSTACK();
  if(!stringp(arg))invalid_argument(arg);
  with_string_0(arg,encoding, lpcstr, {
    arg0 = popSTACK();
    processRECT(lpcrect,arg0);
    uint = I_to_uint32(check_uint(popSTACK()));
    arg = popSTACK();
    check_sint(arg);
    int1 = I_to_sint32(arg);
    arg = popSTACK();
    check_sint(arg);
    int0 = I_to_sint32(arg);
    arg = popSTACK();
    if(!fpointerp(arg))invalid_argument(arg);
    hdc = TheFpointer(arg)->fp_pointer;

    begin_system_call();
    bool0 = ExtTextOutA(hdc,int0,int1,uint,lpcrect,lpcstr,uint0,pint);
    end_system_call();
    if(!bool0){
        do_GDI_ERROR("ExtTextOutA");
    }
    else
    {
      VALUES1(T);
    }
  });
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:ExtTextOutW,&rest r)
{
  object arg;
  BOOL bool0;
  HDC hdc;
  int int0;
  int int1;
  UINT uint;
  RECT* lpcrect = alloca(sizeof(RECT));
  object arg0;
  LPCWSTR lpcwstr;
  UINT uint0;
  PINT pint;
  arg0 = popSTACK();
  processPINT(pint,arg0);
  uint0 = I_to_uint32(check_uint(popSTACK()));
  arg = popSTACK();
  if(!stringp(arg))invalid_argument(arg);
  lpcwstr = WIDECHAR(arg,encoding);
  arg0 = popSTACK();
  processRECT(lpcrect,arg0);
  uint = I_to_uint32(check_uint(popSTACK()));
  int1 = I_to_sint32(check_sint(popSTACK()));
  int0 = I_to_sint32(check_sint(popSTACK()));
  getHDC(hdc,arg);

  begin_system_call();
  bool0 = ExtTextOutW(hdc,int0,int1,uint,lpcrect,lpcwstr,uint0,pint);
  end_system_call();
  if(!bool0){
    do_GDI_ERROR("ExtTextOutW");
  }
  else
  {
    VALUES1(T);
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:FindFirstFileExA,&rest r)
{
  object arg;
  object arg0;
  HANDLE handle;
  LPCSTR lpcstr;
  FINDEX_INFO_LEVELS findex_info_levels;
  void* pvoid;
  FINDEX_SEARCH_OPS findex_search_ops;
  void* pvoid0;
  DWORD dword;
  dword = I_to_uint32(check_uint(popSTACK()));
  arg = popSTACK();
  if(!simple_bit_vector_p(Atype_8Bit,arg))invalid_argument(arg);
  pvoid0 = &(TheSbvector(arg)->data);
  arg0 = popSTACK();
  processFPTYPE(FINDEX_SEARCH_OPS,findex_search_ops,arg0);
  arg = popSTACK();
  if(!simple_bit_vector_p(Atype_8Bit,arg))invalid_argument(arg);
  pvoid = &(TheSbvector(arg)->data);
  arg0 = popSTACK();
  processFPTYPE(FINDEX_INFO_LEVELS,findex_info_levels,arg0);
  arg = popSTACK();
  if(!stringp(arg))invalid_argument(arg);
  with_string_0(arg,encoding, lpcstr, {
    begin_system_call();
    handle = FindFirstFileExA(lpcstr,findex_info_levels,pvoid,findex_search_ops,pvoid0,dword);
    end_system_call();
    if(NULL ==handle){
        do_GDI_ERROR("FindFirstFileExA");
    }
    else
    {
        VALUES1(allocate_fpointer((FOREIGN)handle));
    }
  });
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:FindFirstFileExW,&rest r)
{
  object arg;
  object arg0;
  HANDLE handle;
  LPCWSTR lpcwstr;
  FINDEX_INFO_LEVELS findex_info_levels;
  void* pvoid;
  FINDEX_SEARCH_OPS findex_search_ops;
  void* pvoid0;
  DWORD dword;
  dword = I_to_uint32(check_uint(popSTACK()));
  arg = popSTACK();
  if(!simple_bit_vector_p(Atype_8Bit,arg))invalid_argument(arg);
  pvoid0 = &(TheSbvector(arg)->data);
  arg0 = popSTACK();
  processFPTYPE(FINDEX_SEARCH_OPS,findex_search_ops,arg0);
  arg = popSTACK();
  if(!simple_bit_vector_p(Atype_8Bit,arg))invalid_argument(arg);
  pvoid = &(TheSbvector(arg)->data);
  arg0 = popSTACK();
  processFPTYPE(FINDEX_INFO_LEVELS,findex_info_levels,arg0);
  arg = popSTACK();
  if(!stringp(arg))invalid_argument(arg);
  lpcwstr = WIDECHAR(arg,encoding);
  begin_system_call();
  handle = FindFirstFileExW(lpcwstr,findex_info_levels,pvoid,findex_search_ops,pvoid0,dword);
  end_system_call();
  if(NULL ==handle){
    do_GDI_ERROR("FindFirstFileExW");
  }
  else
  {
    VALUES1(allocate_fpointer((FOREIGN)handle));
  }
  return;
}
// untested - was never called
DEFUN( GDI:GetCharacterPlacementA, hdc string nCount nMaxExtent dwFlags)
/*
    string
    nCount     - number of characters in string
    nMaxExtent - maximum extent for displayed string
    dwFlags    - GCP_ placement flags

    returns SIZE (width + height) + GCP_RESULTS* pointer to buffer for placement result
*/
{
  object arg;
  DWORD dword;
  HDC hdc;
  LPCSTR lpcstr;
  int nCount, nMaxExtent;
  GCP_RESULTSA* lpgcp_resultsa = alloca(sizeof(GCP_RESULTSA));
  DWORD dwFlags;
  dwFlags = I_to_uint32(check_uint(popSTACK()));
  nMaxExtent = I_to_sint32(check_sint(popSTACK()));
  nCount = I_to_sint32(check_sint(popSTACK()));
  arg = popSTACK();
  if(!stringp(arg))invalid_argument(arg);
  with_string_0(arg,encoding, lpcstr, {
    getHDC(hdc,arg);

    begin_system_call();
    dword = GetCharacterPlacementA(hdc,lpcstr,nCount,nMaxExtent,lpgcp_resultsa,dwFlags);
    end_system_call();
    if(!dword){
        do_GDI_ERROR("GetCharacterPlacementA");
    }
    else
    {
        value1 = outputLPSIZE((SIZE *)&dword);
        value2 = outputGCP_RESULTSA(lpgcp_resultsa);
        mv_count=2;
    }
  });
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:GetCharacterPlacementW, hdc string nCount nMaxExtent dwFlags)
{
  object arg;
  DWORD dword;
  HDC hdc;
  LPCWSTR lpcwstr;
  int nCount, nMaxExtent;
  GCP_RESULTSW* lpgcp_resultsw = alloca(sizeof(GCP_RESULTSW));
  DWORD dwFlags;
  dwFlags = I_to_uint32(check_uint(popSTACK()));
  nMaxExtent = I_to_sint32(check_sint(popSTACK()));
  nCount = I_to_sint32(check_sint(popSTACK()));
  arg = popSTACK();
  if(!stringp(arg))invalid_argument(arg);
  lpcwstr = WIDECHAR(arg,encoding);
  getHDC(hdc,arg);

  begin_system_call();
  dword = GetCharacterPlacementW(hdc,lpcwstr,nCount,nMaxExtent,lpgcp_resultsw,dwFlags);
  end_system_call();
  if(!dword){
    do_GDI_ERROR("GetCharacterPlacementW");
  }
  else
  {
    value1 = outputLPSIZE((SIZE *)&dword);
    value2 = outputGCP_RESULTSW(lpgcp_resultsw);
    mv_count=2;
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:GetDIBits,&rest r)
{
  object arg;
  int int0;
  HDC hdc;
  HBITMAP hbitmap;
  UINT uint;
  UINT uint0;
  void* pvoid;
  BITMAPINFO* lpbitmapinfo = alloca(sizeof(BITMAPINFO));
  object arg0;
  UINT uint1;
  uint1 = I_to_uint32(check_uint(popSTACK()));
  arg0 = popSTACK();
  processFPTYPE(BITMAPINFO*,lpbitmapinfo,arg0);
  arg = popSTACK();
  if(!simple_bit_vector_p(Atype_8Bit,arg))invalid_argument(arg);
  pvoid = &(TheSbvector(arg)->data);
  uint0 = I_to_uint32(check_uint(popSTACK()));
  uint = I_to_uint32(check_uint(popSTACK()));
  arg = popSTACK();
  processFPTYPE(HBITMAP,hbitmap,arg);
  getHDC(hdc,arg);

  begin_system_call();
  int0 = GetDIBits(hdc,hbitmap,uint,uint0,pvoid,lpbitmapinfo,uint1);
  end_system_call();
  if(0 <=int0){
    do_GDI_ERROR("GetDIBits");
  }
  else
  {
    VALUES1(sint32_to_I(int0));
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:GetTextExtentExPointA,&rest r)
{
  object arg;
  BOOL bool0;
  HDC hdc;
  LPCSTR lpcstr;
  int int0;
  int int1;
  int* lpint;
  int* lpint0;
  SIZE* lpsize = alloca(sizeof(SIZE));
  processLPSIZE(lpsize,popSTACK());
  arg = popSTACK();
  if(!simple_bit_vector_p(Atype_32Bit,arg))invalid_argument(arg);
  lpint0 = (int*)&(TheSbvector(arg)->data);
  arg = popSTACK();
  if(!simple_bit_vector_p(Atype_32Bit,arg))invalid_argument(arg);
  lpint = (int*)&(TheSbvector(arg)->data);
  int1 = I_to_sint32(check_sint(popSTACK()));
  int0 = I_to_sint32(check_sint(popSTACK()));
  arg = popSTACK();
  if(!stringp(arg))invalid_argument(arg);
  with_string_0(arg,encoding, lpcstr, {
    arg = popSTACK();
    if(!fpointerp(arg))invalid_argument(arg);
    hdc = TheFpointer(arg)->fp_pointer;

    begin_system_call();
    bool0 = GetTextExtentExPointA(hdc,lpcstr,int0,int1,lpint,lpint0,lpsize);
    end_system_call();
    if(!bool0){
      do_GDI_ERROR("GetTextExtentExPointA");
    }
    else
    {
      VALUES1(T);
    }
  });
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:GetTextExtentExPointW,&rest r)
{
  object arg;
  BOOL bool0;
  HDC hdc;
  LPCWSTR lpcwstr;
  int int0;
  int int1;
  int* lpint;
  int* lpint0;
  SIZE* lpsize = alloca(sizeof(SIZE));
  processLPSIZE(lpsize,popSTACK());
  arg = popSTACK();
  if(!simple_bit_vector_p(Atype_32Bit,arg))invalid_argument(arg);
  lpint0 = (int*)&(TheSbvector(arg)->data);
  arg = popSTACK();
  if(!simple_bit_vector_p(Atype_32Bit,arg))invalid_argument(arg);
  lpint = (int*)&(TheSbvector(arg)->data);
  int1 = I_to_sint32(check_sint(popSTACK()));
  int0 = I_to_sint32(check_sint(popSTACK()));
  arg = popSTACK();
  if(!stringp(arg))invalid_argument(arg);
  lpcwstr = WIDECHAR(arg,encoding);
  getHDC(hdc,arg);

  begin_system_call();
  bool0 = GetTextExtentExPointW(hdc,lpcwstr,int0,int1,lpint,lpint0,lpsize);
  end_system_call();
  if(!bool0){
    do_GDI_ERROR("GetTextExtentExPointW");
  }
  else
  {
    VALUES1(T);
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:MaskBlt,&rest r)
{
  object arg;
  BOOL bool0;
  HDC hdc;
  int int0;
  int int1;
  int int2;
  int int3;
  HDC hdc0;
  int int4;
  int int5;
  HBITMAP hbitmap;
  int int6;
  int int7;
  DWORD dword;
  dword = I_to_uint32(check_uint(popSTACK()));
  int7 = I_to_sint32(check_sint(popSTACK()));
  int6 = I_to_sint32(check_sint(popSTACK()));
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hbitmap = TheFpointer(arg)->fp_pointer;
  int5 = I_to_sint32(check_sint(popSTACK()));
  int4 = I_to_sint32(check_sint(popSTACK()));
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hdc0 = TheFpointer(arg)->fp_pointer;
  int3 = I_to_sint32(check_sint(popSTACK()));
  int2 = I_to_sint32(check_sint(popSTACK()));
  int1 = I_to_sint32(check_sint(popSTACK()));
  int0 = I_to_sint32(check_sint(popSTACK()));
  getHDC(hdc,arg);
  begin_system_call();
  bool0 = MaskBlt(hdc,int0,int1,int2,int3,hdc0,int4,int5,hbitmap,int6,int7,dword);
  end_system_call();
  if(!bool0){
    do_GDI_ERROR("MaskBlt");
  }
  else
  {
    VALUES1(T);
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:PatBlt,&rest r)
{
  object arg;
  BOOL bool0;
  HDC hdc;
  int int0;
  int int1;
  int int2;
  int int3;
  DWORD dword;
  dword = I_to_uint32(check_uint(popSTACK()));
  int3 = I_to_sint32(check_sint(popSTACK()));
  int2 = I_to_sint32(check_sint(popSTACK()));
  int1 = I_to_sint32(check_sint(popSTACK()));
  int0 = I_to_sint32(check_sint(popSTACK()));
  getHDC(hdc,arg);
  begin_system_call();
  bool0 = PatBlt(hdc,int0,int1,int2,int3,dword);
  end_system_call();
  if(!bool0){
    do_GDI_ERROR("PatBlt");
  }
  else
  {
    VALUES1(T);
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:Pie,&rest r)
{
  object arg;
  BOOL bool0;
  HDC hdc;
  int int0;
  int int1;
  int int2;
  int int3;
  int int4;
  int int5;
  int int6;
  int int7;
  int7 = I_to_sint32(check_sint(popSTACK()));
  int6 = I_to_sint32(check_sint(popSTACK()));
  int5 = I_to_sint32(check_sint(popSTACK()));
  int4 = I_to_sint32(check_sint(popSTACK()));
  int3 = I_to_sint32(check_sint(popSTACK()));
  int2 = I_to_sint32(check_sint(popSTACK()));
  int1 = I_to_sint32(check_sint(popSTACK()));
  int0 = I_to_sint32(check_sint(popSTACK()));
  getHDC(hdc,arg);
  begin_system_call();
  bool0 = Pie(hdc,int0,int1,int2,int3,int4,int5,int6,int7);
  end_system_call();
  if(!bool0){
    do_GDI_ERROR("Pie");
  }
  else
  {
    VALUES1(T);
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:PlgBlt,&rest r)
{
  object arg;
  object arg0;
  BOOL bool0;
  HDC hdc;
  POINT point;
  HDC hdc0;
  int int0;
  int int1;
  int int2;
  int int3;
  HBITMAP hbitmap;
  int int4;
  int int5;
  int5 = I_to_sint32(check_sint(popSTACK()));
  int4 = I_to_sint32(check_sint(popSTACK()));
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hbitmap = TheFpointer(arg)->fp_pointer;
  int3 = I_to_sint32(check_sint(popSTACK()));
  int2 = I_to_sint32(check_sint(popSTACK()));
  int1 = I_to_sint32(check_sint(popSTACK()));
  int0 = I_to_sint32(check_sint(popSTACK()));
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hdc0 = TheFpointer(arg)->fp_pointer;
  arg0 = popSTACK();
  processPOINT(&point,arg0);
  getHDC(hdc,arg);
  begin_system_call();
  bool0 = PlgBlt(hdc,&point,hdc0,int0,int1,int2,int3,hbitmap,int4,int5);
  end_system_call();
  if(!bool0){
    do_GDI_ERROR("PlgBlt");
  }
  else
  {
    VALUES1(T);
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:RoundRect,&rest r)
{
  object arg;
  BOOL bool0;
  HDC hdc;
  int int0;
  int int1;
  int int2;
  int int3;
  int int4;
  int int5;
  int5 = I_to_sint32(check_sint(popSTACK()));
  int4 = I_to_sint32(check_sint(popSTACK()));
  int3 = I_to_sint32(check_sint(popSTACK()));
  int2 = I_to_sint32(check_sint(popSTACK()));
  int1 = I_to_sint32(check_sint(popSTACK()));
  int0 = I_to_sint32(check_sint(popSTACK()));
  getHDC(hdc,arg);
  begin_system_call();
  bool0 = RoundRect(hdc,int0,int1,int2,int3,int4,int5);
  end_system_call();
  if(!bool0){
    do_GDI_ERROR("RoundRect");
  }
  else
  {
    VALUES1(T);
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:ScaleViewportExtEx,&rest r)
{
  object arg;
  BOOL bool0;
  HDC hdc;
  int int0;
  int int1;
  int int2;
  int int3;
  SIZE* lpsize = alloca(sizeof(SIZE));
  object arg0;
  processLPSIZE(lpsize,popSTACK());
  int3 = I_to_sint32(check_sint(popSTACK()));
  int2 = I_to_sint32(check_sint(popSTACK()));
  int1 = I_to_sint32(check_sint(popSTACK()));
  int0 = I_to_sint32(check_sint(popSTACK()));
  getHDC(hdc,arg);

  begin_system_call();
  bool0 = ScaleViewportExtEx(hdc,int0,int1,int2,int3,lpsize);
  end_system_call();
  if(!bool0){
    do_GDI_ERROR("ScaleViewportExtEx");
  }
  else
  {
    VALUES1(T);
  }
  return;
}
// untested - was never called
DEFUN( GDI:ScaleWindowExtEx, hdc Xnum Xdenom Ynum Ydenom lpSize)
/*
    HDC hdc,	- handle of device context 
    int Xnum,	- horizontal multiplicand 
    int Xdenom,	- horizontal divisor 
    int Ynum,	- vertical multiplicand 
    int Ydenom,	- vertical divisor 
    LPSIZE lpSize - address of previous window extents
*/
{
  object arg;
  BOOL bool0;
  HDC hdc;
  int Xnum,Xdenom,Ynum,Ydenom;
  SIZE* lpSize = alloca(sizeof(SIZE));
  processLPSIZE(lpSize,popSTACK());
  Ydenom = I_to_sint32(check_sint(popSTACK()));
  Ynum   = I_to_sint32(check_sint(popSTACK()));
  Xdenom = I_to_sint32(check_sint(popSTACK()));
  Xnum   = I_to_sint32(check_sint(popSTACK()));
  getHDC(hdc,arg);

  begin_system_call();
  bool0 = ScaleWindowExtEx(hdc,Xnum,Xdenom,Ynum,Ydenom,lpSize);
  end_system_call();
  if(!bool0){
    do_GDI_ERROR("ScaleWindowExtEx");
  }
  else
  {
    VALUES1(T);
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:SetDIBits,&rest r)
{
  object arg;
  object arg0;
  int int0;
  HDC hdc;
  HBITMAP hbitmap;
  UINT uint;
  UINT uint0;
  void* pcvoid;
  PBITMAPINFO pbitmapinfo;
  UINT uint1;
  uint1 = I_to_uint32(check_uint(popSTACK()));
  arg0 = popSTACK();
  processFPTYPE(PBITMAPINFO,pbitmapinfo,arg0);
  arg = popSTACK();
  if(!simple_bit_vector_p(Atype_8Bit,arg))invalid_argument(arg);
  pcvoid = &(TheSbvector(arg)->data);
  uint0 = I_to_uint32(check_uint(popSTACK()));
  uint = I_to_uint32(check_uint(popSTACK()));
  arg = popSTACK();
  processFPTYPE(HBITMAP,hbitmap,arg);
  getHDC(hdc,arg);

  begin_system_call();
  int0 = SetDIBits(hdc,hbitmap,uint,uint0,pcvoid,pbitmapinfo,uint1);
  end_system_call();
  if(0 <=int0){
    do_GDI_ERROR("SetDIBits");
  }
  else
  {
    VALUES1(sint32_to_I(int0));
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:SetDIBitsToDevice,&rest r)
{
  object arg;
  object arg0;
  int int4;
  HDC hdc;
  int int0;
  int int1;
  DWORD dword;
  DWORD dword0;
  int int2;
  int int3;
  UINT uint;
  UINT uint0;
  void* pcvoid;
  PBITMAPINFO pbitmapinfo;
  UINT uint1;
  uint1 = I_to_uint32(check_uint(popSTACK()));
  arg0 = popSTACK();
  processFPTYPE(PBITMAPINFO,pbitmapinfo,arg0);
  arg = popSTACK();
  if(!simple_bit_vector_p(Atype_8Bit,arg))invalid_argument(arg);
  pcvoid = &(TheSbvector(arg)->data);
  uint0 = I_to_uint32(check_uint(popSTACK()));
  uint = I_to_uint32(check_uint(popSTACK()));
  int3 = I_to_sint32(check_sint(popSTACK()));
  int2 = I_to_sint32(check_sint(popSTACK()));
  dword0 = I_to_uint32(check_uint(popSTACK()));
  dword = I_to_uint32(check_uint(popSTACK()));
  int1 = I_to_sint32(check_sint(popSTACK()));
  int0 = I_to_sint32(check_sint(popSTACK()));
  getHDC(hdc,arg);
  begin_system_call();
  int4 = SetDIBitsToDevice(hdc,int0,int1,dword,dword0,int2,int3,uint,uint0,pcvoid,pbitmapinfo,uint1);
  end_system_call();
  if(0 <=int4){
    do_GDI_ERROR("SetDIBitsToDevice");
  }
  else
  {
    VALUES1(sint32_to_I(int4));
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:StretchBlt,&rest r)
{
  object arg;
  BOOL bool0;
  HDC hdc;
  int int0;
  int int1;
  int int2;
  int int3;
  HDC hdc0;
  int int4;
  int int5;
  int int6;
  int int7;
  DWORD dword;
  dword = I_to_uint32(check_uint(popSTACK()));
  int7 = I_to_sint32(check_sint(popSTACK()));
  int6 = I_to_sint32(check_sint(popSTACK()));
  int5 = I_to_sint32(check_sint(popSTACK()));
  int4 = I_to_sint32(check_sint(popSTACK()));
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hdc0 = TheFpointer(arg)->fp_pointer;
  int3 = I_to_sint32(check_sint(popSTACK()));
  int2 = I_to_sint32(check_sint(popSTACK()));
  int1 = I_to_sint32(check_sint(popSTACK()));
  int0 = I_to_sint32(check_sint(popSTACK()));
  getHDC(hdc,arg);
  begin_system_call();
  bool0 = StretchBlt(hdc,int0,int1,int2,int3,hdc0,int4,int5,int6,int7,dword);
  end_system_call();
  if(!bool0){
    do_GDI_ERROR("StretchBlt");
  }
  else
  {
    VALUES1(T);
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:StretchDIBits,&rest r)
{
  object arg;
  object arg0;
  int int8;
  HDC hdc;
  int int0;
  int int1;
  int int2;
  int int3;
  int int4;
  int int5;
  int int6;
  int int7;
  void* pvoid;
  PBITMAPINFO pbitmapinfo;
  UINT uint;
  DWORD dword;
  dword = I_to_uint32(check_uint(popSTACK()));
  uint = I_to_uint32(check_uint(popSTACK()));
  arg0 = popSTACK();
  processFPTYPE(PBITMAPINFO,pbitmapinfo,arg0);
  arg = popSTACK();
  if(!simple_bit_vector_p(Atype_8Bit,arg))invalid_argument(arg);
  pvoid = &(TheSbvector(arg)->data);
  int7 = I_to_sint32(check_sint(popSTACK()));
  int6 = I_to_sint32(check_sint(popSTACK()));
  int5 = I_to_sint32(check_sint(popSTACK()));
  int4 = I_to_sint32(check_sint(popSTACK()));
  int3 = I_to_sint32(check_sint(popSTACK()));
  int2 = I_to_sint32(check_sint(popSTACK()));
  int1 = I_to_sint32(check_sint(popSTACK()));
  int0 = I_to_sint32(check_sint(popSTACK()));
  getHDC(hdc,arg);
  begin_system_call();
  int8 = StretchDIBits(hdc,int0,int1,int2,int3,int4,int5,int6,int7,pvoid,pbitmapinfo,uint,dword);
  end_system_call();
  if(0 <=int8){
    do_GDI_ERROR("StretchDIBits");
  }
  else
  {
    VALUES1(sint32_to_I(int8));
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:TabbedTextOutA,&rest r)
{
  object arg;
  LONG long0;
  HDC hdc;
  int int0;
  int int1;
  LPCSTR lpcstr;
  int int2;
  int int3;
  int* lpint;
  int int4;
  int4 = I_to_sint32(check_sint(popSTACK()));
  arg = popSTACK();
  if(!simple_bit_vector_p(Atype_32Bit,arg))invalid_argument(arg);
  lpint = (int*)&(TheSbvector(arg)->data);
  int3 = I_to_sint32(check_sint(popSTACK()));
  int2 = I_to_sint32(check_sint(popSTACK()));
  arg = popSTACK();
  if(!stringp(arg))invalid_argument(arg);
  with_string_0(arg,encoding, lpcstr, {
    arg = popSTACK();
    check_sint(arg);
    int1 = I_to_sint32(arg);
    arg = popSTACK();
    check_sint(arg);
    int0 = I_to_sint32(arg);
    arg = popSTACK();
    if(!fpointerp(arg))invalid_argument(arg);
    hdc = TheFpointer(arg)->fp_pointer;
    begin_system_call();
    long0 = TabbedTextOutA(hdc,int0,int1,lpcstr,int2,int3,lpint,int4);
    end_system_call();
    if(0 <=long0){
        do_GDI_ERROR("TabbedTextOutA");
    }
    else
    {
        VALUES1(sint32_to_I(long0));
    }
  });
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:TabbedTextOutW,&rest r)
{
  object arg;
  LONG long0;
  HDC hdc;
  int int0;
  int int1;
  LPCWSTR lpcwstr;
  int int2;
  int int3;
  int* lpint;
  int int4;
  int4 = I_to_sint32(check_sint(popSTACK()));
  arg = popSTACK();
  if(!simple_bit_vector_p(Atype_32Bit,arg))invalid_argument(arg);
  lpint = (int*)&(TheSbvector(arg)->data);
  int3 = I_to_sint32(check_sint(popSTACK()));
  int2 = I_to_sint32(check_sint(popSTACK()));
  processLPWSTR(lpcwstr,popSTACK());
  int1 = I_to_sint32(check_sint(popSTACK()));
  int0 = I_to_sint32(check_sint(popSTACK()));
  getHDC(hdc,arg);
  begin_system_call();
  long0 = TabbedTextOutW(hdc,int0,int1,lpcwstr,int2,int3,lpint,int4);
  end_system_call();
  if(0 <=long0){
    do_GDI_ERROR("TabbedTextOutW");
  }
  else
  {
    VALUES1(sint32_to_I(long0));
  }
  return;
}
// untested - was never called
DEFUN( GDI:SearchPathA, lpPath lpFileName lpExtension nBufferLength lpBuffer)
/* Accepts 3 strings and a number of foreign allocated chars for the last arg.
   Returns two strings (path + filename only) and the length of the path.
*/
{
  object arg, arg0;
  DWORD nPathLength;
  LPCSTR lpPath;
  LPCSTR lpFileName;
  LPCSTR lpExtension;
  DWORD nBufferLength;
  LPSTR lpBuffer;
  LPSTR lpFilePart;
  /*
  arg = popSTACK();
  processFPTYPE(LPSTR,lpBuffer,arg);
  nBufferLength = I_to_uint32(check_uint(popSTACK()));
  arg = popSTACK();
  if(!stringp(arg))invalid_argument(arg);
  with_string_0(arg,encoding, lpExtension, {
    arg0 = popSTACK();
    if(!stringp(arg0))invalid_argument(arg0);
    with_string_0(arg0,encoding, lpFileName, {
      arg = popSTACK();
      if (nullp(arg)) {
        lpPath = NULL;
      } else {
        if(!stringp(arg))invalid_argument(arg);
        lpPath = string_to_asciz(arg,encoding);
      }
      begin_system_call();
      nPathLength = SearchPathA(lpPath,lpFileName,lpExtension,nBufferLength,
                                lpBuffer,&lpFilePart);
      end_system_call();
      if(!nPathLength){
        do_GDI_ERROR("SearchPathA");
      }
      else {
        VALUES3(asciz_to_string(lpBuffer,encoding),
                allocate_fpointer(lpFilePart),
                uint32_to_I(nPathLength));
      }
    });
  });
  */
  return;
}
// untested - was never called
// looks wrong
DEFUN( GDI:SearchPathW, lpPath lpFileName lpExtension nBufferLength lpBuffer)
{
  object arg;
  DWORD nPathLength;
  LPCWSTR lpPath;
  LPCWSTR lpFileName;
  LPCWSTR lpExtension;
  DWORD nBufferLength;
  LPWSTR lpBuffer;
  LPWSTR lpFilePart;
  object arg0;
  arg0 = popSTACK();
  processFPTYPE(LPWSTR,lpBuffer,arg0);
  nBufferLength = I_to_uint32(check_uint(popSTACK()));
  arg = popSTACK();
  if(!stringp(arg))invalid_argument(arg);
  lpExtension = WIDECHAR(arg,encoding);
  arg = popSTACK();
  if(!stringp(arg))invalid_argument(arg);
  lpFileName = WIDECHAR(arg,encoding);
  arg = popSTACK();
  if (nullp(arg))
    lpPath = NULL;
  else {
    if(!stringp(arg))invalid_argument(arg);
    lpPath = WIDECHAR(arg,encoding);
  }

  begin_system_call();
  nPathLength = SearchPathW(lpPath,lpFileName,lpExtension,nBufferLength,
                            lpBuffer,&lpFilePart);
  end_system_call();
  if(!nPathLength){
    do_GDI_ERROR("SearchPathW");
  }
  else
  {
    VALUES3(outputLPWSTR(lpBuffer,nPathLength),
            allocate_fpointer(lpFilePart),
            uint32_to_I(nPathLength));
  }
  return;
}
