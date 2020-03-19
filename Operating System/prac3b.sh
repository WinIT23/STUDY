num=2
while [ $num -le 300 ]
do
	
	sq=$(echo "sqrt($num)" | bc -l)
	sq=${sq%.*}
	div=2
	while [ $div -lt `expr $sq + 1` ]
	do
		if [ `expr $num % $div` -eq 0 ] ; then
		div=0
		break
		fi
		div=`expr $div + 1`
	done
	if [ $div -ne 0 ] ; then
	echo $num
	fi
	num=`expr $num + 1`
done
