Run: Driver.o
	g++ Driver.o -o Run
Driver.o: Driver.cpp
	g++ -c Driver.cpp
clean: 
	rm -f *.o
	rm Run
run: Run
	./Run
