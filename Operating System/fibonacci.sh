echo "enter the term for which fibonacci value is required:"
read N

last1=0
last2=1

if [ $N -eq 0 ]
then
	echo "0"
else
	while [ $N -gt 0 ]
	do
		next=`expr $last1 + $last2`
		last1=$last2
		last2=$next
		N=`expr $N - 1`
		echo $next
	done
fi 	 
