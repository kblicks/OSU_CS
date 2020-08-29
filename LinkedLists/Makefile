CC=g++
exe_file = test_linked_list

$(exe_file): test_linked_list.cpp linked_list.o
	$(CC) test_linked_list.cpp  linked_list.o -o $(exe_file)

book.o:  node.h linked_list.cpp linked_list.h
	$(CC)  -c linked_list.cpp

clean: 
	rm -f *.o $(exe_file)