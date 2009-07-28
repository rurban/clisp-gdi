#!/usr/bin/perl -n

# document.pl funcs-*.h  >> gdi.xml
# Reini Urban

#BEGIN { print "<section id=\"gdi-functions\"><title>Functions</title>\n"; }
#END { print "</section>\n"; }

($r,$n,$a) = /^(\w+)\s+(\w+)\((.+)\);/;
$a =~ s/,/ /g;
$a =~ s/void/ /g;
print "<varlistentry id=\"$n\"><term><code>($n $a)</code></term>\n";
print "  <para>See <link linkend=\"http://social.msdn.microsoft.com/search/en-us/?query=$n\">MSDN</link></para>\n";
if ($r eq "BOOL") {
    print "  <para>Returns <constant>&t;</constant> or <constant>&nil;</constant>.</para>\n";
} elsif ($r =~ /int|UINT|LPARAM|DWORD|WORD|LONG/) {
    print "  <para>Returns <constant>&t;</constant> and a <type>&integer;</type>.</para>\n";
} elsif ($r =~ /CHAR|char/) {
    print "  <para>Returns <constant>&t;</constant> and a <type>$r</type>.</para>\n";
} elsif ($r =~ /void/i) {
    print "  <para>Returns nothing.</para>\n";
} elsif ($r =~ /^H|ATOM/)
    print "  <para>Returns <constant>&t;</constant> and a &foreign-pointer; to the <type>$r</type> handle.</para>\n";
} else { # ($r =~ /^H|ATOM/)
    print "  <para>Returns <constant>&t;</constant> and a &foreign-pointer; to the <type>$r</type> structure.</para>\n";
}
print "</varlistentry>\n";
