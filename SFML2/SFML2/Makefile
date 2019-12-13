CC = g++
CFLAGS = -c -Wall -g -fPIC
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system -fPIC -Wall
SOURCES = SFML2.cpp SFML_GameObject.cpp SFML_GraphicalGameObject.cpp

OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE = SFML2

	
all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *.o
