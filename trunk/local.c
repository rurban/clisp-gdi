#line 1 "local.c"
/* Process incoming args and create return values (lisp structs and foreign ptrs) */
/* processTYPE(c-ptr, object): lisp => C
   object = outputTYPE(c-ptr): C => lisp */

extern object allocate_ffloat (ffloat value);

/* Global error handling */
/* TODO: call customizable lisp handler, like
   (GDI::error-handler fn) to be able to use
   (error signature) or popup a window or ignore the error.
*/
#define do_GDI_ERROR(fn)        \
  DWORD e;			\
  begin_system_call();          \
  e = GetLastError();		\
  end_system_call();		\
  value1 = NIL;                 \
  value2 = uint32_to_I(e);	\
  mv_count=2

#define do_GDI_ERROR_ext(fn)    \
    DWORD e;			\
    begin_system_call();	\
    e = GetLastError();		\
    end_system_call();		\
    value1 = NIL;		\
    value2 = uint32_to_I(e);	\
  /* dynamic_bind(``*last-error*``, value2), */   \
    /*pushSTACK(value2);*/      \
    /*pushSTACK(``last-error``);*/  \
    /*funcall(L(setq),2);*/      \
    /*pushSTACK(TheSubr(subr_self)->name);*/ \
    /*GDI::error-handler;*/     \
    /*OS_error();*/             \
    mv_count=2

nonreturning_function(static, invalid_argument, (object obj)) {
  pushSTACK(obj);
  error(error_condition,GETTEXT("~S is an invalid argument"));
}
nonreturning_function(static, invalid_named_argument, (object obj, char *name)) {
  pushSTACK(asciz_to_string(name, encoding));
  pushSTACK(obj);
  error(error_condition,GETTEXT("~S is an invalid argument for ~S"));
}

#define getHDC(hdc,arg)                         	\
  arg = popSTACK(); 					\
  if(!fpointerp(arg))invalid_named_argument(arg, "hdc");\
  hdc = TheFpointer(arg)->fp_pointer

/* allow processFPTYPE_fn(HPALETTE,hpalette,popSTACK()); */
#define processFPTYPE_fn(type, ptr, arg) 	\
    { object obj = arg;			        \
      if(!fpointerp(obj))invalid_argument(obj); \
      ptr = (type)TheFpointer(obj)->fp_pointer;}

/* only processFPTYPE(HPALETTE,hpalette,arg); */
#define processFPTYPE(type, ptr, arg) 		\
      if(!fpointerp(arg))invalid_argument(arg); \
      ptr = (type)TheFpointer(arg)->fp_pointer

