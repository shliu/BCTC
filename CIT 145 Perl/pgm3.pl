#!/user/local/bin/perl
#
#pgm3.pl - Steven Liu
#cit145-j0e1
#due March, 11, 2010
#This program uses the quadratic equation to solve second-order polynomials

print "Input a value for the coefficient a: ";
$a = <>;
chomp ($a);
print "Input a value for the coefficient b: ";
$b = <>;
chomp ($b);
print "Input a value for the coefficient c: ";
$c = <>;
chomp ($c);

print "The possible values for x are:\n";

$x1 = (-$b + sqrt($b**2 - 4 * $a * $c)) / (2 * $a);
print "     $x1 \n"; 
$x2 = (-$b - sqrt($b**2 - 4 * $a * $c)) / (2 * $a);
print "     $x2 \n";


exit;
