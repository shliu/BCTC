#!/user/local/bin/perl



print "\n";
$counter = 0;

while ($input = <>)
{
  if ($input !~ /\d/)
  {
    print "Input was not a digit, end program";
    last;
  }
  else 
  {
    chomp ($input);
    $array[$counter] = $input;
    $counter++;
  }
}


print "\n$counter digits were entered\nYou entered:\n@array\n\n";













exit;

