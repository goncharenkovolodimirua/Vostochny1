CC = g++
CFLAGS = -c -Wall -g -fPIC
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system -fPIC -Wall
SOURCES = Background.cpp  GameButton.cpp  pch.cpp  PlayerShip.cpp  SFML_GameObject.cpp  SFML_GraphicalGameObject.cpp Bullet.cpp      Meteor.cpp      PhysicalGameObject.cpp  SFML2.cpp       SFML_GameWindow.cpp  SFML_TextGameObject.cpp

OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE = SFML2

	
all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *.o
