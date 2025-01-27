echo "\033[38;5;230m*******************************************************"
echo "\033[38;5;222m\033[1m                   TESTER PUSH_SWAP                    \033[0m"
echo "\033[38;5;230m*******************************************************\033[0m"
number_of_test=$1
test_i=0
number_of_moves=0
total_moves_all_tests=0
mean_moves=0
while [ $test_i -lt $number_of_test ]
do
	ARG1="$(shuf -i 1-$2 | tr '\n' ' ')"
	echo "\033[38;5;70m\033[1mInput:\033[0m $ARG1"
	test_i=$(( $test_i + 1 ))
	./push_swap $ARG1 > result.txt
	number_of_moves=$(cat result.txt | wc -l)
	echo "\033[38;5;70m\033[1mMovements: \033[0m"
	echo "\033[38;5;150m"
	cat result.txt
	echo "\033[0m"
	echo "\033[38;5;70m\033[1mNumber of moves:\033[0m $number_of_moves"
	total_moves_all_tests=$(( $number_of_moves + $total_moves_all_tests ))
	if [ $number_of_moves -gt 5500 ]; then
		break;
	fi
done
mean_moves=$(( $total_moves_all_tests / $number_of_test ))
echo "\033[38;5;230m================================================\033[0m"
echo "\033[38;5;98m\033[1mMean moves for all tests:\033[0m $mean_moves"
echo "\033[38;5;98m\033[1mNumber of tests done:\033[0m $test_i"
echo "\033[38;5;230m================================================\033[0m"
