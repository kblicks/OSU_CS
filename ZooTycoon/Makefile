CC= g++
exe_file = zoo_tycoon

$(exe_file): zoo_tycoon.cpp zoo.o animal.o monkey.o sea_otter.o sloth.o
	$(CC) zoo_tycoon.cpp zoo.o animal.o monkey.o sea_otter.o sloth.o -o $(exe_file)

book.o: zoo.cpp zoo.h animal.cpp animal.h monkey.cpp monkey.h sea_otter.cpp sea_otter.h sloth.cpp sloth.h
	$(CC) -c zoo.cpp -c animal.cpp -c monkey.cpp -c sea_otter.cpp -c sloth.cpp

clean:
	rm -f *.o $(exe_file)