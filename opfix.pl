use warnings;
use strict;

open(FH, "<","./lookup.txt");

my $line_count = 0;
my $inst = "";
my $size = "";
my $cycles = "";
my $flags = "";

while(<FH>) {
    chomp;
    $line_count++;
    if($line_count % 3 == 1) {
        if($line_count == 634) {
            # print("skipping to Call NC____________________________\n");
            $line_count += 3;
        }
        if($line_count == 658) {
            # print("skipping to Call C____________________________\n");
            $line_count += 3;
        }
        if($line_count == 664) {
            # print("skipping to SBC____________________________\n");
            $line_count += 3;
        }
        if($line_count == 682) {
            # print("skipping to PUSH HL____________________________\n");
            $line_count += 6;
        }
        if($line_count == 706) {
            # print("skipping to XOR____________________________\n");
            $line_count += 9;
        }
        if($line_count == 733) {
            # print("skipping to PUSH AF____________________________\n");
            $line_count += 3;
        }
        if($line_count == 757) {
            # print("skipping to CP____________________________\n");
            $line_count += 6;
        }
        
        $inst = $_;
    }
    if($line_count % 3 == 2) {
        /\s*(\d)  (\d)/;
        $size = $1;
        $cycles = $2;
    }
    if ($line_count% 3 == 0) {
        $flags = $_;
        my $integer = int(($line_count/3))/16.1;
        my $remain = (($line_count/3)%16);
        if($remain == 0) {
            $remain = 16;
        }
        printf("{0x%01x%01x, ",$integer,$remain-1);
        print("std::make_tuple(\"$inst\",$size, $cycles, \"$flags\")},\n");
    }
}

close(FH);
