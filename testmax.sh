#!/bin/bash

numTests=10
#numCountMax=20
numCount=10
declare -a numArr
sum=''
avg=''
minNum=''
maxNum=''
score=0
for (( test=1; test<=$numTests; test=test+1 )); do
	# Generate numbers
	echo Test $test for maximum value ..................
	#numCount=$(($RANDOM%$numCountMax+1))
	for (( idx=0; idx<$numCount; idx=idx+1 )); do
		numArr[$idx]=$(($RANDOM%1000))
	done
	echo List of numbers: ${numArr[@]}

		maxNum=${numArr[0]}
	for (( idx=0; idx<$numCount; idx=idx+1 )); do
		if [ "${numArr[$idx]}" -gt "$maxNum" ]; then
			maxNum=$((${numArr[$idx]}))
		fi
	done
	
	output=$($(echo ./a.out ${numArr[@]}))
	expected_output="$maxNum"
	
	if [ $? -eq 0 ]; then
		echo "Program executed successfully"
	else
		echo "Program failed to execute"
		exit 1
	fi
	
	if [ "$output" == "$expected_output" ]; then
		echo "Passed test $test for maximum value"
		score=$(($score + 1))
	else
		echo "Failed test $test for maximum value, expected output: '$expected_output', your output: '$output'"
		exit 1
	fi
	
done

echo "Tests completed"
echo "Final score: $score"