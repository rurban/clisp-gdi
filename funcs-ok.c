#line 2 "funcs-ok.c"

/* functions that probably translated ok */

// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:AbortDoc, hdc)
{
  object arg;
  int int0;
  HDC hdc;
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hdc = TheFpointer(arg)->fp_pointer;
  begin_system_call();
  int0 = AbortDoc(hdc);
  end_system_call();
  if(0 <=int0){
    DWORD e;
    begin_system_call();
    e = GetLastError();
    end_system_call();
    value1 = NIL;
    value2 = uint32_to_I(e);
    mv_count=2;
  }
  else
  {
    value1 = T;
    value2 = sint32_to_I(int0);
    mv_count=2;
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:AbortPath, hdc)
{
  object arg;
  BOOL bool0;
  HDC hdc;
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hdc = TheFpointer(arg)->fp_pointer;
  begin_system_call();
  bool0 = AbortPath(hdc);
  end_system_call();
  if(!bool0){
    DWORD e;
    begin_system_call();
    e = GetLastError();
    end_system_call();
    value1 = NIL;
    value2 = uint32_to_I(e);
    mv_count=2;
  }
  else
  {
    value1 = T;
    mv_count=1;
  }
  return;
}
// untested - was never called
// inspected - changed ATOM from fp to int
DEFUN( GDI:AddAtomA, lpcstr)
{
  object arg;
  ATOM atom;
  LPCSTR lpcstr;
  arg = popSTACK();
  if(!stringp(arg))invalid_argument(arg);
  with_string_0(arg,encoding, lpcstr, {
    begin_system_call();
    atom = AddAtomA(lpcstr);
    end_system_call();
    if(!atom){
      DWORD e;
      begin_system_call();
      e = GetLastError();
      end_system_call();
      value1 = NIL;
      value2 = uint32_to_I(e);
      mv_count=2;
    }
    else
    {
      value1 = T;
      //value2 = allocate_fpointer((FOREIGN)atom);
      value2 = uint32_to_I(atom);
      mv_count=2;
    }
  });
  return;
}
// untested - was never called
// inspected - changed ATOM from fp to int
DEFUN( GDI:AddAtomW, lpcwstr)
{
  object arg;
  ATOM atom;
  LPCWSTR lpcwstr;
  arg = popSTACK();
  if(!stringp(arg))invalid_argument(arg);
  lpcwstr = WIDECHAR(arg,encoding);
  begin_system_call();
  atom = AddAtomW(lpcwstr);
  end_system_call();
  if(!atom){
    DWORD e;
    begin_system_call();
    e = GetLastError();
    end_system_call();
    value1 = NIL;
    value2 = uint32_to_I(e);
    mv_count=2;
  }
  else
  {
    value1 = T;
    value2 = uint32_to_I(atom);
    //value2 = allocate_fpointer((FOREIGN)&atom);
    mv_count=2;
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:BeginPath, hdc)
{
  object arg;
  BOOL bool0;
  HDC hdc;
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hdc = TheFpointer(arg)->fp_pointer;
  begin_system_call();
  bool0 = BeginPath(hdc);
  end_system_call();
  if(!bool0){
    DWORD e;
    begin_system_call();
    e = GetLastError();
    end_system_call();
    value1 = NIL;
    value2 = uint32_to_I(e);
    mv_count=2;
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
DEFUN( GDI:CancelDC, hdc)
{
  object arg;
  BOOL bool0;
  HDC hdc;
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hdc = TheFpointer(arg)->fp_pointer;
  begin_system_call();
  bool0 = CancelDC(hdc);
  end_system_call();
  if(!bool0){
    DWORD e;
    begin_system_call();
    e = GetLastError();
    end_system_call();
    value1 = NIL;
    value2 = uint32_to_I(e);
    mv_count=2;
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
DEFUN( GDI:CloseEnhMetaFile, hdc)
{
  object arg;
  HENHMETAFILE henhmetafile;
  HDC hdc;
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hdc = TheFpointer(arg)->fp_pointer;
  begin_system_call();
  henhmetafile = CloseEnhMetaFile(hdc);
  end_system_call();
  if(NULL ==henhmetafile){
    DWORD e;
    begin_system_call();
    e = GetLastError();
    end_system_call();
    value1 = NIL;
    value2 = uint32_to_I(e);
    mv_count=2;
  }
  else
  {
    value1 = T;
    value2 = allocate_fpointer((FOREIGN)henhmetafile);
    mv_count=2;
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:CloseFigure, hdc)
{
  object arg;
  BOOL bool0;
  HDC hdc;
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hdc = TheFpointer(arg)->fp_pointer;
  begin_system_call();
  bool0 = CloseFigure(hdc);
  end_system_call();
  if(!bool0){
    DWORD e;
    begin_system_call();
    e = GetLastError();
    end_system_call();
    value1 = NIL;
    value2 = uint32_to_I(e);
    mv_count=2;
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
DEFUN( GDI:CloseMetaFile, hdc)
{
  object arg;
  HMETAFILE hmetafile;
  HDC hdc;
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hdc = TheFpointer(arg)->fp_pointer;
  begin_system_call();
  hmetafile = CloseMetaFile(hdc);
  end_system_call();
  if(NULL ==hmetafile){
    DWORD e;
    begin_system_call();
    e = GetLastError();
    end_system_call();
    value1 = NIL;
    value2 = uint32_to_I(e);
    mv_count=2;
  }
  else
  {
    value1 = T;
    value2 = allocate_fpointer((FOREIGN)hmetafile);
    mv_count=2;
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:ColorMatchToTarget, hdc hdc0 dword)
{
#ifdef __CYGWIN__
  error(error_condition,GETTEXT("ColorMatchToTarget not supported under cygwin"));
#else
  object arg;
  BOOL bool0;
  HDC hdc;
  HDC hdc0;
  DWORD dword;
  dword = I_to_uint32(check_uint(popSTACK()));
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hdc0 = TheFpointer(arg)->fp_pointer;
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hdc = TheFpointer(arg)->fp_pointer;
  begin_system_call();
  bool0 = ColorMatchToTarget(hdc,hdc0,dword);
  end_system_call();
  if(!bool0){
    DWORD e;
    begin_system_call();
    e = GetLastError();
    end_system_call();
    value1 = NIL;
    value2 = uint32_to_I(e);
    mv_count=2;
  }
  else
  {
    value1 = T;
    mv_count=1;
  }
#endif
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:CombineRgn, hrgn hrgn0 hrgn1 int0)
{
  object arg;
  int int1;
  HRGN hrgn;
  HRGN hrgn0;
  HRGN hrgn1;
  int int0;
  arg = popSTACK();
  check_sint(arg);
  int0 = I_to_sint32(arg);
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hrgn1 = TheFpointer(arg)->fp_pointer;
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hrgn0 = TheFpointer(arg)->fp_pointer;
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hrgn = TheFpointer(arg)->fp_pointer;
  begin_system_call();
  int1 = CombineRgn(hrgn,hrgn0,hrgn1,int0);
  end_system_call();
  if(0 <=int1){
    DWORD e;
    begin_system_call();
    e = GetLastError();
    end_system_call();
    value1 = NIL;
    value2 = uint32_to_I(e);
    mv_count=2;
  }
  else
  {
    value1 = T;
    value2 = sint32_to_I(int1);
    mv_count=2;
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:CreateCompatibleBitmap, hdc int0 int1)
{
  object arg;
  HBITMAP hbitmap;
  HDC hdc;
  int int0;
  int int1;
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
  hbitmap = CreateCompatibleBitmap(hdc,int0,int1);
  end_system_call();
  if(NULL ==hbitmap){
    DWORD e;
    begin_system_call();
    e = GetLastError();
    end_system_call();
    value1 = NIL;
    value2 = uint32_to_I(e);
    mv_count=2;
  }
  else
  {
    value1 = T;
    value2 = allocate_fpointer((FOREIGN)hbitmap);
    mv_count=2;
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:CreateCompatibleDC, hdc)
{
  object arg;
  HDC hdc0;
  HDC hdc;
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hdc = TheFpointer(arg)->fp_pointer;
  begin_system_call();
  hdc0 = CreateCompatibleDC(hdc);
  end_system_call();
  if(NULL ==hdc0){
    DWORD e;
    begin_system_call();
    e = GetLastError();
    end_system_call();
    value1 = NIL;
    value2 = uint32_to_I(e);
    mv_count=2;
  }
  else
  {
    value1 = T;
    value2 = allocate_fpointer((FOREIGN)hdc0);
    mv_count=2;
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:CreateDIBPatternBrush, hglobal uint)
{
  object arg;
  HBRUSH hbrush;
  HGLOBAL hglobal;
  UINT uint;
  uint = I_to_uint32(check_uint(popSTACK()));
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hglobal = TheFpointer(arg)->fp_pointer;
  begin_system_call();
  hbrush = CreateDIBPatternBrush(hglobal,uint);
  end_system_call();
  if(NULL ==hbrush){
    DWORD e;
    begin_system_call();
    e = GetLastError();
    end_system_call();
    value1 = NIL;
    value2 = uint32_to_I(e);
    mv_count=2;
  }
  else
  {
    value1 = T;
    value2 = allocate_fpointer((FOREIGN)hbrush);
    mv_count=2;
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:CreateDiscardableBitmap, hdc int0 int1)
{
  object arg;
  HBITMAP hbitmap;
  HDC hdc;
  int int0;
  int int1;
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
  hbitmap = CreateDiscardableBitmap(hdc,int0,int1);
  end_system_call();
  if(NULL ==hbitmap){
    DWORD e;
    begin_system_call();
    e = GetLastError();
    end_system_call();
    value1 = NIL;
    value2 = uint32_to_I(e);
    mv_count=2;
  }
  else
  {
    value1 = T;
    value2 = allocate_fpointer((FOREIGN)hbitmap);
    mv_count=2;
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:CreateEllipticRgn, int0 int1 int2 int3)
{
  object arg;
  HRGN hrgn;
  int int0;
  int int1;
  int int2;
  int int3;
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
  hrgn = CreateEllipticRgn(int0,int1,int2,int3);
  end_system_call();
  if(NULL ==hrgn){
    DWORD e;
    begin_system_call();
    e = GetLastError();
    end_system_call();
    value1 = NIL;
    value2 = uint32_to_I(e);
    mv_count=2;
  }
  else
  {
    value1 = T;
    value2 = allocate_fpointer((FOREIGN)hrgn);
    mv_count=2;
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:CreateHalftonePalette, hdc)
{
  object arg;
  HPALETTE hpalette;
  HDC hdc;
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hdc = TheFpointer(arg)->fp_pointer;
  begin_system_call();
  hpalette = CreateHalftonePalette(hdc);
  end_system_call();
  if(NULL ==hpalette){
    DWORD e;
    begin_system_call();
    e = GetLastError();
    end_system_call();
    value1 = NIL;
    value2 = uint32_to_I(e);
    mv_count=2;
  }
  else
  {
    value1 = T;
    value2 = allocate_fpointer((FOREIGN)hpalette);
    mv_count=2;
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:CreateHatchBrush, int0 colorref)
{
  object arg;
  HBRUSH hbrush;
  int int0;
  COLORREF colorref;
  colorref = I_to_uint32(check_uint(popSTACK()));
  arg = popSTACK();
  check_sint(arg);
  int0 = I_to_sint32(arg);
  begin_system_call();
  hbrush = CreateHatchBrush(int0,colorref);
  end_system_call();
  if(NULL ==hbrush){
    DWORD e;
    begin_system_call();
    e = GetLastError();
    end_system_call();
    value1 = NIL;
    value2 = uint32_to_I(e);
    mv_count=2;
  }
  else
  {
    value1 = T;
    value2 = allocate_fpointer((FOREIGN)hbrush);
    mv_count=2;
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:CreatePatternBrush, hbitmap)
{
  object arg;
  HBRUSH hbrush;
  HBITMAP hbitmap;
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hbitmap = TheFpointer(arg)->fp_pointer;
  begin_system_call();
  hbrush = CreatePatternBrush(hbitmap);
  end_system_call();
  if(NULL ==hbrush){
    DWORD e;
    begin_system_call();
    e = GetLastError();
    end_system_call();
    value1 = NIL;
    value2 = uint32_to_I(e);
    mv_count=2;
  }
  else
  {
    value1 = T;
    value2 = allocate_fpointer((FOREIGN)hbrush);
    mv_count=2;
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:CreatePen, int0 int1 colorref)
{
  object arg;
  HPEN hpen;
  int int0;
  int int1;
  COLORREF colorref;
  colorref = I_to_uint32(check_uint(popSTACK()));
  arg = popSTACK();
  check_sint(arg);
  int1 = I_to_sint32(arg);
  arg = popSTACK();
  check_sint(arg);
  int0 = I_to_sint32(arg);
  begin_system_call();
  hpen = CreatePen(int0,int1,colorref);
  end_system_call();
  if(NULL ==hpen){
    DWORD e;
    begin_system_call();
    e = GetLastError();
    end_system_call();
    value1 = NIL;
    value2 = uint32_to_I(e);
    mv_count=2;
  }
  else
  {
    value1 = T;
    value2 = allocate_fpointer((FOREIGN)hpen);
    mv_count=2;
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:CreateRectRgn, int0 int1 int2 int3)
{
  object arg;
  HRGN hrgn;
  int int0;
  int int1;
  int int2;
  int int3;
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
  hrgn = CreateRectRgn(int0,int1,int2,int3);
  end_system_call();
  if(NULL ==hrgn){
    DWORD e;
    begin_system_call();
    e = GetLastError();
    end_system_call();
    value1 = NIL;
    value2 = uint32_to_I(e);
    mv_count=2;
  }
  else
  {
    value1 = T;
    value2 = allocate_fpointer((FOREIGN)hrgn);
    mv_count=2;
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:CreateSolidBrush, colorref)
{
  object arg;
  HBRUSH hbrush;
  COLORREF colorref;
  colorref = I_to_uint32(check_uint(popSTACK()));
  begin_system_call();
  hbrush = CreateSolidBrush(colorref);
  end_system_call();
  if(NULL ==hbrush){
    DWORD e;
    begin_system_call();
    e = GetLastError();
    end_system_call();
    value1 = NIL;
    value2 = uint32_to_I(e);
    mv_count=2;
  }
  else
  {
    value1 = T;
    value2 = allocate_fpointer((FOREIGN)hbrush);
    mv_count=2;
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:DeleteColorSpace, hcolorspace)
{
  object arg;
  BOOL bool0;
  HCOLORSPACE hcolorspace;
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hcolorspace = TheFpointer(arg)->fp_pointer;
  begin_system_call();
  bool0 = DeleteColorSpace(hcolorspace);
  end_system_call();
  if(!bool0){
    DWORD e;
    begin_system_call();
    e = GetLastError();
    end_system_call();
    value1 = NIL;
    value2 = uint32_to_I(e);
    mv_count=2;
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
DEFUN( GDI:DeleteDC, hdc)
{
  object arg;
  BOOL bool0;
  HDC hdc;
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hdc = TheFpointer(arg)->fp_pointer;
  begin_system_call();
  bool0 = DeleteDC(hdc);
  end_system_call();
  if(!bool0){
    DWORD e;
    begin_system_call();
    e = GetLastError();
    end_system_call();
    value1 = NIL;
    value2 = uint32_to_I(e);
    mv_count=2;
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
DEFUN( GDI:DeleteEnhMetaFile, henhmetafile)
{
  object arg;
  BOOL bool0;
  HENHMETAFILE henhmetafile;
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  henhmetafile = TheFpointer(arg)->fp_pointer;
  begin_system_call();
  bool0 = DeleteEnhMetaFile(henhmetafile);
  end_system_call();
  if(!bool0){
    DWORD e;
    begin_system_call();
    e = GetLastError();
    end_system_call();
    value1 = NIL;
    value2 = uint32_to_I(e);
    mv_count=2;
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
DEFUN( GDI:DeleteMetaFile, hmetafile)
{
  object arg;
  BOOL bool0;
  HMETAFILE hmetafile;
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hmetafile = TheFpointer(arg)->fp_pointer;
  begin_system_call();
  bool0 = DeleteMetaFile(hmetafile);
  end_system_call();
  if(!bool0){
    DWORD e;
    begin_system_call();
    e = GetLastError();
    end_system_call();
    value1 = NIL;
    value2 = uint32_to_I(e);
    mv_count=2;
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
DEFUN( GDI:DeleteObject, hgdiobj)
{
  object arg;
  BOOL bool0;
  HGDIOBJ hgdiobj;
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hgdiobj = TheFpointer(arg)->fp_pointer;
  begin_system_call();
  bool0 = DeleteObject(hgdiobj);
  end_system_call();
  if(!bool0){
    DWORD e;
    begin_system_call();
    e = GetLastError();
    end_system_call();
    value1 = NIL;
    value2 = uint32_to_I(e);
    mv_count=2;
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
DEFUN( GDI:Ellipse, hdc int0 int1 int2 int3)
{
  object arg;
  BOOL bool0;
  HDC hdc;
  int int0;
  int int1;
  int int2;
  int int3;
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
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hdc = TheFpointer(arg)->fp_pointer;
  begin_system_call();
  bool0 = Ellipse(hdc,int0,int1,int2,int3);
  end_system_call();
  if(!bool0){
    DWORD e;
    begin_system_call();
    e = GetLastError();
    end_system_call();
    value1 = NIL;
    value2 = uint32_to_I(e);
    mv_count=2;
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
DEFUN( GDI:EndDoc, hdc)
{
  object arg;
  int int0;
  HDC hdc;
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hdc = TheFpointer(arg)->fp_pointer;
  begin_system_call();
  int0 = EndDoc(hdc);
  end_system_call();
  if(0 <=int0){
    DWORD e;
    begin_system_call();
    e = GetLastError();
    end_system_call();
    value1 = NIL;
    value2 = uint32_to_I(e);
    mv_count=2;
  }
  else
  {
    value1 = T;
    value2 = sint32_to_I(int0);
    mv_count=2;
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:EndPage, hdc)
{
  object arg;
  int int0;
  HDC hdc;
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hdc = TheFpointer(arg)->fp_pointer;
  begin_system_call();
  int0 = EndPage(hdc);
  end_system_call();
  if(0 <=int0){
    DWORD e;
    begin_system_call();
    e = GetLastError();
    end_system_call();
    value1 = NIL;
    value2 = uint32_to_I(e);
    mv_count=2;
  }
  else
  {
    value1 = T;
    value2 = sint32_to_I(int0);
    mv_count=2;
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:EndPath, hdc)
{
  object arg;
  BOOL bool0;
  HDC hdc;
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hdc = TheFpointer(arg)->fp_pointer;
  begin_system_call();
  bool0 = EndPath(hdc);
  end_system_call();
  if(!bool0){
    DWORD e;
    begin_system_call();
    e = GetLastError();
    end_system_call();
    value1 = NIL;
    value2 = uint32_to_I(e);
    mv_count=2;
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
DEFUN( GDI:EqualRgn, hrgn hrgn0)
{
  object arg;
  BOOL bool0;
  HRGN hrgn;
  HRGN hrgn0;
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hrgn0 = TheFpointer(arg)->fp_pointer;
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hrgn = TheFpointer(arg)->fp_pointer;
  begin_system_call();
  bool0 = EqualRgn(hrgn,hrgn0);
  end_system_call();
  if(!bool0){
    DWORD e;
    begin_system_call();
    e = GetLastError();
    end_system_call();
    value1 = NIL;
    value2 = uint32_to_I(e);
    mv_count=2;
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
DEFUN( GDI:EscapeCommFunction, handle dword)
{
  object arg;
  BOOL bool0;
  HANDLE handle;
  DWORD dword;
  dword = I_to_uint32(check_uint(popSTACK()));
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  handle = TheFpointer(arg)->fp_pointer;
  begin_system_call();
  bool0 = EscapeCommFunction(handle,dword);
  end_system_call();
  if(!bool0){
    DWORD e;
    begin_system_call();
    e = GetLastError();
    end_system_call();
    value1 = NIL;
    value2 = uint32_to_I(e);
    mv_count=2;
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
DEFUN( GDI:ExcludeClipRect, hdc int0 int1 int2 int3)
{
  object arg;
  int int4;
  HDC hdc;
  int int0;
  int int1;
  int int2;
  int int3;
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
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hdc = TheFpointer(arg)->fp_pointer;
  begin_system_call();
  int4 = ExcludeClipRect(hdc,int0,int1,int2,int3);
  end_system_call();
  if(0 <=int4){
    DWORD e;
    begin_system_call();
    e = GetLastError();
    end_system_call();
    value1 = NIL;
    value2 = uint32_to_I(e);
    mv_count=2;
  }
  else
  {
    value1 = T;
    value2 = sint32_to_I(int4);
    mv_count=2;
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:ExtFloodFill, hdc int0 int1 colorref uint)
{
  object arg;
  BOOL bool0;
  HDC hdc;
  int int0;
  int int1;
  COLORREF colorref;
  UINT uint;
  uint = I_to_uint32(check_uint(popSTACK()));
  colorref = I_to_uint32(check_uint(popSTACK()));
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
  bool0 = ExtFloodFill(hdc,int0,int1,colorref,uint);
  end_system_call();
  if(!bool0){
    DWORD e;
    begin_system_call();
    e = GetLastError();
    end_system_call();
    value1 = NIL;
    value2 = uint32_to_I(e);
    mv_count=2;
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
DEFUN( GDI:ExtSelectClipRgn, hdc hrgn int0)
{
  object arg;
  int int1;
  HDC hdc;
  HRGN hrgn;
  int int0;
  arg = popSTACK();
  check_sint(arg);
  int0 = I_to_sint32(arg);
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hrgn = TheFpointer(arg)->fp_pointer;
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hdc = TheFpointer(arg)->fp_pointer;
  begin_system_call();
  int1 = ExtSelectClipRgn(hdc,hrgn,int0);
  end_system_call();
  if(0 <=int1){
    DWORD e;
    begin_system_call();
    e = GetLastError();
    end_system_call();
    value1 = NIL;
    value2 = uint32_to_I(e);
    mv_count=2;
  }
  else
  {
    value1 = T;
    value2 = sint32_to_I(int1);
    mv_count=2;
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:FillPath, hdc)
{
  object arg;
  BOOL bool0;
  HDC hdc;
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hdc = TheFpointer(arg)->fp_pointer;
  begin_system_call();
  bool0 = FillPath(hdc);
  end_system_call();
  if(!bool0){
    DWORD e;
    begin_system_call();
    e = GetLastError();
    end_system_call();
    value1 = NIL;
    value2 = uint32_to_I(e);
    mv_count=2;
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
DEFUN( GDI:FillRgn, hdc hrgn hbrush)
{
  object arg;
  int int0;
  HDC hdc;
  HRGN hrgn;
  HBRUSH hbrush;
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hbrush = TheFpointer(arg)->fp_pointer;
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hrgn = TheFpointer(arg)->fp_pointer;
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hdc = TheFpointer(arg)->fp_pointer;
  begin_system_call();
  int0 = FillRgn(hdc,hrgn,hbrush);
  end_system_call();
  if(0 <=int0){
    DWORD e;
    begin_system_call();
    e = GetLastError();
    end_system_call();
    value1 = NIL;
    value2 = uint32_to_I(e);
    mv_count=2;
  }
  else
  {
    value1 = T;
    value2 = sint32_to_I(int0);
    mv_count=2;
  }
  return;
}
// untested - was never called
// inspected - changed ATOM from fp to int
DEFUN( GDI:FindAtomA, lpcstr)
{
  object arg;
  ATOM atom;
  LPCSTR lpcstr;
  arg = popSTACK();
  if(!stringp(arg))invalid_argument(arg);
  with_string_0(arg,encoding, lpcstr, {
    begin_system_call();
    atom = FindAtomA(lpcstr);
    end_system_call();
    if(0 ==atom){
      DWORD e;
      begin_system_call();
      e = GetLastError();
      end_system_call();
      value1 = NIL;
      value2 = uint32_to_I(e);
      mv_count=2;
    }
    else
    {
      value1 = T;
      //value2 = allocate_fpointer((FOREIGN)atom);
      value2 = uint32_to_I(atom);
      mv_count=2;
    }
  });
  return;
}
// untested - was never called
// inspected - changed ATOM from fp to int
DEFUN( GDI:FindAtomW, lpcwstr)
{
  object arg;
  ATOM atom;
  LPCWSTR lpcwstr;
  arg = popSTACK();
  if(!stringp(arg))invalid_argument(arg);
  lpcwstr = WIDECHAR(arg,encoding);
  begin_system_call();
  atom = FindAtomW(lpcwstr);
  end_system_call();
  if(0 ==atom){
    DWORD e;
    begin_system_call();
    e = GetLastError();
    end_system_call();
    value1 = NIL;
    value2 = uint32_to_I(e);
    mv_count=2;
  }
  else
  {
    value1 = T;
    //value2 = allocate_fpointer((FOREIGN)atom);
    value2 = uint32_to_I(atom);
    mv_count=2;
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:FlattenPath, hdc)
{
  object arg;
  BOOL bool0;
  HDC hdc;
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hdc = TheFpointer(arg)->fp_pointer;
  begin_system_call();
  bool0 = FlattenPath(hdc);
  end_system_call();
  if(!bool0){
    DWORD e;
    begin_system_call();
    e = GetLastError();
    end_system_call();
    value1 = NIL;
    value2 = uint32_to_I(e);
    mv_count=2;
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
DEFUN( GDI:FloodFill, hdc int0 int1 colorref)
{
  object arg;
  BOOL bool0;
  HDC hdc;
  int int0;
  int int1;
  COLORREF colorref;
  colorref = I_to_uint32(check_uint(popSTACK()));
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
  bool0 = FloodFill(hdc,int0,int1,colorref);
  end_system_call();
  if(!bool0){
    DWORD e;
    begin_system_call();
    e = GetLastError();
    end_system_call();
    value1 = NIL;
    value2 = uint32_to_I(e);
    mv_count=2;
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
DEFUN( GDI:FrameRgn, hdc hrgn hbrush int0 int1)
{
  object arg;
  BOOL bool0;
  HDC hdc;
  HRGN hrgn;
  HBRUSH hbrush;
  int int0;
  int int1;
  arg = popSTACK();
  check_sint(arg);
  int1 = I_to_sint32(arg);
  arg = popSTACK();
  check_sint(arg);
  int0 = I_to_sint32(arg);
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hbrush = TheFpointer(arg)->fp_pointer;
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hrgn = TheFpointer(arg)->fp_pointer;
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hdc = TheFpointer(arg)->fp_pointer;
  begin_system_call();
  bool0 = FrameRgn(hdc,hrgn,hbrush,int0,int1);
  end_system_call();
  if(!bool0){
    DWORD e;
    begin_system_call();
    e = GetLastError();
    end_system_call();
    value1 = NIL;
    value2 = uint32_to_I(e);
    mv_count=2;
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
DEFUN( GDI:GdiSetBatchLimit, dword)
{
  object arg;
  DWORD dword0;
  DWORD dword;
  dword = I_to_uint32(check_uint(popSTACK()));
  begin_system_call();
  dword0 = GdiSetBatchLimit(dword);
  end_system_call();
  if(!dword0){
    DWORD e;
    begin_system_call();
    e = GetLastError();
    end_system_call();
    value1 = NIL;
    value2 = uint32_to_I(e);
    mv_count=2;
  }
  else
  {
    value1 = T;
    value2 = uint32_to_I(dword0);
    mv_count=2;
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:GetArcDirection, hdc)
{
  object arg;
  int int0;
  HDC hdc;
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hdc = TheFpointer(arg)->fp_pointer;
  begin_system_call();
  int0 = GetArcDirection(hdc);
  end_system_call();
  if(0 <=int0){
    DWORD e;
    begin_system_call();
    e = GetLastError();
    end_system_call();
    value1 = NIL;
    value2 = uint32_to_I(e);
    mv_count=2;
  }
  else
  {
    value1 = T;
    value2 = sint32_to_I(int0);
    mv_count=2;
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:GetBkColor, hdc)
{
  object arg;
  COLORREF colorref;
  HDC hdc;
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hdc = TheFpointer(arg)->fp_pointer;
  begin_system_call();
  colorref = GetBkColor(hdc);
  end_system_call();
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:GetBkMode, hdc)
{
  object arg;
  int int0;
  HDC hdc;
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hdc = TheFpointer(arg)->fp_pointer;
  begin_system_call();
  int0 = GetBkMode(hdc);
  end_system_call();
  if(0 <=int0){
    DWORD e;
    begin_system_call();
    e = GetLastError();
    end_system_call();
    value1 = NIL;
    value2 = uint32_to_I(e);
    mv_count=2;
  }
  else
  {
    value1 = T;
    value2 = sint32_to_I(int0);
    mv_count=2;
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:GetClipRgn, hdc hrgn)
{
  object arg;
  int int0;
  HDC hdc;
  HRGN hrgn;
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hrgn = TheFpointer(arg)->fp_pointer;
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hdc = TheFpointer(arg)->fp_pointer;
  begin_system_call();
  int0 = GetClipRgn(hdc,hrgn);
  end_system_call();
  if(0 <=int0){
    DWORD e;
    begin_system_call();
    e = GetLastError();
    end_system_call();
    value1 = NIL;
    value2 = uint32_to_I(e);
    mv_count=2;
  }
  else
  {
    value1 = T;
    value2 = sint32_to_I(int0);
    mv_count=2;
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:GetColorSpace, hdc)
{
  object arg;
  HANDLE handle;
  HDC hdc;
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hdc = TheFpointer(arg)->fp_pointer;
  begin_system_call();
  handle = GetColorSpace(hdc);
  end_system_call();
  if(NULL ==handle){
    DWORD e;
    begin_system_call();
    e = GetLastError();
    end_system_call();
    value1 = NIL;
    value2 = uint32_to_I(e);
    mv_count=2;
  }
  else
  {
    value1 = T;
    value2 = allocate_fpointer((FOREIGN)handle);
    mv_count=2;
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:GetCurrentObject, hdc uint)
{
  object arg;
  HGDIOBJ hgdiobj;
  HDC hdc;
  UINT uint;
  uint = I_to_uint32(check_uint(popSTACK()));
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hdc = TheFpointer(arg)->fp_pointer;
  begin_system_call();
  hgdiobj = GetCurrentObject(hdc,uint);
  end_system_call();
  if(NULL ==hgdiobj){
    DWORD e;
    begin_system_call();
    e = GetLastError();
    end_system_call();
    value1 = NIL;
    value2 = uint32_to_I(e);
    mv_count=2;
  }
  else
  {
    value1 = T;
    value2 = allocate_fpointer((FOREIGN)hgdiobj);
    mv_count=2;
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:GetFontLanguageInfo, hdc)
{
  object arg;
  DWORD dword;
  HDC hdc;
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hdc = TheFpointer(arg)->fp_pointer;
  begin_system_call();
  dword = GetFontLanguageInfo(hdc);
  end_system_call();
  if(!dword){
    DWORD e;
    begin_system_call();
    e = GetLastError();
    end_system_call();
    value1 = NIL;
    value2 = uint32_to_I(e);
    mv_count=2;
  }
  else
  {
    value1 = T;
    value2 = uint32_to_I(dword);
    mv_count=2;
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:GetGraphicsMode, hdc)
{
  object arg;
  int int0;
  HDC hdc;
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hdc = TheFpointer(arg)->fp_pointer;
  begin_system_call();
  int0 = GetGraphicsMode(hdc);
  end_system_call();
  if(0 <=int0){
    DWORD e;
    begin_system_call();
    e = GetLastError();
    end_system_call();
    value1 = NIL;
    value2 = uint32_to_I(e);
    mv_count=2;
  }
  else
  {
    value1 = T;
    value2 = sint32_to_I(int0);
    mv_count=2;
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:GetMapMode, hdc)
{
  object arg;
  int int0;
  HDC hdc;
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hdc = TheFpointer(arg)->fp_pointer;
  begin_system_call();
  int0 = GetMapMode(hdc);
  end_system_call();
  if(0 <=int0){
    DWORD e;
    begin_system_call();
    e = GetLastError();
    end_system_call();
    value1 = NIL;
    value2 = uint32_to_I(e);
    mv_count=2;
  }
  else
  {
    value1 = T;
    value2 = sint32_to_I(int0);
    mv_count=2;
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:GetMetaRgn, hdc hrgn)
{
  object arg;
  int int0;
  HDC hdc;
  HRGN hrgn;
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hrgn = TheFpointer(arg)->fp_pointer;
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hdc = TheFpointer(arg)->fp_pointer;
  begin_system_call();
  int0 = GetMetaRgn(hdc,hrgn);
  end_system_call();
  if(0 <=int0){
    DWORD e;
    begin_system_call();
    e = GetLastError();
    end_system_call();
    value1 = NIL;
    value2 = uint32_to_I(e);
    mv_count=2;
  }
  else
  {
    value1 = T;
    value2 = sint32_to_I(int0);
    mv_count=2;
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:GetNearestColor, hdc colorref)
{
  object arg;
  COLORREF colorref0;
  HDC hdc;
  COLORREF colorref;
  colorref = I_to_uint32(check_uint(popSTACK()));
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hdc = TheFpointer(arg)->fp_pointer;
  begin_system_call();
  colorref0 = GetNearestColor(hdc,colorref);
  end_system_call();
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:GetNearestPaletteIndex, hpalette colorref)
{
  object arg;
  UINT uint;
  HPALETTE hpalette;
  COLORREF colorref;
  colorref = I_to_uint32(check_uint(popSTACK()));
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hpalette = TheFpointer(arg)->fp_pointer;
  begin_system_call();
  uint = GetNearestPaletteIndex(hpalette,colorref);
  end_system_call();
  if(!uint){
    DWORD e;
    begin_system_call();
    e = GetLastError();
    end_system_call();
    value1 = NIL;
    value2 = uint32_to_I(e);
    mv_count=2;
  }
  else
  {
    value1 = T;
    value2 = uint32_to_I(uint);
    mv_count=2;
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:GetObjectType, hgdiobj)
{
  object arg;
  DWORD dword;
  HGDIOBJ hgdiobj;
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hgdiobj = TheFpointer(arg)->fp_pointer;
  begin_system_call();
  dword = GetObjectType(hgdiobj);
  end_system_call();
  if(!dword){
    DWORD e;
    begin_system_call();
    e = GetLastError();
    end_system_call();
    value1 = NIL;
    value2 = uint32_to_I(e);
    mv_count=2;
  }
  else
  {
    value1 = T;
    value2 = uint32_to_I(dword);
    mv_count=2;
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:GetPixel, hdc int0 int1)
{
  object arg;
  COLORREF colorref;
  HDC hdc;
  int int0;
  int int1;
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
  colorref = GetPixel(hdc,int0,int1);
  end_system_call();
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:GetPixelFormat, hdc)
{
  object arg;
  int int0;
  HDC hdc;
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hdc = TheFpointer(arg)->fp_pointer;
  begin_system_call();
  int0 = GetPixelFormat(hdc);
  end_system_call();
  if(0 <=int0){
    DWORD e;
    begin_system_call();
    e = GetLastError();
    end_system_call();
    value1 = NIL;
    value2 = uint32_to_I(e);
    mv_count=2;
  }
  else
  {
    value1 = T;
    value2 = sint32_to_I(int0);
    mv_count=2;
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:GetPolyFillMode, hdc)
{
  object arg;
  int int0;
  HDC hdc;
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hdc = TheFpointer(arg)->fp_pointer;
  begin_system_call();
  int0 = GetPolyFillMode(hdc);
  end_system_call();
  if(0 <=int0){
    DWORD e;
    begin_system_call();
    e = GetLastError();
    end_system_call();
    value1 = NIL;
    value2 = uint32_to_I(e);
    mv_count=2;
  }
  else
  {
    value1 = T;
    value2 = sint32_to_I(int0);
    mv_count=2;
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:GETROP2, hdc)
{
  object arg;
  int int0;
  HDC hdc;
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hdc = TheFpointer(arg)->fp_pointer;
  begin_system_call();
  int0 = GetROP2(hdc);
  end_system_call();
  if(0 <=int0){
    DWORD e;
    begin_system_call();
    e = GetLastError();
    end_system_call();
    value1 = NIL;
    value2 = uint32_to_I(e);
    mv_count=2;
  }
  else
  {
    value1 = T;
    value2 = sint32_to_I(int0);
    mv_count=2;
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:GetStockObject, int0)
{
  object arg;
  HGDIOBJ hgdiobj;
  int int0;
  arg = popSTACK();
  check_sint(arg);
  int0 = I_to_sint32(arg);
  begin_system_call();
  hgdiobj = GetStockObject(int0);
  end_system_call();
  if(NULL ==hgdiobj){
    DWORD e;
    begin_system_call();
    e = GetLastError();
    end_system_call();
    value1 = NIL;
    value2 = uint32_to_I(e);
    mv_count=2;
  }
  else
  {
    value1 = T;
    value2 = allocate_fpointer((FOREIGN)hgdiobj);
    mv_count=2;
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:GetStretchBltMode, hdc)
{
  object arg;
  int int0;
  HDC hdc;
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hdc = TheFpointer(arg)->fp_pointer;
  begin_system_call();
  int0 = GetStretchBltMode(hdc);
  end_system_call();
  if(0 <=int0){
    DWORD e;
    begin_system_call();
    e = GetLastError();
    end_system_call();
    value1 = NIL;
    value2 = uint32_to_I(e);
    mv_count=2;
  }
  else
  {
    value1 = T;
    value2 = sint32_to_I(int0);
    mv_count=2;
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:GetSystemPaletteUse, hdc)
{
  object arg;
  UINT uint;
  HDC hdc;
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hdc = TheFpointer(arg)->fp_pointer;
  begin_system_call();
  uint = GetSystemPaletteUse(hdc);
  end_system_call();
  if(!uint){
    DWORD e;
    begin_system_call();
    e = GetLastError();
    end_system_call();
    value1 = NIL;
    value2 = uint32_to_I(e);
    mv_count=2;
  }
  else
  {
    value1 = T;
    value2 = uint32_to_I(uint);
    mv_count=2;
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:GetTextAlign, hdc)
{
  object arg;
  UINT uint;
  HDC hdc;
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hdc = TheFpointer(arg)->fp_pointer;
  begin_system_call();
  uint = GetTextAlign(hdc);
  end_system_call();
  if(!uint){
    DWORD e;
    begin_system_call();
    e = GetLastError();
    end_system_call();
    value1 = NIL;
    value2 = uint32_to_I(e);
    mv_count=2;
  }
  else
  {
    value1 = T;
    value2 = uint32_to_I(uint);
    mv_count=2;
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:GetTextCharacterExtra, hdc)
{
  object arg;
  int int0;
  HDC hdc;
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hdc = TheFpointer(arg)->fp_pointer;
  begin_system_call();
  int0 = GetTextCharacterExtra(hdc);
  end_system_call();
  if(0 <=int0){
    DWORD e;
    begin_system_call();
    e = GetLastError();
    end_system_call();
    value1 = NIL;
    value2 = uint32_to_I(e);
    mv_count=2;
  }
  else
  {
    value1 = T;
    value2 = sint32_to_I(int0);
    mv_count=2;
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:GetTextCharset, hdc)
{
  object arg;
  int int0;
  HDC hdc;
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hdc = TheFpointer(arg)->fp_pointer;
  begin_system_call();
  int0 = GetTextCharset(hdc);
  end_system_call();
  if(0 <=int0){
    DWORD e;
    begin_system_call();
    e = GetLastError();
    end_system_call();
    value1 = NIL;
    value2 = uint32_to_I(e);
    mv_count=2;
  }
  else
  {
    value1 = T;
    value2 = sint32_to_I(int0);
    mv_count=2;
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:GetTextColor, hdc)
{
  object arg;
  COLORREF colorref;
  HDC hdc;
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hdc = TheFpointer(arg)->fp_pointer;
  begin_system_call();
  colorref = GetTextColor(hdc);
  end_system_call();
}
// untested - was never called
// inspected - changed ATOM from fp to int
DEFUN( GDI:GlobalAddAtomA, lpcstr)
{
  object arg;
  ATOM atom;
  LPCSTR lpcstr;
  arg = popSTACK();
  if(!stringp(arg))invalid_argument(arg);
  with_string_0(arg,encoding, lpcstr, {
    begin_system_call();
    atom = GlobalAddAtomA(lpcstr);
    end_system_call();
    if(0 ==atom){
      DWORD e;
      begin_system_call();
      e = GetLastError();
      end_system_call();
      value1 = NIL;
      value2 = uint32_to_I(e);
      mv_count=2;
    }
    else
    {
      value1 = T;
      //value2 = allocate_fpointer((FOREIGN)atom);
      value2 = uint32_to_I(atom);
      mv_count=2;
    }
  });
  return;
}
// untested - was never called
// inspected - changed ATOM from fp to int
DEFUN( GDI:GlobalAddAtomW, lpcwstr)
{
  object arg;
  ATOM atom;
  LPCWSTR lpcwstr;
  arg = popSTACK();
  if(!stringp(arg))invalid_argument(arg);
  lpcwstr = WIDECHAR(arg,encoding);
  begin_system_call();
  atom = GlobalAddAtomW(lpcwstr);
  end_system_call();
  if(0 ==atom){
    DWORD e;
    begin_system_call();
    e = GetLastError();
    end_system_call();
    value1 = NIL;
    value2 = uint32_to_I(e);
    mv_count=2;
  }
  else
  {
    value1 = T;
    //value2 = allocate_fpointer((FOREIGN)atom);
    value2 = uint32_to_I(atom);
    mv_count=2;
  }
  return;
}
// untested - was never called
// inspected - changed ATOM from fp to int
DEFUN( GDI:GlobalFindAtomA, lpcstr)
{
  object arg;
  ATOM atom;
  LPCSTR lpcstr;
  arg = popSTACK();
  if(!stringp(arg))invalid_argument(arg);
  with_string_0(arg,encoding, lpcstr, {
    begin_system_call();
    atom = GlobalFindAtomA(lpcstr);
    end_system_call();
    if(0 ==atom){
      DWORD e;
      begin_system_call();
      e = GetLastError();
      end_system_call();
      value1 = NIL;
      value2 = uint32_to_I(e);
      mv_count=2;
    }
    else
    {
      value1 = T;
      //value2 = allocate_fpointer((FOREIGN)atom);
      value2 = uint32_to_I(atom);
      mv_count=2;
    }
  });
  return;
}
// untested - was never called
// inspected - changed ATOM from fp to int
DEFUN( GDI:GlobalFindAtomW, lpcwstr)
{
  object arg;
  ATOM atom;
  LPCWSTR lpcwstr;
  arg = popSTACK();
  if(!stringp(arg))invalid_argument(arg);
  lpcwstr = WIDECHAR(arg,encoding);
  begin_system_call();
  atom = GlobalFindAtomW(lpcwstr);
  end_system_call();
  if(0 ==atom){
    DWORD e;
    begin_system_call();
    e = GetLastError();
    end_system_call();
    value1 = NIL;
    value2 = uint32_to_I(e);
    mv_count=2;
  }
  else
  {
    value1 = T;
    //value2 = allocate_fpointer((FOREIGN)atom);
    value2 = uint32_to_I(atom);
    mv_count=2;
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:IntersectClipRect, hdc int0 int1 int2 int3)
{
  object arg;
  int int4;
  HDC hdc;
  int int0;
  int int1;
  int int2;
  int int3;
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
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hdc = TheFpointer(arg)->fp_pointer;
  begin_system_call();
  int4 = IntersectClipRect(hdc,int0,int1,int2,int3);
  end_system_call();
  if(0 <=int4){
    DWORD e;
    begin_system_call();
    e = GetLastError();
    end_system_call();
    value1 = NIL;
    value2 = uint32_to_I(e);
    mv_count=2;
  }
  else
  {
    value1 = T;
    value2 = sint32_to_I(int4);
    mv_count=2;
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:InvertRgn, hdc hrgn)
{
  object arg;
  BOOL bool0;
  HDC hdc;
  HRGN hrgn;
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hrgn = TheFpointer(arg)->fp_pointer;
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hdc = TheFpointer(arg)->fp_pointer;
  begin_system_call();
  bool0 = InvertRgn(hdc,hrgn);
  end_system_call();
  if(!bool0){
    DWORD e;
    begin_system_call();
    e = GetLastError();
    end_system_call();
    value1 = NIL;
    value2 = uint32_to_I(e);
    mv_count=2;
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
DEFUN( GDI:LineTo, hdc int0 int1)
{
  object arg;
  BOOL bool0;
  HDC hdc;
  int int0;
  int int1;
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
  bool0 = LineTo(hdc,int0,int1);
  end_system_call();
  if(!bool0){
    DWORD e;
    begin_system_call();
    e = GetLastError();
    end_system_call();
    value1 = NIL;
    value2 = uint32_to_I(e);
    mv_count=2;
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
DEFUN( GDI:LoadCursorFromFileA, lpcstr)
{
  object arg;
  HCURSOR hcursor;
  LPCSTR lpcstr;
  arg = popSTACK();
  if(!stringp(arg))invalid_argument(arg);
  with_string_0(arg,encoding, lpcstr, {
    begin_system_call();
    hcursor = LoadCursorFromFileA(lpcstr);
    end_system_call();
    if(NULL ==hcursor){
      DWORD e;
      begin_system_call();
      e = GetLastError();
      end_system_call();
      value1 = NIL;
      value2 = uint32_to_I(e);
      mv_count=2;
    }
    else
    {
      value1 = T;
      value2 = allocate_fpointer((FOREIGN)hcursor);
      mv_count=2;
    }
  });
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:LoadCursorFromFileW, lpcwstr)
{
  object arg;
  HCURSOR hcursor;
  LPCWSTR lpcwstr;
  arg = popSTACK();
  if(!stringp(arg))invalid_argument(arg);
  lpcwstr = WIDECHAR(arg,encoding);
  begin_system_call();
  hcursor = LoadCursorFromFileW(lpcwstr);
  end_system_call();
  if(NULL ==hcursor){
    DWORD e;
    begin_system_call();
    e = GetLastError();
    end_system_call();
    value1 = NIL;
    value2 = uint32_to_I(e);
    mv_count=2;
  }
  else
  {
    value1 = T;
    value2 = allocate_fpointer((FOREIGN)hcursor);
    mv_count=2;
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:OffsetClipRgn, hdc int0 int1)
{
  object arg;
  int int2;
  HDC hdc;
  int int0;
  int int1;
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
  int2 = OffsetClipRgn(hdc,int0,int1);
  end_system_call();
  if(0 <=int2){
    DWORD e;
    begin_system_call();
    e = GetLastError();
    end_system_call();
    value1 = NIL;
    value2 = uint32_to_I(e);
    mv_count=2;
  }
  else
  {
    value1 = T;
    value2 = sint32_to_I(int2);
    mv_count=2;
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:OffsetRgn, hrgn int0 int1)
{
  object arg;
  int int2;
  HRGN hrgn;
  int int0;
  int int1;
  arg = popSTACK();
  check_sint(arg);
  int1 = I_to_sint32(arg);
  arg = popSTACK();
  check_sint(arg);
  int0 = I_to_sint32(arg);
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hrgn = TheFpointer(arg)->fp_pointer;
  begin_system_call();
  int2 = OffsetRgn(hrgn,int0,int1);
  end_system_call();
  if(0 <=int2){
    DWORD e;
    begin_system_call();
    e = GetLastError();
    end_system_call();
    value1 = NIL;
    value2 = uint32_to_I(e);
    mv_count=2;
  }
  else
  {
    value1 = T;
    value2 = sint32_to_I(int2);
    mv_count=2;
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:PaintRgn, hdc hrgn)
{
  object arg;
  BOOL bool0;
  HDC hdc;
  HRGN hrgn;
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hrgn = TheFpointer(arg)->fp_pointer;
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hdc = TheFpointer(arg)->fp_pointer;
  begin_system_call();
  bool0 = PaintRgn(hdc,hrgn);
  end_system_call();
  if(!bool0){
    DWORD e;
    begin_system_call();
    e = GetLastError();
    end_system_call();
    value1 = NIL;
    value2 = uint32_to_I(e);
    mv_count=2;
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
DEFUN( GDI:PathToRegion, hdc)
{
  object arg;
  HRGN hrgn;
  HDC hdc;
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hdc = TheFpointer(arg)->fp_pointer;
  begin_system_call();
  hrgn = PathToRegion(hdc);
  end_system_call();
  if(NULL ==hrgn){
    DWORD e;
    begin_system_call();
    e = GetLastError();
    end_system_call();
    value1 = NIL;
    value2 = uint32_to_I(e);
    mv_count=2;
  }
  else
  {
    value1 = T;
    value2 = allocate_fpointer((FOREIGN)hrgn);
    mv_count=2;
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:PlayMetaFile, hdc hmetafile)
{
  object arg;
  BOOL bool0;
  HDC hdc;
  HMETAFILE hmetafile;
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hmetafile = TheFpointer(arg)->fp_pointer;
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hdc = TheFpointer(arg)->fp_pointer;
  begin_system_call();
  bool0 = PlayMetaFile(hdc,hmetafile);
  end_system_call();
  if(!bool0){
    DWORD e;
    begin_system_call();
    e = GetLastError();
    end_system_call();
    value1 = NIL;
    value2 = uint32_to_I(e);
    mv_count=2;
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
DEFUN( GDI:PtInRegion, hrgn int0 int1)
{
  object arg;
  BOOL bool0;
  HRGN hrgn;
  int int0;
  int int1;
  arg = popSTACK();
  check_sint(arg);
  int1 = I_to_sint32(arg);
  arg = popSTACK();
  check_sint(arg);
  int0 = I_to_sint32(arg);
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hrgn = TheFpointer(arg)->fp_pointer;
  begin_system_call();
  bool0 = PtInRegion(hrgn,int0,int1);
  end_system_call();
  if(!bool0){
    DWORD e;
    begin_system_call();
    e = GetLastError();
    end_system_call();
    value1 = NIL;
    value2 = uint32_to_I(e);
    mv_count=2;
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
DEFUN( GDI:PtVisible, hdc int0 int1)
{
  object arg;
  BOOL bool0;
  HDC hdc;
  int int0;
  int int1;
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
  bool0 = PtVisible(hdc,int0,int1);
  end_system_call();
  if(!bool0){
    DWORD e;
    begin_system_call();
    e = GetLastError();
    end_system_call();
    value1 = NIL;
    value2 = uint32_to_I(e);
    mv_count=2;
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
DEFUN( GDI:RealizePalette, hdc)
{
  object arg;
  UINT uint;
  HDC hdc;
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hdc = TheFpointer(arg)->fp_pointer;
  begin_system_call();
  uint = RealizePalette(hdc);
  end_system_call();
  if(!uint){
    DWORD e;
    begin_system_call();
    e = GetLastError();
    end_system_call();
    value1 = NIL;
    value2 = uint32_to_I(e);
    mv_count=2;
  }
  else
  {
    value1 = T;
    value2 = uint32_to_I(uint);
    mv_count=2;
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:Rectangle, hdc int0 int1 int2 int3)
{
  object arg;
  BOOL bool0;
  HDC hdc;
  int int0;
  int int1;
  int int2;
  int int3;
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
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hdc = TheFpointer(arg)->fp_pointer;
  begin_system_call();
  bool0 = Rectangle(hdc,int0,int1,int2,int3);
  end_system_call();
  if(!bool0){
    DWORD e;
    begin_system_call();
    e = GetLastError();
    end_system_call();
    value1 = NIL;
    value2 = uint32_to_I(e);
    mv_count=2;
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
DEFUN( GDI:ResizePalette, hpalette uint)
{
  object arg;
  BOOL bool0;
  HPALETTE hpalette;
  UINT uint;
  uint = I_to_uint32(check_uint(popSTACK()));
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hpalette = TheFpointer(arg)->fp_pointer;
  begin_system_call();
  bool0 = ResizePalette(hpalette,uint);
  end_system_call();
  if(!bool0){
    DWORD e;
    begin_system_call();
    e = GetLastError();
    end_system_call();
    value1 = NIL;
    value2 = uint32_to_I(e);
    mv_count=2;
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
DEFUN( GDI:RestoreDC, hdc int0)
{
  object arg;
  BOOL bool0;
  HDC hdc;
  int int0;
  arg = popSTACK();
  check_sint(arg);
  int0 = I_to_sint32(arg);
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hdc = TheFpointer(arg)->fp_pointer;
  begin_system_call();
  bool0 = RestoreDC(hdc,int0);
  end_system_call();
  if(!bool0){
    DWORD e;
    begin_system_call();
    e = GetLastError();
    end_system_call();
    value1 = NIL;
    value2 = uint32_to_I(e);
    mv_count=2;
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
DEFUN( GDI:SaveDC, hdc)
{
  object arg;
  int int0;
  HDC hdc;
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hdc = TheFpointer(arg)->fp_pointer;
  begin_system_call();
  int0 = SaveDC(hdc);
  end_system_call();
  if(0 <=int0){
    DWORD e;
    begin_system_call();
    e = GetLastError();
    end_system_call();
    value1 = NIL;
    value2 = uint32_to_I(e);
    mv_count=2;
  }
  else
  {
    value1 = T;
    value2 = sint32_to_I(int0);
    mv_count=2;
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:SelectClipPath, hdc int0)
{
  object arg;
  BOOL bool0;
  HDC hdc;
  int int0;
  arg = popSTACK();
  check_sint(arg);
  int0 = I_to_sint32(arg);
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hdc = TheFpointer(arg)->fp_pointer;
  begin_system_call();
  bool0 = SelectClipPath(hdc,int0);
  end_system_call();
  if(!bool0){
    DWORD e;
    begin_system_call();
    e = GetLastError();
    end_system_call();
    value1 = NIL;
    value2 = uint32_to_I(e);
    mv_count=2;
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
DEFUN( GDI:SelectClipRgn, hdc hrgn)
{
  object arg;
  int int0;
  HDC hdc;
  HRGN hrgn;
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hrgn = TheFpointer(arg)->fp_pointer;
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hdc = TheFpointer(arg)->fp_pointer;
  begin_system_call();
  int0 = SelectClipRgn(hdc,hrgn);
  end_system_call();
  if(0 <=int0){
    DWORD e;
    begin_system_call();
    e = GetLastError();
    end_system_call();
    value1 = NIL;
    value2 = uint32_to_I(e);
    mv_count=2;
  }
  else
  {
    value1 = T;
    value2 = sint32_to_I(int0);
    mv_count=2;
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:SelectObject, hdc hgdiobj)
{
  object arg;
  HGDIOBJ hgdiobj0;
  HDC hdc;
  HGDIOBJ hgdiobj;
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hgdiobj = TheFpointer(arg)->fp_pointer;
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hdc = TheFpointer(arg)->fp_pointer;
  begin_system_call();
  hgdiobj0 = SelectObject(hdc,hgdiobj);
  end_system_call();
  if(NULL ==hgdiobj0){
    DWORD e;
    begin_system_call();
    e = GetLastError();
    end_system_call();
    value1 = NIL;
    value2 = uint32_to_I(e);
    mv_count=2;
  }
  else
  {
    value1 = T;
    value2 = allocate_fpointer((FOREIGN)hgdiobj0);
    mv_count=2;
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:SetArcDirection, hdc int0)
{
  object arg;
  int int1;
  HDC hdc;
  int int0;
  arg = popSTACK();
  check_sint(arg);
  int0 = I_to_sint32(arg);
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hdc = TheFpointer(arg)->fp_pointer;
  begin_system_call();
  int1 = SetArcDirection(hdc,int0);
  end_system_call();
  if(0 <=int1){
    DWORD e;
    begin_system_call();
    e = GetLastError();
    end_system_call();
    value1 = NIL;
    value2 = uint32_to_I(e);
    mv_count=2;
  }
  else
  {
    value1 = T;
    value2 = sint32_to_I(int1);
    mv_count=2;
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:SetBkColor, hdc colorref)
{
  object arg;
  COLORREF colorref0;
  HDC hdc;
  COLORREF colorref;
  colorref = I_to_uint32(check_uint(popSTACK()));
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hdc = TheFpointer(arg)->fp_pointer;
  begin_system_call();
  colorref0 = SetBkColor(hdc,colorref);
  end_system_call();
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:SetBkMode, hdc int0)
{
  object arg;
  int int1;
  HDC hdc;
  int int0;
  arg = popSTACK();
  check_sint(arg);
  int0 = I_to_sint32(arg);
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hdc = TheFpointer(arg)->fp_pointer;
  begin_system_call();
  int1 = SetBkMode(hdc,int0);
  end_system_call();
  if(0 <=int1){
    DWORD e;
    begin_system_call();
    e = GetLastError();
    end_system_call();
    value1 = NIL;
    value2 = uint32_to_I(e);
    mv_count=2;
  }
  else
  {
    value1 = T;
    value2 = sint32_to_I(int1);
    mv_count=2;
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:SetColorSpace, hdc hcolorspace)
{
  object arg;
  BOOL bool0;
  HDC hdc;
  HCOLORSPACE hcolorspace;
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hcolorspace = TheFpointer(arg)->fp_pointer;
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hdc = TheFpointer(arg)->fp_pointer;
  begin_system_call();
  bool0 = SetColorSpace(hdc,hcolorspace);
  end_system_call();
  if(!bool0){
    DWORD e;
    begin_system_call();
    e = GetLastError();
    end_system_call();
    value1 = NIL;
    value2 = uint32_to_I(e);
    mv_count=2;
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
DEFUN( GDI:SetGraphicsMode, hdc int0)
{
  object arg;
  int int1;
  HDC hdc;
  int int0;
  arg = popSTACK();
  check_sint(arg);
  int0 = I_to_sint32(arg);
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hdc = TheFpointer(arg)->fp_pointer;
  begin_system_call();
  int1 = SetGraphicsMode(hdc,int0);
  end_system_call();
  if(0 <=int1){
    DWORD e;
    begin_system_call();
    e = GetLastError();
    end_system_call();
    value1 = NIL;
    value2 = uint32_to_I(e);
    mv_count=2;
  }
  else
  {
    value1 = T;
    value2 = sint32_to_I(int1);
    mv_count=2;
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:SetICMMode, hdc int0)
{
  object arg;
  int int1;
  HDC hdc;
  int int0;
  arg = popSTACK();
  check_sint(arg);
  int0 = I_to_sint32(arg);
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hdc = TheFpointer(arg)->fp_pointer;
  begin_system_call();
  int1 = SetICMMode(hdc,int0);
  end_system_call();
  if(0 <=int1){
    DWORD e;
    begin_system_call();
    e = GetLastError();
    end_system_call();
    value1 = NIL;
    value2 = uint32_to_I(e);
    mv_count=2;
  }
  else
  {
    value1 = T;
    value2 = sint32_to_I(int1);
    mv_count=2;
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:SetMapMode, hdc int0)
{
  object arg;
  int int1;
  HDC hdc;
  int int0;
  arg = popSTACK();
  check_sint(arg);
  int0 = I_to_sint32(arg);
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hdc = TheFpointer(arg)->fp_pointer;
  begin_system_call();
  int1 = SetMapMode(hdc,int0);
  end_system_call();
  if(0 <=int1){
    DWORD e;
    begin_system_call();
    e = GetLastError();
    end_system_call();
    value1 = NIL;
    value2 = uint32_to_I(e);
    mv_count=2;
  }
  else
  {
    value1 = T;
    value2 = sint32_to_I(int1);
    mv_count=2;
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:SetMapperFlags, hdc dword)
{
  object arg;
  DWORD dword0;
  HDC hdc;
  DWORD dword;
  dword = I_to_uint32(check_uint(popSTACK()));
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hdc = TheFpointer(arg)->fp_pointer;
  begin_system_call();
  dword0 = SetMapperFlags(hdc,dword);
  end_system_call();
  if(!dword0){
    DWORD e;
    begin_system_call();
    e = GetLastError();
    end_system_call();
    value1 = NIL;
    value2 = uint32_to_I(e);
    mv_count=2;
  }
  else
  {
    value1 = T;
    value2 = uint32_to_I(dword0);
    mv_count=2;
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:SetMetaRgn, hdc)
{
  object arg;
  int int0;
  HDC hdc;
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hdc = TheFpointer(arg)->fp_pointer;
  begin_system_call();
  int0 = SetMetaRgn(hdc);
  end_system_call();
  if(0 <=int0){
    DWORD e;
    begin_system_call();
    e = GetLastError();
    end_system_call();
    value1 = NIL;
    value2 = uint32_to_I(e);
    mv_count=2;
  }
  else
  {
    value1 = T;
    value2 = sint32_to_I(int0);
    mv_count=2;
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:SetPolyFillMode, hdc int0)
{
  object arg;
  int int1;
  HDC hdc;
  int int0;
  arg = popSTACK();
  check_sint(arg);
  int0 = I_to_sint32(arg);
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hdc = TheFpointer(arg)->fp_pointer;
  begin_system_call();
  int1 = SetPolyFillMode(hdc,int0);
  end_system_call();
  if(0 <=int1){
    DWORD e;
    begin_system_call();
    e = GetLastError();
    end_system_call();
    value1 = NIL;
    value2 = uint32_to_I(e);
    mv_count=2;
  }
  else
  {
    value1 = T;
    value2 = sint32_to_I(int1);
    mv_count=2;
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:SetROP2, hdc int0)
{
  object arg;
  int int1;
  HDC hdc;
  int int0;
  arg = popSTACK();
  check_sint(arg);
  int0 = I_to_sint32(arg);
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hdc = TheFpointer(arg)->fp_pointer;
  begin_system_call();
  int1 = SetROP2(hdc,int0);
  end_system_call();
  if(0 <=int1){
    DWORD e;
    begin_system_call();
    e = GetLastError();
    end_system_call();
    value1 = NIL;
    value2 = uint32_to_I(e);
    mv_count=2;
  }
  else
  {
    value1 = T;
    value2 = sint32_to_I(int1);
    mv_count=2;
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:SetRectRgn, hrgn int0 int1 int2 int3)
{
  object arg;
  BOOL bool0;
  HRGN hrgn;
  int int0;
  int int1;
  int int2;
  int int3;
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
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hrgn = TheFpointer(arg)->fp_pointer;
  begin_system_call();
  bool0 = SetRectRgn(hrgn,int0,int1,int2,int3);
  end_system_call();
  if(!bool0){
    DWORD e;
    begin_system_call();
    e = GetLastError();
    end_system_call();
    value1 = NIL;
    value2 = uint32_to_I(e);
    mv_count=2;
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
DEFUN( GDI:SetStretchBltMode, hdc int0)
{
  object arg;
  int int1;
  HDC hdc;
  int int0;
  arg = popSTACK();
  check_sint(arg);
  int0 = I_to_sint32(arg);
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hdc = TheFpointer(arg)->fp_pointer;
  begin_system_call();
  int1 = SetStretchBltMode(hdc,int0);
  end_system_call();
  if(0 <=int1){
    DWORD e;
    begin_system_call();
    e = GetLastError();
    end_system_call();
    value1 = NIL;
    value2 = uint32_to_I(e);
    mv_count=2;
  }
  else
  {
    value1 = T;
    value2 = sint32_to_I(int1);
    mv_count=2;
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:SetSystemPaletteUse, hdc uint)
{
  object arg;
  UINT uint0;
  HDC hdc;
  UINT uint;
  uint = I_to_uint32(check_uint(popSTACK()));
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hdc = TheFpointer(arg)->fp_pointer;
  begin_system_call();
  uint0 = SetSystemPaletteUse(hdc,uint);
  end_system_call();
  if(!uint0){
    DWORD e;
    begin_system_call();
    e = GetLastError();
    end_system_call();
    value1 = NIL;
    value2 = uint32_to_I(e);
    mv_count=2;
  }
  else
  {
    value1 = T;
    value2 = uint32_to_I(uint0);
    mv_count=2;
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:SetTextAlign, hdc uint)
{
  object arg;
  UINT uint0;
  HDC hdc;
  UINT uint;
  uint = I_to_uint32(check_uint(popSTACK()));
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hdc = TheFpointer(arg)->fp_pointer;
  begin_system_call();
  uint0 = SetTextAlign(hdc,uint);
  end_system_call();
  if(!uint0){
    DWORD e;
    begin_system_call();
    e = GetLastError();
    end_system_call();
    value1 = NIL;
    value2 = uint32_to_I(e);
    mv_count=2;
  }
  else
  {
    value1 = T;
    value2 = uint32_to_I(uint0);
    mv_count=2;
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:SetTextCharacterExtra, hdc int0)
{
  object arg;
  int int1;
  HDC hdc;
  int int0;
  arg = popSTACK();
  check_sint(arg);
  int0 = I_to_sint32(arg);
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hdc = TheFpointer(arg)->fp_pointer;
  begin_system_call();
  int1 = SetTextCharacterExtra(hdc,int0);
  end_system_call();
  if(0 <=int1){
    DWORD e;
    begin_system_call();
    e = GetLastError();
    end_system_call();
    value1 = NIL;
    value2 = uint32_to_I(e);
    mv_count=2;
  }
  else
  {
    value1 = T;
    value2 = sint32_to_I(int1);
    mv_count=2;
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:SetTextJustification, hdc int0 int1)
{
  object arg;
  BOOL bool0;
  HDC hdc;
  int int0;
  int int1;
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
  bool0 = SetTextJustification(hdc,int0,int1);
  end_system_call();
  if(!bool0){
    DWORD e;
    begin_system_call();
    e = GetLastError();
    end_system_call();
    value1 = NIL;
    value2 = uint32_to_I(e);
    mv_count=2;
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
DEFUN( GDI:ShowWindow, hwnd int0)
{
  object arg;
  BOOL bool0;
  HWND hwnd;
  int int0;
  arg = popSTACK();
  check_sint(arg);
  int0 = I_to_sint32(arg);
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hwnd = TheFpointer(arg)->fp_pointer;
  begin_system_call();
  bool0 = ShowWindow(hwnd,int0);
  end_system_call();
  if(!bool0){
    DWORD e;
    begin_system_call();
    e = GetLastError();
    end_system_call();
    value1 = NIL;
    value2 = uint32_to_I(e);
    mv_count=2;
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
DEFUN( GDI:ShowWindowAsync, hwnd int0)
{
  object arg;
  BOOL bool0;
  HWND hwnd;
  int int0;
  arg = popSTACK();
  check_sint(arg);
  int0 = I_to_sint32(arg);
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hwnd = TheFpointer(arg)->fp_pointer;
  begin_system_call();
  bool0 = ShowWindowAsync(hwnd,int0);
  end_system_call();
  if(!bool0){
    DWORD e;
    begin_system_call();
    e = GetLastError();
    end_system_call();
    value1 = NIL;
    value2 = uint32_to_I(e);
    mv_count=2;
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
DEFUN( GDI:StartPage, hdc)
{
  object arg;
  int int0;
  HDC hdc;
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hdc = TheFpointer(arg)->fp_pointer;
  begin_system_call();
  int0 = StartPage(hdc);
  end_system_call();
  if(0 <=int0){
    DWORD e;
    begin_system_call();
    e = GetLastError();
    end_system_call();
    value1 = NIL;
    value2 = uint32_to_I(e);
    mv_count=2;
  }
  else
  {
    value1 = T;
    value2 = sint32_to_I(int0);
    mv_count=2;
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:StrokeAndFillPath, hdc)
{
  object arg;
  BOOL bool0;
  HDC hdc;
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hdc = TheFpointer(arg)->fp_pointer;
  begin_system_call();
  bool0 = StrokeAndFillPath(hdc);
  end_system_call();
  if(!bool0){
    DWORD e;
    begin_system_call();
    e = GetLastError();
    end_system_call();
    value1 = NIL;
    value2 = uint32_to_I(e);
    mv_count=2;
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
DEFUN( GDI:StrokePath, hdc)
{
  object arg;
  BOOL bool0;
  HDC hdc;
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hdc = TheFpointer(arg)->fp_pointer;
  begin_system_call();
  bool0 = StrokePath(hdc);
  end_system_call();
  if(!bool0){
    DWORD e;
    begin_system_call();
    e = GetLastError();
    end_system_call();
    value1 = NIL;
    value2 = uint32_to_I(e);
    mv_count=2;
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
DEFUN( GDI:SwapBuffers, hdc)
{
  object arg;
  BOOL bool0;
  HDC hdc;
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hdc = TheFpointer(arg)->fp_pointer;
  begin_system_call();
  bool0 = SwapBuffers(hdc);
  end_system_call();
  if(!bool0){
    DWORD e;
    begin_system_call();
    e = GetLastError();
    end_system_call();
    value1 = NIL;
    value2 = uint32_to_I(e);
    mv_count=2;
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
DEFUN( GDI:UnrealizeObject, hgdiobj)
{
  object arg;
  BOOL bool0;
  HGDIOBJ hgdiobj;
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hgdiobj = TheFpointer(arg)->fp_pointer;
  begin_system_call();
  bool0 = UnrealizeObject(hgdiobj);
  end_system_call();
  if(!bool0){
    DWORD e;
    begin_system_call();
    e = GetLastError();
    end_system_call();
    value1 = NIL;
    value2 = uint32_to_I(e);
    mv_count=2;
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
DEFUN( GDI:UpdateColors, hdc)
{
  object arg;
  BOOL bool0;
  HDC hdc;
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hdc = TheFpointer(arg)->fp_pointer;
  begin_system_call();
  bool0 = UpdateColors(hdc);
  end_system_call();
  if(!bool0){
    DWORD e;
    begin_system_call();
    e = GetLastError();
    end_system_call();
    value1 = NIL;
    value2 = uint32_to_I(e);
    mv_count=2;
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
DEFUN( GDI:UpdateWindow, hwnd)
{
  object arg;
  BOOL bool0;
  HWND hwnd;
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hwnd = TheFpointer(arg)->fp_pointer;
  begin_system_call();
  bool0 = UpdateWindow(hwnd);
  end_system_call();
  if(!bool0){
    DWORD e;
    begin_system_call();
    e = GetLastError();
    end_system_call();
    value1 = NIL;
    value2 = uint32_to_I(e);
    mv_count=2;
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
DEFUN( GDI:WidenPath, hdc)
{
  object arg;
  BOOL bool0;
  HDC hdc;
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hdc = TheFpointer(arg)->fp_pointer;
  begin_system_call();
  bool0 = WidenPath(hdc);
  end_system_call();
  if(!bool0){
    DWORD e;
    begin_system_call();
    e = GetLastError();
    end_system_call();
    value1 = NIL;
    value2 = uint32_to_I(e);
    mv_count=2;
  }
  else
  {
    value1 = T;
    mv_count=1;
  }
  return;
}
