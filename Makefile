BIN = lua2h

COMPILER = cc
FLAGS = -Wall

LIBS  = -llua5.3
LIBS += -lm

all:
	$(COMPILER) $(FLAGS) -o $(BIN) $(BIN).c $(LIBS)
