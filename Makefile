test: main.o AddressBook.o Person.o SMS.o Search.o
	g++ -o test main.o AddressBook.o Person.o SMS.o Search.o

main.o: AddressBook.h main.cpp
	g++ -c main.cpp

Addressbook.o: Person.h Search.h SMS.h AddressBook.cpp
	g++ -c Addressbook.cpp

Person.o: Person.cpp
	g++ -c Person.cpp

SMS.o: SMS.cpp
	g++ -c SMS.cpp

Search.o: Search.cpp
	g++ -c Search.cpp -std=c++0x


$(make):
	g++ -c main.cpp
	g++ -c AddressBook.cpp
	g++ -c Person.cpp
	g++ -c SMS.cpp
	g++ -c Search.cpp
	g++ -o test main.o AddressBook.o Person.o SMS.o Search.o

