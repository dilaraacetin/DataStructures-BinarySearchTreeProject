all:derle bagla calistir
derle:
	g++ -c -I "./include" ./src/Node.cpp -o ./lib/Node.o
	g++ -c -I "./include" ./src/BST.cpp -o ./lib/BST.o
	g++ -c -I "./include" ./src/BSTListNode.cpp -o ./lib/BSTListNode.o
	g++ -c -I "./include" ./src/BSTList.cpp -o ./lib/BSTList.o
	g++ -c -I "./include" ./src/main.cpp -o ./lib/main.o
bagla:
	g++ ./lib/Node.o ./lib/BST.o ./lib/BSTList.o ./lib/BSTListNode.o ./lib/main.o -o ./bin/program
calistir:
	./bin/program