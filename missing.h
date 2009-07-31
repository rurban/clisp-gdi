BOOL         GetTextExtentExPointI(HDC,LPWORD,int,int,LPINT,LPINT,LPSIZE);
int  	     DeviceCapabilitiesExA(LPCSTR,LPCSTR,WORD,LPSTR,DEVMODEA*);
int  	     DeviceCapabilitiesExW(LPCWSTR,LPCWSTR,WORD,LPWSTR,DEVMODEW*);
int 	     GetRelAbs(HDC,DWORD);
int	     SetRelAbs(HDC,int);
HBRUSH       SelectBrushLocal(HBRUSH,HBRUSH);
HFONT        SelectFontLocal(HFONT,HFONT);
BOOL 	     GetFontResourceInfo(LPCTSTR,LPDWORD,LPVOID,DWORD);
BOOL 	     GetFontResourceInfoW(LPCWSTR,LPDWORD,LPVOID,DWORD);
SetFontEnumeration
GdiPlayDCScript
GdiPlayJournal
GdiPlayScript
GetGlyphOutlineWow
