#!/bin/bash

echo "\"8 9 * 9 - 9 - 9 - 4 - 1 +\""
echo -e
./RPN  "8 9 * 9 - 9 - 9 - 4 - 1 +"
echo "./RPN \"7 7 * 7 -\""
echo -e
./RPN "7 7 * 7 -"
echo "./RPN \"1 2 * 2 / 2 * 2 4 - +\""
echo -e
./RPN "1 2 * 2 / 2 * 2 4 - +"
echo "./RPN \"(1 + 1)\""
echo -e
./RPN "(1 + 1)"
