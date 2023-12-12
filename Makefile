TARGET=main
CC=gcc
DEBUG=-g
OPT=-O0
WARN=-Wall
UTILS=bintr.c
UTILS1=utils.c
CCFLAGS=$(DEBUG) $(OPT) $(WARN)
LD=gcc
OBJS=main.c
all: main.c
	$(LD) -o $(TARGET) $(OBJS) $(DEBUG) $(OPT) $(WARN) $(UTILS) $(UTILS1) -lm

run: 
	./main
