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
      value2 = allocate_fpointer((FOREIGN)henhmetafile0);
      mv_count=2;
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
    value2 = allocate_fpointer((FOREIGN)henhmetafile0);
    mv_count=2;
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
      value2 = allocate_fpointer((FOREIGN)hmetafile0);
      mv_count=2;
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
    value2 = allocate_fpointer((FOREIGN)hmetafile0);
    mv_count=2;
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
DEFUN( GDI:CreateColorSpaceA, lplogcolorspacea)
{
  object arg;
  HCOLORSPACE hcolorspace;
  LOGCOLORSPACEA* lplogcolorspacea = alloca(sizeof(LOGCOLORSPACEA));
  object arg0;
  arg0 = popSTACK();
  processLOGCOLORSPACEA(lplogcolorspacea,arg0);
  begin_system_call();
  hcolorspace = CreateColorSpaceA(lplogcolorspacea);
  end_system_call();
  if(NULL ==hcolorspace){
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
    value2 = allocate_fpointer((FOREIGN)hcolorspace);
    mv_count=2;
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:CreateColorSpaceW, lplogcolorspacew)
{
  object arg;
  HCOLORSPACE hcolorspace;
  LOGCOLORSPACEW* lplogcolorspacew = alloca(sizeof(LOGCOLORSPACEW));
  object arg0;
  arg0 = popSTACK();
  processLOGCOLORSPACEW(lplogcolorspacew,arg0);
  begin_system_call();
  hcolorspace = CreateColorSpaceW(lplogcolorspacew);
  end_system_call();
  if(NULL ==hcolorspace){
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
    value2 = allocate_fpointer((FOREIGN)hcolorspace);
    mv_count=2;
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
  DEVMODEA* devmodea_p = alloca(sizeof(DEVMODEA));
  object arg0;
  arg0 = popSTACK();
  processDEVMODEA(devmodea_p,arg0);
  arg = popSTACK();
  if(!stringp(arg))invalid_argument(arg);
  with_string_0(arg,encoding, lpcstr1, {
    arg = popSTACK();
    if(!stringp(arg))invalid_argument(arg);
    with_string_0(arg,encoding, lpcstr0, {
      arg = popSTACK();
      if(!stringp(arg))invalid_argument(arg);
      with_string_0(arg,encoding, lpcstr, {
        processDEVMODEA(devmodea_p,arg0);
        begin_system_call();
        hdc = CreateDCA(lpcstr,lpcstr0,lpcstr1,devmodea_p);
        end_system_call();
        if(NULL ==hdc){
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
          value2 = allocate_fpointer((FOREIGN)hdc);
          mv_count=2;
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
  DEVMODEW* devmodew_p = alloca(sizeof(DEVMODEW));
  object arg0;
  arg0 = popSTACK();
  processDEVMODEW(devmodew_p,arg0);
  arg = popSTACK();
  if(!stringp(arg))invalid_argument(arg);
  lpcwstr1 = WIDECHAR(arg,encoding);
  arg = popSTACK();
  if(!stringp(arg))invalid_argument(arg);
  lpcwstr0 = WIDECHAR(arg,encoding);
  arg = popSTACK();
  if(!stringp(arg))invalid_argument(arg);
  lpcwstr = WIDECHAR(arg,encoding);
  processDEVMODEW(devmodew_p,arg0);
  begin_system_call();
  hdc = CreateDCW(lpcwstr,lpcwstr0,lpcwstr1,devmodew_p);
  end_system_call();
  if(NULL ==hdc){
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
    value2 = allocate_fpointer((FOREIGN)hdc);
    mv_count=2;
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
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hdc = TheFpointer(arg)->fp_pointer;
  processRECT(lpcrect,arg0);
  begin_system_call();
  hdc0 = CreateEnhMetaFileW(hdc,lpcwstr,lpcrect,lpcwstr0);
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
    value2 = allocate_fpointer((FOREIGN)hfont);
    mv_count=2;
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
    value2 = allocate_fpointer((FOREIGN)hfont);
    mv_count=2;
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
  DEVMODEA* devmodea_p = alloca(sizeof(DEVMODEA));
  object arg0;
  arg0 = popSTACK();
  processDEVMODEA(devmodea_p,arg0);
  arg = popSTACK();
  if(!stringp(arg))invalid_argument(arg);
  with_string_0(arg,encoding, lpcstr1, {
    arg = popSTACK();
    if(!stringp(arg))invalid_argument(arg);
    with_string_0(arg,encoding, lpcstr0, {
      arg = popSTACK();
      if(!stringp(arg))invalid_argument(arg);
      with_string_0(arg,encoding, lpcstr, {
        processDEVMODEA(devmodea_p,arg0);
        begin_system_call();
        hdc = CreateICA(lpcstr,lpcstr0,lpcstr1,devmodea_p);
        end_system_call();
        if(NULL ==hdc){
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
          value2 = allocate_fpointer((FOREIGN)hdc);
          mv_count=2;
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
  DEVMODEW* devmodew_p = alloca(sizeof(DEVMODEW));
  object arg0;
  arg0 = popSTACK();
  processDEVMODEW(devmodew_p,arg0);
  arg = popSTACK();
  if(!stringp(arg))invalid_argument(arg);
  lpcwstr1 = WIDECHAR(arg,encoding);
  arg = popSTACK();
  if(!stringp(arg))invalid_argument(arg);
  lpcwstr0 = WIDECHAR(arg,encoding);
  arg = popSTACK();
  if(!stringp(arg))invalid_argument(arg);
  lpcwstr = WIDECHAR(arg,encoding);
  processDEVMODEW(devmodew_p,arg0);
  begin_system_call();
  hdc = CreateICW(lpcwstr,lpcwstr0,lpcwstr1,devmodew_p);
  end_system_call();
  if(NULL ==hdc){
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
    value2 = allocate_fpointer((FOREIGN)hdc);
    mv_count=2;
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:CreateIconFromResource, pbyte dword bool0 dword0)
{
  object arg;
  object arg0;
  HICON hicon;
  PBYTE pbyte;
  DWORD dword;
  BOOL bool0;
  DWORD dword0;
  dword0 = I_to_uint32(check_uint(popSTACK()));
  arg0 = popSTACK();
  processBOOL(&bool0,arg0);
  dword = I_to_uint32(check_uint(popSTACK()));
  arg0 = popSTACK();
  processPBYTE(pbyte,arg0);
  begin_system_call();
  hicon = CreateIconFromResource(pbyte,dword,bool0,dword0);
  end_system_call();
  if(NULL ==hicon){
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
    value2 = allocate_fpointer((FOREIGN)hicon);
    mv_count=2;
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
    value2 = allocate_fpointer((FOREIGN)hicon);
    mv_count=2;
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
      value2 = allocate_fpointer((FOREIGN)hdc);
      mv_count=2;
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
    value2 = allocate_fpointer((FOREIGN)hdc);
    mv_count=2;
  }
  return;
}
// untested - was never called
// uninspected - compiles but code was not checked
DEFUN( GDI:CreatePalette, logpalette_p)
{
  object arg;
  HPALETTE hpalette;
  LOGPALETTE* logpalette_p = alloca(sizeof(LOGPALETTE));
  object arg0;
  arg0 = popSTACK();
  processLOGPALETTE(logpalette_p,arg0);
  processLOGPALETTE(logpalette_p,arg0);
  begin_system_call();
  hpalette = CreatePalette(logpalette_p);
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
DEFUN( GDI:CreatePenIndirect, logpen_p)
{
  object arg;
  HPEN hpen;
  LOGPEN* logpen_p = alloca(sizeof(LOGPEN));
  object arg0;
  arg0 = popSTACK();
  processLOGPEN(logpen_p,arg0);
  processLOGPEN(logpen_p,arg0);
  begin_system_call();
  hpen = CreatePenIndirect(logpen_p);
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
DEFUN( GDI:CreateRectRgnIndirect, lpcrect)
{
  object arg;
  HRGN hrgn;
  RECT* lpcrect = alloca(sizeof(RECT));
  object arg0;
  arg0 = popSTACK();
  processRECT(lpcrect,arg0);
  processRECT(lpcrect,arg0);
  begin_system_call();
  hrgn = CreateRectRgnIndirect(lpcrect);
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
    value2 = allocate_fpointer((FOREIGN)hwnd);
    mv_count=2;
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
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hdc = TheFpointer(arg)->fp_pointer;
  processRECT(lpcrect,arg0);
  begin_system_call();
  bool0 = FillRect(hdc,lpcrect,hbrush);
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
    value2 = allocate_fpointer((FOREIGN)h0);
    mv_count=2;
  }
  return;
}
// Nothing in the docs indicates that this function can return a error code,
// so to be consistant, I will return T and the result.

// tested ok
DEFUN( GDI:GetDeviceCaps, hdc int0)
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
  int1 = GetDeviceCaps(hdc,int0);
  end_system_call();
  if(int1 <= 0){
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
  value1 = sint32_to_I(int1);
  mv_count=1;
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
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hdc = TheFpointer(arg)->fp_pointer;
  processRECT(lpcrect,arg0);
  begin_system_call();
  bool0 = PlayEnhMetaFile(hdc,henhmetafile,lpcrect);
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
  processRECT(lpcrect,arg0);
  begin_system_call();
  bool0 = RectInRegion(hrgn,lpcrect);
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
DEFUN( GDI:RectVisible, hdc lpcrect)
{
  object arg;
  BOOL bool0;
  HDC hdc;
  RECT* lpcrect = alloca(sizeof(RECT));
  object arg0;
  arg0 = popSTACK();
  processRECT(lpcrect,arg0);
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hdc = TheFpointer(arg)->fp_pointer;
  processRECT(lpcrect,arg0);
  begin_system_call();
  bool0 = RectVisible(hdc,lpcrect);
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
DEFUN( GDI:ResetDCA, hdc devmodea_p)
{
  object arg;
  HDC hdc0;
  HDC hdc;
  DEVMODEA* devmodea_p = alloca(sizeof(DEVMODEA));
  object arg0;
  arg0 = popSTACK();
  processDEVMODEA(devmodea_p,arg0);
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hdc = TheFpointer(arg)->fp_pointer;
  processDEVMODEA(devmodea_p,arg0);
  begin_system_call();
  hdc0 = ResetDCA(hdc,devmodea_p);
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
DEFUN( GDI:ResetDCW, hdc devmodew_p)
{
  object arg;
  HDC hdc0;
  HDC hdc;
  DEVMODEW* devmodew_p = alloca(sizeof(DEVMODEW));
  object arg0;
  arg0 = popSTACK();
  processDEVMODEW(devmodew_p,arg0);
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hdc = TheFpointer(arg)->fp_pointer;
  processDEVMODEW(devmodew_p,arg0);
  begin_system_call();
  hdc0 = ResetDCW(hdc,devmodew_p);
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
  if(!fpointerp(arg))invalid_argument(arg);
  hpalette = TheFpointer(arg)->fp_pointer;
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hdc = TheFpointer(arg)->fp_pointer;
  begin_system_call();
  hpalette0 = SelectPalette(hdc,hpalette,bool0);
  end_system_call();
  if(NULL ==hpalette0){
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
    value2 = allocate_fpointer((FOREIGN)hpalette0);
    mv_count=2;
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
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hdc = TheFpointer(arg)->fp_pointer;
  processCOLORADJUSTMENT(coloradjustment_p,arg0);
  begin_system_call();
  bool0 = SetColorAdjustment(hdc,coloradjustment_p);
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
DEFUN( GDI:SetDeviceGammaRamp, hdc pvoid)
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
  bool0 = SetDeviceGammaRamp(hdc,pvoid);
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
DEFUN( GDI:SetICMProfileA, hdc lpstr)
{
  object arg;
  BOOL bool0;
  HDC hdc;
  LPSTR lpstr;
  arg = popSTACK();
  if(!stringp(arg))invalid_argument(arg);
  lpstr = TheAsciz(string_to_asciz(arg,encoding));
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hdc = TheFpointer(arg)->fp_pointer;
  begin_system_call();
  bool0 = SetICMProfileA(hdc,lpstr);
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
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hdc = TheFpointer(arg)->fp_pointer;
  begin_system_call();
  bool0 = SetICMProfileW(hdc,lpwstr);
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
  bool0 = SetPixelV(hdc,int0,int1,colorref);
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
DEFUN( GDI:SetTextColor, hdc colorref)
{
  object arg;
  COLORREF colorref0;
  HDC hdc;
  COLORREF colorref;
  arg = popSTACK();
  colorref = processCOLORREF(arg);
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hdc = TheFpointer(arg)->fp_pointer;
  begin_system_call();
  colorref0 = SetTextColor(hdc,colorref);
  end_system_call();
  if(CLR_INVALID == colorref0){
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
    value2 = fixnum(colorref0);
    mv_count=2;
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
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hdc = TheFpointer(arg)->fp_pointer;
  processXFORM(xform_p,arg0);
  begin_system_call();
  bool0 = SetWorldTransform(hdc,xform_p);
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
DEFUN( GDI:DestroyCursor, hcursor)
{
  object arg;
  BOOL bool0;
  HCURSOR hcursor;
  object arg0;
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hcursor = TheFpointer(arg)->fp_pointer;
  begin_system_call();
  bool0 = DestroyCursor(hcursor);
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
// written by hand
DEFUN( GDI:SetCursor, hcursor)
{
  object arg;
  BOOL bool0;
  HCURSOR hcursor, hcursor0;
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hcursor = (HCURSOR)TheFpointer(arg)->fp_pointer;
  begin_system_call();
  hcursor0 = SetCursor(hcursor);
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
    value2 = allocate_fpointer((FOREIGN)hcursor0);
    mv_count=2;
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
// written by hand
DEFUN( GDI:ChangeCursor, hwnd hcursor0)
{
  object arg;
  HWND hwnd;
  HCURSOR hcursor0, hcursor;
  object arg0;
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hcursor0 = TheFpointer(arg)->fp_pointer;
  arg0 = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg0);
  hwnd = TheFpointer(arg0)->fp_pointer;
  begin_system_call();
  hcursor = (HCURSOR)SetClassLong(hwnd, GCL_HCURSOR, (LONG) hcursor0);
  end_system_call();
  if(!hcursor){
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
    value2 = sint32_to_I(lppoint->x);
    value3 = sint32_to_I(lppoint->y);
    mv_count=3;
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
  arg = popSTACK();
  check_sint(arg);
  int1 = I_to_sint32(arg);
  arg = popSTACK();
  check_sint(arg);
  int0 = I_to_sint32(arg);
  begin_system_call();
  bool0 = SetCursorPos(int0, int1);
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
// written by hand
DEFUN( GDI:GetCursorInfo, pcursorinfo)
{
  BOOL bool0;
  CURSORINFO pcursorinfo;
  object arg0; 
  arg0 = popSTACK();
  processCURSORINFO(&pcursorinfo,arg0); 
  begin_system_call();
  bool0 = GetCursorInfo(&pcursorinfo);
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
    outputCURSORINFO(&pcursorinfo,arg0);
    value1 = T;
    mv_count=1;
  }
  return;
}
// cygwin w32api error: linked to msimg32, but defined in gdi32
// written by hand
/*
DEFUN( GDI:GetDCPenColor, hdc)
{
  object arg;
  HDC hdc;
  COLORREF colorref;
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hdc = TheFpointer(arg)->fp_pointer;
  begin_system_call();
  colorref = GetDCPenColor(hdc);
  end_system_call();
  if(CLR_INVALID == colorref){
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
    value2 = fixnum(colorref);
    mv_count=2;
  }
  return;
}
*/
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
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hdc = TheFpointer(arg)->fp_pointer;
  begin_system_call();
  colorref0 = SetDCPenColor(hdc,colorref);
  end_system_call();
  if(CLR_INVALID == colorref0){
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
    value2 = fixnum(colorref0);
    mv_count=2;
  }
  return;
}
// cygwin w32api error: linked to msimg32, but defined in gdi32
// written by hand
/*
DEFUN( GDI:GetDCBrushColor, hdc)
{
  object arg;
  HDC hdc;
  COLORREF colorref;
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hdc = TheFpointer(arg)->fp_pointer;
  begin_system_call();
  colorref = GetDCBrushColor(hdc);
  end_system_call();
  if(CLR_INVALID == colorref){
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
    value2 = fixnum(colorref);
    mv_count=2;
  }
  return;
}
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
  arg = popSTACK();
  if(!fpointerp(arg))invalid_argument(arg);
  hdc = TheFpointer(arg)->fp_pointer;
  begin_system_call();
  colorref0 = SetDCBrushColor(hdc,colorref);
  end_system_call();
  if(CLR_INVALID == colorref0){
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
    value2 = fixnum(colorref0);
    mv_count=2;
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
    value2 = allocate_fpointer((FOREIGN)h0);
    mv_count=2;
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
    value2 = allocate_fpointer((FOREIGN)h0);
    mv_count=2;
  }
  return;
}
