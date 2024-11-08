all: setup build_c build_risc

setup:
	mkdir output
	mkdir risc_test
	mkdir c_test
clean:
	rm -r -f risc_test
	rm -r -f c_test

remove:
	rm -r -f bin
	rm -r -f output
	rm -r -f dump

build_c:
	gcc -w risc_without_approximation.c -o c_test/test_without 
	gcc -w risc_midpoint_rule.c -o c_test/test_midpoint 
	gcc -w risc_simpsons_rule.c -o c_test/test_simpsons 
	gcc -w risc_trapezoidal_rule.c -o c_test/test_trapezoidal 

build_risc: 
	riscv64-unknown-linux-gnu-gcc -w risc_without_approximation.c -o risc_test/test_without --static
	riscv64-unknown-linux-gnu-gcc -w risc_midpoint_rule.c -o risc_test/test_midpoint --static
	riscv64-unknown-linux-gnu-gcc -w risc_simpsons_rule.c -o risc_test/test_simpsons --static
	riscv64-unknown-linux-gnu-gcc -w risc_trapezoidal_rule.c -o risc_test/test_trapezoidal --static
