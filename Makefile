CC = g++
DEVFLAGS = -Wall
PROG = game
SRCS := $(patsubst %.cpp,%.o,$(wildcard *.cpp))
SRCS += $(patsubst %.cpp,%.o,$(wildcard */*.cpp))
COMPILE = $(CC) -c
LIBS = -lsfml-graphics -lsfml-window -lsfml-system

all: $(PROG)

$(PROG): $(SRCS)
	$(CC) -o $(PROG) $(SRCS) $(LIBS)

clean:
	rm -f *.o
	rm -f */*.o

%.o: %.cpp
	$(COMPILE) -o $@ $<