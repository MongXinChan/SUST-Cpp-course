# Makefile with static library

.PHONY: liba testliba clean

# 定义编译器
CC = gcc

# 定义静态库文件名
LIBFUN = libfun.a

# 默认目标
all: testliba

# 编译静态库
liba: $(LIBFUN)
$(LIBFUN): max.o min.o
	ar cr $@ $^

# 编译 max.o
max.o: max.c fun.h
	$(CC) -c max.c

# 编译 min.o
min.o: min.c fun.h
	$(CC) -c min.c

# 编译并链接 main.out
testliba: main.out
main.out: main.o $(LIBFUN)
	$(CC) -o $@ main.o -L. -lfun

# 编译 main.o
main.o: main.c fun.h
	$(CC) -c main.c

# 清理生成的文件
clean:
	rm -f *.o *.a main.out