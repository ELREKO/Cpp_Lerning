#!/bin/bash

echo -e "!!make!! \n\n "

make re

echo -e "\n\n !!Testen!! \n\n "
echo -e "------------./convert 66 ------------- \n\n "
./convert 66 

echo -e "\n\n ------------./convert B ------------- \n\n "
./convert B

echo -e "\n\n ------------./convert 66.000000001  ------------- \n\n "
./convert 66.0000000001 

echo -e "\n\n ------------./convert 1111.001  ------------- \n\n "
./convert 1111.000001

echo -e "\n\n ------------./convert 2147483647 ------------- \n\n "
./convert 2147483647

echo -e "\n\n ------------./convert 2147483648  ------------- \n\n "
./convert 2147483648 

echo -e "\n\n ------------./convert -2147483648 ------------- \n\n "
./convert -2147483648

echo -e "\n\n ------------./convert -2147483649  ------------- \n\n "
./convert -2147483649

echo -e "\n\n ------------./convert 340282236638528859811704183484516925440 ------------- \n\n "
./convert 	340282236638528859811704183484516925440

echo -e "\n\n ------------./convert 340282336638528859811704183484516925440  ------------- \n\n "
./convert 	340282336638528859811704183484516925440

echo -e "\n\n ------------./convert -340282236638528859811704183484516925440 ------------- \n\n "
./convert 	-340282236638528859811704183484516925440

echo -e "\n\n ------------./convert -340282336638528859811704183484516925440  ------------- \n\n "
./convert 	-340282336638528859811704183484516925440

echo -e "\n\n ------------./convert 1111.000010000100001  ------------- \n\n "
./convert 1111.000010000100001

echo -e "\n\n ------------./convert 211.0001 ------------- \n\n "
./convert -21.00001

echo -e "\n\n ------------./convert 21100012312.01  ------------- \n\n "
./convert 21100012312.01

echo -e "\n\n ------------./convert 66.000000001  ------------- \n\n "
./convert 66.0000000001 



echo -e "\n\n -----------Test Beendet------------"



