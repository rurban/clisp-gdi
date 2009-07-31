# awk.parser - recursive-descent translator for part of awk
#   input:  awk program (very restricted subset)
#   output: C code to implement the awk program

BEGIN { program() }

function advance() {      # lexical analyzer; returns next token
    if (tok == "(eof)") return "(eof)"
    while (length(line) == 0)
        if (getline line == 0)
            return tok = "(eof)"
    sub(/^[ \t]+/, "", line)   # remove white space
    if (match(line, /^[A-Za-z_][A-Za-z_0-9]*/) ||    # identifier
        match(line, /^-?([0-9]+\.?[0-9]*|\.[0-9]+)/) ||  # number
        match(line, /^(<|<=|==|!=|>=|>)/) ||         # relational
        match(line, /^./)) {                    # everything else
            tok = substr(line, 1, RLENGTH)
            line = substr(line, RLENGTH+1)
            return tok
        }
    error("line " NR " incomprehensible at " line)
}
function gen(s) {     # print s with 2*nt leading spaces
    printf("%s%s\n", substr("                                          ", 1, 2*nt), s)
}
function eat(s) {     # read next token if s == tok
    if (tok != s) error("line " NF ": saw " tok ", expected " s)
    advance()
}
function nl() {       # absorb newlines and semicolons
    while (tok == "\n" || tok == ";")
        advance()
}
function error(s) { print "Error: " s | "cat 1>&2"; exit 1 }

function program() {
    advance()
    gen("#line 1 \"funcs.c\"")
    pastats()
    if (tok != "(eof)") error("program continues after END")
}
function pastats() {
    nt=0;
    while (tok != "END" && tok != "(eof)") pastat()
}
function initCurrentNames(c,a,i,n) {
    n = split("void int char float double long bool",a, " ")
    for(i=1; i <=n; i++)c[a[i]]=1
}
# rettype funcname (args...);
function pastat(retType, retName, funcName,args,argTypes, argNames,rest) {
    delete currentNames
    delete inits
    initCurrentNames(currentNames)
    retType = tok
    advance()
    funcName = tok
    advance()
    eat("(")
    args=exprlist()
    eat(")")
    nl()
    makeArgTypes(args,argTypes)
    makeArgNames(args,argNames)
    rest = 0
    if(doHead(funcName,argNames) ~ /rest/)rest = 1
    gen("{")
    nt++
    retName = makeUniqueName(tolower(retType))
    doIdentDecl("object","arg")
    doIdentDecl(retType,retName)
    doIdentList(argTypes,argNames,inits)
    doInits(inits)
    if(rest)doRest();
    doCall(retName, funcName, argNames)
    doRet(retType,retName,funcName)
    nt--; gen("}")
}
function doRest(){
   # gen("skipSTACK(argcount);");
}

function makeUniqueName(n)
{
   if( n in currentNames)return makeUniqueNameAux(n,0)
   else
   {
      currentNames[n] = 1
      return n
   }
}
function makeUniqueNameAux(n,i,v)
{
   v = n i
   if( v in currentNames)return makeUniqueNameAux(n,i+1)
   else
   {
      currentNames[v]=1
      return v
   }
}
function makeStringFromArray(a,n,i,s)
{
   n = a[0]
   if( n >= 6)return "&rest r"
   s = ""
   for(i=1; i <= n; i++)s=s " " a[i]
   return s
}
function doHead(f,a,s) {
   s = makeStringFromArray(a)
   gen("// untested - was never called")
   gen("// uninspected - compiles but code was not checked")
   gen("DEFUN( GDI:" f "," s ")")
   #gen("DEFUN( " toupper(f) ":" f "," s ")")
   return s
}
function doCall(r,f,a,s,i,sep) {
   s=""
   sep=""
   for(i=1; i <= a[0]; i++){
      s = s sep a[i]
      sep = ","
   }
   gen("begin_call();")
   gen(r " = " f "(" s ");")
   gen("end_call();")
}
function doRet(r,name,f) {
    if(r ~/H.*/)doHandle(name,f)
    else if("void" == r)doVoid(f)
    else if("BOOL"==r)doBool(name,f)
    else if("BYTE"==r)doByte(name,f)
    else if("WORD"==r)doWord(name,f)
    else if("ATOM"==r)doAtom(name,f)
    else if("CHAR"==r || "char" == r)doChar(name,f)
    else if("int"==r || "LONG" == r || "WORD" == r || "INT" == r || "LPARAM"==r)doInt(name,"s",f)
    else if("DWORD"==r || "UINT" == r)doInt(name,"u",f)
}
function gen_error(f){
  gen("GDI_ERROR(\""f"\");")
}
function doInt(name,ty,f){
  if(ty == "u") gen("if(!" name "){")
  else gen("if(0 <=" name "){")
  nt++
  gen_error(f)
  nt--
  gen("}")
  gen("else")
  gen("{")
  nt++
  gen("value1 = "ty"int32_to_I("name");")
  gen("mv_count=1;")
  nt--
  gen("}")
  gen("return;")
}
function doHandle(h,f) {
  gen("if(NULL ==" h "){")
  nt++
  gen_error(f)
  nt--
  gen("}")
  gen("else")
  gen("{")
  nt++
  gen("value1 = allocate_fpointer((FOREIGN)"h");")
  gen("mv_count=1;")
  nt--
  gen("}")
  gen("return;")
}
function doVoid(f)
{
   gen("mv_count = 0;")
   gen("return;")
}
function doByte(b,f)
{
   gen("value1 = uint8_to_I(" b ");")
   gen("mv_count = 1;")
   gen("return;")
}
function doWord(b,f)
{
   gen("value1 = uint16_to_I(" b ");")
   gen("mv_count = 1;")
   gen("return;")
}
function doAtom(h,f) {
  gen("if(0 ==" h "){")
  nt++
  gen_error(f)
  nt--
  gen("}")
  gen("else")
  gen("{")
  nt++
  #gen("value1 = allocate_fpointer((FOREIGN)"h");")
  gen("value1 = uint32_to_I(" h ");")
  gen("mv_count=1;")
  nt--
  gen("}")
  gen("return;")
}
function doBool(b,f) {
  gen("if(!" b "){")
  nt++
  gen_error(f)
  nt--
  gen("}")
  gen("else")
  gen("{")
  nt++
  gen("value1 = T;")
  gen("mv_count=1;")
  nt--
  gen("}")
  gen("return;")
}

