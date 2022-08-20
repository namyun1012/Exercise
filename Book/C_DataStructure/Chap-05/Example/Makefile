DBLinkedList.o : DBLinkedList.h DBLinkedList.cc
	g++ -c DBLinkedList.cc

main.o : main.cc DBLinkedList.h 
	g++ -c main.cc

main : main.o DBLinkedList.o
	g++ DBLinkedList.o main.o -o main