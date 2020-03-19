fib()
{
	if [ $1 -lt 2 ] 
	then
		return $1
	else
		local x=`expr $1 - 1`
		local y=`expr $1 - 2`
		fib $x
		x=$?
		fib $y
		y=$?
		x=`expr $x + $y`
		return $x
	fi
}

echo "enter the term for which fibonacci value is required:"
read N
echo "SERIES:"
i=0
while [ $i -le `expr $N - 1` ]
do
	fib $i
	a=$?
	echo -n "$a "
	i=`expr $i + 1`
done
echo ""
