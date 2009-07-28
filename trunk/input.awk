function doIdent( type, name, arg) {
    if(type ~ /^H.*/) {
       return (name " = TheFpointer("arg")->fp_pointer;")
    }
    else if( "DWORD" == type || "UINT" == type || "DWORD32" == type ||
              "COLORREF" == type) {
       return (name " = I_to_uint32("arg");")
    }
    else if( "int" == type || "INT" == type || "LONG" == type || "LPARAM"==type){
       return (name " = I_to_sint32("arg");")
    }
    else if( "LPSTR" == type || "LPCSTR" == type) {
       return (name " = string_to_asciz("arg",encoding);")
    }
    else if( "LPWSTR" == type || "LPCWSTR" == type) {
       return (name " = WIDECHAR("arg",encoding);")
    }
    else if( "float" == type || "FLOAT" == type) {
       return (name " = ffloat_value("arg");")
    }
    else if("BYTE_P" == type) {
       return (name " = &(TheSbvector("arg")->data);")
    }
    else if("INT_P" == type || "DWORD_P" == type || "LPINT" == type) {
       return (name " = &(TheSbvector("arg")->data);")
    }
    else if("PVOID" == type || "PCVOID" == type) {
       return (name " = &(TheSbvector("arg")->data);")
    }
    else if(type ~ /^LPC.*/) {
       return (name " = &(TheSbvector("arg")->data);")
    }
    else if(type ~ /^LP.*/) {
       return (name " = &(TheSbvector("arg")->data);")
    }
    else
    {
       sub("_P$","",type)
       return (name " = &(TheSbvector("arg")->data);")
    }
}
{ print doIdent( $1, "  p->" gensub(/;/, / /, "g",$2), "TheRecord(arg)->recdata[i++]") }
