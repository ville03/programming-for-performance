CPPFLAGS = -std=c++17 -Wall -Wextra -Wshadow -pedantic -march=native

#HEADERS = include/.hpp

.PHONY: clean debug

main: main.cpp $(HEADERS)
	g++ $(CPPFLAGS) -Ofast -o main main.cpp

clean:
	rm -f main

debug: main.cpp $(HEADERS)
	g++ $(CPPFLAGS) -DDEBUG -g -o main main.cpp

%.hpp: