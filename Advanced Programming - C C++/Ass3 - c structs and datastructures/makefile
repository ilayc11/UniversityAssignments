JerryBoree: JerryBoreeMain.o Jerry.o MultiValueHashTable.o LinkedList.o KeyValuePair.o HashTable.o
	gcc JerryBoreeMain.o Jerry.o MultiValueHashTable.o LinkedList.o KeyValuePair.o HashTable.o -o JerryBoree

LinkedList.o: LinkedList.c LinkedList.h
	gcc -c LinkedList.c
	
KeyValuePair.o: KeyValuePair.c KeyValuePair.h
	gcc -c KeyValuePair.c

HashTable.o: HashTable.c HashTable.h LinkedList.h KeyValuePair.h
	gcc -c HashTable.c

MultiValueHashTable.o: MultiValueHashTable.c MultiValueHashTable.h HashTable.h
	gcc -c MultiValueHashTable.c

Jerry.o: Jerry.h Jerry.c
	gcc -c Jerry.c
	
JerryBoreeMain.o: JerryBoreeMain.c MultiValueHashTable.h Jerry.h
	gcc -c JerryBoreeMain.c
clean:
	rm -f *.o JerryBoree
