HEADERS=
OBJECTS=build/main.o
DBGOBJECTS=build/dbgmain.o
SFML=-lsfml-graphics -lsfml-window -lsfml-system
EVERY=$(SFML) -std=c++17
COMPILE=$(EVERY) -c -O3
LINK=$(EVERY) -O3
DBGCOMPILE=$(EVERY) -c -g -O0
DBGLINK=$(EVERY) -g -O0

FLAGS=-O3 -std=c++17 DBGFLAGS=$(FLAGS)
DBGFLAGS+=
all: game dbggame
game:$(OBJECTS)
	g++ $^ -o $@ $(LINK)
dbggame:$(DBGOBJECTS)
	g++ $^ -o $@ $(DBGLINK)
build/dbg%.o:%.cpp $(HEADERS)
	g++ $^ -o $@ $(DBGCOMPILE)
build/%.o:%.cpp $(HEADERS)
	g++ $^ -o $@ $(COMPILE)
clean:
	rm -f *.o *.gch game dbggame a.out
