CC=g++
exe_file = go_fish


$(exe_file): go_fish.cpp card.o deck.o hand.o player.o game.o
	$(CC) go_fish.cpp card.o deck.o hand.o player.o game.o -o $(exe_file)

book.o: card.cpp card.h deck.cpp deck.h hand.cpp hand.h player.cpp player.h game.cpp game.h
	$(CC) -c card.cpp -c deck.cpp -c hand.cpp -c player.cpp -c game.cpp


clean: 
	rm -f *.o $(exe_file)




