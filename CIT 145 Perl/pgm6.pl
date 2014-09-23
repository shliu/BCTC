#!/user/local/bin/perl

# pgm6.pl - Steven Liu
# cit145-j0e1
# due April, 29, 2010

# This is a simple program to find the 
# Max, Min, and Ave of values entered
# Max, Min, and Ave must be found using
# their own individual subroutines


print "\nEnter numbers, one per line.\n";
print "When you are done, enter a blank line.\n";

$input = <>;
chomp ($input);

$counter = 0;
while ($input !~ /^$/)
{
  $inputarray[$counter] = $input;
  $counter++;

  $input = <>;
  chomp ($input);
}
print "\n";


if ($counter == 0)
{
  print "You did not enter any values! Terminating program.\n\n";
}
else
{
  print "You entered $counter values\n\n";
  
  print "The minimum of the numbers you entered is ".&sub_min(@inputarray)."\n\n";

  print "The maximum of the numbers you entered is ".&sub_max(@inputarray)."\n\n";

  print "The average of the numbers you entered is ".&sub_ave(@inputarray)."\n\n";
}


exit;


# Finds smallest value in passed array 
# Repeatedly compares adjacent values from 0-n
# Keeps the smallest value for return
sub sub_min
{
  my @array = @_;
  my $minval = $array[0];

  foreach $value (@array)
  {
    if ($value < $minval)
    {
      $minval = $value; 
    }
  }
  return $minval;
}


# Finds biggest value in passed array 
# Repeatedly compares adjacent values from 0-n
# Keeps the largest value for return
sub sub_max
{
  my @array = @_;
  my $maxval = $array[0];

  foreach $value (@array)
  {
    if ($value > $maxval)
    {
      $maxval = $value; 
    }
  }
  return $maxval;
}


# Finds average of all values in passed array
# Totals all values then divides it by number
# of values in the array
sub sub_ave
{
  my @array = @_;
  my $totval;
  foreach $value (@array)
  {
    $totval += $value;
  }

  my $numval = @array;
  my $aveval = $totval / $numval;

  return $aveval;
}



