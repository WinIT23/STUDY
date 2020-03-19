echo "enter number to be reversed"
read number

while [ $number -gt 0 ]
do
	a=`expr $number % 10`
	echo -n "$a"
	number=`expr $number / 10`
done
