#!/usr/bin/perl

# modernize.pl funcs-*.c
# Reini Urban

while (my $fn = shift) {
  my %F;
  open F, "< $fn";
  open OUT, "> $fn.new";
  # passthru pararaphs of defun's
  local $/ = "\nDEFUN";
  while (<F>) {
    my ($func, $defun);
    if (/begin_system_call\(\);\n\s+\w+ = (\w+)\(.+\);\n\s+end_system_call/) {
      $func = $1;
      if (/^\( GDI:([A-Z]+)[,)]/) {
        $defun = $1;
        print "$defun => $func\n";
        $F{$defun} = $func;
        s/^\( GDI:([A-Z]+)/( GDI:$func/;
      }
    }
    print OUT;
  }
  close F;
  close OUT;
}

