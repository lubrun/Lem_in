#!/bin/sh
set +x
gcc -Wall -Werror -Wextra -g srcs/*.c libft/libft.a -o Lem-in
echo "-------------FLOW-ONE-------------"
./generator --flow-one > one
./Lem-in < one | grep "tour"
cat one | grep "required" | tail -1
echo "-------------FLOW-TEN-------------"
./generator --flow-ten > ten
./Lem-in < ten | grep "tour"
cat ten | grep "required" | tail -1
echo "---------FLOW-THOUSAND---------"
./generator --flow-thousand > thousand
./Lem-in < thousand | grep "tour"
cat thousand | grep "required" | tail -1
#echo "---------BIG---------"
#./generator --big > big
#./Lem-in < big | grep "tour"
#cat big | grep "required" | tail -1
#echo "---------BIG-SUPERPOSITION---------"
#./generator --big-superposition > big-sup
#./Lem-in < big-sup | grep "tour"
#cat big-sup | grep "required" | tail -1

