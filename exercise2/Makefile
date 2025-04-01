CPPFLAGS = -std=c++17 -Wall -Wextra -Wshadow -pedantic -march=native

#HEADERS = include/.hpp

.PHONY: clean debug

main: query.cpp $(HEADERS)
	g++ $(CPPFLAGS) -Ofast -o main query.cpp

clean:
	rm -f main

debug: query.cpp $(HEADERS)
	g++ $(CPPFLAGS) -DDEBUG -g -o main query.cpp

%.hpp: