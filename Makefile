all: compile

compile:
	gcc -I ./include/ -o ./lib/arsiv.o -c ./src/arsiv.c
	gcc -I ./include/ -o ./lib/dosya.o -c ./src/dosya.c
	gcc -I ./include/ -o ./lib/utils.o -c ./src/utils.c
	gcc -I ./include/ -o ./lib/main.o -c ./src/main.c
	gcc -I ./include/ -o ./bin/tarsau ./lib/arsiv.o ./lib/dosya.o ./lib/utils.o ./lib/main.o

run:
	./bin/tarsau -b test/t1 test/t2 -o s1.sau

clean:
	rm -f ./lib/*.o
	rm -f ./bin/tarsau