#gcc 1gerador.c -o 1gerador
#./1gerador

#gcc 2gerador.c -o 2gerador
#./2gerador

gcc main.c parentese.c opcode.c -o main.bin
time ./main.bin
gcc main.c parentese.c opcode.c -o main.bin -O4
time ./main.bin

#gcc -pg main.c parentese.c opcode.c -o main.bin
#time ./main.bin

#gprof main.bin gmon.out > log.txtlear
#gedit log.txtlear