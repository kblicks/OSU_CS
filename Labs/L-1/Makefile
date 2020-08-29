CC=g++
exe_file =multdiv_run


$(exe_file): prog.cpp multdiv.o
	$(CC) prog.cpp multdiv.o -o $(exe_file)

book.o: multdiv.cpp multdiv.h
	$(CC) -c multdiv.cpp

clean: 
	rm -f *.o $(exe_file)