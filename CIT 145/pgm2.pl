#!/user/local/bin/perl
#
#pgm2.pl - Steven Liu
#
#cit145-j0e1
#due March 4, 2010
#
#This simple program prompts user for two values and does some calculations using these two values
#It will then output the results on the screen

print "pgm2.pl\n\n";

print "Input value 1: ";
$value1 = <>;
chomp($value1);

print "Input value 2: ";
$value2 = <>;
chomp($value2);
print "\n";

print "The two inputted values were $value1 and $value2\n\n";

$output = $value1 + $value2;
print "The sum of $value1 and $value2 is $output\n\n";

$output = $value1 - $value2;
print "The difference of $value1 and $value2 is $output\n\n";

$output = $value1 * $value2;
print "The product of $value1 and $value2 is $output\n\n";

$output = $value1 / $value2;
print "The division of $value1 and $value2 is $output\n\n";

$output = $value1 ** $value2;
print "$value1 raised to the $value2 power is $output\n\n";

$output = $value1 % $value2;
print "$value1 mod $value2 is $output\n\n";

exit;

