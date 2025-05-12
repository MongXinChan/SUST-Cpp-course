# 定义编译器
CC = gcc

# 定义静态库文件名
LIBFUN = libfun.a

# 定义源文件目录和头文件目录
SRC_DIR = src
INC_DIR = include

# 定义编译选项
CFLAGS = -I$(INC_DIR)

# 定义源文件和目标文件
lib_srcs := $(wildcard $(SRC_DIR)/*.c)
lib_objs := $(patsubst $(SRC_DIR)/%.c, lib/%.o, $(lib_srcs))

# 创建 lib 目录
lib_dir:
	@mkdir -p lib

# 编译源文件
lib/%.o : $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# 创建静态库
$(LIBFUN) : $(lib_objs)
	@mkdir -p lib
	ar cr $@ $^

# 默认目标
all: $(LIBFUN)

# 清理生成的文件
clean:
	rm -rf lib/*.o lib/*.a

# 伪目标
.PHONY: all clean lib_dir