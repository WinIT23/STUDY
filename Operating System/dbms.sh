echo "1. Create New File"
echo "2. Open Existing One"
read decision

case $decision in
	1)	echo "Enter Filename to be given: "
		read filename
		touch $filename;;
	2)	echo "Enter Filename or path"
		read filename
		if [ -f $filename ]
		then	echo "File opened"
		else
			echo "File Doesn't Exists"
			exit
		fi
esac

while [ 1 -eq 1 ]
do
	echo "enter 1 to insert"
	echo "enter 2 to update"
	echo "enter 3 to delete"
	echo "enter 4 to quit"
	echo "enter 5 to display records" 

	read choice
	clear
	duplicate=''
	case $choice in 
	
		1)	echo "Enter Roll No.: "
			read rollno

			duplicate=$(grep $rollno $filename)

			if [ "$duplicate" != '' ]
			then
				echo "Record Already Present: "
				break
			fi	
			echo "Enter Name: "
			read name
			echo "Enter JEE score"	 
			read jee

			if [ "$rollno" = "" || "$name" = "" || "$jee" = "" ]
			then
				echo "Enter All values!"
				continue;
			fi

			echo $rollno#$name#$jee >> $filename
			
			echo "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!Record Inserted.!!!!!!!!!!!!!!!!!!!!!!!!!!!!!";;
		
		2)	echo "Enter Roll No.: "
			read oldrollno
			
			if [ "$oldrollno" = "" ]
			then
				echo "Enter Roll No Correctly!"
				continue;
			fi

			record=$(grep $oldrollno $filename)
			if [ "$record" = '' ]
			then
				echo "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!Record Doesn't Exists!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
				continue
			fi

			oldname="$(echo $record | cut -d'#' -f2)"
			oldjee="$(echo $record | cut -d'#' -f3)"
			grep -v $oldrollno $filename > temp && mv temp $filename
			echo "enter new roll no (keep empty if you do not want to change it)"
			read newrollno
			
			echo "enter new name (keep empty if you do not want to change it)"
			read newname
			echo "enter new jee (keep empty if you do not want to change it)"
			read newjee
			if [ "$newrollno" = '' ]
			then
				data=$(echo $oldrollno#)
			else
				data=$(echo $newrollno#)
			fi
			if [ "$newname" = '' ]
			then
				data=$(echo $data$oldname#)
			else
				data=$(echo $data$newname#)
			fi
			if [ "$newjee" = '' ]
			then
				data=$(echo $data$oldjee)
			else
				data=$(echo $data$newjee)
			fi
			echo $data >> $filename
			
			echo "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!Record updated.!!!!!!!!!!!!!!!!!!!!!!!!!!!!!";;
	
		3)	echo "Enter roll no to be deleted: "
			read rollno
			
			if [ "$rollno" = "" ]
			then
				echo "Enter Roll No Correctly!"
				continue;
			fi

			record=$(grep $oldrollno $filename)
			if [ "$record" = '' ]
			then
				echo "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!Record Doesn't Exists!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
				continue
			fi

			grep -v $rollno $filename > temp && mv temp $filename
			echo "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!Record deleted.!!!!!!!!!!!!!!!!!!!!!!!!!!!!!";;
		
		4)	break;;

		5)	cat $filename;;
	esac
done
