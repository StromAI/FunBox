i=0
while [ "$i" != "50" ]
do
	a=$(($i*2))
	b=$(($a+1))
	i=$(($i+1))
	echo "$b"
done