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
	echo Test $test ..................
	#numCount=$(($RANDOM%$numCountMax+1))
	for (( idx=0; idx<$numCount; idx=idx+1 )); do
		numArr[$idx]=$(($RANDOM%1000))
	done
	
	# Calculate average
	sum=0
	for (( idx=0; idx<$numCount; idx=idx+1 )); do
		sum=$(($sum + ${numArr[$idx]}))
	done
	avg=$(($sum/$numCount))
	
	# Calculate minimum
	minNum=${numArr[0]}
	for (( idx=0; idx<$numCount; idx=idx+1 )); do
		if [ "${numArr[$idx]}" -lt "$minNum" ]; then
			minNum=${numArr[$idx]}
		fi
	done
	
	# Calculate maximum
	maxNum=${numArr[0]}
	for (( idx=0; idx<$numCount; idx=idx+1 )); do
		if [ "${numArr[$idx]}" -gt "$maxNum" ]; then
			maxNum=$((${numArr[$idx]}))
		fi
	done
	
	output=$($(echo ./a.out ${numArr[@]}))
	expected_output="$avg $minNum $maxNum"
	
	if [ $? -eq 0 ]; then
		echo "Program executed successfully"
	else
		echo "Program failed to execute"
		exit 1
	fi
	
	if [ "$output" == "$expected_output" ]; then
		echo "Passed test $test"
		score=$(($score + 1))
	else
		echo "Failed test $test, expected output: '$expected_output', your output: '$output'"
	fi
	
done

echo "Tests completed"
echo "Final score: $score"
