#!/user/local/bin/perl

# pgm5.pl - Steven Liu
# cit145-j0e1
# due April, 15, 2010

# This program uses the quadratic equation to solve
# a group of second-order polynomials
# This time input will be from a file
# Inputs will be checked for: 
# a)correct num of coefficients
# b)bad math
# Output will be formatted to look a certain way  
# Finally, output will be to a file

$workdir = `pwd`;
chomp($workdir);

print "\nInput the name of the file which has the coefficients of the\nquadratic equation (a, b, and c), one set per line:\n\n";

$inputfile = <>;
chomp ($inputfile);

if (!(-e "$inputfile"))
{
  print "Input file does not exist!  Terminating program.\n\n";
  exit;
}

open (INPUT, $inputfile);

print "\nInput the name of the output file you wish to create:\n\n";

$outputfile = <>;
chomp ($outputfile);

open (OUTPUT, ">>".$outputfile);

if (!(-w "$outputfile"))
{
  print "Output file cannot be opened!  Terminating program.\n\n";
  exit;
}

print "\nThis program is being executed by ".`whoami`;
print "from $workdir/pgm5.pl\n\n";
print "Its input file is\n";
print "$inputfile\n";
print "Its output file is $outputfile\n\n";

$counter = 0; # Counts total lines (equations processed)
foreach $line (<INPUT>)
{
  # Note that messages are built up by sections:
  # [coefficients][type of solution/error][x values]

  @word = split (' ', $line);

  $numword = @word;

  if ($numword != 3) # Bad coefficients = don't do any math
  {
    print OUTPUT "ERROR: Input must have 3 coefficients, line read had $numword\n";
  }
  else # Print [coefficients][type of solution/error][x values]
  {
    #-------------------- 
    # Print [coefficients]
    #-------------------- 
    $a = $word[0];
    $b = $word[1];
    $c = $word[2]; 
    printf OUTPUT "For a=%7.3f, b=%7.3f, c=%7.3f: ", $a, $b, $c;
    #-------------------- 

    #-------------------- 
    # Find and print [type of solution/error]
    #-------------------- 
    if ($a == 0)
    {
      $answer = "Not a quadratic equation if a = 0";
      $flag = 0;
    }
    elsif (($b**2 - 4 * $a * $c) < 0)
    {
      $answer = "Can not solve, b^2 - 4ac negative.";
      $flag = 0;
    }
    else
    {
      $x1 = (-$b + sqrt($b**2 - 4 * $a * $c)) / (2 * $a);
      $x2 = (-$b - sqrt($b**2 - 4 * $a * $c)) / (2 * $a);

      if ($x1 == $x2)
      {
        $answer = "One solution for x: ";
        $flag = 1;
      }
      else
      {
        $answer = "Two solutions for x: ";
        $flag = 2;
      }
    } 
    print OUTPUT "$answer";
    #-----------------------

    #-----------------------
    # Only print [x values] when solution type is not error
    #-----------------------
    if ($flag == 2)
    {
      printf OUTPUT "%7.3f and %7.3f", $x1, $x2;
    }
    if ($flag == 1)
    {
      printf OUTPUT "%7.3f", $x1;
    }
    #-----------------------

    print OUTPUT "\n";
  }
  $counter++;
}

print "$counter equations processed\n\n";

close (INPUT);
close (OUTPUT);
exit;