static void processBOOL(void *p,object arg){
    // arg: T or nil => 0 or 1
    BOOL b;
    b = (BOOL)I_to_uint32(arg);
    p = &b;
}
//static void processFINDEX_INFO_LEVELS(void *p,object arg){ assert(0); }
//static void processFINDEX_SEARCH_OPS(void *p,object arg){ assert(0); }
//static void processLPSTR(void *p,object arg){ assert(0); }
static void processLPWSTR(LPCWSTR lpcwstr,object arg){ 
  if(!stringp(arg))invalid_argument(arg);
  lpcwstr = WIDECHAR(arg,encoding);
}
// create a S16string how? size includes the ending 0
static object outputLPWSTR(LPCWSTR lpcwstr, uint size){ 
  /*object string = allocate_imm_s16string(size-1);
    copy_16bit_16bit(lpcwstr, &TheS16string(string)->data[0],size-1);*/
  //assert(0);
  //return asciz_to_string(lpcwstr,GLO(misc_encoding));
  return allocate_fpointer(lpcwstr);
}
// size includes the ending 0
static object outputLPSTR(LPCSTR lpcstr, uint size){
  return asciz_to_string(lpcstr,GLO(misc_encoding));
}
//static void processPBITMAPINFO(void *p,object arg){ assert(0); }
static void processPINT(void *p,object arg){
    int i;
    i = I_to_uint32(check_uint(arg));
    p = &i;
}
//static void processSTR_P(void *p,object arg){ assert(0); }
//static void processWSTR_P(void *p,object arg){ assert(0); }
//static void processABC(ABC *p, object arg){ assert(0); }
static void processPBYTE(BYTE *p, object arg){
    BYTE i;
    i = I_to_uint32(check_uint(arg));
    p = &i;
}
static void processBYTE(BYTE *p, object arg){
    BYTE i;
    i = I_to_sint32(check_sint(arg));
    p = &i;
}
//static void processABCFLOAT(ABCFLOAT *p, object arg){ assert(0); }
//static void processENHMETAHEADER(void *p, object arg){ assert(0); }
//static void processFONTSIGNATURE(void *p, object arg){ assert(0); }
//static void processKERNINGPAIR(void *p, object arg){ assert(0); }
//static void processOUTLINETEXTMETRICA(void *p, object arg){ assert(0); }
//static void processOUTLINETEXTMETRICW(void *p, object arg){ assert(0); }
//static void processRASTERIZER_STATUS(void *p, object arg){ assert(0); }
//static void processRGBQUAD(RGBQUAD *p, object arg){ assert(0); }
//static void processTEXTMETRICW(TEXTMETRICW*p, object arg){ assert(0); }
//static void outputGLYPHMETRICS(GLYPHMETRICS* p, object arg){ assert(0); }
//static void processGCP_RESULTSA(GCP_RESULTSA* p, object arg){ assert(0); }
//static void processGCP_RESULTSW(GCP_RESULTSW* p, object arg){ assert(0); }
//static void processHANDLETABLE_C(HANDLETABLE* p, object arg, unsigned int count){}
//static void processLOGCOLORSPACEA(LOGCOLORSPACEA* p, object arg){ assert(0); }
//static void processLOGCOLORSPACEW(LOGCOLORSPACEW* p, object arg){ assert(0); }
//static void processMETARECORD(METARECORD* p, object arg){ assert(0); }
//static void processPOLYTEXTW(POLYTEXTW* p, object arg){ assert(0); }
//static void processSIZE(SIZE* p, object arg){ assert(0); }
static void processvoid(void* p, object arg){
  p = (void *)I_to_uint32(arg);
}
//static void processABORTPROC(ABORTPROC *p,object arg){ assert(0); }
//static void processBITMAPINFO(BITMAPINFO *p,object arg){ assert(0); }
//static void processBITMAPINFOHEADER(BITMAPINFOHEADER *p,object arg){ assert(0); }
//static void processDEVMODEA(DEVMODEA *p,object arg){ assert(0); }
//static void processDEVMODEW(DEVMODEW *p,object arg){ assert(0); }
//static void processDOCINFOA(DOCINFOA *p,object arg){ assert(0); }
//static void processDOCINFOW(DOCINFOW *p,object arg){ assert(0); }
//static void processENHMETARECORD(ENHMETARECORD *p,object arg){ assert(0); }
//static void processENHMFENUMPROC(ENHMFENUMPROC *p,object arg){ assert(0); }
static void processFONTENUMPROCA(FONTENUMPROCA *p,object arg){ 
  if(!fpointerp(arg))invalid_argument(arg);
  p = (FONTENUMPROCA *)TheFpointer(arg)->fp_pointer;
}
//static void processFONTENUMPROCW(FONTENUMPROCW *p,object arg){ assert(0); }
//static void processGLYPHMETRICS(GLYPHMETRICS *p,object arg){ assert(0); }
//static void processGOBJENUMPROC(GOBJENUMPROC *p,object arg){ assert(0); }
//static void processICMENUMPROCA(ICMENUMPROCA *p,object arg){ assert(0); }
//static void processICMENUMPROCW(ICMENUMPROCW *p,object arg){ assert(0); }
//static void processLINEDDAPROC(LINEDDAPROC *p,object arg){ assert(0); }
//static void processLOGPALETTE(LOGPALETTE *p,object arg){ assert(0); }
//static void processLOGPEN(LOGPEN *p,object arg){ assert(0); }
//static void processLPABC(LPABC *p,object arg){ assert(0); }
//static void processLPABCFLOAT(LPABCFLOAT *p,object arg){ assert(0); }
//static void processLPBITMAPINFO(LPBITMAPINFO *p,object arg){ assert(0); }
//static void processLPCHARSETINFO(LPCHARSETINFO *p,object arg){ assert(0); }
//static void processLPCOLORADJUSTMENT(LPCOLORADJUSTMENT *p,object arg){ assert(0); }
//static void processLPCRECT(LPCRECT *p,object arg){ assert(0); }
//static void processLPENHMETAHEADER(LPENHMETAHEADER *p,object arg){ assert(0); }
//static void processLPFONTSIGNATURE(LPFONTSIGNATURE *p,object arg){ assert(0); }
//static void processLPGCP_RESULTSA(LPGCP_RESULTSA *p,object arg){ assert(0); }
//static void processLPGCP_RESULTSW(LPGCP_RESULTSW *p,object arg){ assert(0); }
//static void processLPHANDLETABLE(LPHANDLETABLE *p,object arg){ assert(0); }
//static void processLPINT(LPINT *p,object arg){ assert(0); }
//static void processLPKERNINGPAIR(LPKERNINGPAIR *p,object arg){ assert(0); }
//static void processLPLOGCOLORSPACEA(LPLOGCOLORSPACEA *p,object arg){ assert(0); }
//static void processLPLOGCOLORSPACEW(LPLOGCOLORSPACEW *p,object arg){ assert(0); }
//static void processLPMETARECORD(LPMETARECORD *p,object arg){ assert(0); }
//static void processLPOUTLINETEXTMETRICA(LPOUTLINETEXTMETRICA *p,object arg){ assert(0); }
//static void processLPOUTLINETEXTMETRICW(LPOUTLINETEXTMETRICW *p,object arg){ assert(0); }
//static void processLPPALETTEENTRY(LPPALETTEENTRY *p,object arg){ assert(0); }
//static void processLPPIXELFORMATDESCRIPTOR(LPPIXELFORMATDESCRIPTOR *p,object arg){ assert(0); }
//static void processLPPOINT(LPPOINT *p,object arg){ assert(0); }
//static void processLPRASTERIZER_STATUS(LPRASTERIZER_STATUS *p,object arg){ assert(0); }
//static void processLPRECT(LPRECT *p,object arg){ assert(0); }
//static void processLPSIZE(LPSIZE *p,object arg){ assert(0); }
//static void processLPTEXTMETRICA(LPTEXTMETRICA *p,object arg){ assert(0); }
//static void processLPTEXTMETRICW(LPTEXTMETRICW *p,object arg){ assert(0); }
//static void processLPXFORM(LPXFORM *p,object arg){ assert(0); }
//static void processMFENUMPROC(MFENUMPROC *p,object arg){ assert(0); }
//static void processPFLOAT(PFLOAT *p,object arg){ assert(0); }
//static void processRGNDATA(RGNDATA *p,object arg){ assert(0); }
//static void processRGNDATA_C(RGNDATA *p,object arg, int count){}

