CC=g++
exe_file = driver


$(exe_file): driver.cpp pclasses.o
	$(CC) driver.cpp pclasses.o -o $(exe_file)

book.o: pclasses.cpp p_classes.h
	$(CC) -c pclasses.cpp

clean: 
	rm -f *.o $(exe_file)