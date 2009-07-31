#line 2 "funcs-ok.c"

/* functions that probably translated ok */

// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:AbortDoc, hdc)
{
  object arg;
  int int0;
  HDC hdc;
  getHDC(hdc,arg);
  begin_system_call();
  int0 = AbortDoc(hdc);
  end_system_call();
  if(0 <=int0){
    do_GDI_ERROR("AbortDoc");
  }
  else
  {
    VALUES1(sint32_to_I(int0));
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
  getHDC(hdc,arg);
  begin_system_call();
  bool0 = AbortPath(hdc);
  end_system_call();
  if(!bool0){
    do_GDI_ERROR("AbortPath");
  }
  else
  {
    VALUES1(T);
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
      do_GDI_ERROR("AddAtomA");
    }
    else
    {
      //value1 = allocate_fpointer((FOREIGN)atom);
      VALUES1(uint32_to_I(atom));
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
    do_GDI_ERROR("AddAtomW");
  }
  else
  {
    VALUES1(uint32_to_I(atom)); //value2 = allocate_fpointer((FOREIGN)&atom));
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
  getHDC(hdc,arg);
  begin_system_call();
  bool0 = BeginPath(hdc);
  end_system_call();
  if(!bool0){
    do_GDI_ERROR("BeginPath");
  }
  else
  {
    VALUES1(T);
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
  getHDC(hdc,arg);
  begin_system_call();
  bool0 = CancelDC(hdc);
  end_system_call();
  if(!bool0){
    do_GDI_ERROR("CancelDC");
  }
  else
  {
    VALUES1(T);
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
  getHDC(hdc,arg);
  begin_system_call();
  henhmetafile = CloseEnhMetaFile(hdc);
  end_system_call();
  if(NULL ==henhmetafile){
    do_GDI_ERROR("CloseEnhMetaFile");
  }
  else
  {
    VALUES1(allocate_fpointer((FOREIGN)henhmetafile));
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
  getHDC(hdc,arg);
  begin_system_call();
  bool0 = CloseFigure(hdc);
  end_system_call();
  if(!bool0){
    do_GDI_ERROR("CloseFigure");
  }
  else
  {
    VALUES1(T);
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
  getHDC(hdc,arg);
  begin_system_call();
  hmetafile = CloseMetaFile(hdc);
  end_system_call();
  if(NULL ==hmetafile){
    do_GDI_ERROR("CloseMetaFile");
  }
  else
  {
    VALUES1(allocate_fpointer((FOREIGN)hmetafile));
  }
  return;
}
// untested - was never called
// was disabled on older cygwin
DEFUN( GDI:ColorMatchToTarget, hdc hdcTarget uiAction)
/* uiAction - one of the CS_ values: CS_ENABLE, CS_DISABLE, CS_DELETE_TRANSFORM
 */
{
  object arg;
  BOOL bool0;
  HDC hdc;
  HDC hdcTarget;
  DWORD uiAction;
  uiAction = I_to_uint32(check_uint(popSTACK()));
  getHDC(hdcTarget,arg);
  getHDC(hdc,arg);
  begin_system_call();
  bool0 = ColorMatchToTarget(hdc,hdcTarget,uiAction);
  end_system_call();
  if(!bool0){
    do_GDI_ERROR("ColorMatchToTarget");
  }
  else
  {
    VALUES1(T);
  }
  return;
}
// untested - was never called
DEFUN( GDI:CombineRgn, hrgnDest hrgnSrc1 hrgnSrc2 fnCombineMode)
/* hrgnDest must exist before CombineRgn is called.
   fnCombineMode - one of the RGN_ values */
{
  object arg;
  int int1;
  HRGN hrgnDest,hrgnSrc1,hrgnSrc2;
  int fnCombineMode;
  fnCombineMode = I_to_sint32(check_sint(popSTACK()));
  arg = popSTACK();
  processFPTYPE(HRGN,hrgnSrc2,arg);
  arg = popSTACK();
  processFPTYPE(HRGN,hrgnSrc1,arg);
  arg = popSTACK();
  processFPTYPE(HRGN,hrgnDest,arg);

  begin_system_call();
  int1 = CombineRgn(hrgnDest,hrgnSrc1,hrgnSrc2,fnCombineMode);
  end_system_call();
  if(0 <=int1){
    do_GDI_ERROR("CombineRgn");
  }
  else
  {
    VALUES1(sint32_to_I(int1));
  }
  return;
}
// untested - was never called
DEFUN( GDI:CreateCompatibleBitmap, hdc nWidth nHeight)
{
  object arg;
  HBITMAP hbitmap;
  HDC hdc;
  int nWidth,nHeight;
  nHeight = I_to_sint32(check_sint(popSTACK()));
  nWidth = I_to_sint32(check_sint(popSTACK()));
  getHDC(hdc,arg);

  begin_system_call();
  hbitmap = CreateCompatibleBitmap(hdc,nWidth,nHeight);
  end_system_call();
  if(NULL ==hbitmap){
    do_GDI_ERROR("CreateCompatibleBitmap");
  }
  else
  {
    value1 = allocate_fpointer((FOREIGN)hbitmap);
    /* TODO: Attach a DeleteObject finalizer to it */
    mv_count=1;
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
  getHDC(hdc,arg);
  begin_system_call();
  hdc0 = CreateCompatibleDC(hdc);
  end_system_call();
  if(NULL ==hdc0){
    do_GDI_ERROR("CreateCompatibleDC");
  }
  else
  {
    VALUES1(allocate_fpointer((FOREIGN)hdc0));
  }
  return;
}
// untested - was never called
DEFUN( GDI:CreateDIBPatternBrush, hglobal fuColorSpec)
/* fuColorSpec - one of the DIB_ values */
{
  object arg;
  HBRUSH hbrush;
  HGLOBAL hglobal;
  UINT fuColorSpec;
  fuColorSpec = I_to_uint32(check_uint(popSTACK()));
  arg = popSTACK();
  processFPTYPE(HGLOBAL,hglobal,arg);
  begin_system_call();
  hbrush = CreateDIBPatternBrush(hglobal,fuColorSpec);
  end_system_call();
  if(NULL ==hbrush){
    do_GDI_ERROR("CreateDIBPatternBrush");
  }
  else
  {
    VALUES1(allocate_fpointer((FOREIGN)hbrush));
  }
  return;
}
// untested - was never called
DEFUN( GDI:CreateDiscardableBitmap, hdc nWidth nHeight)
/* For Win32-based applications, use the CreateCompatibleBitmap function instead. */
{
  object arg;
  HBITMAP hbitmap;
  HDC hdc;
  int nWidth, nHeight;
  nHeight = I_to_sint32(check_sint(popSTACK()));
  nWidth  = I_to_sint32(check_sint(popSTACK()));
  getHDC(hdc,arg);
  begin_system_call();
  hbitmap = CreateDiscardableBitmap(hdc,nWidth,nHeight);
  end_system_call();
  if(NULL ==hbitmap){
    do_GDI_ERROR("CreateDiscardableBitmap");
  }
  else
  {
    VALUES1(allocate_fpointer((FOREIGN)hbitmap));
  }
  return;
}
// untested - was never called
DEFUN( GDI:CreateEllipticRgn, nLeftRect nTopRect nRightRect nBottomRect)
{
  object arg;
  HRGN hrgn;
  int nLeftRect,nTopRect,nRightRect,nBottomRect;
  nBottomRect = I_to_sint32(check_sint(popSTACK()));
  nRightRect  = I_to_sint32(check_sint(popSTACK()));
  nTopRect    = I_to_sint32(check_sint(popSTACK()));
  nLeftRect   = I_to_sint32(check_sint(popSTACK()));
  begin_system_call();
  hrgn = CreateEllipticRgn(nLeftRect,nTopRect,nRightRect,nBottomRect);
  end_system_call();
  if(NULL ==hrgn){
    do_GDI_ERROR("CreateEllipticRgn");
  }
  else
  {
    VALUES1(allocate_fpointer((FOREIGN)hrgn));
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
  getHDC(hdc,arg);
  begin_system_call();
  hpalette = CreateHalftonePalette(hdc);
  end_system_call();
  if(NULL ==hpalette){
    do_GDI_ERROR("CreateHalftonePalette");
  }
  else
  {
    VALUES1(allocate_fpointer((FOREIGN)hpalette));
  }
  return;
}
// untested - was never called
DEFUN( GDI:CreateHatchBrush, fnStyle colorref)
/* fnStyle is one of HS_BDIAGONAL, HS_CROSS, HS_DIAGCROSS, HS_FDIAGONAL, HS_HORIZONTAL
 *   HS_VERTICAL.
 * Returns a handle to the logical brush.
 */
{
  object arg;
  HBRUSH hbrush;
  int fnStyle;
  COLORREF colorref;
  colorref = processCOLORREF(popSTACK());
  fnStyle = I_to_sint32(check_sint(popSTACK()));
  begin_system_call();
  hbrush = CreateHatchBrush(fnStyle,colorref);
  end_system_call();
  if(NULL ==hbrush){
    do_GDI_ERROR("CreateHatchBrush");
  }
  else
  {
    VALUES1(allocate_fpointer((FOREIGN)hbrush));
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
    do_GDI_ERROR("CreatePatternBrush");
  }
  else
  {
    VALUES1(allocate_fpointer((FOREIGN)hbrush));
  }
  return;
}
// untested - was never called
DEFUN( GDI:CreatePen, fnPenStyle nWidth colorref)
{
  object arg;
  HPEN hpen;
  int fnPenStyle, nWidth;
  COLORREF colorref;
  colorref = processCOLORREF(popSTACK());
  nWidth = I_to_sint32(check_sint(popSTACK()));
  fnPenStyle = I_to_sint32(check_sint(popSTACK()));
  begin_system_call();
  hpen = CreatePen(fnPenStyle, nWidth, colorref);
  end_system_call();
  if(NULL ==hpen){
    do_GDI_ERROR("CreatePen");
  }
  else
  {
    VALUES1(allocate_fpointer((FOREIGN)hpen));
  }
  return;
}
// untested - was never called
DEFUN( GDI:CreateRectRgn, nLeftRect nTopRect nRightRect nBottomRect)
{
  object arg;
  HRGN hrgn;
  int nLeftRect,nTopRect,nRightRect,nBottomRect;
  nBottomRect = I_to_sint32(check_sint(popSTACK()));
  nRightRect  = I_to_sint32(check_sint(popSTACK()));
  nTopRect    = I_to_sint32(check_sint(popSTACK()));
  nLeftRect   = I_to_sint32(check_sint(popSTACK()));
  begin_system_call();
  hrgn = CreateRectRgn(nLeftRect,nTopRect,nRightRect,nBottomRect);
  end_system_call();
  if(NULL ==hrgn){
    do_GDI_ERROR("CreateRectRgn");
  }
  else
  {
    VALUES1(allocate_fpointer((FOREIGN)hrgn));
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
  colorref = processCOLORREF(popSTACK());
  begin_system_call();
  hbrush = CreateSolidBrush(colorref);
  end_system_call();
  if(NULL ==hbrush){
    do_GDI_ERROR("CreateSolidBrush");
  }
  else
  {
    VALUES1(allocate_fpointer((FOREIGN)hbrush));
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
  processFPTYPE(HCOLORSPACE,hcolorspace,arg)
  begin_system_call();
  bool0 = DeleteColorSpace(hcolorspace);
  end_system_call();
  if(!bool0){
    do_GDI_ERROR("DeleteColorSpace");
  }
  else
  {
    VALUES1(T);
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
  getHDC(hdc,arg);
  begin_system_call();
  bool0 = DeleteDC(hdc);
  end_system_call();
  if(!bool0){
    do_GDI_ERROR("DeleteDC");
  }
  else
  {
    VALUES1(T);
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
  processFPTYPE(HENHMETAFILE,henhmetafile,arg)
  begin_system_call();
  bool0 = DeleteEnhMetaFile(henhmetafile);
  end_system_call();
  if(!bool0){
    do_GDI_ERROR("DeleteEnhMetaFile");
  }
  else
  {
    VALUES1(T);
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
  processFPTYPE(HMETAFILE,hmetafile,arg)
  begin_system_call();
  bool0 = DeleteMetaFile(hmetafile);
  end_system_call();
  if(!bool0){
    do_GDI_ERROR("DeleteMetaFile");
  }
  else
  {
    VALUES1(T);
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
  processFPTYPE(HGDIOBJ,hgdiobj,arg)
  begin_system_call();
  bool0 = DeleteObject(hgdiobj);
  end_system_call();
  if(!bool0){
    do_GDI_ERROR("DeleteObject");
  }
  else
  {
    VALUES1(T);
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:Ellipse, hdc nLeftRect nTopRect nRightRect nBottomRect)
{
  object arg;
  BOOL bool0;
  HDC hdc;
  int nLeftRect,nTopRect,nRightRect,nBottomRect;
  nBottomRect = I_to_sint32(check_sint(popSTACK()));
  nRightRect  = I_to_sint32(check_sint(popSTACK()));
  nTopRect    = I_to_sint32(check_sint(popSTACK()));
  nLeftRect   = I_to_sint32(check_sint(popSTACK()));
  getHDC(hdc,arg);
  begin_system_call();
  bool0 = Ellipse(hdc,nLeftRect,nTopRect,nRightRect,nBottomRect);
  end_system_call();
  if(!bool0){
    do_GDI_ERROR("Ellipse");
  }
  else
  {
    VALUES1(T);
  }
  return;
}
// untested - was never called
DEFUN( GDI:EndDoc, hdc)
{
  object arg;
  int int0;
  HDC hdc;
  getHDC(hdc,arg);
  begin_system_call();
  int0 = EndDoc(hdc);
  end_system_call();
  if(0 <=int0){
    do_GDI_ERROR("EndDoc");
  }
  else
  {
    VALUES1(sint32_to_I(int0));
  }
  return;
}
// untested - was never called
DEFUN( GDI:EndPage, hdc)
{
  object arg;
  int int0;
  HDC hdc;
  getHDC(hdc,arg);
  begin_system_call();
  int0 = EndPage(hdc);
  end_system_call();
  if(0 <=int0){
    do_GDI_ERROR("EndPage");
  }
  else
  {
    VALUES1(sint32_to_I(int0));
  }
  return;
}
// untested - was never called
DEFUN( GDI:EndPath, hdc)
{
  object arg;
  BOOL bool0;
  HDC hdc;
  getHDC(hdc,arg);
  begin_system_call();
  bool0 = EndPath(hdc);
  end_system_call();
  if(!bool0){
    do_GDI_ERROR("EndPath");
  }
  else
  {
    VALUES1(T);
  }
  return;
}
// untested - was never called
DEFUN( GDI:EqualRgn, hrgn hrgn0)
{
  object arg;
  BOOL bool0;
  HRGN hrgn;
  HRGN hrgn0;
  processFPTYPE_fn(HRGN,hrgn0,popSTACK());
  processFPTYPE_fn(HRGN,hrgn,popSTACK());
  begin_system_call();
  bool0 = EqualRgn(hrgn,hrgn0);
  end_system_call();
  if(!bool0){
    do_GDI_ERROR("EqualRgn");
  }
  else
  {
    VALUES1(T);
  }
  return;
}
// untested - was never called
DEFUN( GDI:EscapeCommFunction, handle dword)
{
  object arg;
  BOOL bool0;
  HANDLE handle;
  DWORD dword;
  dword = I_to_uint32(check_uint(popSTACK()));
  arg = popSTACK();
  processFPTYPE(HANDLE,handle,arg)
  begin_system_call();
  bool0 = EscapeCommFunction(handle,dword);
  end_system_call();
  if(!bool0){
    do_GDI_ERROR("EscapeCommFunction");
  }
  else
  {
    VALUES1(T);
  }
  return;
}
// untested - was never called
DEFUN( GDI:ExcludeClipRect, hdc nLeftRect nTopRect nRightRect nBottomRect)
{
  object arg;
  int int4;
  HDC hdc;
  int nLeftRect,nTopRect,nRightRect,nBottomRect;
  nBottomRect = I_to_sint32(check_sint(popSTACK()));
  nRightRect  = I_to_sint32(check_sint(popSTACK()));
  nTopRect    = I_to_sint32(check_sint(popSTACK()));
  nLeftRect   = I_to_sint32(check_sint(popSTACK()));
  getHDC(hdc,arg);
  begin_system_call();
  int4 = ExcludeClipRect(hdc,nLeftRect,nTopRect,nRightRect,nBottomRect);
  end_system_call();
  if(0 <=int4){
    do_GDI_ERROR("ExcludeClipRect");
  }
  else
  {
    VALUES1(sint32_to_I(int4));
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:ExtFloodFill, hdc nXStart nYStart colorref fuFillType)
{
  object arg;
  BOOL bool0;
  HDC hdc;
  int nXStart,nYStart;
  COLORREF colorref;
  UINT fuFillType;
  fuFillType = I_to_uint32(check_uint(popSTACK()));
  colorref = processCOLORREF(popSTACK());
  nXStart = I_to_sint32(check_sint(popSTACK()));
  nYStart = I_to_sint32(check_sint(popSTACK()));
  getHDC(hdc,arg);
  begin_system_call();
  bool0 = ExtFloodFill(hdc,nXStart,nYStart,colorref,fuFillType);
  end_system_call();
  if(!bool0){
    do_GDI_ERROR("ExtFloodFill");
  }
  else
  {
    VALUES1(T);
  }
  return;
}
// untested - was never called
DEFUN( GDI:ExtSelectClipRgn, hdc hrgn fnMode)
/* Returns the symbols as described in the MSDN docs, not 0-3 */
{
  object arg;
  int int1;
  HDC hdc;
  HRGN hrgn;
  int fnMode;
  fnMode = I_to_sint32(check_sint(popSTACK()));
  arg = popSTACK();
  processFPTYPE(HRGN,hrgn,arg);
  getHDC(hdc,arg);
  begin_system_call();
  int1 = ExtSelectClipRgn(hdc,hrgn,fnMode);
  end_system_call();
  if(0 <=int1) {
      //do_GDI_ERROR("ExtSelectClipRgn");
      value1 = `GDI::ERROR`; /* value 0 */
      mv_count=1;
  }
  else
  {
    // return the constants, not the int
    // NULLREGION, SIMPLEREGION, COMPLEXREGION
    if (int1 == 1)
        value1 = `GDI::NULLREGION`;
    else if (int1 == 2)
        value1 = `GDI::SIMPLEREGION`;
    else if (int1 == 3)
        value1 = `GDI::COMPLEXREGION`;
    else
        VALUES1(sint32_to_I(int1));
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
  getHDC(hdc,arg);
  begin_system_call();
  bool0 = FillPath(hdc);
  end_system_call();
  if(!bool0){
    do_GDI_ERROR("FillPath");
  }
  else
  {
    VALUES1(T);
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
  processFPTYPE(HBRUSH,hbrush,arg);
  arg = popSTACK();
  processFPTYPE(HRGN,hrgn,arg);
  getHDC(hdc,arg);
  begin_system_call();
  int0 = FillRgn(hdc,hrgn,hbrush);
  end_system_call();
  if(0 <=int0){
    do_GDI_ERROR("FillRgn");
  }
  else
  {
    VALUES1(sint32_to_I(int0));
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
        do_GDI_ERROR("FindAtomA");
    }
    else
    {
      VALUES1(uint32_to_I(atom));
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
    do_GDI_ERROR("FindAtomW");
  }
  else
  {
    VALUES1(uint32_to_I(atom));
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
  getHDC(hdc,arg);
  begin_system_call();
  bool0 = FlattenPath(hdc);
  end_system_call();
  if(!bool0){
    do_GDI_ERROR("FlattenPath");
  }
  else
  {
    VALUES1(T);
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:FloodFill, hdc nXStart nYStart colorref)
{
  object arg;
  BOOL bool0;
  HDC hdc;
  int nXStart,nYStart;
  COLORREF colorref;
  colorref = processCOLORREF(popSTACK());
  nYStart = I_to_sint32(check_sint(popSTACK()));
  nXStart = I_to_sint32(check_sint(popSTACK()));
  getHDC(hdc,arg);
  begin_system_call();
  bool0 = FloodFill(hdc,nXStart,nYStart,colorref);
  end_system_call();
  if(!bool0){
    do_GDI_ERROR("FloodFill");
  }
  else
  {
    VALUES1(T);
  }
  return;
}
// untested - was never called
DEFUN( GDI:FrameRgn, hdc hrgn hbrush nWidth nHeight)
{
  object arg;
  BOOL bool0;
  HDC hdc;
  HRGN hrgn;
  HBRUSH hbrush;
  int nWidth,nHeight;
  nHeight = I_to_sint32(check_sint(popSTACK()));
  nWidth = I_to_sint32(check_sint(popSTACK()));
  arg = popSTACK();
  processFPTYPE(HBRUSH,hbrush,arg);
  arg = popSTACK();
  processFPTYPE(HRGN,hrgn,arg);
  getHDC(hdc,arg);
  begin_system_call();
  bool0 = FrameRgn(hdc,hrgn,hbrush,nWidth,nHeight);
  end_system_call();
  if(!bool0){
    do_GDI_ERROR("FrameRgn");
  }
  else
  {
    VALUES1(T);
  }
  return;
}
// untested - was never called
DEFUN( GDI:GdiSetBatchLimit, dwLimit)
{
  object arg;
  DWORD dword0;
  DWORD dwLimit;
  dwLimit = I_to_uint32(check_uint(popSTACK()));
  begin_system_call();
  dword0 = GdiSetBatchLimit(dwLimit);
  end_system_call();
  if(!dword0){
    do_GDI_ERROR("GdiSetBatchLimit");
  }
  else
  {
    VALUES1(uint32_to_I(dword0));
  }
  return;
}
// untested - was never called
DEFUN( GDI:GetArcDirection, hdc)
{
  object arg;
  int int0;
  HDC hdc;
  getHDC(hdc,arg);
  begin_system_call();
  int0 = GetArcDirection(hdc);
  end_system_call();
  if(0 <=int0){
    do_GDI_ERROR("GetArcDirection");
  }
  else
  {
    VALUES1(sint32_to_I(int0));
  }
  return;
}
// untested - was never called
// fixed
// TODO: return make-rgb, resp. outputCOLORREF
DEFUN( GDI:GetBkColor, hdc)
{
  object arg;
  COLORREF colorref;
  HDC hdc;
  getHDC(hdc,arg);
  begin_system_call();
  colorref = GetBkColor(hdc);
  end_system_call();
  if(0 <=(int)colorref){
    do_GDI_ERROR("GetBkColor");
  }
  else
  {
    VALUES1(sint32_to_I((int)colorref));
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:GetBkMode, hdc)
{
  object arg;
  int int0;
  HDC hdc;
  getHDC(hdc,arg);
  begin_system_call();
  int0 = GetBkMode(hdc);
  end_system_call();
  if(0 <=int0){
    do_GDI_ERROR("GetBkMode");
  }
  else
  {
    VALUES1(sint32_to_I(int0));
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
  processFPTYPE(HRGN,hrgn,arg);
  getHDC(hdc,arg);
  begin_system_call();
  int0 = GetClipRgn(hdc,hrgn);
  end_system_call();
  if(0 <=int0){
    do_GDI_ERROR("GetClipRgn");
  }
  else
  {
    VALUES1(sint32_to_I(int0));
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
  getHDC(hdc,arg);
  begin_system_call();
  handle = GetColorSpace(hdc);
  end_system_call();
  if(NULL ==handle){
    do_GDI_ERROR("GetColorSpace");
  }
  else
  {
    VALUES1(allocate_fpointer((FOREIGN)handle));
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
  getHDC(hdc,arg);
  begin_system_call();
  hgdiobj = GetCurrentObject(hdc,uint);
  end_system_call();
  if(NULL ==hgdiobj){
    do_GDI_ERROR("GetCurrentObject");
  }
  else
  {
    VALUES1(allocate_fpointer((FOREIGN)hgdiobj));
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
  getHDC(hdc,arg);
  begin_system_call();
  dword = GetFontLanguageInfo(hdc);
  end_system_call();
  if(!dword){
    do_GDI_ERROR("GetFontLanguageInfo");
  }
  else
  {
    VALUES1(uint32_to_I(dword));
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
  getHDC(hdc,arg);
  begin_system_call();
  int0 = GetGraphicsMode(hdc);
  end_system_call();
  if(0 <=int0){
    do_GDI_ERROR("GetGraphicsMode");
  }
  else
  {
    VALUES1(sint32_to_I(int0));
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
  getHDC(hdc,arg);
  begin_system_call();
  int0 = GetMapMode(hdc);
  end_system_call();
  if(0 <=int0){
    do_GDI_ERROR("GetMapMode");
  }
  else
  {
    VALUES1(sint32_to_I(int0));
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
  processFPTYPE(HRGN,hrgn,arg);
  getHDC(hdc,arg);
  begin_system_call();
  int0 = GetMetaRgn(hdc,hrgn);
  end_system_call();
  if(0 <=int0){
    do_GDI_ERROR("GetMetaRgn");
  }
  else
  {
    VALUES1(sint32_to_I(int0));
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
  getHDC(hdc,arg);
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
  processFPTYPE(HPALETTE,hpalette,arg);
  begin_system_call();
  uint = GetNearestPaletteIndex(hpalette,colorref);
  end_system_call();
  if(!uint){
    do_GDI_ERROR("GetNearestPaletteIndex");
  }
  else
  {
    VALUES1(uint32_to_I(uint));
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
    do_GDI_ERROR("GetObjectType");
  }
  else
  {
    VALUES1(uint32_to_I(dword));
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
  int1 = I_to_sint32(check_sint(popSTACK()));
  int0 = I_to_sint32(check_sint(popSTACK()));
  getHDC(hdc,arg);
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
  getHDC(hdc,arg);
  begin_system_call();
  int0 = GetPixelFormat(hdc);
  end_system_call();
  if(0 <=int0){
    do_GDI_ERROR("GetPixelFormat");
  }
  else
  {
    VALUES1(sint32_to_I(int0));
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
  getHDC(hdc,arg);
  begin_system_call();
  int0 = GetPolyFillMode(hdc);
  end_system_call();
  if(0 <=int0){
    do_GDI_ERROR("GetPolyFillMode");
  }
  else
  {
    VALUES1(sint32_to_I(int0));
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
  getHDC(hdc,arg);
  begin_system_call();
  int0 = GetROP2(hdc);
  end_system_call();
  if(0 <=int0){
    do_GDI_ERROR("GetROP2");
  }
  else
  {
    VALUES1(sint32_to_I(int0));
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
  int0 = I_to_sint32(check_sint(popSTACK()));
  begin_system_call();
  hgdiobj = GetStockObject(int0);
  end_system_call();
  if(NULL ==hgdiobj){
    do_GDI_ERROR("GetStockObject");
  }
  else
  {
    VALUES1(allocate_fpointer((FOREIGN)hgdiobj));
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
  getHDC(hdc,arg);
  begin_system_call();
  int0 = GetStretchBltMode(hdc);
  end_system_call();
  if(0 <=int0){
    do_GDI_ERROR("GetStretchBltMode");
  }
  else
  {
    VALUES1(sint32_to_I(int0));
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
  getHDC(hdc,arg);
  begin_system_call();
  uint = GetSystemPaletteUse(hdc);
  end_system_call();
  if(!uint){
    do_GDI_ERROR("GetSystemPaletteUse");
  }
  else
  {
    VALUES1(uint32_to_I(uint));
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
  getHDC(hdc,arg);
  begin_system_call();
  uint = GetTextAlign(hdc);
  end_system_call();
  if(!uint){
    do_GDI_ERROR("GetTextAlign");
  }
  else
  {
    VALUES1(uint32_to_I(uint));
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
  getHDC(hdc,arg);
  begin_system_call();
  int0 = GetTextCharacterExtra(hdc);
  end_system_call();
  if(0 <=int0){
    do_GDI_ERROR("GetTextCharacterExtra");
  }
  else
  {
    VALUES1(sint32_to_I(int0));
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
  getHDC(hdc,arg);
  begin_system_call();
  int0 = GetTextCharset(hdc);
  end_system_call();
  if(0 <=int0){
    do_GDI_ERROR("GetTextCharset");
  }
  else
  {
    VALUES1(sint32_to_I(int0));
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
  getHDC(hdc,arg);
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
    do_GDI_ERROR("GlobalAddAtomA");
    }
    else
    {
      // allocate_fpointer((FOREIGN)atom);
      VALUES1(uint32_to_I(atom));
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
    do_GDI_ERROR("GlobalAddAtomW");
  }
  else
  {
    //allocate_fpointer((FOREIGN)atom);
    VALUES1(uint32_to_I(atom));
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
    do_GDI_ERROR("GlobalFindAtomA");
    }
    else
    {
      //allocate_fpointer((FOREIGN)atom);
      VALUES1(uint32_to_I(atom));
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
    do_GDI_ERROR("GlobalFindAtomW");
  }
  else
  {
    //allocate_fpointer((FOREIGN)atom);
    VALUES1(uint32_to_I(atom));
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
  int3 = I_to_sint32(check_sint(popSTACK()));
  int2 = I_to_sint32(check_sint(popSTACK()));
  int1 = I_to_sint32(check_sint(popSTACK()));
  int0 = I_to_sint32(check_sint(popSTACK()));
  getHDC(hdc,arg);
  begin_system_call();
  int4 = IntersectClipRect(hdc,int0,int1,int2,int3);
  end_system_call();
  if(0 <=int4){
    do_GDI_ERROR("IntersectClipRect");
  }
  else
  {
    VALUES1(sint32_to_I(int4));
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
  getHDC(hdc,arg);
  begin_system_call();
  bool0 = InvertRgn(hdc,hrgn);
  end_system_call();
  if(!bool0){
    do_GDI_ERROR("InvertRgn");
  }
  else
  {
    VALUES1(T);
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
  int1 = I_to_sint32(check_sint(popSTACK()));
  int0 = I_to_sint32(check_sint(popSTACK()));
  getHDC(hdc,arg);
  begin_system_call();
  bool0 = LineTo(hdc,int0,int1);
  end_system_call();
  if(!bool0){
    do_GDI_ERROR("LineTo");
  }
  else
  {
    VALUES1(T);
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
    do_GDI_ERROR("LoadCursorFromFileA");
    }
    else
    {
    VALUES1(allocate_fpointer((FOREIGN)hcursor));
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
    do_GDI_ERROR("LoadCursorFromFileW");
  }
  else
  {
    VALUES1(allocate_fpointer((FOREIGN)hcursor));
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
  int1 = I_to_sint32(check_sint(popSTACK()));
  int0 = I_to_sint32(check_sint(popSTACK()));
  getHDC(hdc,arg);
  begin_system_call();
  int2 = OffsetClipRgn(hdc,int0,int1);
  end_system_call();
  if(0 <=int2){
    do_GDI_ERROR("OffsetClipRgn");
  }
  else
  {
    VALUES1(sint32_to_I(int2));
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
  int1 = I_to_sint32(check_sint(popSTACK()));
  int0 = I_to_sint32(check_sint(popSTACK()));
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hrgn = TheFpointer(arg)->fp_pointer;
  begin_system_call();
  int2 = OffsetRgn(hrgn,int0,int1);
  end_system_call();
  if(0 <=int2){
    do_GDI_ERROR("OffsetRgn");
  }
  else
  {
    VALUES1(sint32_to_I(int2));
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
  getHDC(hdc,arg);
  begin_system_call();
  bool0 = PaintRgn(hdc,hrgn);
  end_system_call();
  if(!bool0){
    do_GDI_ERROR("PaintRgn");
  }
  else
  {
    VALUES1(T);
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
  getHDC(hdc,arg);
  begin_system_call();
  hrgn = PathToRegion(hdc);
  end_system_call();
  if(NULL ==hrgn){
    do_GDI_ERROR("PathToRegion");
  }
  else
  {
    VALUES1(allocate_fpointer((FOREIGN)hrgn));
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
  getHDC(hdc,arg);
  begin_system_call();
  bool0 = PlayMetaFile(hdc,hmetafile);
  end_system_call();
  if(!bool0){
    do_GDI_ERROR("PlayMetaFile");
  }
  else
  {
    VALUES1(T);
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
  int1 = I_to_sint32(check_sint(popSTACK()));
  int0 = I_to_sint32(check_sint(popSTACK()));
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hrgn = TheFpointer(arg)->fp_pointer;
  begin_system_call();
  bool0 = PtInRegion(hrgn,int0,int1);
  end_system_call();
  if(!bool0){
    do_GDI_ERROR("PtInRegion");
  }
  else
  {
    VALUES1(T);
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
  int1 = I_to_sint32(check_sint(popSTACK()));
  int0 = I_to_sint32(check_sint(popSTACK()));
  getHDC(hdc,arg);
  begin_system_call();
  bool0 = PtVisible(hdc,int0,int1);
  end_system_call();
  if(!bool0){
    do_GDI_ERROR("PtVisible");
  }
  else
  {
    VALUES1(T);
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
  getHDC(hdc,arg);
  begin_system_call();
  uint = RealizePalette(hdc);
  end_system_call();
  if(!uint){
    do_GDI_ERROR("RealizePalette");
  }
  else
  {
    VALUES1(uint32_to_I(uint));
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
  int3 = I_to_sint32(check_sint(popSTACK()));
  int2 = I_to_sint32(check_sint(popSTACK()));
  int1 = I_to_sint32(check_sint(popSTACK()));
  int0 = I_to_sint32(check_sint(popSTACK()));
  getHDC(hdc,arg);
  begin_system_call();
  bool0 = Rectangle(hdc,int0,int1,int2,int3);
  end_system_call();
  if(!bool0){
    do_GDI_ERROR("Rectangle");
  }
  else
  {
    VALUES1(T);
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
    do_GDI_ERROR("ResizePalette");
  }
  else
  {
    VALUES1(T);
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
  int0 = I_to_sint32(check_sint(popSTACK()));
  getHDC(hdc,arg);
  begin_system_call();
  bool0 = RestoreDC(hdc,int0);
  end_system_call();
  if(!bool0){
    do_GDI_ERROR("RestoreDC");
  }
  else
  {
    VALUES1(T);
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
  getHDC(hdc,arg);
  begin_system_call();
  int0 = SaveDC(hdc);
  end_system_call();
  if(0 <=int0){
    do_GDI_ERROR("SaveDC");
  }
  else
  {
    VALUES1(sint32_to_I(int0));
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
  int0 = I_to_sint32(check_sint(popSTACK()));
  getHDC(hdc,arg);
  begin_system_call();
  bool0 = SelectClipPath(hdc,int0);
  end_system_call();
  if(!bool0){
    do_GDI_ERROR("SelectClipPath");
  }
  else
  {
    VALUES1(T);
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
  getHDC(hdc,arg);
  begin_system_call();
  int0 = SelectClipRgn(hdc,hrgn);
  end_system_call();
  if(0 <=int0){
    do_GDI_ERROR("SelectClipRgn");
  }
  else
  {
    VALUES1(sint32_to_I(int0));
  }
  return;
}
// tested
DEFUN( GDI:SelectObject, hdc hgdiobj)
{
  object arg;
  HGDIOBJ hgdiobj0;
  HDC hdc;
  HGDIOBJ hgdiobj;
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hgdiobj = TheFpointer(arg)->fp_pointer;
  getHDC(hdc,arg);
  begin_system_call();
  hgdiobj0 = SelectObject(hdc,hgdiobj);
  end_system_call();
  if(NULL ==hgdiobj0){
    do_GDI_ERROR("SelectObject");
  }
  else
  {
    VALUES1(allocate_fpointer((FOREIGN)hgdiobj0));
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
  int0 = I_to_sint32(check_sint(popSTACK()));
  getHDC(hdc,arg);
  begin_system_call();
  int1 = SetArcDirection(hdc,int0);
  end_system_call();
  if(0 <=int1){
    do_GDI_ERROR("SetArcDirection");
  }
  else
  {
    VALUES1(sint32_to_I(int1));
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
  getHDC(hdc,arg);
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
  int0 = I_to_sint32(check_sint(popSTACK()));
  getHDC(hdc,arg);
  begin_system_call();
  int1 = SetBkMode(hdc,int0);
  end_system_call();
  if(0 <=int1){
    do_GDI_ERROR("SetBkMode");
  }
  else
  {
    VALUES1(sint32_to_I(int1));
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
  getHDC(hdc,arg);
  begin_system_call();
  bool0 = SetColorSpace(hdc,hcolorspace);
  end_system_call();
  if(!bool0){
    do_GDI_ERROR("SetColorSpace");
  }
  else
  {
    VALUES1(T);
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
  int0 = I_to_sint32(check_sint(popSTACK()));
  getHDC(hdc,arg);
  begin_system_call();
  int1 = SetGraphicsMode(hdc,int0);
  end_system_call();
  if(0 <=int1){
    do_GDI_ERROR("SetGraphicsMode");
  }
  else
  {
    VALUES1(sint32_to_I(int1));
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
  int0 = I_to_sint32(check_sint(popSTACK()));
  getHDC(hdc,arg);
  begin_system_call();
  int1 = SetICMMode(hdc,int0);
  end_system_call();
  if(0 <=int1){
    do_GDI_ERROR("SetICMMode");
  }
  else
  {
    VALUES1(sint32_to_I(int1));
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
  int0 = I_to_sint32(check_sint(popSTACK()));
  getHDC(hdc,arg);
  begin_system_call();
  int1 = SetMapMode(hdc,int0);
  end_system_call();
  if(0 <=int1){
    do_GDI_ERROR("SetMapMode");
  }
  else
  {
    VALUES1(sint32_to_I(int1));
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
  getHDC(hdc,arg);
  begin_system_call();
  dword0 = SetMapperFlags(hdc,dword);
  end_system_call();
  if(!dword0){
    do_GDI_ERROR("SetMapperFlags");
  }
  else
  {
    VALUES1(uint32_to_I(dword0));
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
  getHDC(hdc,arg);
  begin_system_call();
  int0 = SetMetaRgn(hdc);
  end_system_call();
  if(0 <=int0){
    do_GDI_ERROR("SetMetaRgn");
  }
  else
  {
    VALUES1(sint32_to_I(int0));
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
  int0 = I_to_sint32(check_sint(popSTACK()));
  getHDC(hdc,arg);
  begin_system_call();
  int1 = SetPolyFillMode(hdc,int0);
  end_system_call();
  if(0 <=int1){
    do_GDI_ERROR("SetPolyFillMode");
  }
  else
  {
    VALUES1(sint32_to_I(int1));
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
  int0 = I_to_sint32(check_sint(popSTACK()));
  getHDC(hdc,arg);
  begin_system_call();
  int1 = SetROP2(hdc,int0);
  end_system_call();
  if(0 <=int1){
    do_GDI_ERROR("SetROP2");
  }
  else
  {
    VALUES1(sint32_to_I(int1));
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
  int3 = I_to_sint32(check_sint(popSTACK()));
  int2 = I_to_sint32(check_sint(popSTACK()));
  int1 = I_to_sint32(check_sint(popSTACK()));
  int0 = I_to_sint32(check_sint(popSTACK()));
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hrgn = TheFpointer(arg)->fp_pointer;
  begin_system_call();
  bool0 = SetRectRgn(hrgn,int0,int1,int2,int3);
  end_system_call();
  if(!bool0){
    do_GDI_ERROR("SetRectRgn");
  }
  else
  {
    VALUES1(T);
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
  int0 = I_to_sint32(check_sint(popSTACK()));
  getHDC(hdc,arg);
  begin_system_call();
  int1 = SetStretchBltMode(hdc,int0);
  end_system_call();
  if(0 <=int1){
    do_GDI_ERROR("SetStretchBltMode");
  }
  else
  {
    VALUES1(sint32_to_I(int1));
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
  getHDC(hdc,arg);
  begin_system_call();
  uint0 = SetSystemPaletteUse(hdc,uint);
  end_system_call();
  if(!uint0){
    do_GDI_ERROR("SetSystemPaletteUse");
  }
  else
  {
    VALUES1(uint32_to_I(uint0));
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
  getHDC(hdc,arg);
  begin_system_call();
  uint0 = SetTextAlign(hdc,uint);
  end_system_call();
  if(!uint0){
    do_GDI_ERROR("SetTextAlign");
  }
  else
  {
    VALUES1(uint32_to_I(uint0));
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
  int0 = I_to_sint32(check_sint(popSTACK()));
  getHDC(hdc,arg);
  begin_system_call();
  int1 = SetTextCharacterExtra(hdc,int0);
  end_system_call();
  if(0 <=int1){
    do_GDI_ERROR("SetTextCharacterExtra");
  }
  else
  {
    VALUES1(sint32_to_I(int1));
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
  int1 = I_to_sint32(check_sint(popSTACK()));
  int0 = I_to_sint32(check_sint(popSTACK()));
  getHDC(hdc,arg);
  begin_system_call();
  bool0 = SetTextJustification(hdc,int0,int1);
  end_system_call();
  if(!bool0){
    do_GDI_ERROR("SetTextJustification");
  }
  else
  {
    VALUES1(T);
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
  int0 = I_to_sint32(check_sint(popSTACK()));
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hwnd = TheFpointer(arg)->fp_pointer;
  begin_system_call();
  bool0 = ShowWindow(hwnd,int0);
  end_system_call();
  if(!bool0){
    do_GDI_ERROR("ShowWindow");
  }
  else
  {
    VALUES1(T);
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
  int0 = I_to_sint32(check_sint(popSTACK()));
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hwnd = TheFpointer(arg)->fp_pointer;
  begin_system_call();
  bool0 = ShowWindowAsync(hwnd,int0);
  end_system_call();
  if(!bool0){
    do_GDI_ERROR("ShowWindowAsync");
  }
  else
  {
    VALUES1(T);
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
  getHDC(hdc,arg);
  begin_system_call();
  int0 = StartPage(hdc);
  end_system_call();
  if(0 <=int0){
    do_GDI_ERROR("StartPage");
  }
  else
  {
    VALUES1(sint32_to_I(int0));
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
  getHDC(hdc,arg);
  begin_system_call();
  bool0 = StrokeAndFillPath(hdc);
  end_system_call();
  if(!bool0){
    do_GDI_ERROR("StrokeAndFillPath");
  }
  else
  {
    VALUES1(T);
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
  getHDC(hdc,arg);
  begin_system_call();
  bool0 = StrokePath(hdc);
  end_system_call();
  if(!bool0){
    do_GDI_ERROR("StrokePath");
  }
  else
  {
    VALUES1(T);
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
  getHDC(hdc,arg);
  begin_system_call();
  bool0 = SwapBuffers(hdc);
  end_system_call();
  if(!bool0){
    do_GDI_ERROR("SwapBuffers");
  }
  else
  {
    VALUES1(T);
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
    do_GDI_ERROR("UnrealizeObject");
  }
  else
  {
    VALUES1(T);
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
  getHDC(hdc,arg);
  begin_system_call();
  bool0 = UpdateColors(hdc);
  end_system_call();
  if(!bool0){
    do_GDI_ERROR("UpdateColors");
  }
  else
  {
    VALUES1(T);
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
    do_GDI_ERROR("UpdateWindow");
  }
  else
  {
    VALUES1(T);
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
  getHDC(hdc,arg);
  begin_system_call();
  bool0 = WidenPath(hdc);
  end_system_call();
  if(!bool0){
    do_GDI_ERROR("WidenPath");
  }
  else
  {
    VALUES1(T);
  }
  return;
}
