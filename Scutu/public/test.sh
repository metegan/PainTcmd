#!/bin/bash
for F_IN in `ls | grep .in`
do
	F_OUT=${F_IN%.*}.out
	~/Bureau/INSA/Génie_logiciel/PainTcmd/bin/Debug/PainTcmd < $F_IN &> tmp
	sdiff $F_OUT tmp > /dev/null
	if [ "$?" == "1" ]; then
		echo "ERR $F_OUT"
	else
		echo "OK $F_OUT"
	fi
done
