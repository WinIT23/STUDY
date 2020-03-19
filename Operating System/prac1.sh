c=$1
while test $c -gt 0
do
c=`expr $c - 1`
echo -n "Enter First Operand:"
read a
echo -n "Enter Second Operand:"
read b

echo -n "Enter Operator:"
read exp

case $exp in
	"*") echo -n "Multiply:"; expr $a \* $b ;;
	"/") echo -n "Divide:"; expr $a / $b ;;
	"+") echo -n "Addition:"; expr $a + $b ;;
	"-") echo -n "Subtraction:"; expr $a - $b ;;
	*) echo "Enter Valid Exp!!"
esac
done
