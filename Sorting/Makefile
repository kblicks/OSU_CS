CC=g++
exe_file = run_wizard

$(exe_file): run_wizard.cpp catalog.o
	$(CC) run_wizard.cpp catalog.o -o $(exe_file)

book.o: catalog.cpp catalog.h
	$(CC) -c catalog.cpp

clean: 
	rm -f *.o $(exe_file)