function doChar(b,f)
{
   gen("mv_count = 1;")
   gen("value1 = int_char(" b ");")
   gen("return;")
}
function pattern() { return expr() }

function statlist() {
    eat("{"); nl(); while (tok != "}") stat(); eat("}"); nl()
}

function stat() {
    if (tok == "print") { eat("print"); gen("print(" exprlist() ");") }
    else if (tok == "if") ifstat()
    else if (tok == "while") whilestat()
    else if (tok == "{") statlist()
    else gen(simplestat() ";")
    nl()
}

function ifstat() {
    eat("if"); eat("("); gen("if (" expr() ") {"); eat(")"); nl(); nt++
    stat()
    if (tok == "else") {      # optional else
        eat("else")
        nl(); nt--; gen("} else {"); nt++
        stat()
    }
    nt--; gen("}")
}

function whilestat() {
    eat("while"); eat("("); gen("while (" expr() ") {"); eat(")"); nl()
    nt++; stat(); nt--; gen("}")
}

function simplestat(   lhs) { # ident = expr | name(exprlist)
    lhs = ident()
    if (tok == "=") {
        eat("=")
        return "assign(" lhs ", " expr() ")"
    } else return lhs
}
 function doIdent( type, name) {
    if(type ~ /^H.*/) {
       gen("arg = popSTACK();")
       gen("processFPTYPE(" type "," name ",arg);")
       #gen("if(!fpointerp(arg))invalid_argument(arg);");
       #gen(name " = TheFpointer(arg)->fp_pointer;")
    }
    else if( "DWORD" == type||"UINT" == type||"ULONG" == type||"DWORD32" == type) {
       gen(name " = I_to_uint32(check_uint(popSTACK()));")
    }
    else if( "int" == type || "INT" == type ||"WORD" == type || "LONG" == type || "LPARAM"==type){
       gen(name " = I_to_sint32(check_sint(popSTACK()));")
    }
    else if( "LPSTR" == type || "LPCSTR" == type) {
       gen("arg = popSTACK();")
       gen("if(!stringp(arg))invalid_argument(arg);");
       gen(name " = TheAsciz(string_to_asciz(arg,encoding));")
    }
    else if( "LPWSTR" == type || "LPCWSTR" == type) {
       gen("arg = popSTACK();")
       gen("if(!stringp(arg))invalid_argument(arg);");
       gen(name " = WIDECHAR(arg,encoding);")
    }
    else if( "float" == type || "FLOAT" == type) {
       gen("arg = popSTACK();")
       gen("check_ffloat(arg);");
       gen(name " = ffloat_value(arg);")
    }
    else if("BYTE_P" == type) {
       gen("arg = popSTACK();")
       gen("if(!simple_bit_vector_p(Atype_8Bit,arg))invalid_argument(arg);");
       gen(name " = (BYTE*)&(TheSbvector(arg)->data);")
    }
    else if("INT_P" == type || "DWORD_P" == type || "LPINT" == type) {
       gen("arg = popSTACK();")
       gen("if(!simple_bit_vector_p(Atype_32Bit,arg))invalid_argument(arg);");
       gen(name " = (INT*)&(TheSbvector(arg)->data);")
    }
    else if("PVOID" == type || "PCVOID" == type) {
       gen("arg = popSTACK();")
       gen("if(!simple_bit_vector_p(Atype_8Bit,arg))invalid_argument(arg);");
       gen(name " = (void*)&(TheSbvector(arg)->data);")
    }
    else if(type ~ /^LPC.*/) {
       sub("^LPC","",type)
       gen("process"type"("name",popSTACK());")
    }
    else if(type ~ /^LP.*/) {
       sub("^LP","",type)
       gen("process"type"("name",popSTACK());")
    }
    else if(type == "COLORREF") {
       gen("process"type"("name",popSTACK());")
    }
    else
    {
       sub("_P$","",type)
       gen("arg0 = popSTACK();")
       gen("process"type"("name",arg0);")
    }
}
function doIdentDecl( e,n,i,a) {
   if("BYTE_P" == e || "INT_P" == e || "DWORD_P" == e) {
       sub("_P$","",e)
       gen(e "* " n ";")
   }
   else if("LPINT" == e){
       gen("int* " n ";")
   }
   else if("PVOID" == e || "PCVOID" == e || "void_P" == e) {
       gen("void* " n ";")
   }
   else if( e ~ /_P$/){
      sub("_P$","",e)
      gen(e "* " n " = alloca(sizeof("e"));")
      #gen("object arg0 = 0;")
      a[i] = "process"e"("n",arg0);"
   }
   else if(e ~ /^LPC.*/ && e !~ /STR/) {
      sub("^LPC","",e)
      gen(e "* " n ";// = alloca(sizeof("e"));")
      #gen("object arg0 = 0;")
      a[i] = "process"e"("n",arg0);"
   }
   else if(e ~ /^LP.*/ && e !~ /STR/) {
      sub("^LP","",e)
      gen(e "* " n ";// = alloca(sizeof("e"));")
      #gen("object arg0 = 0;")
      a[i] = "process"e"("n",arg0);"
   }
   else
   {
      gen(e " " n ";")
   }
   return n
}
function makeArgTypes( e,a, n) {
   n = split(e,a,",")
   a[0] = n;
}
function makeArgNames( e,a, n, i) {
   n = split(e,a,",")
   for(i=1; i <= n; i++)a[i] = makeUniqueName(tolower(a[i]))
   a[0]=n
   return n
}

