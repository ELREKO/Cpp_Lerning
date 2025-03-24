#!/bin/bash

GREEN='\033[0;32m'
RED='\033[0;31m'
BLUE='\033[0;34m'
BOLD='\033[0;1m'
UNDERLINE='\033[4m'
END='\033[0m'

make re 

rm test_example

# Loop n times
for i in {1..10}
do
	# Random array size
	size=$((1 + RANDOM % 1000))

	numbers=$(shuf -i 1-100000 -n $size | tr "\n" " ")
	
	echo -e #>> test_example
	echo -e #>> test_example
	echo -e "\033[1;4;34m Testnummer $i" #>> test_example
	echo -e  #>> test_example
	./PmergeMe $numbers #>> test_example

	if [ $? -ne 0 ]; then
		echo -e "$RED$numbers$END"
	fi
done

./PmergeMe $(shuf -i 1-100000 -n 11 | tr "\n" " ")
echo "--------------------------------------------"

NUM=$(shuf -i 1-100000 -n 11 | tr "\n" " ")
./PmergeMe $NUM

NUM=(17 1 2 3 7 6 9)
./PmergeMe $NUM

NUM=(17 1 2 "3 7 6 9")
./PmergeMe $NUM

./PmergeMe 17 1 2 3 "7 6 9"
./PmergeMe 17 1 2 3 "7 6 p 9"
./PmergeMe 17 1 2 -3 "7 6 9"
./PmergeMe 17 1 2 "7 6 9" 1

# ./PmergeMe 70 91 3 1  71 2 9 4   7 5 301 20   120 92 23 6   

