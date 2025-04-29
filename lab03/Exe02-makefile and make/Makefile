# 定义编译器
CC=g++
# 定义编译选项
CFLAGS=-Wall -g -IInc
# 定义目标文件目录
BUILD_DIR=build
# 定义源文件目录
SRC_DIR=src
# 定义头文件目录
INC_DIR=Inc
# 定义源文件
SRCS=$(wildcard $(SRC_DIR)/*.cpp)
# 定义目标文件
OBJS=$(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRCS))
# 定义最终的可执行文件
TARGET=$(BUILD_DIR)/lab3_practice

# 默认目标
all: $(TARGET)

# 创建目标文件目录
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# 编译目标文件
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# 链接目标文件生成可执行文件
$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $@
	
# 清理生成的文件
clean:
	rm -rf $(BUILD_DIR)

# 防止隐式规则干扰
.PHONY: all clean