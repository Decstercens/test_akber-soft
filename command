gcc -c src/readString.c -o build/readString.o
gcc -c src/hashItem.c -o build/hashItem.o
gcc -c src/fileWork.c -o build/fileWork.o
gcc -c src/saveStringAsHash.c -o build/saveStringAsHash.o
gcc -o build/test_akber  build/readString.o build/saveStringAsHash.o build/hashItem.o build/fileWork.o -lm
./build/test_akber 