function doInits(inits,i) {
   for(i = 1; i <= inits[0]; i++){
     if(i in inits)gen(inits[i])
   }
}
function doIdentList( types,names,inits,i,n) {
   n = names[0];
   inits[0] = n
   for(i=1; i <= n; i++)doIdentDecl(types[i],names[i],i,inits)
   for(i=n; 1 <= i; i--)doIdent(types[i],names[i])
}
function exprlist(    n, e, e0) { # expr , expr , ...
    e = ident()        # has to be at least one
    for (n = 1; tok == ","; n++) {
        advance()
        e = e "," ident()
    }
    return e
}

function expr(e) {            # rel | rel relop rel
    e = rel()
    while (tok ~ /<|<=|==|!=|>=|>/) {
        op = tok
        advance()
        e = sprintf("eval(\"%s\", %s, %s)", op, e, rel())
    }
    return e
}

function rel(op, e) {         # term | term [+-] term
    e = term()
    while (tok == "+" || tok == "-") {
        op = tok
        advance()
        e = sprintf("eval(\"%s\", %s, %s)", op, e, term())
    }
    return e
}

function term(op, e) {        # fact | fact [*/%] fact
    e = fact()
    while (tok == "*" || tok == "/" || tok == "%") {
        op = tok
        advance()
        e = sprintf("eval(\"%s\", %s, %s)", op, e, fact())
    }
    return e
}

function fact(  e) {          # (expr) | $fact | ident | number
    if (tok == "(") {
        eat("("); e = expr(); eat(")")
        return "(" e ")"
    } else if (tok == "$") {
        eat("$")
        return "field(" fact() ")"
    } else if (tok ~ /^[A-Za-z][A-Za-z0-9]*/) {
        return ident()
    } else if (tok ~ /^-?([0-9]+\.?[0-9]*|\.[0-9]+)/) {
        e = tok
        advance()
        return "num((float)" e ")"
    } else
        error("unexpected " tok " at line " NR)
}

function ident(  id, e) {     # name | name[expr] | name(exprlist)
    if (!match(tok, /^[A-Za-z_][A-Za-z_0-9]*/))
        error("unexpected " tok " at line " NR)
    id = tok
    advance()
    if (tok == "[") {         # array
        eat("["); e = expr(); eat("]")
        return "array(" id ", " e ")"
    } else if (tok == "(") {  # function call
        eat("(")
        if (tok != ")") {
            e = exprlist()
            eat(")")
        } else eat(")")
        return id "(" e ")"   # calls are statements
    } else
        return id             # variable
}
