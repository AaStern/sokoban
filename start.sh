#!/bin/bash
logo(){
echo "		                8               8                    "
echo "		                8               8                    "
echo "		.oPYo.  .oPYo.  8  .o   .oPYo.  8oPYo.  .oPYo.  odYo "
echo "		Yb..    8    8  8oP'    8    8  8    8  .oooo8  8' \`8"
echo "		  'Yb.  8    8  8 \`b.   8    8  8    8  8    8  8   8"
echo "		\`YooP'  \`YooP'  8  \`o.  \`YooP'  \`YooP'  \`YooP8  8   8"
echo
}
logo;
echo "				Press ENTER to continue"
read
make clean
make
main(){
clear;
logo;
echo "                          Please select the map:"
echo
echo "	                                 1  2  3"
echo "	e - exit"
echo

read a

case $a in
	1)
	./SoKoBan map
	;;
	2)
	./SoKoBan map2
	;;
	3)
	./SoKoBan map3
	;;
	e)
	clear;
	exit;
	;;
esac
}
while :
do
	main;
done