static void processICONINFO(ICONINFO *p,object arg)
{
   int i = 1;
   p->fIcon = nullp(TheRecord(arg)->recdata[i++]);
   p->xHotspot = I_to_L(TheRecord(arg)->recdata[i++]);
   p->yHotspot = I_to_L(TheRecord(arg)->recdata[i++]);
   p->hbmMask = TheFpointer(TheRecord(arg)->recdata[i++])->fp_pointer;
   p->hbmColor = TheFpointer(TheRecord(arg)->recdata[i++])->fp_pointer;
}
static void processLOGFONTA(LOGFONTA *p,object arg)
{
   int i = 1;
   p->lfHeight = I_to_L(TheRecord(arg)->recdata[i++]);
   p->lfWidth = I_to_L(TheRecord(arg)->recdata[i++]);
   p->lfEscapement = I_to_L(TheRecord(arg)->recdata[i++]);
   p->lfOrientation = I_to_L(TheRecord(arg)->recdata[i++]);
   p->lfWeight = I_to_L(TheRecord(arg)->recdata[i++]);
   p->lfItalic = I_to_uint8(TheRecord(arg)->recdata[i++]);
   p->lfUnderline = I_to_uint8(TheRecord(arg)->recdata[i++]);
   p->lfStrikeOut = I_to_uint8(TheRecord(arg)->recdata[i++]);
   p->lfCharSet = I_to_uint8(TheRecord(arg)->recdata[i++]);
   p->lfOutPrecision = I_to_uint8(TheRecord(arg)->recdata[i++]);
   p->lfClipPrecision = I_to_uint8(TheRecord(arg)->recdata[i++]);
   p->lfQuality = I_to_uint8(TheRecord(arg)->recdata[i++]);
   p->lfPitchAndFamily = I_to_uint8(TheRecord(arg)->recdata[i++]);
   strncpy(p->lfFaceName,
      (LPCSTR)TheAsciz(string_to_asciz(TheRecord(arg)->recdata[i++],encoding)),
      sizeof(p->lfFaceName));
}
static void processPLOGFONTA(LOGFONTA *p,object arg)
{
  if(!fpointerp(arg))invalid_argument(arg);
  p = (LOGFONTA *)TheFpointer(arg)->fp_pointer;
}
static void processLOGFONTW(LOGFONTW *p,object arg){ assert(0); }
static object outputRECT(RECT *r)
{
  int i = 0;
  object p;
  object num;
  pushSTACK(p); // Push the record to keep it safe from gc
  num = UL_to_I(r->left); // Can cause gc
  TheRecord(STACK_0)->recdata[i++] = num;
  num = UL_to_I(r->top); // Can cause gc
  TheRecord(STACK_0)->recdata[i++] = num;
  num = UL_to_I(r->right); // Can cause gc
  TheRecord(STACK_0)->recdata[i++] = num;
  num = UL_to_I(r->bottom); // Can cause gc
  TheRecord(popSTACK())->recdata[i++] = num;
  return p;
}
// untested - was never called
// used in: 
// removed from: AnimatePallette SetPaletteEntries GetPaletteEntries 
//               GetEnhMetaFilePaletteEntries GetSystemPaletteEntries
/*
static void processPALETTEENTRY(PALETTEENTRY* p, object arg)
{
   int i = 0;
   p->peRed = I_to_uint8(TheRecord(arg)->recdata[i++]);
   p->peGreen = I_to_uint8(TheRecord(arg)->recdata[i++]);
   p->peBlue = I_to_uint8(TheRecord(arg)->recdata[i++]);
   p->peFlags = I_to_uint8(TheRecord(arg)->recdata[i++]);
}
*/
// untested - was never called
// could be used in CheckColorsInGamut, but we use 8-bit bitvectors
static void processRGBQUAD_C(RGBQUAD* p, object args,DWORD length)
{
   int j;
   for(j = 0; j < length; j++,p++)
   {
      int i = 0;
      object arg = TheSvector(args)->data[j];
      p->rgbRed = I_to_uint8(TheRecord(arg)->recdata[i++]);
      p->rgbGreen = I_to_uint8(TheRecord(arg)->recdata[i++]);
      p->rgbBlue = I_to_uint8(TheRecord(arg)->recdata[i++]);
      p->rgbReserved = 0;
   }
}
static DWORD processCOLORREF(object arg)
{
  // check for int or struct
  if (integerp(arg)) {
    return I_to_uint32(arg);
  } else {
    int i = 0;
    BYTE r = I_to_uint8(TheRecord(arg)->recdata[i++]);
    BYTE g = I_to_uint8(TheRecord(arg)->recdata[i++]);
    BYTE b = I_to_uint8(TheRecord(arg)->recdata[i++]);
    return RGB(r,g,b);
  }
}
// untested - was never called
// NULL is for the identity transform
static void processXFORM(XFORM *p, object arg)
{
  if (nullp(arg)) {
    p = NULL;
  } else {
    int i = 0;
    ffloatjanus jfloat;
#if 0
    if (fpointerp(arg)) {
      //p = TheFvariable(obj)->fv_address;
      //pushSTACK(arg);
      //`foreign_pointer`;
      p = (XFORM*)ulong_to_I((uintP)TheFpointer(arg)->fp_pointer);
      return;
    }
#endif
    FF_to_c_float(TheRecord(arg)->recdata[i++],&jfloat);
    p->eM11 = (float)(jfloat.eksplicit);
    FF_to_c_float(TheRecord(arg)->recdata[i++],&jfloat);
    p->eM12 = (float)(jfloat.eksplicit);
    FF_to_c_float(TheRecord(arg)->recdata[i++],&jfloat);
    p->eM21 = (float)(jfloat.eksplicit);
    FF_to_c_float(TheRecord(arg)->recdata[i++],&jfloat);
    p->eM22 = (float)(jfloat.eksplicit);
    FF_to_c_float(TheRecord(arg)->recdata[i++],&jfloat);
    p->eDx = (float)(jfloat.eksplicit);
    FF_to_c_float(TheRecord(arg)->recdata[i++],&jfloat);
    p->eDy = (float)(jfloat.eksplicit);
  }
}
static object outputXFORM(XFORM *p){ 
  int i = 1;
  object arg;
  pushSTACK(arg);
  TheRecord(STACK_0)->recdata[i++] = allocate_ffloat(p->eM11);
  TheRecord(STACK_0)->recdata[i++] = allocate_ffloat(p->eM12);
  TheRecord(STACK_0)->recdata[i++] = allocate_ffloat(p->eM21);
  TheRecord(STACK_0)->recdata[i++] = allocate_ffloat(p->eM22);
  TheRecord(STACK_0)->recdata[i++] = allocate_ffloat(p->eDx);
  TheRecord(popSTACK())->recdata[i++] = allocate_ffloat(p->eDy);
  return arg;
}
static object outputABCFLOAT(ABCFLOAT *p){ 
  int i = 1;
  object arg;
  pushSTACK(arg);
  TheRecord(STACK_0)->recdata[i++] = allocate_ffloat(p->abcfA);
  TheRecord(STACK_0)->recdata[i++] = allocate_ffloat(p->abcfB);
  TheRecord(popSTACK())->recdata[i++] = allocate_ffloat(p->abcfC);
  return arg;
}
static void processLPSIZE(SIZE *p, object arg)
{
   int i = 1;
   p->cx = I_to_L(TheRecord(arg)->recdata[i++]);
   p->cy = I_to_L(TheRecord(arg)->recdata[i++]);
}
// Return a SIZE structure
static object outputLPSIZE(SIZE *lpsize)
{
  int i = 1;
  object arg;
  pushSTACK(arg);
  TheRecord(STACK_0)->recdata[i++] = fixnum(lpsize->cx);
  TheRecord(popSTACK())->recdata[i++] = fixnum(lpsize->cy);
  return arg;
}
// untested - was never called
// uninspected - compiles but code was not checked
static void processPOINT(POINT* p, object arg)
{
   int i = 0;
   p->x = I_to_sint32(TheRecord(arg)->recdata[i++]);
   p->y = I_to_sint32(TheRecord(arg)->recdata[i++]);
}
static object outputPOINT(POINT *p)
{
  int i = 1;
  object arg;
  pushSTACK(arg);
  TheRecord(STACK_0)->recdata[i++] = fixnum(p->x);
  TheRecord(popSTACK())->recdata[i++] = fixnum(p->y);
  return arg;
}

