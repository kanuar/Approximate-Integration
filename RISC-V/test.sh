echo this test bench is for a cache of size 131072 bytes, which is 4 way associative and has a block size of 512 bytes, therefore there are 64 sets in this arrangement
echo [+] setting up
mkdir bin/risc
mkdir bin/c
echo [-] setup completed
echo [+] entering c_test
valgrind --log-file=bin/c/test_without.log --tool=cachegrind --cachegrind-out-file=bin/c/c_test_without.txt --cache-sim=yes --branch-sim=yes --I1=131072,4,512 --D1=131072,4,512 ./c_test/test_without > bin/c/c_test_without.log
valgrind --log-file=bin/c/test_midpoint.log --tool=cachegrind --cachegrind-out-file=bin/c/c_test_midpoint.txt --cache-sim=yes --branch-sim=yes --I1=131072,4,512 --D1=131072,4,512 ./c_test/test_midpoint > bin/c/c_test_midpoint.log
valgrind --log-file=bin/c/test_simpsons.log --tool=cachegrind --cachegrind-out-file=bin/c/c_test_simpson.txt --cache-sim=yes --branch-sim=yes --I1=131072,4,512 --D1=131072,4,512 ./c_test/test_simpsons > bin/c/c_test_simpson.log
valgrind --log-file=bin/c/test_trapezoidal.log --tool=cachegrind --cachegrind-out-file=bin/c/c_test_trapezoidal.txt --cache-sim=yes --branch-sim=yes --I1=131072,4,512 --D1=131072,4,512 ./c_test/test_trapezoidal > bin/c/c_test_trapezoidal.log
echo [-] exiting c_test
echo [+] entering risc_test
echo [+] testing without
spike -p4 --ic=64:4:512 --dc=64:4:512 $PK risc_test/test_without > bin/risc/risc_test_without.txt
echo [-] testing without completed
echo [+] testing midpoint
spike -p4 --ic=64:4:512 --dc=64:4:512 $PK risc_test/test_midpoint > bin/risc/risc_test_midpoint.txt
echo [-] testing midpoint completed
echo [+] testing trapezoidal
spike -p4 --ic=64:4:512 --dc=64:4:512 $PK risc_test/test_trapezoidal > bin/risc/risc_test_trapezoidal.txt
echo [-] testing trapezoidal completed
echo [+] testing simpsons
spike -p4 --ic=64:4:512 --dc=64:4:512 $PK risc_test/test_simpsons > bin/risc/risc_test_simpsons.txt
echo [-] testing simpsons completed
echo [-] exiting risc_test
rm bin/c/c_test_simpson.txt
rm bin/c/c_test_without.txt
rm bin/c/c_test_midpoint.txt
rm bin/c/c_test_trapezoidal.txt
echo [-] removed temp files 
echo [+] creating obj dump files for risc_test
mkdir dump
riscv64-unknown-linux-gnu-objdump -d risc_test/test_without > dump/test_without.txt
riscv64-unknown-linux-gnu-objdump -d risc_test/test_midpoint > dump/test_midpoint.txt
riscv64-unknown-linux-gnu-objdump -d risc_test/test_simpsons > dump/test_simpsons.txt
riscv64-unknown-linux-gnu-objdump -d risc_test/test_trapezoidal > dump/test_trapezoidal.txt
echo [-] dump completed
