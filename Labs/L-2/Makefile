CC=g++
exe_file = driver


$(exe_file): driver.cpp student_db.o
	$(CC) driver.cpp student_db.o -o $(exe_file)

book.o: student_db.cpp student_db.h
	$(CC) -c student_db.cpp

clean: 
	rm -f *.o $(exe_file)