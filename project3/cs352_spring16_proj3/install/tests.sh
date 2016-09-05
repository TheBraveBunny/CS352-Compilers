#!/bin/bash
if [ "$#" -eq 0 ]; then
	OPTION=1
else OPTION=$1
fi

#overall counters
TOTAL=0
CORRECT=0
FAIL_COUNT=0

#########################################
# TEST OUTPUTS (File names and outputs)
#########################################
echo -e "\033[96m---------------------------------\033[0m"
echo -e "\033[91mAST Traversal Correctness:\033[0m"
echo -e "\033[96m---------------------------------\033[0m"

##declare array of test names and the corresponding desired output
declare -a testNames
declare -a testResults

#initialize the test file name and outputs
testNames[0]=./tests/handout.c
testResults[0]=$( cat ./tests/handout.out )
testNames[1]=./tests/if_else.c
testResults[1]=$( cat ./tests/if_else.out )
testNames[2]=./tests/if_while.c
testResults[2]=$( cat ./tests/if_while.out )
testNames[3]=./tests/nested_conditions.c
testResults[3]=$( cat ./tests/nested_conditions.out )
testNames[4]=./tests/scope.c
testResults[4]=`cat ./tests/scope.out`
testNames[5]=./tests/switchcase.c
testResults[5]=`cat ./tests/switchcase.out`
testNames[6]=./tests/switchcase2.c
testResults[6]=`cat ./tests/switchcase2.out`
testNames[7]=./tests/while.c
testResults[7]=`cat ./tests/while.out`
testNames[8]=./tests/while2.c
testResults[8]=$( cat ./tests/while2.out )
testNames[9]=./tests/break.c
testResults[9]=$( cat ./tests/break.out )
testNames[10]=./tests/break2.c
testResults[10]=$( cat ./tests/break2.out )
testNames[11]=./tests/break3.c
testResults[11]=$( cat ./tests/break3.out )
testNames[12]=./tests/while_switch.c
testResults[12]=$( cat ./tests/while_switch.out )
testNames[13]=./tests/while_switch2.c
testResults[13]=$( cat ./tests/while_switch2.out )
testNames[14]=./tests/while_switch3.c
testResults[14]=$( cat ./tests/while_switch3.out )
testNames[15]=./tests/nested_while.c
testResults[15]=$( cat ./tests/nested_while.out )
testNames[16]=./tests/complicated.c
testResults[16]=$( cat ./tests/complicated.out )


#testNames[X]=./tests/output/
#testResults[X]=$(printf "")

#########################################
#Compare outputs
#########################################

for (( i = 0; i< ${#testNames[@]}; i=$i+1));
do
	let TOTAL=TOTAL+1
	#print current test	
	if [[ $OPTION > 0 ]]; then
		echo "Running ${testNames[${i}]}:"
	fi

	#run the cc1 program and redirect the output and delete it
       	`./cc1 ${testNames[${i}]} &> out`	
	rm ./out
	#grab the info from 'output.txt' and then delete it
	OUTPUT=`cat output.txt`
	rm output.txt

	#compare the results to the expected results
	if [[ "$OUTPUT" == ${testResults[${i}]} ]]; then
		if [[ $OPTION > 0 ]]; then
			echo -e "\033[1;32mTest Passed\033[0m"
		fi
		let CORRECT=CORRECT+1
	else
		if [[ $OPTION > 0 ]]; then
			echo -e "\033[1;31mTest Failed\033[0m"
			echo "PARSER OUTPUT: " 
			echo $OUTPUT
			echo "EXPECTED: "
			echo ${testResults[${i}]}
		fi
		let FAIL_COUNT=FAIL_COUNT+1
	fi
done

#remove the generated assembly files
rm ./tests/*.s


############################################
#FINAL RESULTS: print the overall results
###########################################

#print the overall score
echo
echo -e "\033[1;4mTotal Score:\033[0m $CORRECT/$TOTAL"
if [[ $CORRECT == $TOTAL ]]; then
	echo -e "\033[1;32mAll Tests Passed\033[0m"
else
	echo -e "\033[1;31m$FAIL_COUNT Test(s) Failed\033[0m"
fi
echo
