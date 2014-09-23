#!/user/local/bin/perl

# pgm4.pl - Steven Liu
# cit145-j0e1
# due April, 1, 2010

# This program uses the quadratic equation to solve second-order polynomials
# Additionally, input will be parsed to remove spaces
# And there will be certain input checking

print "\nInput values for the coefficients a, b, and c separated with spaces: ";
$input = <>;
chomp ($input);
($a, $b, $c) = split (' ', $input);

print "\n";
if ($a == 0)
{
    print "The coefficient for 'a' cannot be zero\!\n";
}
elsif (($b**2 - 4 * $a * $c) < 0)
{
    print "Cannot take square root of negative numbers\!\n";
}
else
{
    $x1 = (-$b + sqrt($b**2 - 4 * $a * $c)) / (2 * $a);
    $x2 = (-$b - sqrt($b**2 - 4 * $a * $c)) / (2 * $a);

    print "The possible values for x are:\n";
    print "$x1\n";
    if ($x1 != $x2)
    {
        print "$x2\n";
    }
}
print "\n";


exit;
