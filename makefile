TITLE=game
HEADERS=
OBJECTS=main.o
TOCLEAN=*.o *.gch $(TITLE) dbg$(TITLE) a.out
SFML=-lsfml-graphics -lsfml-window -lsfml-system
EVERY=$(SFML) -std=c++17
COMPILE=$(EVERY) -c -O3
LINK=$(EVERY) -O3
DBGCOMPILE=$(EVERY) -c -g -O0
DBGLINK=$(EVERY) -g -O0

all: dbg$(TITLE) $(TITLE)
$(TITLE):$(OBJECTS)
	g++ $(addprefix build/, $(OBJECTS)) -o $@ $(LINK)
dbg$(TITLE):$(addprefix dbg, $(OBJECTS))
	g++ $(addprefix build/dbg, $(OBJECTS)) -o $@ $(DBGLINK) 
dbg%.o:%.cpp $(HEADERS)
	g++ $< -o build/$@ $(DBGCOMPILE)
%.o:%.cpp $(HEADERS)
	g++ $< -o build/$@ $(COMPILE) 
clean:
	rm -f $(TOCLEAN) $(addprefix build/, $(TOCLEAN)) 
