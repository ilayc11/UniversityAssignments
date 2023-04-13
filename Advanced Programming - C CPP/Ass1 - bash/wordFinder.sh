array=($@)
arraylen=${#array[@]}
paraNumif=0
firstCondition=0
secondCondition=0


checkParaNum() {
if (( $arraylen < 3 ))
then
echo "Number of parameters received : `echo $arraylen`" >&2
else
paraNumif=1
fi
}

checkFirstCon(){
if [[ ${#array[-2]} = 1 && ( ${array[-2]} =~ [a-z] || ${array[-2]} =~ [A-Z] || ${array[-2]} =~ [0-9?] ) ]]
then
array[-2]=${array[-2],}
firstCondition=1
fi
}

checkSecondCon(){
if [[ ${array[-1]} =~ [0-9] && ${array[-1]} -gt 0 ]]
then
secondCondition=1
fi
}

checkFileIntegrity(){
local i=0
while (( $i < $arraylen-2 ))
do
	if [[ -d ${array[i]} || ! -e "`echo ${array[i]}`" ]]
	then
	echo "File does not exist : `echo ${array[i]}`" >&2
	echo "Usage : wordFinder.sh <valid file name> [More Files] ... <char> <length>"
	fileIntegrityFlag=0
	break
	else
	i=$i+1
	fi
done	
}

wordSliceFunc(){
	tr '[A-Z]' '[a-z]' <${array[$sent_i]} >tempFile.txt
	wordsTempArray=( $( grep -o -E '\b'${array[-2]}'\w{'$(( ${array[-1]} - 1))',}\b' tempFile.txt |sort ))
	rm tempFile.txt
}

mainFunc(){
if [ ${#wordsFinalArray[@]} = 0 ]
then
	if [ ${#wordsTempArray[@]} = 0 ]
	then
	return
	fi
	wordsFinalArray[${#wordsFinalArray[@]}]=${wordsTempArray[0]}
fi

wordExistFlag=0
i=0
while (( $i < ${#wordsTempArray[@]} ))
do

	k=0
	while (( $k < ${#wordsFinalArray[@]} ))
	do
		if [[ "${wordsFinalArray[k]}" = "${wordsTempArray[i]}" ]]
		then
			
			wordsNumArray[k]=$(( ${wordsNumArray[k]} + 1 ))
			wordExistFlag=1
		fi
		k=$(( $k + 1))
	done
	if [ $wordExistFlag = 0 ]
	then	
		
		wordsFinalArray[${#wordsFinalArray[@]}]=${wordsTempArray[i]}
		wordsNumArray[${#wordsNumArray[@]}]=1
	fi
	
	i=$(( $i + 1 ))
	wordExistFlag=0
	
done
}

sortFunc(){
t=0
v=0
while (( $t < ${#wordsFinalArray[@]} ))
do
	while (( $v < $(( ${#wordsFinalArray[@]} - $t -1 )) ))
	do
	
	if (( ${wordsNumArray[v]} > ${wordsNumArray[$(( $v + 1 ))]} ))
	then
	
		temp1=${wordsNumArray[v]}
		temp2=${wordsFinalArray[v]}
	
		wordsNumArray[$v]=${wordsNumArray[$(( $v + 1 ))]}
		wordsFinalArray[$v]=${wordsFinalArray[$(( $v + 1 ))]}
	
		wordsNumArray[$(( $v + 1 ))]=$temp1
		wordsFinalArray[$(( $v + 1 ))]=$temp2
	
	fi
	if [[ ${wordsNumArray[v]} = ${wordsNumArray[$(( $v + 1 ))]} ]]
	then
		temp1=${wordsFinalArray[v]}
		temp2=${wordsFinalArray[$(( $v + 1 ))]}
		
		if [[ "$temp1" > "$temp2" ]]
		then
		wordsFinalArray[v]=$temp2
		wordsFinalArray[$(( $v + 1 ))]=$temp1
		fi
		
		
	
	fi
	v=$(( $v + 1 ))
	done
	v=0
	t=$(( $t + 1 ))
done
}

checkParaNum
if [[ $paraNumif = 1 ]]
then
	checkFirstCon
	
	
	if [[ $firstCondition = 0 ]]
	then
		echo "Only one char needed : `echo ${array[-2]}`" >&2
	fi
	
	checkSecondCon
	if [[ $secondCondition = 0 ]]
	then
		echo "Not a positive number : `echo ${array[-1]}`" >&2
	fi
	
	if [[ $firstCondition -eq 0 || $secondCondition -eq 0 ]]
	then
		echo "Usage : wordFinder.sh <valid file name> [More Files] ... <char> <length>"
	else
		fileIntegrityFlag=1
		checkFileIntegrity
	fi
	
	if [[ $fileIntegrityFlag = 1 ]]
	then
	sent_i=0
	wordsFinalArray=()
	wordsNumArray=()
	
	while (( $sent_i < $arraylen-2 ))
	do
	wordSliceFunc
	mainFunc
	sent_i=$(( $sent_i + 1 ))
	done
	fi
	
sortFunc
p=0
while (( $p < ${#wordsFinalArray[@]} ))
do
	echo "`echo ${wordsNumArray[$p]}` `echo ${wordsFinalArray[$p]}`"
	p=$(( $p + 1 ))
done
else
echo "Usage : wordFinder.sh <valid file name> [More Files] ... <char> <length>"
fi
	
	
	

