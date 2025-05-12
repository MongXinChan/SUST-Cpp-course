#link with static library in makefile

OBJS = $(patsubst %.c, %.o, $(wildcard ./*.c))
TARGET = main
CC = gcc

LDFLAG = -L./lib_a
LIB = -lmyfun

$(TARGET): $(OBJS)
	$(CC) -o $@ $^ $(LDFLAG) $(LIB)

%.o : %.c
	$(CC) -c $^ -o $@

clean:
	rm -f *.o $(TARGET)