// untested - was never called
// uninspected - compiles but code was not checked
static void processRECT(RECT* p, object arg)
{
  int i = 0;
  p->left = I_to_sint32(TheRecord(arg)->recdata[i++]);
  p->top = I_to_sint32(TheRecord(arg)->recdata[i++]);
  p->right = I_to_sint32(TheRecord(arg)->recdata[i++]);
  p->bottom = I_to_sint32(TheRecord(arg)->recdata[i++]);
}
static void processPOLYTEXTA(POLYTEXTA* p, object arg)
{
  int i = 0;
  p->x = I_to_sint32(TheRecord(arg)->recdata[i++]);
  p->y = I_to_sint32(TheRecord(arg)->recdata[i++]);
  p->n = I_to_uint32(TheRecord(arg)->recdata[i++]);
  p->lpstr = (LPCSTR)TheAsciz(TheRecord(arg)->recdata[i++]);
  p->uiFlags = I_to_uint32(TheRecord(arg)->recdata[i++]);
  processRECT(&p->rcl, TheRecord(arg)->recdata[i++]);
  p->pdx = (int*)I_to_uint32(TheRecord(arg)->recdata[i++]);
}
// untested - was never called
static void processCOLORADJUSTMENT(COLORADJUSTMENT *p, object arg)
{
   int i;
   WORD *w = (WORD*)p;
   SHORT *s = (SHORT*)p;
   for(i = 0; i < 8; i++)w[i]= I_to_uint16(TheRecord(arg)->recdata[i]);
   for(; i < 12; i++)s[i] = I_to_sint16(TheRecord(arg)->recdata[i]);
}
static object outputCOLORADJUSTMENT(COLORADJUSTMENT *p){
    return allocate_fpointer((FOREIGN)p);
}
// untested - was never called
static void processPIXELFORMATDESCRIPTOR(PIXELFORMATDESCRIPTOR* p,object arg)
{
  int i = 0;
  p->nSize = I_to_uint16(TheRecord(arg)->recdata[i++]);
  p->nVersion = I_to_uint16(TheRecord(arg)->recdata[i++]);
  p->dwFlags = I_to_uint32(TheRecord(arg)->recdata[i++]);
  p->iPixelType = I_to_uint8(TheRecord(arg)->recdata[i++]);
  p->cColorBits = I_to_uint8(TheRecord(arg)->recdata[i++]);
  p->cRedBits = I_to_uint8(TheRecord(arg)->recdata[i++]);
  p->cRedShift = I_to_uint8(TheRecord(arg)->recdata[i++]);
  p->cGreenBits = I_to_uint8(TheRecord(arg)->recdata[i++]);
  p->cGreenShift = I_to_uint8(TheRecord(arg)->recdata[i++]);
  p->cBlueBits = I_to_uint8(TheRecord(arg)->recdata[i++]);
  p->cBlueShift = I_to_uint8(TheRecord(arg)->recdata[i++]);
  p->cAlphaBits = I_to_uint8(TheRecord(arg)->recdata[i++]);
  p->cAlphaShift = I_to_uint8(TheRecord(arg)->recdata[i++]);
  p->cAccumBits = I_to_uint8(TheRecord(arg)->recdata[i++]);
  p->cAccumRedBits = I_to_uint8(TheRecord(arg)->recdata[i++]);
  p->cAccumGreenBits = I_to_uint8(TheRecord(arg)->recdata[i++]);
  p->cAccumBlueBits = I_to_uint8(TheRecord(arg)->recdata[i++]);
  p->cAccumAlphaBits = I_to_uint8(TheRecord(arg)->recdata[i++]);
  p->cDepthBits = I_to_uint8(TheRecord(arg)->recdata[i++]);
  p->cStencilBits = I_to_uint8(TheRecord(arg)->recdata[i++]);
  p->cAuxBuffers = I_to_uint8(TheRecord(arg)->recdata[i++]);
  p->iLayerType = I_to_uint8(TheRecord(arg)->recdata[i++]);
  p->bReserved = I_to_uint8(TheRecord(arg)->recdata[i++]);
  p->dwLayerMask = I_to_uint32(TheRecord(arg)->recdata[i++]);
  p->dwVisibleMask = I_to_uint32(TheRecord(arg)->recdata[i++]);
  p->dwDamageMask = I_to_uint32(TheRecord(arg)->recdata[i++]);
}
// untested - was never called
// uninspected - compiles but code was not checked
// known not to work
static FIXED toFixed(float f)
{
  FIXED fixed;
  fixed.value = (int)f;
  fixed.fract = (WORD)(10000*(f - fixed.value));
  return fixed;
}

