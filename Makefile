test: main.o addressbook.o person.o sms.o search.o
	g++ -o test main.o addressbook.o person.o sms.o search.o

main.o: addressbook.h main.cpp
	g++ -c main.cpp

addressbook.o: person.h search.h sms.h addressbook.cpp
	g++ -c addressbook.cpp

person.o: person.cpp
	g++ -c person.cpp

sms.o: sms.cpp
	g++ -c sms.cpp

search.o: search.cpp
	g++ -c search.cpp


$(make):
	g++ -c main.cpp
	g++ -c addressbook.cpp
	g++ -c person.cpp
	g++ -c sms.cpp
	g++ -c search.cpp
	g++ -o main main.o addressbook.o person.o sms.o search.o

