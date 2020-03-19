echo "1. present directory: "
echo "2. make new directory: "
echo "3. remove directory: "
echo "4. rename directory: "
echo "5. Move to parent directory: "
echo "6. change present directory: "
echo "7. check for directory: "
echo "8. check for file: "
echo "9. change permission of file: "
echo "10. move directory 1 to directory 2: "
echo "11. exit: "

read decision

case $decision in
	1)	pwd;;

	2)	echo "Enter directory name: "
		read name
		mkdir $name;;
	
	3)	echo "Enter directory name you want to remove : "
		read name
		rmdir $name;;

	4)	echo "Enter directory-name to be changed : "
		read name1
		echo "Enter directory-name to be created : "
		read name2
		mv $name1 $name2;;

	5)	cd ..
		pwd;;
	
	6)	echo "Enter directory path : "
		read x
		cd $x
		pwd;;

	7)	echo "Enter directory name you want : "
		read name
		if [ -d $name ] 
		then
    			echo "Directory exists." 
		else
    			echo "Directory does not exist."
		fi;;

	8)	echo "Enter file name : "
		read x
		if [ -f "$x" ]
		then
			echo "$x is a valid file."
		else
			echo "$x isn't a valid file."
		fi;;

	9)	echo "Enter directory name you want : "
		read y
		echo "Read by owner only : 400"
		echo "Read by group only : 040"
		echo "Read by all : 004"
		echo "Write by owner only : 200"
		echo "Write by group only : 020"
		echo "Write by owner only : 002"
		echo "Execute by owner only : 100"
		echo "Execute by group only : 010"
		echo "Execute by all : 001"
		read x
		chmod $x $y;;	

	10)	echo "Enter source directory name : "
		read x
		echo "Enter destination directory name : "
		read y
		mv $x $y;;
	
	
	
	11)	exit 0;;
esac		