static void processMAT2(MAT2 *p, object arg)
{
  int i = 0;
  ffloatjanus f;
  FF_to_c_float(TheRecord(arg)->recdata[i++],&f);
  p->eM11 = toFixed((float)(f.eksplicit));
  FF_to_c_float(TheRecord(arg)->recdata[i++],&f);
  p->eM12 = toFixed((float)(f.eksplicit));
  FF_to_c_float(TheRecord(arg)->recdata[i++],&f);
  p->eM21 = toFixed((float)(f.eksplicit));
  FF_to_c_float(TheRecord(arg)->recdata[i++],&f);
  p->eM22 = toFixed((float)(f.eksplicit));
}
// untested - was never called
// uninspected - compiles but code was not checked
static void processBITMAP(BITMAP *p,object arg)
{
  int i = 0;
  p->bmType = (LONG)I_to_sint32(TheRecord(arg)->recdata[i++]);
  p->bmWidth = (LONG)I_to_sint32(TheRecord(arg)->recdata[i++]);
  p->bmHeight = (LONG)I_to_sint32(TheRecord(arg)->recdata[i++]);
  p->bmWidthBytes = (LONG)I_to_sint32(TheRecord(arg)->recdata[i++]);
  p->bmPlanes = (WORD)I_to_uint16(TheRecord(arg)->recdata[i++]);
  p->bmBitsPixel = (WORD)I_to_uint16(TheRecord(arg)->recdata[i++]);
  p->bmBits = (LPVOID)&TheSbvector( TheRecord(arg)->recdata[i++])->data[0];
}
// untested - was never called
// uninspected - compiles but code was not checked
static void processLOGBRUSH(LOGBRUSH* p, object arg)
{
   int i = 0;
   p->lbStyle = I_to_uint32(TheRecord(arg)->recdata[i++]);
   p->lbColor = processCOLORREF(TheRecord(arg)->recdata[i++]);
   p->lbHatch = I_to_sint32(TheRecord(arg)->recdata[i++]);
}
// untested - was never called
// uninspected - compiles but code was not checked
static void processMETAFILEPICT(METAFILEPICT *p,object arg)
{
  int i = 0;
  p->mm = I_to_sint32(TheRecord(arg)->recdata[i++]);
  p->xExt = I_to_sint32(TheRecord(arg)->recdata[i++]);
  p->yExt = I_to_sint32(TheRecord(arg)->recdata[i++]);
  p->hMF = TheFpointer(TheRecord(arg)->recdata[i++])->fp_pointer;
}

