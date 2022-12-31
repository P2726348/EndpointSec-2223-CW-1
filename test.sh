#!/bin/bash

numTests=10
numCountMax=20
numCount=''
declare -a numArr
sum=''
avg=''
minNum=''
maxNum=''
score=0

for test in {1..$numTests}; do
	# Generate numbers
	echo Test $test ..................
	numCount=$(($RANDOM%$numCountMax))
	for idx in {1..$numCount}; do
		numArr[$idx]=$(($RANDOM%1000))
	done
	
	# Calculate average
	sum=0
	for idx in {1..$numCount}; do
		sum = $(($sum + $numArr[$idx]))
	avg=$(($sum/$numCount))
	
	# Calculate minimum
	minNum=$numArr[0]
	for idx in {1..$numCount}; do
		if [ "$numArr[$idx]" < "$minNum" ]; then
			minNum=$(($numArr[$idx]))
		fi
	done
	
	# Calculate maximum
	maxNum=$numArr[0]
	for idx in {1..$numCount}; do
		if [ "$numArr[$idx]" > "$maxNum" ]; then
			maxNum=$(($numArr[$idx]))
		fi
	done
	
	output=$($(echo ./a.out ${numArr[a]}))
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
