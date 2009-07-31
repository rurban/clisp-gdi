#line 2 "funcs-count.c"
// -*- d -*-
/* functions <= 5 args */

// untested - was never called
DEFUN( GDI:AnimatePalette, hpalette iStartIndex cEntries paletteentry_p)
/* The AnimatePalette function only changes entries with the PC_RESERVED flag
set in the corresponding palPalEntry member of the LOGPALETTE structure.

paletteentry_p is a pointer to the first member of an array of PALETTEENTRY 
structs used to replace the current entries */
{
  object arg;
  BOOL bool0;
  HPALETTE hpalette;
  UINT iStartIndex;
  UINT cEntries;
  PALETTEENTRY* paletteentry_p;
  arg = popSTACK();
  processFPTYPE(PALETTEENTRY*,paletteentry_p,arg);
  cEntries = I_to_uint32(check_uint(popSTACK()));
  iStartIndex = I_to_uint32(check_uint(popSTACK()));
  arg = popSTACK();
  processFPTYPE(HPALETTE,hpalette,arg)

  begin_system_call();
  bool0 = AnimatePalette(hpalette,iStartIndex,cEntries,paletteentry_p);
  end_system_call();
  if(!bool0){
    do_GDI_ERROR("AnimatePalette");
  }
  else
  {
    VALUES1(T);
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:ChoosePixelFormat, hdc pixelformatdescriptor_p)
{
  object arg;
  int int0;
  HDC hdc;
  PIXELFORMATDESCRIPTOR* pixelformatdescriptor_p = alloca(sizeof(PIXELFORMATDESCRIPTOR));
  object arg0;
  arg0 = popSTACK();
  processPIXELFORMATDESCRIPTOR(pixelformatdescriptor_p,arg0);
  getHDC(hdc,arg);

  begin_system_call();
  int0 = ChoosePixelFormat(hdc,pixelformatdescriptor_p);
  end_system_call();
  if(0 <=int0){
    do_GDI_ERROR("ChoosePixelFormat");
  }
  else
  {
    VALUES1(sint32_to_I(int0));
  }
  return;
}
// untested - was never called
DEFUN( GDI:CreateBitmap, nWidth nHeight cPlanes cBitsPerPel lpvBits)
/* Create monochrom bitmaps. Use CreateCompatibleBitmap to create color bitmaps.
 * lpvBits - bitvector of color data used to set the colors in a rectangle 
 *   of pixels. Each scan line in the rectangle must be word aligned, scan lines 
 *   that are not word aligned must be padded with zeros.
 * Returns a handle to the bitmap.
 */
{
  object arg;
  HBITMAP hbitmap;
  int nWidth, nHeight;
  UINT cPlanes, cBitsPerPel;
  void* lpvBits;
  arg = popSTACK();
  if(!simple_bit_vector_p(Atype_8Bit,arg))invalid_argument(arg);
  lpvBits = &(TheSbvector(arg)->data);
  cBitsPerPel = I_to_uint32(check_uint(popSTACK()));
  cPlanes = I_to_uint32(check_uint(popSTACK()));
  nHeight = I_to_sint32(check_sint(popSTACK()));
  nWidth  = I_to_sint32(check_sint(popSTACK()));

  begin_system_call();
  hbitmap = CreateBitmap(nWidth,nHeight,cPlanes,cBitsPerPel,lpvBits);
  end_system_call();
  if(NULL ==hbitmap){
    do_GDI_ERROR("CreateBitmap");
  }
  else
  {
    VALUES1(allocate_fpointer((FOREIGN)hbitmap));
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:CreateDIBPatternBrushPt, pcvoid uint)
{
  object arg;
  HBRUSH hbrush;
  void* pcvoid;
  UINT uint;
  uint = I_to_uint32(check_uint(popSTACK()));
  arg = popSTACK();
  if(!simple_bit_vector_p(Atype_8Bit,arg))invalid_argument(arg);
  pcvoid = &(TheSbvector(arg)->data);
  begin_system_call();
  hbrush = CreateDIBPatternBrushPt(pcvoid,uint);
  end_system_call();
  if(NULL ==hbrush){
    do_GDI_ERROR("CreateDIBPatternBrushPt");
  }
  else
  {
    VALUES1(allocate_fpointer((FOREIGN)hbrush));
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:CreatePolyPolygonRgn, point_p int_p int0 int1)
{
  object arg;
  HRGN hrgn;
  POINT* point_p = alloca(sizeof(POINT));
  object arg0;
  INT* int_p;
  int int0;
  int int1;
  int1 = I_to_sint32(check_sint(popSTACK()));
  int0 = I_to_sint32(check_sint(popSTACK()));
  arg = popSTACK();
  if(!simple_bit_vector_p(Atype_32Bit,arg))invalid_argument(arg);
  int_p = (INT*)&(TheSbvector(arg)->data);
  arg0 = popSTACK();
  processPOINT(point_p,arg0);

  begin_system_call();
  hrgn = CreatePolyPolygonRgn(point_p,int_p,int0,int1);
  end_system_call();
  if(NULL ==hrgn){
    do_GDI_ERROR("CreatePolyPolygonRgn");
  }
  else
  {
    VALUES1(allocate_fpointer((FOREIGN)hrgn));
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:CreatePolygonRgn, point_p int0 int1)
{
  object arg;
  HRGN hrgn;
  POINT* point_p = alloca(sizeof(POINT));
  object arg0;
  int int0;
  int int1;
  int1 = I_to_sint32(check_sint(popSTACK()));
  int0 = I_to_sint32(check_sint(popSTACK()));
  arg0 = popSTACK();
  processPOINT(point_p,arg0);

  begin_system_call();
  hrgn = CreatePolygonRgn(point_p,int0,int1);
  end_system_call();
  if(NULL ==hrgn){
    do_GDI_ERROR("CreatePolygonRgn");
  }
  else
  {
    VALUES1(allocate_fpointer((FOREIGN)hrgn));
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:CreateScalableFontResourceA, dword lpcstr lpcstr0 lpcstr1)
{
  object arg;
  BOOL bool0;
  DWORD dword;
  LPCSTR lpcstr;
  LPCSTR lpcstr0;
  LPCSTR lpcstr1;
  arg = popSTACK();
  if(!stringp(arg))invalid_argument(arg);
  with_string_0(arg,encoding, lpcstr1, {
    arg = popSTACK();
    if(!stringp(arg))invalid_argument(arg);
    with_string_0(arg,encoding, lpcstr0, {
      arg = popSTACK();
      if(!stringp(arg))invalid_argument(arg);
      with_string_0(arg,encoding, lpcstr, {
        dword = I_to_uint32(check_uint(popSTACK()));
        begin_system_call();
        bool0 = CreateScalableFontResourceA(dword,lpcstr,lpcstr0,lpcstr1);
  end_system_call();
  if(!bool0){
    do_GDI_ERROR("CreateScalableFontResourceA");
        }
        else
        {
          VALUES1(T);
        }
      });
    });
  });
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:CreateScalableFontResourceW, dword lpcwstr lpcwstr0 lpcwstr1)
{
  object arg;
  BOOL bool0;
  DWORD dword;
  LPCWSTR lpcwstr;
  LPCWSTR lpcwstr0;
  LPCWSTR lpcwstr1;
  arg = popSTACK();
  if(!stringp(arg))invalid_argument(arg);
  lpcwstr1 = WIDECHAR(arg,encoding);
  arg = popSTACK();
  if(!stringp(arg))invalid_argument(arg);
  lpcwstr0 = WIDECHAR(arg,encoding);
  arg = popSTACK();
  if(!stringp(arg))invalid_argument(arg);
  lpcwstr = WIDECHAR(arg,encoding);
  dword = I_to_uint32(check_uint(popSTACK()));
  begin_system_call();
  bool0 = CreateScalableFontResourceW(dword,lpcwstr,lpcwstr0,lpcwstr1);
  end_system_call();
  if(!bool0){
    do_GDI_ERROR("CreateScalableFontResourceW");
  }
  else
  {
    VALUES1(T);
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:DPtoLP, hdc lppoint int0)
{
  object arg;
  BOOL bool0;
  HDC hdc;
  POINT* lppoint = alloca(sizeof(POINT));
  object arg0;
  int int0;
  int0 = I_to_sint32(check_sint(popSTACK()));
  arg0 = popSTACK();
  processPOINT(lppoint,arg0);
  getHDC(hdc,arg);

  begin_system_call();
  bool0 = DPtoLP(hdc,lppoint,int0);
  end_system_call();
  if(!bool0){
    do_GDI_ERROR("DPtoLP");
  }
  else
  {
    VALUES1(T);
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:DescribePixelFormat, hdc int0 uint lppixelformatdescriptor)
{
  object arg;
  int int1;
  HDC hdc;
  int int0;
  UINT uint;
  PIXELFORMATDESCRIPTOR* lppixelformatdescriptor = alloca(sizeof(PIXELFORMATDESCRIPTOR));
  object arg0;
  arg0 = popSTACK();
  processPIXELFORMATDESCRIPTOR(lppixelformatdescriptor,arg0);
  uint = I_to_uint32(check_uint(popSTACK()));
  int0 = I_to_sint32(check_sint(popSTACK()));
  getHDC(hdc,arg);

  begin_system_call();
  int1 = DescribePixelFormat(hdc,int0,uint,lppixelformatdescriptor);
  end_system_call();
  if(0 <=int1){
    do_GDI_ERROR("DescribePixelFormat");
  }
  else
  {
    VALUES1(sint32_to_I(int1));
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:DrawEscape, hdc int0 int1 lpcstr)
{
  object arg;
  int int2;
  HDC hdc;
  int int0;
  int int1;
  LPCSTR lpcstr;
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
    int2 = DrawEscape(hdc,int0,int1,lpcstr);
  end_system_call();
  if(0 <=int2){
    do_GDI_ERROR("DrawEscape");
    }
    else
    {
    VALUES1(sint32_to_I(int2));
    }
  });
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:ExtCreatePen, dword dword0 logbrush_p dword1 dword_p)
{
  object arg;
  HPEN hpen;
  DWORD dword;
  DWORD dword0;
  LOGBRUSH* logbrush_p = alloca(sizeof(LOGBRUSH));
  object arg0;
  DWORD dword1;
  DWORD* dword_p;
  arg = popSTACK();
  if(!simple_bit_vector_p(Atype_32Bit,arg))invalid_argument(arg);
  dword_p = (DWORD*)&(TheSbvector(arg)->data);
  dword1 = I_to_uint32(check_uint(popSTACK()));
  arg0 = popSTACK();
  processLOGBRUSH(logbrush_p,arg0);
  dword0 = I_to_uint32(check_uint(popSTACK()));
  dword = I_to_uint32(check_uint(popSTACK()));

  begin_system_call();
  hpen = ExtCreatePen(dword,dword0,logbrush_p,dword1,dword_p);
  end_system_call();
  if(NULL ==hpen){
    do_GDI_ERROR("ExtCreatePen");
  }
  else
  {
    VALUES1(allocate_fpointer((FOREIGN)hpen));
  }
  return;
}
// untested - was never called
DEFUN( GDI:ExtCreateRegion, xform_p nCount rgndata_p)
/*
   xform_p - NIL or fp_zero is for the identity transform
 */
{
  object arg;
  HRGN hrgn;
  XFORM* xform_p = alloca(sizeof(XFORM));
  object arg0;
  DWORD nCount;
  RGNDATA* rgndata_p;

  arg = popSTACK();
  processFPTYPE(RGNDATA*,rgndata_p,arg);
  nCount = I_to_uint32(check_uint(popSTACK()));
  //rgndata_p = alloca(dword*sizeof(RGNDATA));
  //processRGNDATA_C(&rgndata_p,arg,nCount);
  arg0 = popSTACK();
  processXFORM(xform_p,arg0);

  begin_system_call();
  hrgn = ExtCreateRegion(xform_p,nCount,rgndata_p);
  end_system_call();
  if(NULL ==hrgn){
    do_GDI_ERROR("ExtCreateRegion");
  }
  else
  {
    VALUES1(allocate_fpointer((FOREIGN)hrgn));
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:FixBrushOrgEx, hdc int0 int1 lppoint)
{
  object arg;
  BOOL bool0;
  HDC hdc;
  int int0;
  int int1;
  POINT* lppoint = alloca(sizeof(POINT));
  object arg0;
  arg0 = popSTACK();
  processPOINT(lppoint,arg0);
  int1 = I_to_sint32(check_sint(popSTACK()));
  int0 = I_to_sint32(check_sint(popSTACK()));
  getHDC(hdc,arg);

  begin_system_call();
  bool0 = FixBrushOrgEx(hdc,int0,int1,lppoint);
  end_system_call();
  if(!bool0){
    do_GDI_ERROR("FixBrushOrgEx");
  }
  else
  {
    VALUES1(T);
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:GdiComment, hdc uint byte_p)
{
  object arg;
  BOOL bool0;
  HDC hdc;
  UINT uint;
  BYTE* byte_p;
  arg = popSTACK();
  if(!simple_bit_vector_p(Atype_8Bit,arg))invalid_argument(arg);
  byte_p = (BYTE*)&(TheSbvector(arg)->data);
  uint = I_to_uint32(check_uint(popSTACK()));
  getHDC(hdc,arg);
  begin_system_call();
  bool0 = GdiComment(hdc,uint,byte_p);
  end_system_call();
  if(!bool0){
    do_GDI_ERROR("GdiComment");
  }
  else
  {
    VALUES1(T);
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:GdiFlush,)
{
  object arg;
  BOOL bool0;
  begin_system_call();
  bool0 = GdiFlush();
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
    VALUES1(T);
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:GdiGetBatchLimit,)
{
  object arg;
  DWORD dword;
  begin_system_call();
  dword = GdiGetBatchLimit();
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
    VALUES1(uint32_to_I(dword));
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:LPtoDP, hdc lppoint int0)
{
  object arg;
  BOOL bool0;
  HDC hdc;
  POINT* lppoint = alloca(sizeof(POINT));
  object arg0;
  int int0;
  int0 = I_to_sint32(check_sint(popSTACK()));
  arg0 = popSTACK();
  processPOINT(lppoint,arg0);
  getHDC(hdc,arg);

  begin_system_call();
  bool0 = LPtoDP(hdc,lppoint,int0);
  end_system_call();
  if(!bool0){
    do_GDI_ERROR("LPtoDP");
  }
  else
  {
    VALUES1(T);
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:ModifyWorldTransform, hdc xform_p dword)
{
  object arg;
  BOOL bool0;
  HDC hdc;
  XFORM* xform_p = alloca(sizeof(XFORM));
  object arg0;
  DWORD dword;
  dword = I_to_uint32(check_uint(popSTACK()));
  arg0 = popSTACK();
  processXFORM(xform_p,arg0);
  getHDC(hdc,arg);

  begin_system_call();
  bool0 = ModifyWorldTransform(hdc,xform_p,dword);
  end_system_call();
  if(!bool0){
    do_GDI_ERROR("ModifyWorldTransform");
  }
  else
  {
    VALUES1(T);
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:MoveToEx, hdc int0 int1 lppoint)
{
  object arg;
  BOOL bool0;
  HDC hdc;
  int int0;
  int int1;
  POINT* lppoint = alloca(sizeof(POINT));
  object arg0;
  arg0 = popSTACK();
  processPOINT(lppoint,arg0);
  int1 = I_to_sint32(check_sint(popSTACK()));
  int0 = I_to_sint32(check_sint(popSTACK()));
  getHDC(hdc,arg);

  begin_system_call();
  bool0 = MoveToEx(hdc,int0,int1,lppoint);
  end_system_call();
  if(!bool0){
    do_GDI_ERROR("MoveToEx");
  }
  else
  {
    VALUES1(T);
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:OffsetViewportOrgEx, hdc int0 int1 lppoint)
{
  object arg;
  BOOL bool0;
  HDC hdc;
  int int0;
  int int1;
  POINT* lppoint = alloca(sizeof(POINT));
  object arg0;
  arg0 = popSTACK();
  processPOINT(lppoint,arg0);
  int1 = I_to_sint32(check_sint(popSTACK()));
  int0 = I_to_sint32(check_sint(popSTACK()));
  getHDC(hdc,arg);

  begin_system_call();
  bool0 = OffsetViewportOrgEx(hdc,int0,int1,lppoint);
  end_system_call();
  if(!bool0){
    do_GDI_ERROR("OffsetViewportOrgEx");
  }
  else
  {
    VALUES1(T);
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:OffsetWindowOrgEx, hdc int0 int1 lppoint)
{
  object arg;
  BOOL bool0;
  HDC hdc;
  int int0;
  int int1;
  POINT* lppoint = alloca(sizeof(POINT));
  object arg0;
  arg0 = popSTACK();
  processPOINT(lppoint,arg0);
  int1 = I_to_sint32(check_sint(popSTACK()));
  int0 = I_to_sint32(check_sint(popSTACK()));
  getHDC(hdc,arg);

  begin_system_call();
  bool0 = OffsetWindowOrgEx(hdc,int0,int1,lppoint);
  end_system_call();
  if(!bool0){
    do_GDI_ERROR("OffsetWindowOrgEx");
  }
  else
  {
    VALUES1(T);
  }
  return;
}
// untested - was never called
/**
 * The lpHandletable and nHandles parameters must be identical to those 
 * passed to the EnumMetaFileProc callback procedure by EnumMetaFile. 
 */
// uninspected - compiles but code was not checked
DEFUN( GDI:PlayEnhMetaFileRecord, hdc lphandletable enhmetarecord_p nHandles)
{
  object arg;
  BOOL bool0;
  HDC hdc;
  HANDLETABLE* lphandletable;
  ENHMETARECORD* enhmetarecord_p = alloca(sizeof(ENHMETARECORD));
  UINT nHandles;
  nHandles = I_to_uint32(check_uint(popSTACK()));
  arg = popSTACK();
  processFPTYPE(ENHMETARECORD*,enhmetarecord_p,arg);
  arg = popSTACK();
  //lphandletable = alloca(nHandles*sizeof(HANDLETABLE));
  processFPTYPE(HANDLETABLE*,lphandletable,arg);//,nHandles); //unimplemented
  getHDC(hdc,arg);

  begin_system_call();
  bool0 = PlayEnhMetaFileRecord(hdc,lphandletable,enhmetarecord_p,nHandles);
  end_system_call();
  if(!bool0){
    do_GDI_ERROR("PlayEnhMetaFileRecord");
  }
  else
  {
    VALUES1(T);
  }
  return;
}
// untested - was never called
/**
 * The lpHandletable and nHandles parameters must be identical to those 
 * passed to the EnumMetaFileProc callback procedure by EnumMetaFile. 
 */
// uninspected - compiles but code was not checked
DEFUN( GDI:PlayMetaFileRecord, hdc lphandletable lpmetarecord nHandles)
{
  object arg;
  BOOL bool0;
  HDC hdc;
  HANDLETABLE* lphandletable;
  METARECORD* lpmetarecord;
  UINT nHandles;
  nHandles = I_to_uint32(check_uint(popSTACK()));
  arg = popSTACK();
  processFPTYPE(METARECORD*,lpmetarecord,arg);
  arg = popSTACK();
  //lphandletable = alloca(nHandles*sizeof(HANDLETABLE));
  processFPTYPE(HANDLETABLE*,lphandletable,arg);//,nHandles);//unimplemented
  getHDC(hdc,arg);

  begin_system_call();
  bool0 = PlayMetaFileRecord(hdc,lphandletable,lpmetarecord,nHandles);
  end_system_call();
  if(!bool0){
    do_GDI_ERROR("PlayMetaFileRecord");
  }
  else
  {
    VALUES1(T);
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:PolyBezier, hdc point_p dword)
{
  object arg;
  BOOL bool0;
  HDC hdc;
  POINT* point_p = alloca(sizeof(POINT));
  object arg0;
  DWORD dword;
  dword = I_to_uint32(check_uint(popSTACK()));
  arg0 = popSTACK();
  processPOINT(point_p,arg0);
  getHDC(hdc,arg);

  begin_system_call();
  bool0 = PolyBezier(hdc,point_p,dword);
  end_system_call();
  if(!bool0){
    do_GDI_ERROR("PolyBezier");
  }
  else
  {
    VALUES1(T);
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:PolyBezierTo, hdc point_p dword)
{
  object arg;
  BOOL bool0;
  HDC hdc;
  POINT* point_p = alloca(sizeof(POINT));
  object arg0;
  DWORD dword;
  dword = I_to_uint32(check_uint(popSTACK()));
  arg0 = popSTACK();
  processPOINT(point_p,arg0);
  getHDC(hdc,arg);

  begin_system_call();
  bool0 = PolyBezierTo(hdc,point_p,dword);
  end_system_call();
  if(!bool0){
    do_GDI_ERROR("PolyBezierTo");
  }
  else
  {
    VALUES1(T);
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:PolyDraw, hdc point_p byte_p int0)
{
  object arg;
  BOOL bool0;
  HDC hdc;
  POINT* point_p = alloca(sizeof(POINT));
  object arg0;
  BYTE* byte_p;
  int int0;
  int0 = I_to_sint32(check_sint(popSTACK()));
  arg = popSTACK();
  if(!simple_bit_vector_p(Atype_8Bit,arg))invalid_argument(arg);
  byte_p = (BYTE*)&(TheSbvector(arg)->data);
  arg0 = popSTACK();
  processPOINT(point_p,arg0);
  getHDC(hdc,arg);

  begin_system_call();
  bool0 = PolyDraw(hdc,point_p,byte_p,int0);
  end_system_call();
  if(!bool0){
    do_GDI_ERROR("PolyDraw");
  }
  else
  {
    VALUES1(T);
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:PolyPolygon, hdc point_p int_p int0)
{
  object arg;
  BOOL bool0;
  HDC hdc;
  POINT* point_p = alloca(sizeof(POINT));
  object arg0;
  INT* int_p;
  int int0;
  int0 = I_to_sint32(check_sint(popSTACK()));
  arg = popSTACK();
  if(!simple_bit_vector_p(Atype_32Bit,arg))invalid_argument(arg);
  int_p = (INT*)&(TheSbvector(arg)->data);
  arg0 = popSTACK();
  processPOINT(point_p,arg0);
  getHDC(hdc,arg);

  begin_system_call();
  bool0 = PolyPolygon(hdc,point_p,int_p,int0);
  end_system_call();
  if(!bool0){
    do_GDI_ERROR("PolyPolygon");
  }
  else
  {
    VALUES1(T);
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:PolyPolyline, hdc point_p dword_p dword)
{
  object arg;
  BOOL bool0;
  HDC hdc;
  POINT* point_p = alloca(sizeof(POINT));
  object arg0;
  DWORD* dword_p;
  DWORD dword;
  dword = I_to_uint32(check_uint(popSTACK()));
  arg = popSTACK();
  if(!simple_bit_vector_p(Atype_32Bit,arg))invalid_argument(arg);
  dword_p = (DWORD*)&(TheSbvector(arg)->data);
  arg0 = popSTACK();
  processPOINT(point_p,arg0);
  getHDC(hdc,arg);

  begin_system_call();
  bool0 = PolyPolyline(hdc,point_p,dword_p,dword);
  end_system_call();
  if(!bool0){
    do_GDI_ERROR("PolyPolyline");
  }
  else
  {
    VALUES1(T);
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:PolyTextOutA, hdc polytexta_p int0)
{
  object arg;
  BOOL bool0;
  HDC hdc;
  POLYTEXTA* polytexta_p = alloca(sizeof(POLYTEXTA));
  object arg0;
  int int0;
  int0 = I_to_sint32(check_sint(popSTACK()));
  arg0 = popSTACK();
  processPOLYTEXTA(polytexta_p,arg0);
  getHDC(hdc,arg);

  begin_system_call();
  bool0 = PolyTextOutA(hdc,polytexta_p,int0);
  end_system_call();
  if(!bool0){
    do_GDI_ERROR("PolyTextOutA");
  }
  else
  {
    VALUES1(T);
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:PolyTextOutW, hdc polytextw_p int0)
{
  object arg;
  BOOL bool0;
  HDC hdc;
  POLYTEXTW* polytextw_p;
  object arg0;
  int int0;
  int0 = I_to_sint32(check_sint(popSTACK()));
  arg0 = popSTACK();
  processFPTYPE(POLYTEXTW*,polytextw_p,arg0);
  getHDC(hdc,arg);

  begin_system_call();
  bool0 = PolyTextOutW(hdc,polytextw_p,int0);
  end_system_call();
  if(!bool0){
    do_GDI_ERROR("PolyTextOutW");
  }
  else
  {
    VALUES1(T);
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:Polygon, hdc point_p int0)
{
  object arg;
  BOOL bool0;
  HDC hdc;
  POINT* point_p = alloca(sizeof(POINT));
  object arg0;
  int int0;
  int0 = I_to_sint32(check_sint(popSTACK()));
  arg0 = popSTACK();
  processPOINT(point_p,arg0);
  getHDC(hdc,arg);

  begin_system_call();
  bool0 = Polygon(hdc,point_p,int0);
  end_system_call();
  if(!bool0){
    do_GDI_ERROR("Polygon");
  }
  else
  {
    VALUES1(T);
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:Polyline, hdc point_p int0)
{
  object arg;
  BOOL bool0;
  HDC hdc;
  POINT* point_p = alloca(sizeof(POINT));
  object arg0;
  int int0;
  int0 = I_to_sint32(check_sint(popSTACK()));
  arg0 = popSTACK();
  processPOINT(point_p,arg0);
  getHDC(hdc,arg);

  begin_system_call();
  bool0 = Polyline(hdc,point_p,int0);
  end_system_call();
  if(!bool0){
    do_GDI_ERROR("Polyline");
  }
  else
  {
    VALUES1(T);
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:PolylineTo, hdc point_p dword)
{
  object arg;
  BOOL bool0;
  HDC hdc;
  POINT* point_p = alloca(sizeof(POINT));
  object arg0;
  DWORD dword;
  dword = I_to_uint32(check_uint(popSTACK()));
  arg0 = popSTACK();
  processPOINT(point_p,arg0);
  getHDC(hdc,arg);

  begin_system_call();
  bool0 = PolylineTo(hdc,point_p,dword);
  end_system_call();
  if(!bool0){
    do_GDI_ERROR("PolylineTo");
  }
  else
  {
    VALUES1(T);
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:SetBitmapBits, hbitmap dword pcvoid)
{
  object arg;
  LONG long0;
  HBITMAP hbitmap;
  DWORD dword;
  void* pcvoid;
  arg = popSTACK();
  if(!simple_bit_vector_p(Atype_8Bit,arg))invalid_argument(arg);
  pcvoid = &(TheSbvector(arg)->data);
  dword = I_to_uint32(check_uint(popSTACK()));
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hbitmap = TheFpointer(arg)->fp_pointer;
  begin_system_call();
  long0 = SetBitmapBits(hbitmap,dword,pcvoid);
  end_system_call();
  if(0 <=long0){
    do_GDI_ERROR("SetBitmapBits");
  }
  else
  {
    VALUES1(sint32_to_I(long0));
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:SetBitmapDimensionEx, hbitmap int0 int1)
{
  object arg;
  BOOL bool0;
  HBITMAP hbitmap;
  int int0;
  int int1;
  SIZE lpsize;
  int1 = I_to_sint32(check_sint(popSTACK()));
  int0 = I_to_sint32(check_sint(popSTACK()));
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hbitmap = TheFpointer(arg)->fp_pointer;
  begin_system_call();
  bool0 = SetBitmapDimensionEx(hbitmap,int0,int1,&lpsize);
  end_system_call();
  if(!bool0){
    do_GDI_ERROR("SetBitmapDimensionEx");
  }
  else
  {
    pushSTACK( uint32_to_I(lpsize.cy));
    value1 = uint32_to_I(lpsize.cx);
    value2 = popSTACK();
    mv_count=2;
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:SetBoundsRect, hdc lpcrect uint)
{
  object arg;
  UINT uint0;
  HDC hdc;
  RECT* lpcrect = alloca(sizeof(RECT));
  object arg0;
  UINT uint;
  uint = I_to_uint32(check_uint(popSTACK()));
  arg0 = popSTACK();
  processRECT(lpcrect,arg0);
  getHDC(hdc,arg);

  begin_system_call();
  uint0 = SetBoundsRect(hdc,lpcrect,uint);
  end_system_call();
  if(!uint0){
    do_GDI_ERROR("SetBoundsRect");
  }
  else
  {
    VALUES1(uint32_to_I(uint0));
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:SetBrushOrgEx, hdc int0 int1 lppoint)
{
  object arg;
  BOOL bool0;
  HDC hdc;
  int int0;
  int int1;
  POINT* lppoint = alloca(sizeof(POINT));
  object arg0;
  arg0 = popSTACK();
  processPOINT(lppoint,arg0);
  int1 = I_to_sint32(check_sint(popSTACK()));
  int0 = I_to_sint32(check_sint(popSTACK()));
  getHDC(hdc,arg);

  begin_system_call();
  bool0 = SetBrushOrgEx(hdc,int0,int1,lppoint);
  end_system_call();
  if(!bool0){
    do_GDI_ERROR("SetBrushOrgEx");
  }
  else
  {
    VALUES1(T);
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:SetDIBColorTable, hdc uint uint0 rgbquad_p)
{
  object arg;
  UINT uint1;
  HDC hdc;
  UINT uint;
  UINT uint0;
  RGBQUAD* rgbquad_p;
  object arg0;
  arg0 = popSTACK();
  uint0 = I_to_uint32(check_uint(popSTACK()));
  uint = I_to_uint32(check_uint(popSTACK()));
  getHDC(hdc,arg);
  rgbquad_p = alloca(uint0*sizeof(RGBQUAD));
  processRGBQUAD_C(rgbquad_p,arg0,uint0);

  begin_system_call();
  uint1 = SetDIBColorTable(hdc,uint,uint0,rgbquad_p);
  end_system_call();
  if(!uint1){
    do_GDI_ERROR("SetDIBColorTable");
  }
  else
  {
    VALUES1(uint32_to_I(uint1));
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:SetEnhMetaFileBits, uint byte_p)
{
  object arg;
  HENHMETAFILE henhmetafile;
  UINT uint;
  BYTE* byte_p;
  arg = popSTACK();
  if(!simple_bit_vector_p(Atype_8Bit,arg))invalid_argument(arg);
  byte_p = (BYTE*)&(TheSbvector(arg)->data);
  uint = I_to_uint32(check_uint(popSTACK()));
  begin_system_call();
  henhmetafile = SetEnhMetaFileBits(uint,byte_p);
  end_system_call();
  if(NULL ==henhmetafile){
    do_GDI_ERROR("SetEnhMetaFileBits");
  }
  else
  {
    VALUES1(allocate_fpointer((FOREIGN)henhmetafile));
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:SetMetaFileBitsEx, uint byte_p)
{
  object arg;
  HMETAFILE hmetafile;
  UINT uint;
  BYTE* byte_p;
  arg = popSTACK();
  if(!simple_bit_vector_p(Atype_8Bit,arg))invalid_argument(arg);
  byte_p = (BYTE*)&(TheSbvector(arg)->data);
  uint = I_to_uint32(check_uint(popSTACK()));
  begin_system_call();
  hmetafile = SetMetaFileBitsEx(uint,byte_p);
  end_system_call();
  if(NULL ==hmetafile){
    do_GDI_ERROR("SetMetaFileBitsEx");
  }
  else
  {
    VALUES1(allocate_fpointer((FOREIGN)hmetafile));
  }
  return;
}
// untested - was never called
/**
 * The return value is the number of entries that were set in the logical palette.
 */
DEFUN( GDI:SetPaletteEntries, hpalette iStart cEntries paletteentry_p)
{
  object arg;
  UINT uint1;
  HPALETTE hpalette;
  UINT iStart;
  UINT cEntries;
  PALETTEENTRY* paletteentry_p;
  object arg0;
  arg0 = popSTACK();
  if(!fpointerp(arg0))invalid_argument(arg0);
  paletteentry_p = TheFpointer(arg0)->fp_pointer;
  cEntries = I_to_uint32(check_uint(popSTACK()));
  iStart = I_to_uint32(check_uint(popSTACK()));
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hpalette = TheFpointer(arg)->fp_pointer;

  begin_system_call();
  uint1 = SetPaletteEntries(hpalette,iStart,cEntries,paletteentry_p);
  end_system_call();
  if(!uint1){
    do_GDI_ERROR("SetPaletteEntries");
  }
  else
  {
    VALUES1(uint32_to_I(uint1));
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:SetPixelFormat, hdc int0 pixelformatdescriptor_p)
{
  object arg;
  BOOL bool0;
  HDC hdc;
  int int0;
  PIXELFORMATDESCRIPTOR* pixelformatdescriptor_p = alloca(sizeof(PIXELFORMATDESCRIPTOR));
  object arg0;
  arg0 = popSTACK();
  processPIXELFORMATDESCRIPTOR(pixelformatdescriptor_p,arg0);
  int0 = I_to_sint32(check_sint(popSTACK()));
  getHDC(hdc,arg);

  begin_system_call();
  bool0 = SetPixelFormat(hdc,int0,pixelformatdescriptor_p);
  end_system_call();
  if(!bool0){
    do_GDI_ERROR("SetPixelFormat");
  }
  else
  {
    VALUES1(T);
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:SetViewportExtEx, hdc int0 int1 lpsize)
{
  object arg;
  BOOL bool0;
  HDC hdc;
  int int0;
  int int1;
  SIZE* lpsize;
  object arg0;
  arg0 = popSTACK();
  processLPSIZE(lpsize,arg0);
  int1 = I_to_sint32(check_sint(popSTACK()));
  int0 = I_to_sint32(check_sint(popSTACK()));
  getHDC(hdc,arg);

  begin_system_call();
  bool0 = SetViewportExtEx(hdc,int0,int1,lpsize);
  end_system_call();
  if(!bool0){
    do_GDI_ERROR("SetViewportExtEx");
  }
  else
  {
    VALUES1(T);
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:SetViewportOrgEx, hdc int0 int1 lppoint)
{
  object arg;
  BOOL bool0;
  HDC hdc;
  int int0;
  int int1;
  POINT* lppoint = alloca(sizeof(POINT));
  object arg0;
  arg0 = popSTACK();
  processPOINT(lppoint,arg0);
  int1 = I_to_sint32(check_sint(popSTACK()));
  int0 = I_to_sint32(check_sint(popSTACK()));
  getHDC(hdc,arg);

  begin_system_call();
  bool0 = SetViewportOrgEx(hdc,int0,int1,lppoint);
  end_system_call();
  if(!bool0){
    do_GDI_ERROR("SetViewportOrgEx");
  }
  else
  {
    VALUES1(T);
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:SetWinMetaFileBits, uint byte_p hdc metafilepict_p)
{
  object arg;
  HENHMETAFILE henhmetafile;
  UINT uint;
  BYTE* byte_p;
  HDC hdc;
  METAFILEPICT* metafilepict_p = alloca(sizeof(METAFILEPICT));
  object arg0;
  arg0 = popSTACK();
  processMETAFILEPICT(metafilepict_p,arg0);
  getHDC(hdc,arg);
  arg = popSTACK();
  if(!simple_bit_vector_p(Atype_8Bit,arg))invalid_argument(arg);
  byte_p = (BYTE*)&(TheSbvector(arg)->data);
  uint = I_to_uint32(check_uint(popSTACK()));

  begin_system_call();
  henhmetafile = SetWinMetaFileBits(uint,byte_p,hdc,metafilepict_p);
  end_system_call();
  if(NULL ==henhmetafile){
    do_GDI_ERROR("SetWinMetaFileBits");
  }
  else
  {
    VALUES1(allocate_fpointer((FOREIGN)henhmetafile));
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:SetWindowExtEx, hdc int0 int1 lpsize)
{
  object arg;
  BOOL bool0;
  HDC hdc;
  int int0;
  int int1;
  SIZE* lpsize;// = alloca(sizeof(SIZE));
  object arg0;
  arg0 = popSTACK();
  processLPSIZE(lpsize,arg0);
  int1 = I_to_sint32(check_sint(popSTACK()));
  int0 = I_to_sint32(check_sint(popSTACK()));
  getHDC(hdc,arg);

  begin_system_call();
  bool0 = SetWindowExtEx(hdc,int0,int1,lpsize);
  end_system_call();
  if(!bool0){
    do_GDI_ERROR("SetWindowExtEx");
  }
  else
  {
    VALUES1(T);
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:SetWindowOrgEx, hdc int0 int1 lppoint)
{
  object arg;
  BOOL bool0;
  HDC hdc;
  int int0;
  int int1;
  POINT* lppoint = alloca(sizeof(POINT));
  object arg0;
  arg0 = popSTACK();
  processPOINT(lppoint,arg0);
  int1 = I_to_sint32(check_sint(popSTACK()));
  int0 = I_to_sint32(check_sint(popSTACK()));
  getHDC(hdc,arg);

  begin_system_call();
  bool0 = SetWindowOrgEx(hdc,int0,int1,lppoint);
  end_system_call();
  if(!bool0){
    do_GDI_ERROR("SetWindowOrgEx");
  }
  else
  {
    VALUES1(T);
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:StartDocA, hdc docinfoa_p)
{
  object arg;
  int int0;
  HDC hdc;
  DOCINFOA* docinfoa_p;// = alloca(sizeof(DOCINFOA));
  object arg0;
  arg0 = popSTACK();
  processFPTYPE(DOCINFOA*,docinfoa_p,arg0);
  getHDC(hdc,arg);

  begin_system_call();
  int0 = StartDocA(hdc,docinfoa_p);
  end_system_call();
  if(0 <=int0){
    do_GDI_ERROR("StartDocA");
  }
  else
  {
    VALUES1(sint32_to_I(int0));
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:StartDocW, hdc docinfow_p)
{
  object arg;
  int int0;
  HDC hdc;
  DOCINFOW* docinfow_p;// = alloca(sizeof(DOCINFOW));
  object arg0;
  arg0 = popSTACK();
  processFPTYPE(DOCINFOW*,docinfow_p,arg0);
  getHDC(hdc,arg);

  begin_system_call();
  int0 = StartDocW(hdc,docinfow_p);
  end_system_call();
  if(0 <=int0){
    do_GDI_ERROR("StartDocW");
  }
  else
  {
    VALUES1(sint32_to_I(int0));
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:TextOutA, hdc int0 int1 lpcstr int2)
{
  object arg;
  BOOL bool0;
  HDC hdc;
  int int0;
  int int1;
  LPCSTR lpcstr;
  int int2;
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
    bool0 = TextOutA(hdc,int0,int1,lpcstr,int2);
    end_system_call();
    if(!bool0){
      do_GDI_ERROR("TextOutA");
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
DEFUN( GDI:TextOutW, hdc int0 int1 lpcwstr int2)
{
  object arg;
  BOOL bool0;
  HDC hdc;
  int int0;
  int int1;
  LPCWSTR lpcwstr;
  int int2;
  int2 = I_to_sint32(check_sint(popSTACK()));
  arg = popSTACK();
  if(!stringp(arg))invalid_argument(arg);
  lpcwstr = WIDECHAR(arg,encoding);
  int1 = I_to_sint32(check_sint(popSTACK()));
  int0 = I_to_sint32(check_sint(popSTACK()));
  getHDC(hdc,arg);
  begin_system_call();
  bool0 = TextOutW(hdc,int0,int1,lpcwstr,int2);
  end_system_call();
  if(!bool0){
    do_GDI_ERROR("TextOutW");
  }
  else
  {
    VALUES1(T);
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:UpdateICMRegKeyA, dword dword0 lpstr uint)
{
  object arg;
  BOOL bool0;
  DWORD dword;
  DWORD dword0;
  LPSTR lpstr;
  UINT uint;
  uint = I_to_uint32(check_uint(popSTACK()));
  arg = popSTACK();
  if(!stringp(arg))invalid_argument(arg);
  with_string_0(arg,encoding, lpstr, {
    dword0 = I_to_uint32(check_uint(popSTACK()));
    dword = I_to_uint32(check_uint(popSTACK()));
    begin_system_call();
    bool0 = UpdateICMRegKeyA(dword,dword0,lpstr,uint);
    end_system_call();
    if(!bool0){
      do_GDI_ERROR("UpdateICMRegKeyA");
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
DEFUN( GDI:UpdateICMRegKeyW, dword dword0 lpwstr uint)
{
  object arg;
  BOOL bool0;
  DWORD dword;
  DWORD dword0;
  LPWSTR lpwstr;
  UINT uint;
  uint = I_to_uint32(check_uint(popSTACK()));
  arg = popSTACK();
  if(!stringp(arg))invalid_argument(arg);
  lpwstr = WIDECHAR(arg,encoding);
  dword0 = I_to_uint32(check_uint(popSTACK()));
  dword = I_to_uint32(check_uint(popSTACK()));
  begin_system_call();
  bool0 = UpdateICMRegKeyW(dword,dword0,lpwstr,uint);
  end_system_call();
  if(!bool0){
    do_GDI_ERROR("UpdateICMRegKeyW");
  }
  else
  {
    VALUES1(T);
  }
  return;
}

// Local-Variables:
//  c-basic-offset: 2
// End
