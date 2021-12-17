CC = g++ -std=c++17 -g3
PROG = StringComparer
SRC = main.cpp

$(PROG) : *.o
	$(CC) -o $(PROG) *.o 2> err.txt
	rm *.o

*.o : $(SRC)
	$(CC) -c $(SRC) 2> err.txt

run:
	make
	./$(PROG)

clean:
	rm *.o $(PROG) err.txt