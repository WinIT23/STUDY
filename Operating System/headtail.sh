echo "enter '1' to start reading from head: "
echo "enter '2' to start reading from tail: "
read decision

echo "enter number of lines to be read: "
read lines

echo "enter file-name from which reading is requiired: "
read filename

total=$(wc -l < $filename)

if [ -f $filename ] 
then
	if [ -s $filename ]
	then

		echo "printing data in file :"
		echo ""
		case $decision in

		1)	while IFS= read -r line
			do
				if [ $lines -eq 0 ] ; then
					break;
				fi
				lines=$(($lines - 1))
				echo "$line"
			done < "$filename";;
		2)	lines=`expr $total - $lines`
			echo $lines
			while IFS= read -r line
			do
				if [ $lines -gt 0 ] ; then
					lines=$(($lines - 1))
					continue
				else
					echo "$line"
				fi
			done < "$filename";;

		esac
	else
		echo "file is empty!!"
	fi
else
	echo "file not found!!"
fi	
