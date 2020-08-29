CC=g++
exe_file = application




$(exe_file): application.cpp shape.o rectangle.o circle.o square.o

book.o: shape.cpp shape.h rectangle.cpp rectangle.h circle.cpp circle.h square.cpp square.o
	$(CC) -c shape.cpp -c rectangle.cpp -c circle.cpp -c.square.cpp

	$(CC) application.cpp shape.o rectangle.o circle.o square.o $(exe_file)


clean: 
	rm -f *.o $(exe_file)