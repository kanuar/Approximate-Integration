echo [+] entering make 
mkdir bin
make > bin/make_logs.log
echo [-] exiting make
echo [+] running risc test 
spike $PK risc_test/test_without > output/risc_test_without.txt
spike $PK risc_test/test_simpsons > output/risc_test_simpsons.txt
spike $PK risc_test/test_midpoint > output/risc_test_midpoint.txt
spike $PK risc_test/test_trapezoidal > output/risc_test_trapezoidal.txt
echo [-] exiting risc test
echo [+] entering c test
./c_test/test_without > output/c_test_without.txt
./c_test/test_simpsons > output/c_test_simpsons.txt
./c_test/test_midpoint > output/c_test_midpoint.txt
./c_test/test_trapezoidal > output/c_test_trapezoidal.txt
echo [-] exiting c test
echo [+] cleaning make 
echo [-] end