static void processWNDCLASSA(WNDCLASSA *p, object arg)
{
  object s;
  int i = 1;
  p->style = I_to_uint32(TheRecord(arg)->recdata[i++]);
  p->lpfnWndProc  = WindowProc;
  p->cbClsExtra = I_to_sint32(TheRecord(arg)->recdata[i++]);
  p->cbWndExtra = I_to_sint32(TheRecord(arg)->recdata[i++]);
  p->hInstance = TheFpointer(TheRecord(arg)->recdata[i++])->fp_pointer;
  s = TheRecord(arg)->recdata[i++];
  p->hIcon = nullp(s)?0:TheFpointer(s)->fp_pointer;
  p->hCursor = TheFpointer(TheRecord(arg)->recdata[i++])->fp_pointer;
  p->hbrBackground = TheFpointer(TheRecord(arg)->recdata[i++])->fp_pointer;
  s = TheRecord(arg)->recdata[i++];
  if(nullp(s))
  {
     p->lpszMenuName = NULL;
  }
  else if(stringp(s))
  {
     p->lpszMenuName = (LPCSTR)TheAsciz(string_to_asciz(s,encoding));
  }
  else if(fpointerp(s))
  {
     p->lpszMenuName = TheFpointer(s)->fp_pointer;
  }
  else invalid_argument(s);
  s = TheRecord(arg)->recdata[i++];
  p->lpszClassName = (LPCSTR)(stringp(s)?
                              TheAsciz(string_to_asciz(s,encoding)):
                              TheFpointer(s)->fp_pointer);
}

static void processWNDCLASSW(WNDCLASSW *p, object arg){ assert(0); }

