CC=g++
CFLAGS=-Wall
DEPS = ''
FILE = Trie
compile :
	$(CC) $(CFLAGS) $(FILE).cpp -o $(FILE).o
run :compile
	./$(FILE).o
jumpgame.o : JumpGame.cpp
		$(CC) $(CFLAGS) JumpGame.cpp
clean :
		rm *.o
