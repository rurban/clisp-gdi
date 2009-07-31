BOOL 		AlphaBlend(HDC,int,int,int,int,HDC,int,int,int,int,BLENDFUNCTION);
BOOL 		GradientFill(HDC,PTRIVERTEX,ULONG,PVOID,ULONG,ULONG);
BOOL 		TransparentBlt(HDC,int,int,int,int,HDC,int,int,int,int,UINT);
COLORREF     	GetDCPenColor(HDC);
COLORREF     	GetDCBrushColor(HDC);
