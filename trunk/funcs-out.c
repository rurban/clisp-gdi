#line 2 "funcs-out.c"

/* Functions that return data, therefore not T/nil as first value, but as last. 
 * Also try to return structs as structs, not just foreign pointers. This is still work in progress
 */

// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:CheckColorsInGamut, hdc lpaRGBQuad lpResult nCount)
{
  object arg;
  BOOL bool0;
  HDC hdc;
  void* lpaRGBQuad;
  void* lpResult;
  DWORD nCount;
  nCount = I_to_uint32(check_uint(popSTACK()));
  arg = popSTACK();
  if(!simple_bit_vector_p(Atype_8Bit,arg))invalid_argument(arg);
  lpResult = &(TheSbvector(arg)->data);
  arg = popSTACK();
  if(!simple_bit_vector_p(Atype_8Bit,arg))invalid_argument(arg);
  lpaRGBQuad = &(TheSbvector(arg)->data);
  getHDC(hdc,arg);

  begin_system_call();
  bool0 = CheckColorsInGamut(hdc,lpaRGBQuad,lpResult,nCount);
  end_system_call();
  if(!bool0){
    do_GDI_ERROR("CheckColorsInGamut");
  }
  else
  {
    VALUES1(T);
  }
  return;
}
// untested - was never called
// removed 1st lpxformResult arg
DEFUN( GDI:CombineTransform, lpxform xform1 xform2)
{
  object arg0,arg1,arg2;
  BOOL bool0;
  XFORM xform1;
  XFORM xform2;
  XFORM *lpxform = alloca(sizeof(XFORM));
  arg2 = popSTACK();
  processXFORM(&xform2,arg2);
  arg1 = popSTACK();
  processXFORM(&xform1,arg1);
  arg0 = popSTACK();
  processXFORM(lpxform,arg0);

  begin_system_call();
  bool0 = CombineTransform(lpxform,&xform1,&xform2);
  end_system_call();
  if(!bool0){
    do_GDI_ERROR("CombineTransform");
  }
  else
  {
    value1 = outputXFORM(lpxform,arg0);
    mv_count=1;
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:CreateDIBSection, hdc bitmapinfo_p uint handle dword)
{
  object arg;
  HBITMAP hbitmap;
  HDC hdc;
  BITMAPINFO* bitmapinfo_p;// = alloca(sizeof(BITMAPINFO));
  UINT uint;
  void *ppvBits;
  HANDLE handle;
  DWORD dword;
  dword = I_to_uint32(check_uint(popSTACK()));
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  handle = (nullp(arg))?0:(TheFpointer(arg)->fp_pointer);
  uint = I_to_uint32(check_uint(popSTACK()));
  arg = popSTACK();
  processFPTYPE(BITMAPINFO*,bitmapinfo_p,arg);
  getHDC(hdc,arg);

  begin_system_call();
  hbitmap = CreateDIBSection(hdc,bitmapinfo_p,uint,&ppvBits,handle,dword);
  end_system_call();
  if(NULL ==hbitmap){
    do_GDI_ERROR("CreateDIBSection");
  }
  else
  {
    VALUES2(allocate_fpointer((FOREIGN)hbitmap), 
            allocate_fpointer((FOREIGN)ppvBits));
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:EnumEnhMetaFile, hdc henhmetafile enhmfenumproc pvoid lpcrect)
{
  object arg;
  BOOL bool0;
  HDC hdc;
  HENHMETAFILE henhmetafile;
  ENHMFENUMPROC enhmfenumproc;
  void* pvoid;
  RECT* lpcrect = alloca(sizeof(RECT));
  object arg0;
  arg0 = popSTACK();
  processRECT(lpcrect,arg0);
  arg = popSTACK();
  if(!simple_bit_vector_p(Atype_8Bit,arg))invalid_argument(arg);
  pvoid = &(TheSbvector(arg)->data);
  arg0 = popSTACK();
  processFPTYPE(ENHMFENUMPROC,enhmfenumproc,arg0);
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  henhmetafile = TheFpointer(arg)->fp_pointer;
  getHDC(hdc,arg);

  begin_system_call();
  bool0 = EnumEnhMetaFile(hdc,henhmetafile,enhmfenumproc,pvoid,lpcrect);
  end_system_call();
  if(!bool0){
    do_GDI_ERROR("EnumEnhMetaFile");
  }
  else
  {
    VALUES1(T);
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:EnumFontFamiliesA, hdc lpcstr fontenumproca lparam)
{
  object arg;
  int int0;
  HDC hdc;
  LPCSTR lpcstr;
  FONTENUMPROCA fontenumproca;
  LPARAM lparam;
  object arg0;
  arg = popSTACK();
  check_sint(arg);
  lparam = I_to_sint32(arg);
  arg0 = popSTACK();
  //processFONTENUMPROCA(&fontenumproca,arg0);
  arg = popSTACK();
  if(!stringp(arg))invalid_string_argument(arg);
  with_string_0(arg,encoding, lpcstr, {
    arg = popSTACK();
    if(!fpointerp(arg))invalid_argument(arg);
    hdc = TheFpointer(arg)->fp_pointer;
  
    begin_system_call();
    int0 = EnumFontFamiliesA(hdc,lpcstr,fontenumproca,lparam);
    end_system_call();
    if(0 <=int0){
      do_GDI_ERROR("EnumFontFamiliesA");
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
DEFUN( GDI:EnumFontFamiliesExA, hdc plogfonta fontenumproca lparam dword)
{
  object arg;
  int int0;
  HDC hdc;
  PLOGFONTA plogfonta;
  FONTENUMPROCA fontenumproca;
  LPARAM lparam;
  object arg0;
  DWORD dword;
  dword = I_to_uint32(check_uint(popSTACK()));
  lparam = I_to_sint32(check_sint(popSTACK()));
  arg0 = popSTACK();
  processFPTYPE(FONTENUMPROCA,fontenumproca,arg0);
  //processFONTENUMPROCA(&fontenumproca,arg0);
  arg0 = popSTACK();
  processFPTYPE(PLOGFONTA,plogfonta,arg0);
  //processPLOGFONTA(plogfonta,arg0);
  getHDC(hdc,arg);
  begin_system_call();
  int0 = EnumFontFamiliesExA(hdc,plogfonta,fontenumproca,lparam,dword);
  end_system_call();
  if(0 <=int0){
    do_GDI_ERROR("EnumFontFamiliesExA");
  }
  else
  {
    VALUES1(sint32_to_I(int0));
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:EnumFontFamiliesExW, hdc plogfontw fontenumprocw lparam dword)
{
  object arg;
  int int0;
  HDC hdc;
  PLOGFONTW plogfontw;
  FONTENUMPROCW fontenumprocw;
  LPARAM lparam;
  object arg0;
  DWORD dword;
  dword = I_to_uint32(check_uint(popSTACK()));
  lparam = I_to_sint32(check_sint(popSTACK()));
  arg0 = popSTACK();
  processFPTYPE(FONTENUMPROCW,fontenumprocw,arg0);
  //processFONTENUMPROCW(fontenumprocw,arg0);
  arg0 = popSTACK();
  processFPTYPE(PLOGFONTW,plogfontw,arg0);
  //processPLOGFONTW(plogfontw,arg0);
  getHDC(hdc,arg);
  begin_system_call();
  int0 = EnumFontFamiliesExW(hdc,plogfontw,fontenumprocw,lparam,dword);
  end_system_call();
  if(0 <=int0){
    do_GDI_ERROR("EnumFontFamiliesExW");
  }
  else
  {
    VALUES1(sint32_to_I(int0));
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:EnumFontFamiliesW, hdc lpcwstr fontenumprocw lparam)
{
  object arg;
  int int0;
  HDC hdc;
  LPCWSTR lpcwstr;
  FONTENUMPROCW fontenumprocw;
  LPARAM lparam;
  object arg0;
  lparam = I_to_sint32(check_sint(popSTACK()));
  arg0 = popSTACK();
  processFPTYPE(FONTENUMPROCW,fontenumprocw,arg0);
  arg = popSTACK();
  if(!stringp(arg))invalid_string_argument(arg);
  lpcwstr = WIDECHAR(arg,encoding);
  getHDC(hdc,arg);
  begin_system_call();
  int0 = EnumFontFamiliesW(hdc,lpcwstr,fontenumprocw,lparam);
  end_system_call();
  if(0 <=int0){
    do_GDI_ERROR("EnumFontFamiliesW");
  }
  else
  {
    VALUES1(sint32_to_I(int0));
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:EnumFontsA, hdc lpcstr fontenumproca lparam)
{
  object arg;
  int int0;
  HDC hdc;
  LPCSTR lpcstr;
  FONTENUMPROCA fontenumproca;
  LPARAM lparam;
  object arg0;
  lparam = I_to_sint32(check_sint(popSTACK()));
  arg0 = popSTACK();
  processFPTYPE(FONTENUMPROCA,fontenumproca,arg0);
  arg = popSTACK();
  if(!stringp(arg))invalid_string_argument(arg);
  with_string_0(arg,encoding, lpcstr, {
    arg = popSTACK();
    if(!fpointerp(arg))invalid_argument(arg);
    hdc = TheFpointer(arg)->fp_pointer;
  
    begin_system_call();
    int0 = EnumFontsA(hdc,lpcstr,fontenumproca,lparam);
    end_system_call();
    if(0 <=int0){
      do_GDI_ERROR("EnumFontsA");
    }
    else
    {
      VALUES1(sint32_to_I(int0));
    }
  });
  return;
}
// untested - was never called
DEFUN( GDI:EnumFontsW, hdc lpcwstr fontenumprocw lparam)
{
  object arg;
  int int0;
  HDC hdc;
  LPCWSTR lpcwstr;
  FONTENUMPROCW fontenumprocw;
  LPARAM lparam;
  object arg0;
  lparam = I_to_sint32(check_sint(popSTACK()));
  processFPTYPE(FONTENUMPROCW,fontenumprocw,popSTACK());
  arg = popSTACK();
  if(!stringp(arg))invalid_string_argument(arg);
  lpcwstr = WIDECHAR(arg,encoding);
  getHDC(hdc,arg);
  begin_system_call();
  int0 = EnumFontsW(hdc,lpcwstr,fontenumprocw,lparam);
  end_system_call();
  if(0 <=int0){
    do_GDI_ERROR("EnumFontsW");
  }
  else
  {
    VALUES1(sint32_to_I(int0));
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:EnumICMProfilesA, hdc icmenumproca lparam)
{
  object arg;
  int int0;
  HDC hdc;
  ICMENUMPROCA icmenumproca;
  LPARAM lparam;
  object arg0;
  lparam = I_to_sint32(check_sint(popSTACK()));
  arg0 = popSTACK();
  processFPTYPE(ICMENUMPROCA,icmenumproca,arg0);
  getHDC(hdc,arg);
  begin_system_call();
  int0 = EnumICMProfilesA(hdc,icmenumproca,lparam);
  end_system_call();
  if(0 <=int0){
    do_GDI_ERROR("EnumICMProfilesA");
  }
  else
  {
    VALUES1(sint32_to_I(int0));
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:EnumICMProfilesW, hdc icmenumprocw lparam)
{
  object arg;
  int int0;
  HDC hdc;
  ICMENUMPROCW icmenumprocw;
  LPARAM lparam;
  object arg0;
  lparam = I_to_sint32(check_sint(popSTACK()));
  arg0 = popSTACK();
  processFPTYPE(ICMENUMPROCW,icmenumprocw,arg0);
  getHDC(hdc,arg);
  begin_system_call();
  int0 = EnumICMProfilesW(hdc,icmenumprocw,lparam);
  end_system_call();
  if(0 <=int0){
    do_GDI_ERROR("EnumICMProfilesW");
  }
  else
  {
    VALUES1(sint32_to_I(int0));
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:EnumMetaFile, hdc hmetafile mfenumproc lparam)
{
  object arg;
  BOOL bool0;
  HDC hdc;
  HMETAFILE hmetafile;
  MFENUMPROC mfenumproc;
  LPARAM lparam;
  object arg0;

  lparam = I_to_sint32(check_sint(popSTACK()));
  arg0 = popSTACK();
  processFPTYPE(MFENUMPROC,mfenumproc,arg0);
  arg = popSTACK();
  processFPTYPE(HMETAFILE,hmetafile,arg);
  arg = popSTACK();
  processFPTYPE(HDC,hdc,arg);

  begin_system_call();
  bool0 = EnumMetaFile(hdc,hmetafile,mfenumproc,lparam);
  end_system_call();
  if(!bool0){
    do_GDI_ERROR("EnumMetaFile");
  }
  else
  {
    VALUES1(T);
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:EnumObjects, hdc int0 gobjenumproc lparam)
{
  object arg;
  int int1;
  HDC hdc;
  int int0;
  GOBJENUMPROC gobjenumproc;
  LPARAM lparam;
  object arg0;

  lparam = I_to_sint32(check_sint(popSTACK()));
  arg0 = popSTACK();
  processFPTYPE(GOBJENUMPROC,gobjenumproc,arg0);
  int0 = I_to_sint32(check_sint(popSTACK()));
  getHDC(hdc,arg);

  begin_system_call();
  int1 = EnumObjects(hdc,int0,gobjenumproc,lparam);
  end_system_call();
  if(0 <=int1){
    do_GDI_ERROR("EnumObjects");
  }
  else
  {
    VALUES1(sint32_to_I(int0));
  }
  return;
}

// untested - was never called
DEFUN( GDI:GetAspectRatioFilterEx, hdc)
/** 
 * Retrieve the setting for the current aspect-ratio filter.
 * The aspect ratio is the ratio formed by the width and height 
 * of a pixel on a specified device.
 * Returns AspectRatio.cx and cy
 */
{
  object arg;
  BOOL bool0;
  HDC hdc;
  SIZE size;
  object arg0;
  getHDC(hdc,arg);
  begin_system_call();
  bool0 = GetAspectRatioFilterEx(hdc,&size);
  end_system_call();
  if(!bool0){
    do_GDI_ERROR("GetAspectRatioFilterEx");
  }
  else
  {
    VALUES2(uint32_to_I(size.cx),uint32_to_I(size.cy));
  }
  return;
}

// untested - was never called
DEFUN( GDI:GetBitmapBits, hbitmap long0 pvoid)
/** 
 * Returns: Pointer to a buffer to receive the bitmap bits 
   and the number of copied bits. The bits are stored as an 
   array of byte values.
 */
{
  object arg;
  LONG long1;
  HBITMAP hbitmap;
  LONG long0;
  void* pvoid;
  arg = popSTACK();
  if(!simple_bit_vector_p(Atype_8Bit,arg))invalid_argument(arg);
  pvoid = &(TheSbvector(arg)->data);
  arg = popSTACK();
  check_sint(arg);
  long0 = I_to_sint32(arg);
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hbitmap = TheFpointer(arg)->fp_pointer;
  begin_system_call();
  long1 = GetBitmapBits(hbitmap,long0,pvoid);
  end_system_call();
  if(0 <=long1){
    do_GDI_ERROR("GetBitmapBits");
  }
  else
  {
    value1 = allocate_fpointer((FOREIGN)pvoid);
    value2 = sint32_to_I(long1);
    mv_count=2;
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:GetBitmapDimensionEx, hbitmap)
{
  object arg;
  BOOL bool0;
  HBITMAP hbitmap;
  SIZE size;
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hbitmap = TheFpointer(arg)->fp_pointer;
  begin_system_call();
  bool0 = GetBitmapDimensionEx(hbitmap,&size);
  end_system_call();
  if(!bool0){
    do_GDI_ERROR("GetBitmapDimensionEx");
  }
  else
  {
    VALUES2(uint32_to_I(size.cx),uint32_to_I(size.cy));
  }
  return;
}
// untested - was never called
DEFUN( GDI:GetBoundsRect, hdc lprect flags)
{
  object arg;
  UINT ret;
  HDC hdc;
  RECT rect;
  object arg0;
  UINT flags;
  flags = I_to_uint32(check_uint(popSTACK()));
  arg0 = popSTACK();
  processRECT(&rect,arg0);
  getHDC(hdc,arg);

  begin_system_call();
  ret = GetBoundsRect(hdc,&rect,flags);
  end_system_call();
  if(!ret){
    do_GDI_ERROR("GetBoundsRect");
  }
  else
  {
    value1 = outputRECT(&rect,arg0);
    value2 = uint32_to_I(ret);
    mv_count=2;
  }
  return;
}
// untested - was never called
// removed lppoint
DEFUN( GDI:GetBrushOrgEx, hdc)
{
  object arg;
  BOOL bool0;
  HDC hdc;
  POINT point;
  /*object arg0;
  arg0 = popSTACK();
  processPOINT(&point,arg0);*/
  getHDC(hdc,arg);
  begin_system_call();
  bool0 = GetBrushOrgEx(hdc,&point);
  end_system_call();
  if(!bool0){
    do_GDI_ERROR("GetBrushOrgEx");
  }
  else
  {
    VALUES2(fixnum(point.x), fixnum(point.y));
    //VALUES1(outputPOINT(&point, arg0));
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:GetCharABCWidthsA, hdc iFirstChar iLastChar lpABC)
{
  object arg;
  BOOL bool0;
  HDC hdc;
  UINT iFirstChar,iLastChar;
  ABC* lpABC = alloca(sizeof(ABC));
  object arg0;
  arg0 = popSTACK();
  if(!fpointerp(arg0))invalid_named_argument(arg0,"lpABC");
  lpABC = (ABC*)TheFpointer(arg0)->fp_pointer;
  //processABC(lpabc,arg0);
  iLastChar = I_to_uint32(check_uint(popSTACK()));
  iFirstChar = I_to_uint32(check_uint(popSTACK()));
  getHDC(hdc,arg);

  begin_system_call();
  bool0 = GetCharABCWidthsA(hdc,iFirstChar,iLastChar,lpABC);
  end_system_call();
  if(!bool0){
    do_GDI_ERROR("GetCharABCWidthsA");
  }
  else
  {
    VALUES1(T);
  }
  return;
}
// untested - was never called
// 
DEFUN( GDI:GetCharABCWidthsFloatA, hdc iFirstChar iLastChar lpabcfloat)
{
  object arg;
  BOOL bool0;
  HDC hdc;
  UINT iFirstChar, iLastChar;
  ABCFLOAT* lpabcfloat;
  object arg0;
  arg0 = popSTACK();
  if(!fpointerp(arg0))invalid_named_argument(arg0, "lpabcfloat");
  lpabcfloat = (ABCFLOAT*)TheFpointer(arg0)->fp_pointer;
  //processABCFLOAT(lpabcfloat,arg0);
  iLastChar = I_to_uint32(check_uint(popSTACK()));
  iFirstChar = I_to_uint32(check_uint(popSTACK()));
  getHDC(hdc,arg);

  begin_system_call();
  bool0 = GetCharABCWidthsFloatA(hdc,iFirstChar,iLastChar,lpabcfloat);
  end_system_call();
  if(!bool0){
    do_GDI_ERROR("GetCharABCWidthsFloatA");
  }
  else
  {
    //value1 = outputABCFLOAT(lpabcfloat);
    VALUES1(allocate_fpointer((FOREIGN)lpabcfloat));
  }
  return;
}
// untested - was never called
DEFUN( GDI:GetCharABCWidthsFloatW, hdc iFirstChar iLastChar lpabcfloat)
{
  object arg;
  BOOL bool0;
  HDC hdc;
  UINT iFirstChar, iLastChar;
  ABCFLOAT* lpabcfloat;
  object arg0;

  arg0 = popSTACK();
  if(!fpointerp(arg0))invalid_named_argument(arg0, "lpabcfloat");
  lpabcfloat = (ABCFLOAT*)TheFpointer(arg0)->fp_pointer;
  //processABCFLOAT(lpabcfloat,arg0);
  iLastChar = I_to_uint32(check_uint(popSTACK()));
  iFirstChar = I_to_uint32(check_uint(popSTACK()));
  getHDC(hdc,arg);

  begin_system_call();
  bool0 = GetCharABCWidthsFloatW(hdc,iFirstChar,iLastChar,lpabcfloat);
  end_system_call();
  if(!bool0){
    do_GDI_ERROR("GetCharABCWidthsFloatW");
  }
  else
  {
    VALUES1(allocate_fpointer((FOREIGN)lpabcfloat));
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:GetCharABCWidthsW, hdc iFirstChar iLastChar lpabc)
{
  object arg;
  BOOL bool0;
  HDC hdc;
  UINT iFirstChar,iLastChar;
  ABC* lpabc = alloca(sizeof(ABC));
  object arg0;

  arg0 = popSTACK();
  if(!fpointerp(arg0))invalid_named_argument(arg0, "lpabc");
  lpabc = (ABC*)TheFpointer(arg0)->fp_pointer;
  //processABC(lpabc,arg0);
  iLastChar = I_to_uint32(check_uint(popSTACK()));
  iFirstChar = I_to_uint32(check_uint(popSTACK()));
  getHDC(hdc,arg);

  begin_system_call();
  bool0 = GetCharABCWidthsW(hdc,iFirstChar,iLastChar,lpabc);
  end_system_call();
  if(!bool0){
    do_GDI_ERROR("GetCharABCWidthsW");
  }
  else
  {
    VALUES1(allocate_fpointer((FOREIGN)lpabc));
  }
  return;
}
// untested - was never called
DEFUN( GDI:GetCharWidth32A, hdc iFirstChar iLastChar lpint)
{
  object arg;
  BOOL bool0;
  HDC hdc;
  UINT iFirstChar, iLastChar;
  int* lpint;
  arg = popSTACK();
  if(!simple_bit_vector_p(Atype_32Bit,arg))invalid_argument(arg);
  lpint = (int*)&(TheSbvector(arg)->data);
  iLastChar = I_to_uint32(check_uint(popSTACK()));
  iFirstChar = I_to_uint32(check_uint(popSTACK()));
  getHDC(hdc,arg);

  begin_system_call();
  bool0 = GetCharWidth32A(hdc,iFirstChar,iLastChar,lpint);
  end_system_call();
  if(!bool0){
    do_GDI_ERROR("GetCharWidth32A");
  }
  else
  {
    VALUES1(T);
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:GetCharWidth32W, hdc uint uint0 lpint)
{
  object arg;
  BOOL bool0;
  HDC hdc;
  UINT uint;
  UINT uint0;
  int* lpint;
  arg = popSTACK();
  if(!simple_bit_vector_p(Atype_32Bit,arg))invalid_argument(arg);
  lpint = (int*)&(TheSbvector(arg)->data);
  uint0 = I_to_uint32(check_uint(popSTACK()));
  uint = I_to_uint32(check_uint(popSTACK()));
  getHDC(hdc,arg);
  begin_system_call();
  bool0 = GetCharWidth32W(hdc,uint,uint0,lpint);
  end_system_call();
  if(!bool0){
    do_GDI_ERROR("GetCharWidth32W");
  }
  else
  {
    VALUES1(T);
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:GetCharWidthA, hdc uint uint0 lpint)
{
  object arg;
  BOOL bool0;
  HDC hdc;
  UINT uint;
  UINT uint0;
  int* lpint;
  arg = popSTACK();
  if(!simple_bit_vector_p(Atype_32Bit,arg))invalid_argument(arg);
  lpint = (int*)&(TheSbvector(arg)->data);
  uint0 = I_to_uint32(check_uint(popSTACK()));
  uint = I_to_uint32(check_uint(popSTACK()));
  getHDC(hdc,arg);

  begin_system_call();
  bool0 = GetCharWidthA(hdc,uint,uint0,lpint);
  end_system_call();
  if(!bool0){
    do_GDI_ERROR("GetCharWidthA");
  }
  else
  {
    VALUES1(T);
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:GetCharWidthW, hdc uint uint0 lpint)
{
  object arg;
  BOOL bool0;
  HDC hdc;
  UINT uint;
  UINT uint0;
  int* lpint;
  arg = popSTACK();
  if(!simple_bit_vector_p(Atype_32Bit,arg))invalid_argument(arg);
  lpint = (int*)&(TheSbvector(arg)->data);
  uint0 = I_to_uint32(check_uint(popSTACK()));
  uint = I_to_uint32(check_uint(popSTACK()));
  getHDC(hdc,arg);
  begin_system_call();
  bool0 = GetCharWidthW(hdc,uint,uint0,lpint);
  end_system_call();
  if(!bool0){
    do_GDI_ERROR("GetCharWidthW");
  }
  else
  {
    VALUES1(T);
  }
  return;
}

// untested - was never called
DEFUN( GDI:GetClientRect, hwnd lprect)
{
  object arg, arg0;
  BOOL bool0;
  HWND hwnd;
  RECT rect;
  arg0 = popSTACK();
  processRECT(&rect,arg0);
  arg = popSTACK();
  if(!fpointerp(arg))invalid_named_argument(arg,"hwnd");
  hwnd = TheFpointer(arg)->fp_pointer;
  begin_call();
  bool0 = GetClientRect(hwnd,&rect);
  end_call();
  if(!bool0){
    do_GDI_ERROR("GetClientRect");
  }
  else
  {
      VALUES1(outputRECT(&rect, arg0));
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:GetClipBox, hdc lprect)
{
  object arg;
  int int0;
  HDC hdc;
  RECT* lprect = alloca(sizeof(RECT));
  object arg0;
  arg0 = popSTACK();
  processRECT(lprect,arg0);
  getHDC(hdc,arg);

  begin_system_call();
  int0 = GetClipBox(hdc,lprect);
  end_system_call();
  if(0 <=int0){
    do_GDI_ERROR("GetClipBox");
  }
  else
  {
    value1 = outputRECT(lprect,arg0);
    value2 = sint32_to_I(int0);
    mv_count=2;
  }
  return;
}
// untested - was never called
// removed lpcoloradjustment
DEFUN( GDI:GetColorAdjustment, hdc lpcoloradjustment)
{
  BOOL bool0;
  HDC hdc;
  COLORADJUSTMENT coloradjustment;
  object arg,arg0;

  getHDC(hdc,arg);
  begin_system_call();
  bool0 = GetColorAdjustment(hdc,&coloradjustment);
  end_system_call();
  if(!bool0){
    do_GDI_ERROR("GetColorAdjustment");
  }
  else
  {
    VALUES1(outputCOLORADJUSTMENT(&coloradjustment,arg0));
  }
  return;
}
// untested - was never called
DEFUN( GDI:GetCurrentPositionEx, hdc)
{
  object arg;
  BOOL bool0;
  HDC hdc;
  POINT point;
  getHDC(hdc,arg);
  begin_system_call();
  bool0 = GetCurrentPositionEx(hdc,&point);
  end_system_call();
  if(!bool0){
    do_GDI_ERROR("GetCurrentPositionEx");

  }
  else
  {
    VALUES2(uint32_to_I(point.x),uint32_to_I(point.y));
  }
  return;
}
// untested - was never called
DEFUN( GDI:GetDCOrgEx, hdc lppoint)
{
  object arg,arg0;
  BOOL bool0;
  HDC hdc;
  POINT* lppoint = alloca(sizeof(POINT));
  arg0 = popSTACK();
  processPOINT(lppoint,arg0);
  getHDC(hdc,arg);
  begin_system_call();
  bool0 = GetDCOrgEx(hdc,lppoint);
  end_system_call();
  if(!bool0){
    do_GDI_ERROR("GetDCOrgEx");

  }
  else
  {
    //VALUES2(lppoint->x, lppoint->y);
    VALUES1(outputPOINT(lppoint,arg0));
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
// TODO: output RGBQUAD_C
DEFUN( GDI:GetDIBColorTable, hdc uint uint0 rgbquad_p)
{
  object arg;
  UINT uint1;
  HDC hdc;
  UINT uint;
  UINT uint0;
  RGBQUAD* rgbquad_p;
  object arg0;
  arg0 = popSTACK();
  //processRGBQUAD_C(rgbquad_p,arg0,1);
  processFPTYPE(RGBQUAD*,rgbquad_p,arg0);
  uint0 = I_to_uint32(check_uint(popSTACK()));
  uint = I_to_uint32(check_uint(popSTACK()));
  getHDC(hdc,arg);

  begin_system_call();
  uint1 = GetDIBColorTable(hdc,uint,uint0,rgbquad_p);
  end_system_call();
  if(!uint1){
    do_GDI_ERROR("GetDIBColorTable");

  }
  else
  {
    VALUES2(arg0,
            uint32_to_I(uint1));
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:GetDeviceGammaRamp, hdc pvoid)
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
  bool0 = GetDeviceGammaRamp(hdc,pvoid);
  end_system_call();
  if(!bool0){
    do_GDI_ERROR("GetDeviceGammaRamp");

  }
  else
  {
    VALUES1(T);
  }
  return;
}
// untested - was never called
DEFUN( GDI:GetEnhMetaFileA, lpcstr)
{
  object arg;
  HENHMETAFILE henhmetafile;
  LPCSTR lpcstr;
  arg = popSTACK();
  if(!stringp(arg))invalid_string_argument(arg);
  with_string_0(arg,encoding, lpcstr, {
    begin_system_call();
    henhmetafile = GetEnhMetaFileA(lpcstr);
  end_system_call();
  if(NULL ==henhmetafile){
    do_GDI_ERROR("GetEnhMetaFileA");

    }
    else
    {
      VALUES1(allocate_fpointer((FOREIGN)henhmetafile));
    }
  });
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:GetEnhMetaFileDescriptionA, henhmetafile uint lpstr)
{
  object arg;
  UINT uint0;
  HENHMETAFILE henhmetafile;
  UINT uint;
  LPSTR lpstr;
  arg = popSTACK();
  if(!stringp(arg))invalid_string_argument(arg);
  with_string_0(arg,encoding, lpstr, {
    uint = I_to_uint32(check_uint(popSTACK()));
    arg = popSTACK();
    if(!fpointerp(arg))invalid_argument(arg);
    henhmetafile = TheFpointer(arg)->fp_pointer;
    begin_system_call();
    uint0 = GetEnhMetaFileDescriptionA(henhmetafile,uint,lpstr);
  end_system_call();
  if(!uint0){
    do_GDI_ERROR("GetEnhMetaFileDescriptionA");

    }
    else
    {
      value1 = T;
      value2 = uint32_to_I(uint0);
      mv_count=2;
    }
  });
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:GetEnhMetaFileDescriptionW, henhmetafile uint lpwstr)
{
  object arg;
  UINT uint0;
  HENHMETAFILE henhmetafile;
  UINT uint;
  LPWSTR lpwstr;
  arg = popSTACK();
  if(!stringp(arg))invalid_string_argument(arg);
  lpwstr = WIDECHAR(arg,encoding);
  uint = I_to_uint32(check_uint(popSTACK()));
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  henhmetafile = TheFpointer(arg)->fp_pointer;
  begin_system_call();
  uint0 = GetEnhMetaFileDescriptionW(henhmetafile,uint,lpwstr);
  end_system_call();
  if(!uint0){
    do_GDI_ERROR("GetEnhMetaFileDescriptionW");

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
DEFUN( GDI:GetEnhMetaFileHeader, henhmetafile uint lpenhmetaheader)
{
  object arg;
  UINT uint0;
  HENHMETAFILE henhmetafile;
  UINT uint;
  ENHMETAHEADER* lpenhmetaheader;// = alloca(sizeof(ENHMETAHEADER));
  object arg0;
  arg0 = popSTACK();
  processFPTYPE(ENHMETAHEADER*,lpenhmetaheader,arg0);
  uint = I_to_uint32(check_uint(popSTACK()));
  arg = popSTACK();
  processFPTYPE(HENHMETAFILE,henhmetafile,arg);

  begin_system_call();
  uint0 = GetEnhMetaFileHeader(henhmetafile,uint,lpenhmetaheader);
  end_system_call();
  if(!uint0){
    do_GDI_ERROR("GetEnhMetaFileHeader");

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
/**
 * Retrieve optional palette entries from the specified enhanced metafile.
 * lppaletteentry must contain the buffer to receive cEntries PALETTEENTRY structs.
 */
// fixed
DEFUN( GDI:GetEnhMetaFilePaletteEntries, henhmetafile cEntries lppaletteentry)
{
  object arg;
  UINT uint0;
  HENHMETAFILE henhmetafile;
  UINT cEntries;
  PALETTEENTRY* lppaletteentry;
  object arg0;
  arg0 = popSTACK();
  if(!fpointerp(arg0))invalid_argument(arg0);
  lppaletteentry = TheFpointer(arg)->fp_pointer;
  cEntries = I_to_uint32(check_uint(popSTACK()));
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  henhmetafile = TheFpointer(arg)->fp_pointer;

  begin_system_call();
  uint0 = GetEnhMetaFilePaletteEntries(henhmetafile,cEntries,lppaletteentry);
  end_system_call();
  if(!uint0){
    do_GDI_ERROR("GetEnhMetaFilePaletteEntries");

  }
  else
  {
    VALUES1(uint32_to_I(uint0));
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:GetEnhMetaFilePixelFormat, henhmetafile dword pixelformatdescriptor_p)
{
  object arg;
  UINT uint;
  HENHMETAFILE henhmetafile;
  DWORD dword;
  PIXELFORMATDESCRIPTOR* pixelformatdescriptor_p = alloca(sizeof(PIXELFORMATDESCRIPTOR));
  object arg0;
  arg0 = popSTACK();
  processPIXELFORMATDESCRIPTOR(pixelformatdescriptor_p,arg0);
  dword = I_to_uint32(check_uint(popSTACK()));
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  henhmetafile = TheFpointer(arg)->fp_pointer;

  begin_system_call();
  uint = GetEnhMetaFilePixelFormat(henhmetafile,dword,pixelformatdescriptor_p);
  end_system_call();
  if(!uint){
    do_GDI_ERROR("GetEnhMetaFilePixelFormat");

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
DEFUN( GDI:GetEnhMetaFileW, lpcwstr)
{
  object arg;
  HENHMETAFILE henhmetafile;
  LPCWSTR lpcwstr;
  arg = popSTACK();
  if(!stringp(arg))invalid_string_argument(arg);
  lpcwstr = WIDECHAR(arg,encoding);
  begin_system_call();
  henhmetafile = GetEnhMetaFileW(lpcwstr);
  end_system_call();
  if(NULL ==henhmetafile){
    do_GDI_ERROR("GetEnhMetaFileW");

  }
  else
  {
    
      VALUES1(allocate_fpointer((FOREIGN)henhmetafile));
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:GetFontData, hdc dword dword0 pvoid dword1)
{
  object arg;
  DWORD dword2;
  HDC hdc;
  DWORD dword;
  DWORD dword0;
  void* pvoid;
  DWORD dword1;
  dword1 = I_to_uint32(check_uint(popSTACK()));
  arg = popSTACK();
  if(!simple_bit_vector_p(Atype_8Bit,arg))invalid_argument(arg);
  pvoid = &(TheSbvector(arg)->data);
  dword0 = I_to_uint32(check_uint(popSTACK()));
  dword = I_to_uint32(check_uint(popSTACK()));
  getHDC(hdc,arg);
  begin_system_call();
  dword2 = GetFontData(hdc,dword,dword0,pvoid,dword1);
  end_system_call();
  if(!dword2){
    do_GDI_ERROR("GetFontData");

  }
  else
  {
    value1 = T;
    value2 = uint32_to_I(dword2);
    mv_count=2;
  }
  return;
}
// untested - was never called
// changed to return lpdword as integer also
DEFUN( GDI:GetICMProfileA, hdc lpdword lpstr)
{
  object arg;
  BOOL bool0;
  HDC hdc;
  LPDWORD lpdword;
  LPSTR lpstr;
  arg = popSTACK();
  if(!stringp(arg))invalid_string_argument(arg);
  with_string_0(arg,encoding, lpstr, {
    arg = popSTACK();
    if(!fpointerp(arg))invalid_argument(arg);
    lpdword = TheFpointer(arg)->fp_pointer;
    arg = popSTACK();
    if(!fpointerp(arg))invalid_argument(arg);
    hdc = TheFpointer(arg)->fp_pointer;
    begin_system_call();
    bool0 = GetICMProfileA(hdc,lpdword,lpstr);
  end_system_call();
  if(!bool0){
    do_GDI_ERROR("GetICMProfileA");

    }
    else
    {
      value1 = T;
      value2 = uint32_to_I(*lpdword);
      value3 = asciz_to_string(lpstr,encoding);
    }
  });
  return;
}
// untested - was never called
// requires a S16string as lpwstr
// changed to return lpdword as integer also
extern object allocate_s16string (uintL len);
DEFUN( GDI:GetICMProfileW, hdc lpdword lpwstr)
{
  object arg;
  BOOL bool0;
  HDC hdc;
  LPDWORD lpdword;
  LPWSTR lpwstr;
  arg = popSTACK();
  if(!stringp(arg))invalid_string_argument(arg);
  lpwstr = WIDECHAR(arg,encoding);
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  lpdword = TheFpointer(arg)->fp_pointer;
  getHDC(hdc,arg);
  begin_system_call();
  bool0 = GetICMProfileW(hdc,lpdword,lpwstr);
  end_system_call();
  if(!bool0){
    do_GDI_ERROR("GetICMProfileW");

  }
  else
  {
    value1 = T;
    value2 = uint32_to_I(*lpdword);
    /* FIXME */
    //value3 = allocate_s16string(lstrlenW(lpwstr));
    //TheS16string(value3)->data = (void*)lpwstr;
    mv_count=2;
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:GetKerningPairsA, hdc dword lpkerningpair)
{
  object arg;
  DWORD dword0;
  HDC hdc;
  DWORD dword;
  KERNINGPAIR* lpkerningpair;// = alloca(sizeof(KERNINGPAIR));
  object arg0;
  arg0 = popSTACK();
  processFPTYPE(KERNINGPAIR*,lpkerningpair,arg0);
  dword = I_to_uint32(check_uint(popSTACK()));
  getHDC(hdc,arg);

  begin_system_call();
  dword0 = GetKerningPairsA(hdc,dword,lpkerningpair);
  end_system_call();
  if(!dword0){
    do_GDI_ERROR("GetKerningPairsA");
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
DEFUN( GDI:GetKerningPairsW, hdc dword lpkerningpair)
{
  object arg;
  DWORD dword0;
  HDC hdc;
  DWORD dword;
  KERNINGPAIR* lpkerningpair;// = alloca(sizeof(KERNINGPAIR));
  object arg0;
  arg0 = popSTACK();
  processFPTYPE(KERNINGPAIR*,lpkerningpair,arg0);
  dword = I_to_uint32(check_uint(popSTACK()));
  getHDC(hdc,arg);

  begin_system_call();
  dword0 = GetKerningPairsW(hdc,dword,lpkerningpair);
  end_system_call();
  if(!dword0){
    do_GDI_ERROR("GetKerningPairsW");

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
DEFUN( GDI:GetLogColorSpaceA, hcolorspace lplogcolorspacea dword)
{
  object arg;
  BOOL bool0;
  HCOLORSPACE hcolorspace;
  LOGCOLORSPACEA* lplogcolorspacea;// = alloca(sizeof(LOGCOLORSPACEA));
  object arg0;
  DWORD dword;
  dword = I_to_uint32(check_uint(popSTACK()));
  arg0 = popSTACK();
  processFPTYPE(LOGCOLORSPACEA*,lplogcolorspacea,arg0);
  arg = popSTACK();
  processFPTYPE(HCOLORSPACE,hcolorspace,arg);

  begin_system_call();
  bool0 = GetLogColorSpaceA(hcolorspace,lplogcolorspacea,dword);
  end_system_call();
  if(!bool0){
    do_GDI_ERROR("GetLogColorSpaceA");

  }
  else
  {
    VALUES1(T);
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:GetLogColorSpaceW, hcolorspace lplogcolorspacew dword)
{
  object arg;
  BOOL bool0;
  HCOLORSPACE hcolorspace;
  LOGCOLORSPACEW* lplogcolorspacew;// = alloca(sizeof(LOGCOLORSPACEW));
  object arg0;
  DWORD dword;
  dword = I_to_uint32(check_uint(popSTACK()));
  arg0 = popSTACK();
  processFPTYPE(LOGCOLORSPACEW*,lplogcolorspacew,arg0);
  arg = popSTACK();
  processFPTYPE(HCOLORSPACE,hcolorspace,arg);

  begin_system_call();
  bool0 = GetLogColorSpaceW(hcolorspace,lplogcolorspacew,dword);
  end_system_call();
  if(!bool0){
    do_GDI_ERROR("GetLogColorSpaceW");

  }
  else
  {
    VALUES1(T);
  }
  return;
}
// untested - was never called
DEFUN( GDI:GetMetaFileA, lpcstr)
{
  object arg;
  HMETAFILE hmetafile;
  LPCSTR lpcstr;
  arg = popSTACK();
  if(!stringp(arg))invalid_string_argument(arg);
  with_string_0(arg,encoding, lpcstr, {
    begin_system_call();
    hmetafile = GetMetaFileA(lpcstr);
  end_system_call();
  if(NULL ==hmetafile){
    do_GDI_ERROR("GetMetaFileA");

    }
    else
    {
      VALUES1(allocate_fpointer((FOREIGN)hmetafile));
    }
  });
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:GetMetaFileBitsEx, hmetafile uint pvoid)
{
  object arg;
  UINT uint0;
  HMETAFILE hmetafile;
  UINT uint;
  void* pvoid;
  arg = popSTACK();
  if(!simple_bit_vector_p(Atype_8Bit,arg))invalid_argument(arg);
  pvoid = &(TheSbvector(arg)->data);
  uint = I_to_uint32(check_uint(popSTACK()));
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hmetafile = TheFpointer(arg)->fp_pointer;
  begin_system_call();
  uint0 = GetMetaFileBitsEx(hmetafile,uint,pvoid);
  end_system_call();
  if(!uint0){
    do_GDI_ERROR("GetMetaFileBitsEx");

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
DEFUN( GDI:GetMetaFileW, lpcwstr)
{
  object arg;
  HMETAFILE hmetafile;
  LPCWSTR lpcwstr;
  arg = popSTACK();
  if(!stringp(arg))invalid_string_argument(arg);
  lpcwstr = WIDECHAR(arg,encoding);
  begin_system_call();
  hmetafile = GetMetaFileW(lpcwstr);
  end_system_call();
  if(NULL ==hmetafile){
    do_GDI_ERROR("GetMetaFileW");

  }
  else
  {
      VALUES1(allocate_fpointer((FOREIGN)hmetafile));
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:GetObjectA, hgdiobj int0 pvoid)
{
  object arg;
  int int1;
  HGDIOBJ hgdiobj;
  int int0;
  void* pvoid;
  arg = popSTACK();
  if(!simple_bit_vector_p(Atype_8Bit,arg))invalid_argument(arg);
  pvoid = &(TheSbvector(arg)->data);
  int0 = I_to_sint32(check_sint(popSTACK()));
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hgdiobj = TheFpointer(arg)->fp_pointer;
  begin_system_call();
  int1 = GetObjectA(hgdiobj,int0,pvoid);
  end_system_call();
  if(0 <=int1){
    do_GDI_ERROR("GetObjectA");

  }
  else
  {
    VALUES1(sint32_to_I(int1));
  }
  return;
}
// untested - was never called
DEFUN( GDI:GetObjectW, hgdiobj int0 pvoid)
{
  object arg;
  int int1;
  HGDIOBJ hgdiobj;
  int int0;
  void* pvoid;
  arg = popSTACK();
  if(!simple_bit_vector_p(Atype_8Bit,arg))invalid_argument(arg);
  pvoid = &(TheSbvector(arg)->data);
  int0 = I_to_sint32(check_sint(popSTACK()));
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hgdiobj = TheFpointer(arg)->fp_pointer;
  begin_system_call();
  int1 = GetObjectW(hgdiobj,int0,pvoid);
  end_system_call();
  if(0 <=int1){
    do_GDI_ERROR("GetObjectW");

  }
  else
  {
    VALUES1(sint32_to_I(int1));
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:GetOutlineTextMetricsA, hdc uint lpoutlinetextmetrica)
{
  object arg;
  UINT uint0;
  HDC hdc;
  UINT uint;
  OUTLINETEXTMETRICA* lpoutlinetextmetrica;// = alloca(sizeof(OUTLINETEXTMETRICA));
  object arg0;
  arg0 = popSTACK();
  processFPTYPE(OUTLINETEXTMETRICA*,lpoutlinetextmetrica,arg0);
  uint = I_to_uint32(check_uint(popSTACK()));
  getHDC(hdc,arg);

  begin_system_call();
  uint0 = GetOutlineTextMetricsA(hdc,uint,lpoutlinetextmetrica);
  end_system_call();
  if(!uint0){
    do_GDI_ERROR("GetOutlineTextMetricsA");

  }
  else
  {
    VALUES1(uint32_to_I(uint0));
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:GetOutlineTextMetricsW, hdc uint lpoutlinetextmetricw)
{
  object arg;
  UINT uint0;
  HDC hdc;
  UINT uint;
  OUTLINETEXTMETRICW* lpoutlinetextmetricw;// = alloca(sizeof(OUTLINETEXTMETRICW));
  object arg0;
  arg0 = popSTACK();
  processFPTYPE(OUTLINETEXTMETRICW*,lpoutlinetextmetricw,arg0);
  uint = I_to_uint32(check_uint(popSTACK()));
  getHDC(hdc,arg);

  begin_system_call();
  uint0 = GetOutlineTextMetricsW(hdc,uint,lpoutlinetextmetricw);
  end_system_call();
  if(!uint0){
    do_GDI_ERROR("GetOutlineTextMetricsW");

  }
  else
  {
    VALUES1(uint32_to_I(uint0));
  }
  return;
}
// untested - was never called
/**
 * Retrieve a specified range of palette entries from the given logical palette.
 * lppaletteentry must contain the buffer to receive cEntries PALETTEENTRY structs.
 */
// fixed
DEFUN( GDI:GetPaletteEntries, hpalette iStartIndex cEntries lppaletteentry)
{
  object arg;
  UINT uint1;
  HPALETTE hpalette;
  UINT iStartIndex, cEntries;
  PALETTEENTRY* lppaletteentry;
  object arg0;
  arg0 = popSTACK();
  processFPTYPE(PALETTEENTRY*,lppaletteentry,arg0);
  cEntries = I_to_uint32(check_uint(popSTACK()));
  iStartIndex = I_to_uint32(check_uint(popSTACK()));
  arg = popSTACK();
  processFPTYPE(HPALETTE,hpalette,arg0);

  begin_system_call();
  uint1 = GetPaletteEntries(hpalette,iStartIndex,cEntries,lppaletteentry);
  end_system_call();
  if(!uint1){
    do_GDI_ERROR("GetPaletteEntries");

  }
  else
  {
    VALUES1(uint32_to_I(uint1));
  }
  return;
}
// untested - was never called
// return vector of point records?
// See GDI:FlattenPath
DEFUN( GDI:GetPath, hdc lppoint pbyte int0)
{
  object arg;
  int int1;
  HDC hdc;
  POINT* lppoint = alloca(sizeof(POINT));
  object arg0;
  PBYTE pbyte;
  int int0;
  int0 = I_to_sint32(check_sint(popSTACK()));
  arg0 = popSTACK();
  processPBYTE(pbyte,arg0);
  arg0 = popSTACK();
  processPOINT(lppoint,arg0);
  getHDC(hdc,arg);

  begin_system_call();
  int1 = GetPath(hdc,lppoint,pbyte,int0);
  end_system_call();
  if(0 <=int1){
    do_GDI_ERROR("GetPath");

  }
  else
  {
    VALUES1(sint32_to_I(int1));
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:GetRasterizerCaps, lprasterizer_status uint)
{
  object arg;
  BOOL bool0;
  RASTERIZER_STATUS* lprasterizer_status;// = alloca(sizeof(RASTERIZER_STATUS));
  object arg0;
  UINT uint;
  uint = I_to_uint32(check_uint(popSTACK()));
  arg0 = popSTACK();
  processFPTYPE(RASTERIZER_STATUS*,lprasterizer_status,arg0);

  begin_system_call();
  bool0 = GetRasterizerCaps(lprasterizer_status,uint);
  end_system_call();
  if(!bool0){
    do_GDI_ERROR("GetRasterizerCaps");

  }
  else
  {
    VALUES1(T);
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:GetRegionData, hrgn dword lprgndata)
{
  object arg;
  DWORD dword0;
  HRGN hrgn;
  DWORD dword;
  RGNDATA* lprgndata;// = alloca(sizeof(RGNDATA));
  object arg0;
  arg0 = popSTACK();
  processFPTYPE(RGNDATA*,lprgndata,arg0);
  dword = I_to_uint32(check_uint(popSTACK()));
  arg = popSTACK();
  processFPTYPE(HRGN,hrgn,arg0);

  begin_system_call();
  dword0 = GetRegionData(hrgn,dword,lprgndata);
  end_system_call();
  if(!dword0){
    do_GDI_ERROR("GetRegionData");

  }
  else
  {
    VALUES1(uint32_to_I(dword0));
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:GetRgnBox, hrgn lprect)
{
  object arg;
  int int0;
  HRGN hrgn;
  RECT* lprect = alloca(sizeof(RECT));
  object arg0;
  arg0 = popSTACK();
  processRECT(lprect,arg0);
  arg = popSTACK();
  processFPTYPE(HRGN,hrgn,arg0);

  begin_system_call();
  int0 = GetRgnBox(hrgn,lprect);
  end_system_call();
  if(0 <=int0){
    do_GDI_ERROR("GetRgnBox");

  }
  else
  {
    VALUES1(sint32_to_I(int0));
  }
  return;
}
// untested - was never called
/**
 * Retrieves a range of palette entries from the system palette that is associated 
 * with the specified device context.
 *
 * lppaletteentry must contain the buffer to receive cEntries PALETTEENTRY structs.
 * If this parameter is C-PTR-NULL, the function returns the total number of entries 
 * in the palette.
 */
DEFUN( GDI:GetSystemPaletteEntries, hdc iStartIndex cEntries lppaletteentry)
{
  object arg;
  UINT uint1;
  HDC hdc;
  UINT iStartIndex, cEntries;
  PALETTEENTRY* lppaletteentry;
  object arg0;
  arg0 = popSTACK();
  processFPTYPE(PALETTEENTRY*,lppaletteentry,arg0);
  cEntries = I_to_uint32(check_uint(popSTACK()));
  iStartIndex = I_to_uint32(check_uint(popSTACK()));
  getHDC(hdc,arg);

  begin_system_call();
  uint1 = GetSystemPaletteEntries(hdc,iStartIndex,cEntries,lppaletteentry);
  end_system_call();
  if(!uint1){
    do_GDI_ERROR("GetSystemPaletteEntries");

  }
  else
  {
    VALUES1(uint32_to_I(uint1));
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:GetTextCharsetInfo, hdc lpfontsignature dword)
{
  object arg;
  int int0;
  HDC hdc;
  FONTSIGNATURE* lpfontsignature;// = alloca(sizeof(FONTSIGNATURE));
  object arg0;
  DWORD dword;
  dword = I_to_uint32(check_uint(popSTACK()));
  arg0 = popSTACK();
  processFPTYPE(FONTSIGNATURE*,lpfontsignature,arg0);
  getHDC(hdc,arg);

  begin_system_call();
  int0 = GetTextCharsetInfo(hdc,lpfontsignature,dword);
  end_system_call();
  if(0 <=int0){
    do_GDI_ERROR("GetTextCharsetInfo");

  }
  else
  {
    VALUES1(sint32_to_I(int0));
  }
  return;
}
// untested - was never called
DEFUN( GDI:GetTextExtentPoint32A, hdc lpcstr)
{
  object arg, arg0;
  BOOL bool0;
  HDC hdc;
  LPCSTR lpcstr;
  SIZE lpsize;
  arg = popSTACK();
  if(!stringp(arg))invalid_string_argument(arg);
  with_string_0(arg,encoding, lpcstr, {
    getHDC(hdc,arg0);
    begin_system_call();
    bool0 = GetTextExtentPoint32A(hdc,lpcstr,Sstring_length(arg),&lpsize);
    end_system_call();
    if(!bool0){
      do_GDI_ERROR("GetTextExtentPoint32A");
    }
    else
    {
      VALUES2(uint32_to_I(lpsize.cx), uint32_to_I(lpsize.cy));
    }
  });
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:GetTextExtentPoint32W, hdc lpcwstr)
{
  object arg, arg0;
  BOOL bool0;
  HDC hdc;
  LPCWSTR lpcwstr;
  SIZE size;
  arg = popSTACK();
  if(!stringp(arg))invalid_string_argument(arg);
  lpcwstr = WIDECHAR(arg,encoding);
  getHDC(hdc,arg0);

  begin_system_call();
  bool0 = GetTextExtentPoint32W(hdc,lpcwstr,Sstring_length(arg),&size);
  end_system_call();
  if(!bool0){
    do_GDI_ERROR("GetTextExtentPoint32W");
  }
  else
  {
    VALUES2(uint32_to_I(size.cx), uint32_to_I(size.cy));
  }
  return;
}
/*
// untested - was never called
// deprecated
DEFUN( GDI:GetTextExtentPointA, hdc lpcstr int0 lpsize)
{
  object arg;
  BOOL bool0;
  HDC hdc;
  LPCSTR lpcstr;
  int int0;
  SIZE* lpsize = alloca(sizeof(SIZE));
  object arg0;
  arg0 = popSTACK();
  processSIZE(lpsize,arg0);
  int0 = I_to_sint32(check_sint(popSTACK()));
  arg = popSTACK();
  if(!stringp(arg))invalid_string_argument(arg);
  with_string_0(arg,encoding, lpcstr, {
  getHDC(hdc,arg);

  begin_system_call();
  bool0 = GetTextExtentPointA(hdc,lpcstr,int0,lpsize);
  end_system_call();
  if(!bool0){
    do_GDI_ERROR("GetTextExtentPointA");
  }
  else
  {
    VALUES1(T);
  }
  });
  return;
}
// untested - was never called
DEFUN( GDI:GetTextExtentPointW, hdc lpcwstr int0 lpsize)
{
  object arg;
  BOOL bool0;
  HDC hdc;
  LPCWSTR lpcwstr;
  int int0;
  SIZE* lpsize = alloca(sizeof(SIZE));
  object arg0;
  arg0 = popSTACK();
  processSIZE(lpsize,arg0);
  int0 = I_to_sint32(check_sint(popSTACK()));
  arg = popSTACK();
  if(!stringp(arg))invalid_string_argument(arg);
  lpcwstr = WIDECHAR(arg,encoding);
  getHDC(hdc,arg);

  begin_system_call();
  bool0 = GetTextExtentPointW(hdc,lpcwstr,int0,lpsize);
  end_system_call();
  if(!bool0){
    do_GDI_ERROR("GetTextExtentPointW");
  }
  else
  {
    VALUES1(T);
  }
  return;
}
*/
// untested - was never called
DEFUN( GDI:GetTextFaceA, hdc)
{
  object arg;
  int nCount;
  HDC hdc;
  int int0;
  LPSTR lpstr;
  getHDC(hdc,arg);
  begin_system_call();
  nCount = GetTextFaceA(hdc,0,NULL);
  end_system_call();
  if(0 <=nCount){
    do_GDI_ERROR("GetTextFaceA");
  }
  else
  {
    lpstr = (LPSTR)alloca(nCount);
    int0 = GetTextFaceA(hdc,nCount,lpstr);
    end_system_call();
    if(0 <=int0){
      do_GDI_ERROR("GetTextFaceA");
    }
    else {
      VALUES1(asciz_to_string(lpstr,encoding));
    }
  }
  return;
}
// untested - was never called
DEFUN( GDI:GetTextFaceW, hdc)
{
  object arg;
  int nCount;
  HDC hdc;
  int int0;
  LPWSTR lpwstr;
  getHDC(hdc,arg);
  begin_system_call();
  nCount = GetTextFaceW(hdc,0,NULL);
  end_system_call();
  if(0 <=nCount){
    do_GDI_ERROR("GetTextFaceW");
  }
  else
  {
    lpwstr = (LPWSTR)alloca(nCount);
    int0 = GetTextFaceW(hdc,nCount,lpwstr);
    end_system_call();
    if(0 <=int0){
      do_GDI_ERROR("GetTextFaceW");
    }
    else {
      VALUES1(outputLPWSTR(lpwstr,nCount));
    }
  }
  return;
}
// untested - was never called
DEFUN( GDI:GetTextMetricsA, hdc lptextmetrica)
{
  object arg,arg0;
  BOOL bool0;
  HDC hdc;
  TEXTMETRICA *lptextmetrica = alloca(sizeof(TEXTMETRICA));
  arg0 = popSTACK();
  processFPTYPE(TEXTMETRICA*,lptextmetrica,arg0);
  getHDC(hdc,arg);
  begin_system_call();
  bool0 = GetTextMetricsA(hdc,lptextmetrica);
  end_system_call();
  if(!bool0){
    do_GDI_ERROR("GetTextMetricsA");
  }
  else
  {
    VALUES1(outputTEXTMETRICA(lptextmetrica,arg0));
  }
  return;
}
// untested - was never called
DEFUN( GDI:GetTextMetricsW, hdc lptextmetricw)
{
  object arg,arg0;
  BOOL bool0;
  HDC hdc;
  TEXTMETRICW *lptextmetricw = alloca(sizeof(TEXTMETRICW));
  arg0 = popSTACK();
  processFPTYPE(TEXTMETRICW*,lptextmetricw,arg0);
  getHDC(hdc,arg);

  begin_system_call();
  bool0 = GetTextMetricsW(hdc,lptextmetricw);
  end_system_call();
  if(!bool0){
    do_GDI_ERROR("GetTextMetricsW");
  }
  else
  {
    VALUES1(outputTEXTMETRICW(lptextmetricw,arg0));
  }
  return;
}
// untested - was never called
DEFUN( GDI:GetViewportExtEx, hdc)
{
  object arg;
  BOOL bool0;
  HDC hdc;
  SIZE size;
  getHDC(hdc,arg);

  begin_system_call();
  bool0 = GetViewportExtEx(hdc,&size);
  end_system_call();
  if(!bool0){
    do_GDI_ERROR("GetViewportExtEx");
  }
  else
  {
    VALUES2(uint32_to_I(size.cx), uint32_to_I(size.cy));
  }
  return;
}
// untested - was never called
DEFUN( GDI:GetViewportOrgEx, hdc)
{
  object arg;
  BOOL bool0;
  HDC hdc;
  POINT point;
  //object arg0;
  //arg0 = popSTACK();
  //processPOINT(&point,arg0);
  getHDC(hdc,arg);

  begin_system_call();
  bool0 = GetViewportOrgEx(hdc,&point);
  end_system_call();
  if(!bool0){
    do_GDI_ERROR("GetViewportOrgEx");
  }
  else
  {
    VALUES2(fixnum(point.x), fixnum(point.y));
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:GetWinMetaFileBits, henhmetafile uint lpbyte int0 hdc)
{
  object arg;
  UINT uint0;
  HENHMETAFILE henhmetafile;
  UINT uint;
  BYTE* lpbyte = alloca(sizeof(BYTE));
  object arg0;
  INT int0;
  HDC hdc;
  getHDC(hdc,arg);
  int0 = I_to_sint32(check_sint(popSTACK()));
  arg0 = popSTACK();
  processBYTE(lpbyte,arg0);
  uint = I_to_uint32(check_uint(popSTACK()));
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  henhmetafile = TheFpointer(arg)->fp_pointer;

  begin_system_call();
  uint0 = GetWinMetaFileBits(henhmetafile,uint,lpbyte,int0,hdc);
  end_system_call();
  if(!uint0){
    do_GDI_ERROR("GetWinMetaFileBits");

  }
  else
  {
    VALUES1(uint32_to_I(uint0));
  }
  return;
}
// untested - was never called
DEFUN( GDI:GetWindowExtEx, hdc)
{
  object arg;
  BOOL bool0;
  HDC hdc;
  SIZE size;
  //object arg0;
  //arg0 = popSTACK();
  //processSIZE(lpsize,arg0);
  getHDC(hdc,arg);

  begin_system_call();
  bool0 = GetWindowExtEx(hdc,&size);
  end_system_call();
  if(!bool0){
    do_GDI_ERROR("GetWindowExtEx");

  }
  else
  {
    VALUES2(uint32_to_I(size.cx), uint32_to_I(size.cy));
    //VALUES1(outputLPSIZE(lpsize));
  }
  return;
}
// untested - was never called
DEFUN( GDI:GetWindowOrgEx, hdc)
{
  object arg;
  BOOL bool0;
  HDC hdc;
  POINT point;
  getHDC(hdc,arg);
  begin_system_call();
  bool0 = GetWindowOrgEx(hdc,&point);
  end_system_call();
  if(!bool0){
    do_GDI_ERROR("GetWindowOrgEx");
  }
  else
  {
    VALUES2(uint32_to_I(point.x), uint32_to_I(point.y));
    //VALUES1(outputPOINT(lppoint));
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:GetWorldTransform, hdc lpxform)
{
  object arg;
  BOOL bool0;
  HDC hdc;
  XFORM* lpxform = alloca(sizeof(XFORM));
  object arg0;
  arg0 = popSTACK();
  processXFORM(lpxform,arg0);
  getHDC(hdc,arg);

  begin_system_call();
  bool0 = GetWorldTransform(hdc,lpxform);
  end_system_call();
  if(!bool0){
    do_GDI_ERROR("GetWorldTransform");
  }
  else
  {
    VALUES1(outputXFORM(lpxform,arg0));
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:Escape, hdc int0 int1 lpcstr pvoid)
{
  object arg;
  int int2;
  HDC hdc;
  int int0;
  int int1;
  LPCSTR lpcstr;
  void* pvoid;
  arg = popSTACK();
  if(!simple_bit_vector_p(Atype_8Bit,arg))invalid_argument(arg);
  pvoid = &(TheSbvector(arg)->data);
  arg = popSTACK();
  if(!stringp(arg))invalid_string_argument(arg);
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
    int2 = Escape(hdc,int0,int1,lpcstr,pvoid);
    end_system_call();
    if(0 <=int2){
      do_GDI_ERROR("Escape");
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
/*
DEFUN( GDI:SetAbortProc, hdc abortproc)
{
  object arg;
  int int0;
  HDC hdc;
  ABORTPROC abortproc;
  arg0 = popSTACK();
  processABORTPROC(abortproc,arg0);
  getHDC(hdc,arg);
  begin_system_call();
  int0 = SetAbortProc(hdc,abortproc);
  end_system_call();
  if(0 <=int0){
    do_GDI_ERROR("SetAbortProc");

  }
  else
  {
    value1 = T;
    value2 = sint32_to_I(int0);
    mv_count=2;
  }
  return;
}
*/
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:GetCharWidthFloatA, hdc uint uint0)
{
  object arg;
  BOOL bool0;
  HDC hdc;
  UINT uint;
  UINT uint0;
  UINT length;
  FLOAT* pfloat;
  uint0 = I_to_uint32(check_uint(popSTACK()));
  uint = I_to_uint32(check_uint(popSTACK()));
  getHDC(hdc,arg);
  length = uint0 - uint + 1;
  pfloat = alloca(sizeof(FLOAT)*length);
  begin_system_call();
  bool0 = GetCharWidthFloatA(hdc,uint,uint0,pfloat);
  end_system_call();
  if(!bool0){
    do_GDI_ERROR("GetCharWidthFloatA");
  }
  else
  {
    VALUES1(outputFLOATS(pfloat,length));
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:GetCharWidthFloatW, hdc uint uint0 pfloat)
{
  object arg;
  BOOL bool0;
  HDC hdc;
  UINT uint;
  UINT uint0;
  FLOAT* pfloat;
  uint0 = I_to_uint32(check_uint(popSTACK()));
  uint = I_to_uint32(check_uint(popSTACK()));
  getHDC(hdc,arg);
  pfloat = alloca(sizeof(FLOAT)*(uint0 - uint + 1));
  begin_system_call();
  bool0 = GetCharWidthFloatW(hdc,uint,uint0,pfloat);
  end_system_call();
  if(!bool0){
    do_GDI_ERROR("GetCharWidthFloatW");
  }
  else
  {
    VALUES1(outputFLOATS(pfloat,0));
  }
  return;
}

//extern object allocate_ffloat (ffloat value);

// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:GetMiterLimit, hdc pfloat)
{
  object arg;
  BOOL bool0;
  HDC hdc;
  FLOAT pfloat;
  getHDC(hdc,arg);
  begin_system_call();
  bool0 = GetMiterLimit(hdc,&pfloat);
  end_system_call();
  if(!bool0){
    do_GDI_ERROR("GetMiterLimit");
  }
  else
  {
    VALUES1(allocate_ffloat(pfloat));
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:SetMiterLimit, hdc float0)
{
  object arg;
  BOOL bool0;
  HDC hdc;
  FLOAT float0;
  FLOAT pfloat;
  ffloatjanus jfloat0;
  FF_to_c_float(check_ffloat(popSTACK()),&jfloat0);
  float0 = (float)(jfloat0.eksplicit);
  getHDC(hdc,arg);
  begin_system_call();
  bool0 = SetMiterLimit(hdc,float0,&pfloat);
  end_system_call();
  if(!bool0){
    do_GDI_ERROR("SetMiterLimit");
  }
  else
  {
    VALUES1(allocate_ffloat(pfloat));
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:LineDDA, lppoint lppoint0 lineddaproc lparam)
{
  object arg;
  BOOL bool0;
  POINT point;
  POINT point0;
  LINEDDAPROC lineddaproc;
  LPARAM lparam;
  arg = popSTACK();
  check_sint(arg);
  lparam = (LPARAM)I_to_sint32(arg);
  arg = popSTACK();
  processFPTYPE(LINEDDAPROC,lineddaproc,arg);
  arg = popSTACK();
  processPOINT(&point0,arg);
  arg = popSTACK();
  processPOINT(&point,arg);
  begin_system_call();
  bool0 = LineDDA(point.x,point.y,point0.x,point0.y,lineddaproc,lparam);
  end_system_call();
  if(!bool0){
    do_GDI_ERROR("LineDDA");
  }
  else
  {
    VALUES1(T);
  }
  return;
}
// untested - was never called
// Not implemented in Windows NT
/*
DEFUN( GDI:TranslateCharsetInfo, dword_p lpcharsetinfo dword)
{
  object arg;
  BOOL bool0;
  DWORD* dword_p;
  HARSETINFO* lpcharsetinfo = alloca(sizeof(CHARSETINFO));
  object arg0;
  DWORD dword;
  dword = I_to_uint32(check_uint(popSTACK()));
  arg0 = popSTACK();
  processCHARSETINFO(lpcharsetinfo,arg0);
  arg = popSTACK();
  if(!simple_bit_vector_p(Atype_32Bit,arg))invalid_argument(arg);
  dword_p = (DWORD*)&(TheSbvector(arg)->data);

  begin_system_call();
  bool0 = TranslateCharsetInfo(dword_p,lpcharsetinfo,dword);
  end_system_call();
  if(!bool0){
    do_GDI_ERROR("TranslateCharsetInfo");
  }
  else
  {
    VALUES1(T);
  }
  return;
}
*/
