#line 2 "funcs-msimg.c"
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:AlphaBlend,&rest r)
{
  object arg, arg0;
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
  BLENDFUNCTION *blendfunction;
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  blendfunction = (BLENDFUNCTION*)TheFpointer(arg)->fp_pointer;
  int7 = I_to_sint32(check_sint(popSTACK()));
  int6 = I_to_sint32(check_sint(popSTACK()));
  int5 = I_to_sint32(check_sint(popSTACK()));
  int4 = I_to_sint32(check_sint(popSTACK()));
  arg = popSTACK();
  processFPTYPE(HDC,hdc0,arg);
  int3 = I_to_sint32(check_sint(popSTACK()));
  int2 = I_to_sint32(check_sint(popSTACK()));
  int1 = I_to_sint32(check_sint(popSTACK()));
  int0 = I_to_sint32(check_sint(popSTACK()));
  arg = popSTACK();
  processFPTYPE(HDC,hdc,arg);
  begin_call();
  bool0 = AlphaBlend(hdc,int0,int1,int2,int3,hdc0,int4,int5,int6,int7,*blendfunction);
  end_call();
  if(!bool0){
    do_GDI_ERROR("AlphaBlend");
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
DEFUN( GDI:GradientFill,&rest r)
{
  object arg, arg0;
  BOOL bool0;
  HDC hdc;
  PTRIVERTEX ptrivertex;
  ULONG ulong;
  void* pvoid;
  ULONG ulong0;
  ULONG ulong1;
  ulong1 = I_to_uint32(check_uint(popSTACK()));
  ulong0 = I_to_uint32(check_uint(popSTACK()));
  arg = popSTACK();
  if(!simple_bit_vector_p(Atype_8Bit,arg))invalid_argument(arg);
  pvoid = (void*)&(TheSbvector(arg)->data);
  ulong = I_to_uint32(check_uint(popSTACK()));
  arg0 = popSTACK();
  processFPTYPE(PTRIVERTEX,ptrivertex,arg0);
  arg = popSTACK();
  processFPTYPE(HDC,hdc,arg);
  begin_call();
  bool0 = GradientFill(hdc,ptrivertex,ulong,pvoid,ulong0,ulong1);
  end_call();
  if(!bool0){
    do_GDI_ERROR("GradientFill");
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
DEFUN( GDI:TransparentBlt,&rest r)
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
  UINT uint;
  uint = I_to_uint32(check_uint(popSTACK()));
  int7 = I_to_sint32(check_sint(popSTACK()));
  int6 = I_to_sint32(check_sint(popSTACK()));
  int5 = I_to_sint32(check_sint(popSTACK()));
  int4 = I_to_sint32(check_sint(popSTACK()));
  arg = popSTACK();
  processFPTYPE(HDC,hdc0,arg);
  int3 = I_to_sint32(check_sint(popSTACK()));
  int2 = I_to_sint32(check_sint(popSTACK()));
  int1 = I_to_sint32(check_sint(popSTACK()));
  int0 = I_to_sint32(check_sint(popSTACK()));
  arg = popSTACK();
  processFPTYPE(HDC,hdc,arg);
  begin_call();
  bool0 = TransparentBlt(hdc,int0,int1,int2,int3,hdc0,int4,int5,int6,int7,uint);
  end_call();
  if(!bool0){
    do_GDI_ERROR("TransparentBlt");
  }
  else
  {
    value1 = T;
    mv_count=1;
  }
  return;
}
// cygwin w32api error: linked to msimg32, but defined in gdi32.
// cd full; strace ./lisp
// --- Process 884, exception C0000139 at 7C966668
// The procedure entry point GetDCBrushColor could not be located in the dynamic link library MSIMG32.DLL
// untested - was never called
// written by hand
/*
DEFUN( GDI:GetDCPenColor, hdc)
{
  object arg;
  HDC hdc;
  COLORREF colorref;
  getHDC(hdc,arg);
  begin_system_call();
  colorref = GetDCPenColor(hdc);
  end_system_call();
  if(CLR_INVALID == colorref){
    do_GDI_ERROR("GetDCPenColor");
  }
  else
  {
    VALUES1(fixnum(colorref));
  }
  return;
}
// cygwin w32api error: linked to msimg32, but defined in gdi32
// untested - was never called
// written by hand
DEFUN( GDI:GetDCBrushColor, hdc)
{
  object arg;
  HDC hdc;
  COLORREF colorref;
  getHDC(hdc,arg);
  begin_system_call();
  colorref = GetDCBrushColor(hdc);
  end_system_call();
  if(CLR_INVALID == colorref){
    do_GDI_ERROR("GetDCBrushColor");
  }
  else
  {
    VALUES1(fixnum(colorref));
  }
  return;
}
*/
