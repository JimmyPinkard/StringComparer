CC = g++ -std=c++14
PROG = StringComparer
SRC = src/main.cpp
HEAD = src/headers/main.h

$(PROG) : *.o $(HEAD)
	$(CC) -o $(PROG) *.o
	rm *.o

*.o : $(SRC) $(HEAD)
	$(CC) -c $(SRC)

install:
	make
	sudo cp $(PROG) /usr/local/bin/$(PROG)
	make clean

clean:
	rm *.o $(PROG)
