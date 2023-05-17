gcc -c src/readString.c
gcc -c src/hashItem.c
gcc -c src/saveStringAsHash.c
gcc -c src/fileWork.c
gcc -o test_akber  readString.o saveStringAsHash.o hashItem.o fileWork.o -lm
rm *.o
./test_akber