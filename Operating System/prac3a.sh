
if [ $# -ne 3 ] ; then 
echo " enter only 3 values "
exit 1
fi

if [ $1 -gt $2 ] && [ $1 -gt $3 ] ; then
echo "greatest num is "$1

elif [ $2 -gt $1 ] && [ $2 -gt $3 ] ; then 
echo "greatest num is "$2

else
echo "greatest num is "$3

fi
