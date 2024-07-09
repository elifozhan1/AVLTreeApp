kural: derle calistir

derle:
	g++ -I ./include/ -o ./lib/StackNode.o -c ./src/StackNode.cpp
	g++ -I ./include/ -o ./lib/Stack.o -c ./src/Stack.cpp
	g++ -I ./include/ -o ./lib/Node.o -c ./src/Node.cpp
	g++ -I ./include/ -o ./lib/AVL.o -c ./src/AVL.cpp
	g++ -I ./include/ -o ./lib/LinkedListNode.o -c ./src/LinkedListNode.cpp
	g++ -I ./include/ -o ./lib/LinkedList.o -c ./src/LinkedList.cpp
	g++ -I ./include/ -o ./lib/Program.o -c ./src/Program.cpp
	
	g++ -I ./include/ -o ./bin/main ./lib/StackNode.o ./lib/Stack.o ./lib/Node.o ./lib/AVL.o ./lib/LinkedListNode.o ./lib/LinkedList.o ./lib/Program.o ./src/main.cpp
calistir:
	./bin/main.exe