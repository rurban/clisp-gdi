#line 2 "funcs-out.c"

/* Functions that return data, therefore not T/nil as first value, 
 * but as last. Also try to return structs as structs, not just foreign pointers.
 */

// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:CheckColorsInGamut, hdc pvoid pvoid0 dword)
{
  object arg;
  BOOL bool0;
  HDC hdc;
  void* pvoid;
  void* pvoid0;
  DWORD dword;
  dword = I_to_uint32(check_uint(popSTACK()));
  arg = popSTACK();
  if(!simple_bit_vector_p(Atype_8Bit,arg))invalid_argument(arg);
  pvoid0 = &(TheSbvector(arg)->data);
  arg = popSTACK();
  if(!simple_bit_vector_p(Atype_8Bit,arg))invalid_argument(arg);
  pvoid = &(TheSbvector(arg)->data);
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hdc = TheFpointer(arg)->fp_pointer;
  begin_system_call();
  bool0 = CheckColorsInGamut(hdc,pvoid,pvoid0,dword);
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
DEFUN( GDI:CombineTransform, lpxform xform_p xform_p0)
{
  object arg0;
  BOOL bool0;
  XFORM lpxform;
  XFORM xform_p;
  XFORM xform_p0;
  arg0 = popSTACK();
  processXFORM(&xform_p0,arg0);
  arg0 = popSTACK();
  processXFORM(&xform_p,arg0);
  arg0 = popSTACK();
  begin_system_call();
  bool0 = CombineTransform(&lpxform,&xform_p,&xform_p0);
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
    outputXFORM(&lpxform,arg0); // TODO
    value1 = T;
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
  BITMAPINFO* bitmapinfo_p = alloca(sizeof(BITMAPINFO));
  UINT uint;
  void *voidp;
  HANDLE handle;
  DWORD dword;
  dword = I_to_uint32(check_uint(popSTACK()));
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  handle = (nullp(arg))?0:(TheFpointer(arg)->fp_pointer);
  uint = I_to_uint32(check_uint(popSTACK()));
  arg = popSTACK();
  processBITMAPINFO(bitmapinfo_p,arg);
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hdc = TheFpointer(arg)->fp_pointer;
  begin_system_call();
  hbitmap = CreateDIBSection(hdc,bitmapinfo_p,uint,&voidp,handle,dword);
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
    value3 = allocate_fpointer((FOREIGN)voidp);
    mv_count=3;
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
  processENHMFENUMPROC(&enhmfenumproc,arg0);
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  henhmetafile = TheFpointer(arg)->fp_pointer;
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hdc = TheFpointer(arg)->fp_pointer;
  processRECT(lpcrect,arg0);
  begin_system_call();
  bool0 = EnumEnhMetaFile(hdc,henhmetafile,enhmfenumproc,pvoid,lpcrect);
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
/*
DEFUN( GDI:EnumFontFamiliesA, hdc lpcstr fontenumproca lparam)
{
  object arg;
  int int0;
  HDC hdc;
  LPCSTR lpcstr;
  FONTENUMPROCA fontenumproca;
  ARAM* lparam = alloca(sizeof(ARAM));
  object arg0;
  arg = popSTACK();
  check_sint(arg);
  lparam = I_to_sint32(arg);
  arg0 = popSTACK();
  processFONTENUMPROCA(fontenumproca,arg0);
  arg = popSTACK();
  if(!stringp(arg))invalid_argument(arg);
  with_string_0(arg,encoding, lpcstr, {
    arg = popSTACK();
    if(!fpointerp(arg))invalid_argument(arg);
    hdc = TheFpointer(arg)->fp_pointer;
    processARAM(lparam,arg0);
    begin_system_call();
    int0 = EnumFontFamiliesA(hdc,lpcstr,fontenumproca,lparam);
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
  ARAM* lparam = alloca(sizeof(ARAM));
  object arg0;
  DWORD dword;
  dword = I_to_uint32(check_uint(popSTACK()));
  arg = popSTACK();
  check_sint(arg);
  lparam = I_to_sint32(arg);
  arg0 = popSTACK();
  processFONTENUMPROCA(fontenumproca,arg0);
  arg0 = popSTACK();
  processPLOGFONTA(plogfonta,arg0);
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hdc = TheFpointer(arg)->fp_pointer;
  processARAM(lparam,arg0);
  begin_system_call();
  int0 = EnumFontFamiliesExA(hdc,plogfonta,fontenumproca,lparam,dword);
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
DEFUN( GDI:EnumFontFamiliesExW, hdc plogfontw fontenumprocw lparam dword)
{
  object arg;
  int int0;
  HDC hdc;
  PLOGFONTW plogfontw;
  FONTENUMPROCW fontenumprocw;
  ARAM* lparam = alloca(sizeof(ARAM));
  object arg0;
  DWORD dword;
  dword = I_to_uint32(check_uint(popSTACK()));
  arg = popSTACK();
  check_sint(arg);
  lparam = I_to_sint32(arg);
  arg0 = popSTACK();
  processFONTENUMPROCW(fontenumprocw,arg0);
  arg0 = popSTACK();
  processPLOGFONTW(plogfontw,arg0);
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hdc = TheFpointer(arg)->fp_pointer;
  processARAM(lparam,arg0);
  begin_system_call();
  int0 = EnumFontFamiliesExW(hdc,plogfontw,fontenumprocw,lparam,dword);
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
DEFUN( GDI:EnumFontFamiliesW, hdc lpcwstr fontenumprocw lparam)
{
  object arg;
  int int0;
  HDC hdc;
  LPCWSTR lpcwstr;
  FONTENUMPROCW fontenumprocw;
  ARAM* lparam = alloca(sizeof(ARAM));
  object arg0;
  arg = popSTACK();
  check_sint(arg);
  lparam = I_to_sint32(arg);
  arg0 = popSTACK();
  processFONTENUMPROCW(fontenumprocw,arg0);
  arg = popSTACK();
  if(!stringp(arg))invalid_argument(arg);
  lpcwstr = WIDECHAR(arg,encoding);
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hdc = TheFpointer(arg)->fp_pointer;
  processARAM(lparam,arg0);
  begin_system_call();
  int0 = EnumFontFamiliesW(hdc,lpcwstr,fontenumprocw,lparam);
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
DEFUN( GDI:EnumFontsA, hdc lpcstr fontenumproca lparam)
{
  object arg;
  int int0;
  HDC hdc;
  LPCSTR lpcstr;
  FONTENUMPROCA fontenumproca;
  ARAM* lparam = alloca(sizeof(ARAM));
  object arg0;
  arg = popSTACK();
  check_sint(arg);
  lparam = I_to_sint32(arg);
  arg0 = popSTACK();
  processFONTENUMPROCA(fontenumproca,arg0);
  arg = popSTACK();
  if(!stringp(arg))invalid_argument(arg);
  with_string_0(arg,encoding, lpcstr, {
    arg = popSTACK();
    if(!fpointerp(arg))invalid_argument(arg);
    hdc = TheFpointer(arg)->fp_pointer;
    processARAM(lparam,arg0);
    begin_system_call();
    int0 = EnumFontsA(hdc,lpcstr,fontenumproca,lparam);
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
  });
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:EnumFontsW, hdc lpcwstr fontenumproca lparam)
{
  object arg;
  int int0;
  HDC hdc;
  LPCWSTR lpcwstr;
  FONTENUMPROCA fontenumproca;
  ARAM* lparam = alloca(sizeof(ARAM));
  object arg0;
  arg = popSTACK();
  check_sint(arg);
  lparam = I_to_sint32(arg);
  arg0 = popSTACK();
  processFONTENUMPROCA(fontenumproca,arg0);
  arg = popSTACK();
  if(!stringp(arg))invalid_argument(arg);
  lpcwstr = WIDECHAR(arg,encoding);
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hdc = TheFpointer(arg)->fp_pointer;
  processARAM(lparam,arg0);
  begin_system_call();
  int0 = EnumFontsW(hdc,lpcwstr,fontenumproca,lparam);
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
DEFUN( GDI:EnumICMProfilesA, hdc icmenumproca lparam)
{
  object arg;
  int int0;
  HDC hdc;
  ICMENUMPROCA icmenumproca;
  ARAM* lparam = alloca(sizeof(ARAM));
  object arg0;
  arg = popSTACK();
  check_sint(arg);
  lparam = I_to_sint32(arg);
  arg0 = popSTACK();
  processICMENUMPROCA(icmenumproca,arg0);
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hdc = TheFpointer(arg)->fp_pointer;
  processARAM(lparam,arg0);
  begin_system_call();
  int0 = EnumICMProfilesA(hdc,icmenumproca,lparam);
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
DEFUN( GDI:EnumICMProfilesW, hdc icmenumprocw lparam)
{
  object arg;
  int int0;
  HDC hdc;
  ICMENUMPROCW icmenumprocw;
  ARAM* lparam = alloca(sizeof(ARAM));
  object arg0;
  arg = popSTACK();
  check_sint(arg);
  lparam = I_to_sint32(arg);
  arg0 = popSTACK();
  processICMENUMPROCW(icmenumprocw,arg0);
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hdc = TheFpointer(arg)->fp_pointer;
  processARAM(lparam,arg0);
  begin_system_call();
  int0 = EnumICMProfilesW(hdc,icmenumprocw,lparam);
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
DEFUN( GDI:EnumMetaFile, hdc hmetafile mfenumproc lparam)
{
  object arg;
  BOOL bool0;
  HDC hdc;
  HMETAFILE hmetafile;
  MFENUMPROC mfenumproc;
  ARAM* lparam = alloca(sizeof(ARAM));
  object arg0;
  arg = popSTACK();
  check_sint(arg);
  lparam = I_to_sint32(arg);
  arg0 = popSTACK();
  processMFENUMPROC(mfenumproc,arg0);
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hmetafile = TheFpointer(arg)->fp_pointer;
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hdc = TheFpointer(arg)->fp_pointer;
  processARAM(lparam,arg0);
  begin_system_call();
  bool0 = EnumMetaFile(hdc,hmetafile,mfenumproc,lparam);
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
DEFUN( GDI:EnumObjects, hdc int0 gobjenumproc lparam)
{
  object arg;
  int int1;
  HDC hdc;
  int int0;
  GOBJENUMPROC gobjenumproc;
  ARAM* lparam = alloca(sizeof(ARAM));
  object arg0;
  arg = popSTACK();
  check_sint(arg);
  lparam = I_to_sint32(arg);
  arg0 = popSTACK();
  processGOBJENUMPROC(gobjenumproc,arg0);
  arg = popSTACK();
  check_sint(arg);
  int0 = I_to_sint32(arg);
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hdc = TheFpointer(arg)->fp_pointer;
  processARAM(lparam,arg0);
  begin_system_call();
  int1 = EnumObjects(hdc,int0,gobjenumproc,lparam);
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
*/

// untested - was never called
/** 
 * Retrieve the setting for the current aspect-ratio filter.
 * The aspect ratio is the ratio formed by the width and height of a pixel on a specified device.
 * Returns lpAspectRatio [out]
 */
DEFUN( GDI:GetAspectRatioFilterEx, hdc)
{
  object arg;
  BOOL bool0;
  HDC hdc;
  SIZE* lpsize = alloca(sizeof(SIZE));
  object arg0;
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hdc = TheFpointer(arg)->fp_pointer;
  //processSIZE(lpsize,arg0);
  begin_system_call();
  bool0 = GetAspectRatioFilterEx(hdc,lpsize);
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
    outputLPSIZE(lpsize,arg0);
    value1 = arg0;
    mv_count=1;
  }
  return;
}

// untested - was never called
/** 
 * Returns: Pointer to a buffer to receive the bitmap bits 
   and the number of copied bits. The bits are stored as an 
   array of byte values.
 */
DEFUN( GDI:GetBitmapBits, hbitmap long0 pvoid)
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
  SIZE lpsize;
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hbitmap = TheFpointer(arg)->fp_pointer;
  begin_system_call();
  bool0 = GetBitmapDimensionEx(hbitmap,&lpsize);
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
    pushSTACK( uint32_to_I(lpsize.cy));
    value2 = uint32_to_I(lpsize.cx);
    value3 = popSTACK();
    value1 = T;
    mv_count=3;
  }
  return;
}
// untested - was never called
DEFUN( GDI:GetBoundsRect, hdc flags)
{
  object arg;
  UINT ret;
  HDC hdc;
  RECT* lprect = alloca(sizeof(RECT));
  object arg0;
  UINT flags;
  flags = I_to_uint32(check_uint(popSTACK()));
  /*arg0 = popSTACK();
    processRECT(lprect,arg0); */
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hdc = TheFpointer(arg)->fp_pointer;
  processRECT(lprect,arg0);
  begin_system_call();
  ret = GetBoundsRect(hdc,lprect,flags);
  end_system_call();
  if(!ret){
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
    outputRECT(lprect,arg0);
    value1 = arg0;
    value2 = uint32_to_I(ret);
    mv_count=2;
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:GetBrushOrgEx, hdc lppoint)
{
  object arg;
  BOOL bool0;
  HDC hdc;
  POINT* lppoint = alloca(sizeof(POINT));
  object arg0;
  arg0 = popSTACK();
  processPOINT(lppoint,arg0);
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hdc = TheFpointer(arg)->fp_pointer;
  processPOINT(lppoint,arg0);
  begin_system_call();
  bool0 = GetBrushOrgEx(hdc,lppoint);
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
DEFUN( GDI:GetCharABCWidthsA, hdc uint uint0 lpabc)
{
  object arg;
  BOOL bool0;
  HDC hdc;
  UINT uint;
  UINT uint0;
  ABC* lpabc = alloca(sizeof(ABC));
  object arg0;
  arg0 = popSTACK();
  processABC(lpabc,arg0);
  uint0 = I_to_uint32(check_uint(popSTACK()));
  uint = I_to_uint32(check_uint(popSTACK()));
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hdc = TheFpointer(arg)->fp_pointer;
  processABC(lpabc,arg0);
  begin_system_call();
  bool0 = GetCharABCWidthsA(hdc,uint,uint0,lpabc);
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
DEFUN( GDI:GetCharABCWidthsFloatA, hdc uint uint0 lpabcfloat)
{
  object arg;
  BOOL bool0;
  HDC hdc;
  UINT uint;
  UINT uint0;
  ABCFLOAT* lpabcfloat = alloca(sizeof(ABCFLOAT));
  object arg0;
  arg0 = popSTACK();
  processABCFLOAT(lpabcfloat,arg0);
  uint0 = I_to_uint32(check_uint(popSTACK()));
  uint = I_to_uint32(check_uint(popSTACK()));
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hdc = TheFpointer(arg)->fp_pointer;
  processABCFLOAT(lpabcfloat,arg0);
  begin_system_call();
  bool0 = GetCharABCWidthsFloatA(hdc,uint,uint0,lpabcfloat);
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
DEFUN( GDI:GetCharABCWidthsFloatW, hdc uint uint0 lpabcfloat)
{
  object arg;
  BOOL bool0;
  HDC hdc;
  UINT uint;
  UINT uint0;
  ABCFLOAT* lpabcfloat = alloca(sizeof(ABCFLOAT));
  object arg0;
  arg0 = popSTACK();
  processABCFLOAT(lpabcfloat,arg0);
  uint0 = I_to_uint32(check_uint(popSTACK()));
  uint = I_to_uint32(check_uint(popSTACK()));
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hdc = TheFpointer(arg)->fp_pointer;
  processABCFLOAT(lpabcfloat,arg0);
  begin_system_call();
  bool0 = GetCharABCWidthsFloatW(hdc,uint,uint0,lpabcfloat);
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
DEFUN( GDI:GetCharABCWidthsW, hdc uint uint0 lpabc)
{
  object arg;
  BOOL bool0;
  HDC hdc;
  UINT uint;
  UINT uint0;
  ABC* lpabc = alloca(sizeof(ABC));
  object arg0;
  arg0 = popSTACK();
  processABC(lpabc,arg0);
  uint0 = I_to_uint32(check_uint(popSTACK()));
  uint = I_to_uint32(check_uint(popSTACK()));
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hdc = TheFpointer(arg)->fp_pointer;
  processABC(lpabc,arg0);
  begin_system_call();
  bool0 = GetCharABCWidthsW(hdc,uint,uint0,lpabc);
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
DEFUN( GDI:GetCharWidth32A, hdc uint uint0 lpint)
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
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hdc = TheFpointer(arg)->fp_pointer;
  begin_system_call();
  bool0 = GetCharWidth32A(hdc,uint,uint0,lpint);
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
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hdc = TheFpointer(arg)->fp_pointer;
  begin_system_call();
  bool0 = GetCharWidth32W(hdc,uint,uint0,lpint);
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
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hdc = TheFpointer(arg)->fp_pointer;
  begin_system_call();
  bool0 = GetCharWidthA(hdc,uint,uint0,lpint);
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
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hdc = TheFpointer(arg)->fp_pointer;
  begin_system_call();
  bool0 = GetCharWidthW(hdc,uint,uint0,lpint);
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
DEFUN( GDI:GetClientRect, hwnd lprect)
{
  object arg;
  BOOL bool0;
  HWND hwnd;
  RECT* lprect = alloca(sizeof(RECT));
  object arg0 = popSTACK();
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hwnd = TheFpointer(arg)->fp_pointer;
  begin_call();
  bool0 = GetClientRect(hwnd,lprect);
  end_call();
  if(!bool0){
    DWORD e;
    begin_call();
    e = GetLastError();
    end_call();
    value1 = NIL;
    value2 = uint32_to_I(e);
    mv_count=2;
  }
  else
  {
    outputRECT(lprect,arg0);
    value1 = arg0;
    mv_count=1;
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
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hdc = TheFpointer(arg)->fp_pointer;
  processRECT(lprect,arg0);
  begin_system_call();
  int0 = GetClipBox(hdc,lprect);
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
    outputRECT(lprect,arg0);
    value1 = arg0;
    value2 = sint32_to_I(int0);
    mv_count=2;
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:GetColorAdjustment, hdc lpcoloradjustment)
{
  BOOL bool0;
  HDC hdc;
  COLORADJUSTMENT lpcoloradjustment;
  object arg0 = popSTACK();
  object arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hdc = TheFpointer(arg)->fp_pointer;
  begin_system_call();
  bool0 = GetColorAdjustment(hdc,&lpcoloradjustment);
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
    outputCOLORADJUSTMENT(&lpcoloradjustment,arg0);
    value2 = arg0;
    value1 = T;
    mv_count=1;
  }
  return;
}
// untested - was never called
DEFUN( GDI:GetCurrentPositionEx, hdc)
{
  object arg;
  BOOL bool0;
  HDC hdc;
  POINT* lppoint = alloca(sizeof(POINT));
  object arg0;
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hdc = TheFpointer(arg)->fp_pointer;
  begin_system_call();
  bool0 = GetCurrentPositionEx(hdc,lppoint);
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
    outputPOINT(lppoint,arg0);
    value1 = arg0;
    mv_count=1;
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:GetDCOrgEx, hdc lppoint)
{
  object arg;
  BOOL bool0;
  HDC hdc;
  POINT* lppoint = alloca(sizeof(POINT));
  object arg0;
  arg0 = popSTACK();
  processPOINT(lppoint,arg0);
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hdc = TheFpointer(arg)->fp_pointer;
  processPOINT(lppoint,arg0);
  begin_system_call();
  bool0 = GetDCOrgEx(hdc,lppoint);
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
DEFUN( GDI:GetDIBColorTable, hdc uint uint0 rgbquad_p)
{
  object arg;
  UINT uint1;
  HDC hdc;
  UINT uint;
  UINT uint0;
  RGBQUAD* rgbquad_p = alloca(sizeof(RGBQUAD));
  object arg0;
  arg0 = popSTACK();
  processRGBQUAD(rgbquad_p,arg0);
  uint0 = I_to_uint32(check_uint(popSTACK()));
  uint = I_to_uint32(check_uint(popSTACK()));
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hdc = TheFpointer(arg)->fp_pointer;
  processRGBQUAD(rgbquad_p,arg0);
  begin_system_call();
  uint1 = GetDIBColorTable(hdc,uint,uint0,rgbquad_p);
  end_system_call();
  if(!uint1){
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
    value2 = uint32_to_I(uint1);
    mv_count=2;
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
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hdc = TheFpointer(arg)->fp_pointer;
  begin_system_call();
  bool0 = GetDeviceGammaRamp(hdc,pvoid);
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
DEFUN( GDI:GetEnhMetaFileA, lpcstr)
{
  object arg;
  HENHMETAFILE henhmetafile;
  LPCSTR lpcstr;
  arg = popSTACK();
  if(!stringp(arg))invalid_argument(arg);
  with_string_0(arg,encoding, lpcstr, {
    begin_system_call();
    henhmetafile = GetEnhMetaFileA(lpcstr);
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
      value1 = allocate_fpointer((FOREIGN)henhmetafile);
      mv_count=1;
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
  if(!stringp(arg))invalid_argument(arg);
  with_string_0(arg,encoding, lpstr, {
    uint = I_to_uint32(check_uint(popSTACK()));
    arg = popSTACK();
    if(!fpointerp(arg))invalid_argument(arg);
    henhmetafile = TheFpointer(arg)->fp_pointer;
    begin_system_call();
    uint0 = GetEnhMetaFileDescriptionA(henhmetafile,uint,lpstr);
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
  if(!stringp(arg))invalid_argument(arg);
  lpwstr = WIDECHAR(arg,encoding);
  uint = I_to_uint32(check_uint(popSTACK()));
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  henhmetafile = TheFpointer(arg)->fp_pointer;
  begin_system_call();
  uint0 = GetEnhMetaFileDescriptionW(henhmetafile,uint,lpwstr);
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
DEFUN( GDI:GetEnhMetaFileHeader, henhmetafile uint lpenhmetaheader)
{
  object arg;
  UINT uint0;
  HENHMETAFILE henhmetafile;
  UINT uint;
  ENHMETAHEADER* lpenhmetaheader = alloca(sizeof(ENHMETAHEADER));
  object arg0;
  arg0 = popSTACK();
  processENHMETAHEADER(lpenhmetaheader,arg0);
  uint = I_to_uint32(check_uint(popSTACK()));
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  henhmetafile = TheFpointer(arg)->fp_pointer;
  processENHMETAHEADER(lpenhmetaheader,arg0);
  begin_system_call();
  uint0 = GetEnhMetaFileHeader(henhmetafile,uint,lpenhmetaheader);
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
DEFUN( GDI:GetEnhMetaFilePaletteEntries, henhmetafile uint lppaletteentry)
{
  object arg;
  UINT uint0;
  HENHMETAFILE henhmetafile;
  UINT uint;
  PALETTEENTRY* lppaletteentry = alloca(sizeof(PALETTEENTRY));
  object arg0;
  arg0 = popSTACK();
  processPALETTEENTRY(lppaletteentry,arg0);
  uint = I_to_uint32(check_uint(popSTACK()));
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  henhmetafile = TheFpointer(arg)->fp_pointer;
  processPALETTEENTRY(lppaletteentry,arg0);
  begin_system_call();
  uint0 = GetEnhMetaFilePaletteEntries(henhmetafile,uint,lppaletteentry);
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
  processPIXELFORMATDESCRIPTOR(pixelformatdescriptor_p,arg0);
  begin_system_call();
  uint = GetEnhMetaFilePixelFormat(henhmetafile,dword,pixelformatdescriptor_p);
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
DEFUN( GDI:GetEnhMetaFileW, lpcwstr)
{
  object arg;
  HENHMETAFILE henhmetafile;
  LPCWSTR lpcwstr;
  arg = popSTACK();
  if(!stringp(arg))invalid_argument(arg);
  lpcwstr = WIDECHAR(arg,encoding);
  begin_system_call();
  henhmetafile = GetEnhMetaFileW(lpcwstr);
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
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hdc = TheFpointer(arg)->fp_pointer;
  begin_system_call();
  dword2 = GetFontData(hdc,dword,dword0,pvoid,dword1);
  end_system_call();
  if(!dword2){
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
  if(!stringp(arg))invalid_argument(arg);
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
  if(!stringp(arg))invalid_argument(arg);
  lpwstr = WIDECHAR(arg,encoding);
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  lpdword = TheFpointer(arg)->fp_pointer;
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hdc = TheFpointer(arg)->fp_pointer;
  begin_system_call();
  bool0 = GetICMProfileW(hdc,lpdword,lpwstr);
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
  KERNINGPAIR* lpkerningpair = alloca(sizeof(KERNINGPAIR));
  object arg0;
  arg0 = popSTACK();
  processKERNINGPAIR(lpkerningpair,arg0);
  dword = I_to_uint32(check_uint(popSTACK()));
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hdc = TheFpointer(arg)->fp_pointer;
  processKERNINGPAIR(lpkerningpair,arg0);
  begin_system_call();
  dword0 = GetKerningPairsA(hdc,dword,lpkerningpair);
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
DEFUN( GDI:GetKerningPairsW, hdc dword lpkerningpair)
{
  object arg;
  DWORD dword0;
  HDC hdc;
  DWORD dword;
  KERNINGPAIR* lpkerningpair = alloca(sizeof(KERNINGPAIR));
  object arg0;
  arg0 = popSTACK();
  processKERNINGPAIR(lpkerningpair,arg0);
  dword = I_to_uint32(check_uint(popSTACK()));
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hdc = TheFpointer(arg)->fp_pointer;
  processKERNINGPAIR(lpkerningpair,arg0);
  begin_system_call();
  dword0 = GetKerningPairsW(hdc,dword,lpkerningpair);
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
DEFUN( GDI:GetLogColorSpaceA, hcolorspace lplogcolorspacea dword)
{
  object arg;
  BOOL bool0;
  HCOLORSPACE hcolorspace;
  LOGCOLORSPACEA* lplogcolorspacea = alloca(sizeof(LOGCOLORSPACEA));
  object arg0;
  DWORD dword;
  dword = I_to_uint32(check_uint(popSTACK()));
  arg0 = popSTACK();
  processLOGCOLORSPACEA(lplogcolorspacea,arg0);
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hcolorspace = TheFpointer(arg)->fp_pointer;
  processLOGCOLORSPACEA(lplogcolorspacea,arg0);
  begin_system_call();
  bool0 = GetLogColorSpaceA(hcolorspace,lplogcolorspacea,dword);
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
DEFUN( GDI:GetLogColorSpaceW, hcolorspace lplogcolorspacew dword)
{
  object arg;
  BOOL bool0;
  HCOLORSPACE hcolorspace;
  LOGCOLORSPACEW* lplogcolorspacew = alloca(sizeof(LOGCOLORSPACEW));
  object arg0;
  DWORD dword;
  dword = I_to_uint32(check_uint(popSTACK()));
  arg0 = popSTACK();
  processLOGCOLORSPACEW(lplogcolorspacew,arg0);
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hcolorspace = TheFpointer(arg)->fp_pointer;
  processLOGCOLORSPACEW(lplogcolorspacew,arg0);
  begin_system_call();
  bool0 = GetLogColorSpaceW(hcolorspace,lplogcolorspacew,dword);
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
DEFUN( GDI:GetMetaFileA, lpcstr)
{
  object arg;
  HMETAFILE hmetafile;
  LPCSTR lpcstr;
  arg = popSTACK();
  if(!stringp(arg))invalid_argument(arg);
  with_string_0(arg,encoding, lpcstr, {
    begin_system_call();
    hmetafile = GetMetaFileA(lpcstr);
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
      value1 = allocate_fpointer((FOREIGN)hmetafile);
      mv_count=1;
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
DEFUN( GDI:GetMetaFileW, lpcwstr)
{
  object arg;
  HMETAFILE hmetafile;
  LPCWSTR lpcwstr;
  arg = popSTACK();
  if(!stringp(arg))invalid_argument(arg);
  lpcwstr = WIDECHAR(arg,encoding);
  begin_system_call();
  hmetafile = GetMetaFileW(lpcwstr);
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
  arg = popSTACK();
  check_sint(arg);
  int0 = I_to_sint32(arg);
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hgdiobj = TheFpointer(arg)->fp_pointer;
  begin_system_call();
  int1 = GetObjectA(hgdiobj,int0,pvoid);
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
  arg = popSTACK();
  check_sint(arg);
  int0 = I_to_sint32(arg);
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hgdiobj = TheFpointer(arg)->fp_pointer;
  begin_system_call();
  int1 = GetObjectW(hgdiobj,int0,pvoid);
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
    value1 = sint32_to_I(int1);
    mv_count=1;
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
  OUTLINETEXTMETRICA* lpoutlinetextmetrica = alloca(sizeof(OUTLINETEXTMETRICA));
  object arg0;
  arg0 = popSTACK();
  processOUTLINETEXTMETRICA(lpoutlinetextmetrica,arg0);
  uint = I_to_uint32(check_uint(popSTACK()));
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hdc = TheFpointer(arg)->fp_pointer;
  processOUTLINETEXTMETRICA(lpoutlinetextmetrica,arg0);
  begin_system_call();
  uint0 = GetOutlineTextMetricsA(hdc,uint,lpoutlinetextmetrica);
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
    value1 = uint32_to_I(uint0);
    mv_count=1;
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
  OUTLINETEXTMETRICW* lpoutlinetextmetricw = alloca(sizeof(OUTLINETEXTMETRICW));
  object arg0;
  arg0 = popSTACK();
  processOUTLINETEXTMETRICW(lpoutlinetextmetricw,arg0);
  uint = I_to_uint32(check_uint(popSTACK()));
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hdc = TheFpointer(arg)->fp_pointer;
  processOUTLINETEXTMETRICW(lpoutlinetextmetricw,arg0);
  begin_system_call();
  uint0 = GetOutlineTextMetricsW(hdc,uint,lpoutlinetextmetricw);
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
    value1 = uint32_to_I(uint0);
    mv_count=1;
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:GetPaletteEntries, hpalette uint uint0 lppaletteentry)
{
  object arg;
  UINT uint1;
  HPALETTE hpalette;
  UINT uint;
  UINT uint0;
  PALETTEENTRY* lppaletteentry = alloca(sizeof(PALETTEENTRY));
  object arg0;
  arg0 = popSTACK();
  processPALETTEENTRY(lppaletteentry,arg0);
  uint0 = I_to_uint32(check_uint(popSTACK()));
  uint = I_to_uint32(check_uint(popSTACK()));
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hpalette = TheFpointer(arg)->fp_pointer;
  processPALETTEENTRY(lppaletteentry,arg0);
  begin_system_call();
  uint1 = GetPaletteEntries(hpalette,uint,uint0,lppaletteentry);
  end_system_call();
  if(!uint1){
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
    value1 = uint32_to_I(uint1);
    mv_count=1;
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
  arg = popSTACK();
  check_sint(arg);
  int0 = I_to_sint32(arg);
  arg0 = popSTACK();
  processPBYTE(pbyte,arg0);
  arg0 = popSTACK();
  processPOINT(lppoint,arg0);
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hdc = TheFpointer(arg)->fp_pointer;
  processPOINT(lppoint,arg0);
  begin_system_call();
  int1 = GetPath(hdc,lppoint,pbyte,int0);
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
    value1 = sint32_to_I(int1);
    mv_count=1;
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:GetRasterizerCaps, lprasterizer_status uint)
{
  object arg;
  BOOL bool0;
  RASTERIZER_STATUS* lprasterizer_status = alloca(sizeof(RASTERIZER_STATUS));
  object arg0;
  UINT uint;
  uint = I_to_uint32(check_uint(popSTACK()));
  arg0 = popSTACK();
  processRASTERIZER_STATUS(lprasterizer_status,arg0);
  processRASTERIZER_STATUS(lprasterizer_status,arg0);
  begin_system_call();
  bool0 = GetRasterizerCaps(lprasterizer_status,uint);
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
DEFUN( GDI:GetRegionData, hrgn dword lprgndata)
{
  object arg;
  DWORD dword0;
  HRGN hrgn;
  DWORD dword;
  RGNDATA* lprgndata = alloca(sizeof(RGNDATA));
  object arg0;
  arg0 = popSTACK();
  processRGNDATA(lprgndata,arg0);
  dword = I_to_uint32(check_uint(popSTACK()));
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hrgn = TheFpointer(arg)->fp_pointer;
  processRGNDATA(lprgndata,arg0);
  begin_system_call();
  dword0 = GetRegionData(hrgn,dword,lprgndata);
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
  if(!fpointerp(arg))invalid_argument(arg);
  hrgn = TheFpointer(arg)->fp_pointer;
  processRECT(lprect,arg0);
  begin_system_call();
  int0 = GetRgnBox(hrgn,lprect);
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
DEFUN( GDI:GetSystemPaletteEntries, hdc uint uint0 lppaletteentry)
{
  object arg;
  UINT uint1;
  HDC hdc;
  UINT uint;
  UINT uint0;
  PALETTEENTRY* lppaletteentry = alloca(sizeof(PALETTEENTRY));
  object arg0;
  arg0 = popSTACK();
  processPALETTEENTRY(lppaletteentry,arg0);
  uint0 = I_to_uint32(check_uint(popSTACK()));
  uint = I_to_uint32(check_uint(popSTACK()));
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hdc = TheFpointer(arg)->fp_pointer;
  processPALETTEENTRY(lppaletteentry,arg0);
  begin_system_call();
  uint1 = GetSystemPaletteEntries(hdc,uint,uint0,lppaletteentry);
  end_system_call();
  if(!uint1){
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
    value2 = uint32_to_I(uint1);
    mv_count=2;
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
  FONTSIGNATURE* lpfontsignature = alloca(sizeof(FONTSIGNATURE));
  object arg0;
  DWORD dword;
  dword = I_to_uint32(check_uint(popSTACK()));
  arg0 = popSTACK();
  processFONTSIGNATURE(lpfontsignature,arg0);
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hdc = TheFpointer(arg)->fp_pointer;
  processFONTSIGNATURE(lpfontsignature,arg0);
  begin_system_call();
  int0 = GetTextCharsetInfo(hdc,lpfontsignature,dword);
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
DEFUN( GDI:GetTextExtentPoint32A, hdc lpcstr int0)
{
  object arg;
  BOOL bool0;
  HDC hdc;
  LPCSTR lpcstr;
  int int0;
  SIZE lpsize;
  arg = popSTACK();
  check_sint(arg);
  int0 = I_to_sint32(arg); // fixme remove this argument, and get string length
  arg = popSTACK();
  if(!stringp(arg))invalid_argument(arg);
  with_string_0(arg,encoding, lpcstr, {
    arg = popSTACK();
    if(!fpointerp(arg))invalid_argument(arg);
    hdc = TheFpointer(arg)->fp_pointer;
    begin_system_call();
    bool0 = GetTextExtentPoint32A(hdc,lpcstr,int0,&lpsize);
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
      pushSTACK( uint32_to_I(lpsize.cy));
      value2 = uint32_to_I(lpsize.cx);
      value3 = popSTACK();
      value1 = T;
      mv_count=3;
    }
  });
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:GetTextExtentPoint32W, hdc lpcwstr int0 lpsize)
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
  arg = popSTACK();
  check_sint(arg);
  int0 = I_to_sint32(arg);
  arg = popSTACK();
  if(!stringp(arg))invalid_argument(arg);
  lpcwstr = WIDECHAR(arg,encoding);
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hdc = TheFpointer(arg)->fp_pointer;
  processSIZE(lpsize,arg0);
  begin_system_call();
  bool0 = GetTextExtentPoint32W(hdc,lpcwstr,int0,lpsize);
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
  arg = popSTACK();
  check_sint(arg);
  int0 = I_to_sint32(arg);
  arg = popSTACK();
  if(!stringp(arg))invalid_argument(arg);
  with_string_0(arg,encoding, lpcstr, {
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hdc = TheFpointer(arg)->fp_pointer;
  processSIZE(lpsize,arg0);
  begin_system_call();
  bool0 = GetTextExtentPointA(hdc,lpcstr,int0,lpsize);
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
  });
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
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
  arg = popSTACK();
  check_sint(arg);
  int0 = I_to_sint32(arg);
  arg = popSTACK();
  if(!stringp(arg))invalid_argument(arg);
  lpcwstr = WIDECHAR(arg,encoding);
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hdc = TheFpointer(arg)->fp_pointer;
  processSIZE(lpsize,arg0);
  begin_system_call();
  bool0 = GetTextExtentPointW(hdc,lpcwstr,int0,lpsize);
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
DEFUN( GDI:GetTextFaceA, hdc int0 lpstr)
{
  object arg;
  int int1;
  HDC hdc;
  int int0;
  LPSTR lpstr;
  arg = popSTACK();
  if(!stringp(arg))invalid_argument(arg);
  with_string_0(arg,encoding, lpstr, {
    arg = popSTACK();
    check_sint(arg);
    int0 = I_to_sint32(arg);
    arg = popSTACK();
    if(!fpointerp(arg))invalid_argument(arg);
    hdc = TheFpointer(arg)->fp_pointer;
    begin_system_call();
    int1 = GetTextFaceA(hdc,int0,lpstr);
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
  });
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:GetTextFaceW, hdc int0 lpwstr)
{
  object arg;
  int int1;
  HDC hdc;
  int int0;
  LPWSTR lpwstr;
  arg = popSTACK();
  if(!stringp(arg))invalid_argument(arg);
  lpwstr = WIDECHAR(arg,encoding);
  arg = popSTACK();
  check_sint(arg);
  int0 = I_to_sint32(arg);
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hdc = TheFpointer(arg)->fp_pointer;
  begin_system_call();
  int1 = GetTextFaceW(hdc,int0,lpwstr);
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
DEFUN( GDI:GetTextMetricsA, hdc lptextmetrica)
{
  object arg;
  BOOL bool0;
  HDC hdc;
  TEXTMETRICA lptextmetrica;
  object arg0 = popSTACK();
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hdc = TheFpointer(arg)->fp_pointer;
  begin_system_call();
  bool0 = GetTextMetricsA(hdc,&lptextmetrica);
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
    outputTEXTMETRICA(&lptextmetrica,arg0);
    value2 = arg0;
    value1 = T;
    mv_count=2;
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:GetTextMetricsW, hdc lptextmetricw)
{
  object arg;
  BOOL bool0;
  HDC hdc;
  TEXTMETRICW* lptextmetricw = alloca(sizeof(TEXTMETRICW));
  object arg0;
  arg0 = popSTACK();
  processTEXTMETRICW(lptextmetricw,arg0);
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hdc = TheFpointer(arg)->fp_pointer;
  processTEXTMETRICW(lptextmetricw,arg0);
  begin_system_call();
  bool0 = GetTextMetricsW(hdc,lptextmetricw);
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
DEFUN( GDI:GetViewportExtEx, hdc lpsize)
{
  object arg;
  BOOL bool0;
  HDC hdc;
  SIZE* lpsize = alloca(sizeof(SIZE));
  object arg0;
  arg0 = popSTACK();
  processSIZE(lpsize,arg0);
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hdc = TheFpointer(arg)->fp_pointer;
  processSIZE(lpsize,arg0);
  begin_system_call();
  bool0 = GetViewportExtEx(hdc,lpsize);
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
DEFUN( GDI:GetViewportOrgEx, hdc lppoint)
{
  object arg;
  BOOL bool0;
  HDC hdc;
  POINT* lppoint = alloca(sizeof(POINT));
  object arg0;
  arg0 = popSTACK();
  processPOINT(lppoint,arg0);
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hdc = TheFpointer(arg)->fp_pointer;
  processPOINT(lppoint,arg0);
  begin_system_call();
  bool0 = GetViewportOrgEx(hdc,lppoint);
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
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hdc = TheFpointer(arg)->fp_pointer;
  arg = popSTACK();
  check_sint(arg);
  int0 = I_to_sint32(arg);
  arg0 = popSTACK();
  processBYTE(lpbyte,arg0);
  uint = I_to_uint32(check_uint(popSTACK()));
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  henhmetafile = TheFpointer(arg)->fp_pointer;
  processBYTE(lpbyte,arg0);
  begin_system_call();
  uint0 = GetWinMetaFileBits(henhmetafile,uint,lpbyte,int0,hdc);
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
DEFUN( GDI:GetWindowExtEx, hdc lpsize)
{
  object arg;
  BOOL bool0;
  HDC hdc;
  SIZE* lpsize = alloca(sizeof(SIZE));
  object arg0;
  arg0 = popSTACK();
  processSIZE(lpsize,arg0);
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hdc = TheFpointer(arg)->fp_pointer;
  processSIZE(lpsize,arg0);
  begin_system_call();
  bool0 = GetWindowExtEx(hdc,lpsize);
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
DEFUN( GDI:GetWindowOrgEx, hdc lppoint)
{
  object arg;
  BOOL bool0;
  HDC hdc;
  POINT* lppoint = alloca(sizeof(POINT));
  object arg0;
  arg0 = popSTACK();
  processPOINT(lppoint,arg0);
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hdc = TheFpointer(arg)->fp_pointer;
  processPOINT(lppoint,arg0);
  begin_system_call();
  bool0 = GetWindowOrgEx(hdc,lppoint);
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
DEFUN( GDI:GetWorldTransform, hdc lpxform)
{
  object arg;
  BOOL bool0;
  HDC hdc;
  XFORM* lpxform = alloca(sizeof(XFORM));
  object arg0;
  arg0 = popSTACK();
  processXFORM(lpxform,arg0);
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hdc = TheFpointer(arg)->fp_pointer;
  processXFORM(lpxform,arg0);
  begin_system_call();
  bool0 = GetWorldTransform(hdc,lpxform);
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
    int2 = Escape(hdc,int0,int1,lpcstr,pvoid);
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
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hdc = TheFpointer(arg)->fp_pointer;
  begin_system_call();
  int0 = SetAbortProc(hdc,abortproc);
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
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hdc = TheFpointer(arg)->fp_pointer;
  length = uint0 - uint + 1;
  pfloat = alloca(sizeof(FLOAT)*length);
  begin_system_call();
  bool0 = GetCharWidthFloatA(hdc,uint,uint0,pfloat);
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
    value2 = outputFLOATS(pfloat,length);
    value1 = T;
    mv_count=1;
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
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hdc = TheFpointer(arg)->fp_pointer;
  pfloat = alloca(sizeof(FLOAT)*(uint0 - uint + 1));
  begin_system_call();
  bool0 = GetCharWidthFloatW(hdc,uint,uint0,pfloat);
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
    value2 = outputFLOATS(pfloat,0);
    value1 = T;
    mv_count=1;
  }
  return;
}

extern object allocate_ffloat (ffloat value);

// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:GetMiterLimit, hdc pfloat)
{
  object arg;
  BOOL bool0;
  HDC hdc;
  FLOAT pfloat;
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hdc = TheFpointer(arg)->fp_pointer;
  begin_system_call();
  bool0 = GetMiterLimit(hdc,&pfloat);
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
    value2 = allocate_ffloat(pfloat);
    value1 = T;
    mv_count=2;
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
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hdc = TheFpointer(arg)->fp_pointer;
  begin_system_call();
  bool0 = SetMiterLimit(hdc,float0,&pfloat);
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
    value2 = allocate_ffloat(pfloat);
    value1 = T;
    mv_count=2;
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:LineDDA, lppoint lppoint0 lineddaproc lparam)
{
  object arg;
  BOOL bool0;
  POINT lppoint;
  POINT lppoint0;
  LINEDDAPROC lineddaproc;
  LPARAM lparam;
  arg = popSTACK();
  check_sint(arg);
  lparam = (LPARAM)I_to_sint32(arg);
  arg = popSTACK();
  processLINEDDAPROC(&lineddaproc,arg);
  arg = popSTACK();
  processPOINT(&lppoint0,arg);
  arg = popSTACK();
  processPOINT(&lppoint,arg);
  begin_system_call();
  bool0 = LineDDA(lppoint.x,lppoint.y,lppoint0.x,lppoint0.y,lineddaproc,lparam);
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
  processHARSETINFO(lpcharsetinfo,arg0);
  begin_system_call();
  bool0 = TranslateCharsetInfo(dword_p,lpcharsetinfo,dword);
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
*/
