clang -std=c11 -Wall -Wextra -Werror -Wpedantic -I inc -c src/*.c main.c
clang *.o -L. -lmx -o server
./server 1234
