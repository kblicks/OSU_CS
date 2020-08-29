CC=g++
exe_file = driver


$(exe_file): driver.cpp card.o hand.o 
	$(CC) driver.cpp card.o hand.o -o  $(exe_file)

book.o:  card.cpp card.h hand.cpp hand.h 
	$(CC) -c card.cpp -c hand.cpp 


clean: 
	rm -f *.o $(exe_file)