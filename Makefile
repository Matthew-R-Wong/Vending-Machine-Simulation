prog1 : main.o vendingInventory.o vendingItem.o
	g++ main.o vendingInventory.o vendingItem.o -o prog1

main.o : main.cpp vendingInventory.h vendingItem.h
	g++ -c main.cpp -o main.o

vendingInventory.o : vendingInventory.cpp vendingInventory.h
	g++ -c vendingInventory.cpp -o vendingInventory.o

vendingItem.o : vendingItem.cpp vendingItem.h
	g++ -c vendingItem.cpp -o vendingItem.o

clean :
	rm *.o
	rm prog1
