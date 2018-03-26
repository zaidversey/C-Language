C=gcc
CFLAGS=-c -Wall
GLFLAGS=-lglut -lGL -lGLU -lm
SOURCES=particles_OpenGL.c Zaid_particles_fountain.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=particles

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) $(GLFLAGS) -o $@

.c:.o
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f *.o $(EXECUTABLE)
