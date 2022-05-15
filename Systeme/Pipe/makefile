run: main.exe
	./main.exe

main.exe: main.c randgen.o calculator.o
	gcc -o main.exe main.c randgen.o calculator.o

randgen.o: randgen.c
	gcc randgen.c -c

calculator.o: calculator.c
	gcc calculator.c -c

clean:
	rm main.exe
	rm randgen.o
	rm calculator.o