static void processCREATESTRUCTA(CREATESTRUCT *p, object arg)
{
  object s;
  int i = 1;
  p->dwExStyle = I_to_uint32(TheRecord(arg)->recdata[i++]);
  s = TheRecord(arg)->recdata[i++];
  p->lpszClass = stringp(s)?
      (LPCSTR)TheAsciz(string_to_asciz(s,encoding)):
      TheFpointer(s)->fp_pointer;
  p->lpszName = stringp(s)?
      (LPCSTR)TheAsciz(string_to_asciz(TheRecord(arg)->recdata[i++],encoding)):
      TheFpointer(s)->fp_pointer;
  p->style = I_to_uint32(TheRecord(arg)->recdata[i++]);
  p->x = I_to_L(TheRecord(arg)->recdata[i++]);
  p->y = I_to_L(TheRecord(arg)->recdata[i++]);
  p->cx = I_to_L(TheRecord(arg)->recdata[i++]);
  p->cy = I_to_L(TheRecord(arg)->recdata[i++]);
  s = TheRecord(arg)->recdata[i++];
  p->hwndParent = nullp(s)?0:TheFpointer(s)->fp_pointer;
  s = TheRecord(arg)->recdata[i++];
  p->hMenu = nullp(s)?0:TheFpointer(s)->fp_pointer;
  s = TheRecord(arg)->recdata[i++];
  p->hInstance = nullp(s)?0:TheFpointer(s)->fp_pointer;
  p->lpCreateParams = 0;  //= I_to_uint8(TheRecord(arg)->recdata[i++]);
}
// unused
static object outputCREATESTRUCTA(CREATESTRUCT *p)
{
  int i = 1;
  object arg;
  pushSTACK(arg);
  TheRecord(STACK_0)->recdata[i++] = UL_to_I(p->dwExStyle);
  TheRecord(STACK_0)->recdata[i++] = p->lpszClass?
      asciz_to_string((const char*)p->lpszClass,encoding):
      O(fp_zero);
  TheRecord(STACK_0)->recdata[i++] = p->lpszName?
      asciz_to_string((const char*)p->lpszName,encoding):
      O(fp_zero);
  TheRecord(STACK_0)->recdata[i++] = UL_to_I(p->style);
  TheRecord(STACK_0)->recdata[i++] = L_to_I(p->x);
  TheRecord(STACK_0)->recdata[i++] = L_to_I(p->y);
  TheRecord(STACK_0)->recdata[i++] = L_to_I(p->cx);
  TheRecord(STACK_0)->recdata[i++] = L_to_I(p->cy);
  TheRecord(STACK_0)->recdata[i++] = allocate_fpointer((FOREIGN)p->hwndParent);
  TheRecord(STACK_0)->recdata[i++] = allocate_fpointer((FOREIGN)p->hMenu);
  TheRecord(STACK_0)->recdata[i++] = allocate_fpointer((FOREIGN)p->hInstance);
  TheRecord(popSTACK())->recdata[i++] = NIL; //L_to_I(p->lpCreateParams);
  return arg;
}
static object outputTEXTMETRICA(TEXTMETRICA *p)
{
  int i = 1;
  object arg;
  pushSTACK(arg);
  TheRecord(STACK_0)->recdata[i++] = fixnum(p->tmHeight);
  TheRecord(STACK_0)->recdata[i++] = fixnum(p->tmAscent);
  TheRecord(STACK_0)->recdata[i++] = fixnum(p->tmDescent);
  TheRecord(STACK_0)->recdata[i++] = fixnum(p->tmInternalLeading);
  TheRecord(STACK_0)->recdata[i++] = fixnum(p->tmExternalLeading);
  TheRecord(STACK_0)->recdata[i++] = fixnum(p->tmAveCharWidth);
  TheRecord(STACK_0)->recdata[i++] = fixnum(p->tmMaxCharWidth);
  TheRecord(STACK_0)->recdata[i++] = fixnum(p->tmWeight);
  TheRecord(STACK_0)->recdata[i++] = fixnum(p->tmOverhang);
  TheRecord(STACK_0)->recdata[i++] = fixnum(p->tmDigitizedAspectX);
  TheRecord(STACK_0)->recdata[i++] = fixnum(p->tmDigitizedAspectY);
  TheRecord(STACK_0)->recdata[i++] = fixnum(p->tmFirstChar);
  TheRecord(STACK_0)->recdata[i++] = fixnum(p->tmLastChar);
  TheRecord(STACK_0)->recdata[i++] = fixnum(p->tmDefaultChar);
  TheRecord(STACK_0)->recdata[i++] = fixnum(p->tmBreakChar);
  TheRecord(STACK_0)->recdata[i++] = fixnum(p->tmItalic);
  TheRecord(STACK_0)->recdata[i++] = fixnum(p->tmUnderlined);
  TheRecord(STACK_0)->recdata[i++] = fixnum(p->tmStruckOut);
  TheRecord(STACK_0)->recdata[i++] = fixnum(p->tmPitchAndFamily);
  TheRecord(popSTACK())->recdata[i++] = fixnum(p->tmCharSet);
  return arg;
}
static object outputTEXTMETRICW(TEXTMETRICW *p)
{
  int i = 1;
  object arg;
  pushSTACK(arg);
  TheRecord(STACK_0)->recdata[i++] = fixnum(p->tmHeight);
  TheRecord(STACK_0)->recdata[i++] = fixnum(p->tmAscent);
  TheRecord(STACK_0)->recdata[i++] = fixnum(p->tmDescent);
  TheRecord(STACK_0)->recdata[i++] = fixnum(p->tmInternalLeading);
  TheRecord(STACK_0)->recdata[i++] = fixnum(p->tmExternalLeading);
  TheRecord(STACK_0)->recdata[i++] = fixnum(p->tmAveCharWidth);
  TheRecord(STACK_0)->recdata[i++] = fixnum(p->tmMaxCharWidth);
  TheRecord(STACK_0)->recdata[i++] = fixnum(p->tmWeight);
  TheRecord(STACK_0)->recdata[i++] = fixnum(p->tmOverhang);
  TheRecord(STACK_0)->recdata[i++] = fixnum(p->tmDigitizedAspectX);
  TheRecord(STACK_0)->recdata[i++] = fixnum(p->tmDigitizedAspectY);
  TheRecord(STACK_0)->recdata[i++] = fixnum(p->tmFirstChar);
  TheRecord(STACK_0)->recdata[i++] = fixnum(p->tmLastChar);
  TheRecord(STACK_0)->recdata[i++] = fixnum(p->tmDefaultChar);
  TheRecord(STACK_0)->recdata[i++] = fixnum(p->tmBreakChar);
  TheRecord(STACK_0)->recdata[i++] = fixnum(p->tmItalic);
  TheRecord(STACK_0)->recdata[i++] = fixnum(p->tmUnderlined);
  TheRecord(STACK_0)->recdata[i++] = fixnum(p->tmStruckOut);
  TheRecord(STACK_0)->recdata[i++] = fixnum(p->tmPitchAndFamily);
  TheRecord(popSTACK())->recdata[i++] = fixnum(p->tmCharSet);
  return arg;
}
static object outputFLOATS(FLOAT *f, UINT length){
    return allocate_ffloat((ffloat)*f);
}
static void processCURSORINFO(CURSORINFO *c, object arg){
  object s;
  int i = 1;
  c->cbSize  = I_to_uint32(TheRecord(arg)->recdata[i++]);
  c->flags   = I_to_uint32(TheRecord(arg)->recdata[i++]);
  s = TheRecord(arg)->recdata[i++];
  c->hCursor = nullp(s)?0:TheFpointer(s)->fp_pointer;
  c->ptScreenPos.x = I_to_L(TheRecord(arg)->recdata[i++]);
  c->ptScreenPos.y = I_to_L(TheRecord(arg)->recdata[i++]);
}
static object outputCURSORINFO(CURSORINFO *c)
{
  int i = 1;
  object arg;
  pushSTACK(arg);
  TheRecord(STACK_0)->recdata[i++] = UL_to_I(c->cbSize);
  TheRecord(STACK_0)->recdata[i++] = UL_to_I(c->flags);
  TheRecord(STACK_0)->recdata[i++] = allocate_fpointer((FOREIGN)c->hCursor);
  TheRecord(STACK_0)->recdata[i++] = fixnum(c->ptScreenPos.x);
  TheRecord(popSTACK())->recdata[i++] = fixnum(c->ptScreenPos.y);
  return arg;
}
static object outputGCP_RESULTSA(GCP_RESULTSA* p){
  int i = 1;
  object arg;
  pushSTACK(arg);
  TheRecord(STACK_0)->recdata[i++] = fixnum(p->lStructSize);
  TheRecord(STACK_0)->recdata[i++] = p->lpOutString?
      asciz_to_string((const char*)p->lpOutString,encoding):
      O(fp_zero);
  /* TODO: simple_int bitvectors */
  TheRecord(STACK_0)->recdata[i++] = p->lpOrder?
      allocate_fpointer((FOREIGN)p->lpOrder):O(fp_zero);
  TheRecord(STACK_0)->recdata[i++] = p->lpDx?
      allocate_fpointer((FOREIGN)p->lpDx):O(fp_zero);
  TheRecord(STACK_0)->recdata[i++] = p->lpCaretPos?
      allocate_fpointer((FOREIGN)p->lpCaretPos):O(fp_zero);
  TheRecord(STACK_0)->recdata[i++] = p->lpClass?
      asciz_to_string((const char*)p->lpClass,encoding):
      O(fp_zero);
  TheRecord(STACK_0)->recdata[i++] = UL_to_I(p->nGlyphs);
  TheRecord(popSTACK())->recdata[i++] = UL_to_I(p->nMaxFit);
  return arg;
}
static object outputGCP_RESULTSW(GCP_RESULTSW* p){ 
  int i = 1;
  object arg;
  pushSTACK(arg);
  TheRecord(STACK_0)->recdata[i++] = fixnum(p->lStructSize);
  /* TODO: convert to S16string */
  TheRecord(STACK_0)->recdata[i++] = p->lpOutString?
    outputLPWSTR(p->lpOutString,0):O(fp_zero);
  /* TODO: int bitvectors */
  TheRecord(STACK_0)->recdata[i++] = p->lpOrder?
    allocate_fpointer((FOREIGN)p->lpOrder):O(fp_zero);
  TheRecord(STACK_0)->recdata[i++] = p->lpDx?
    allocate_fpointer((FOREIGN)p->lpDx):O(fp_zero);
  TheRecord(STACK_0)->recdata[i++] = p->lpCaretPos?
    allocate_fpointer((FOREIGN)p->lpCaretPos):O(fp_zero);
  /* TODO: convert to S16string */
  TheRecord(STACK_0)->recdata[i++] = p->lpClass?
    outputLPWSTR(p->lpClass,0):O(fp_zero);
  TheRecord(STACK_0)->recdata[i++] = UL_to_I(p->nGlyphs);
  TheRecord(popSTACK())->recdata[i++] = UL_to_I(p->nMaxFit);
  return arg;
}
