# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    map_gen.pl                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vmeter <vmeter@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/26 13:24:11 by vmeter            #+#    #+#              #
#    Updated: 2021/07/26 15:34:49 by vmeter           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/usr/bin/perl

use warnings;
use strict;
die "program x y density" unless (scalar(@ARGV) == 3);
my ($x, $y, $density) = @ARGV;
print "$y.ox\n";
for (my $i = 0; $i < $y; $i++) {
    for (my $j = 0; $j < $x; $j++) {
if (int(rand($y) * 2) < $density) {
    print "o";
}
else {
print "."; }
}
print "\n"; }