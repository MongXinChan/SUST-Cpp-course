# 定义编译器
CXX = g++

# 定义编译选项
compile_flags := -g -O3 -w -fPIC

# 定义包含路径
include_path := ./include
I_options := $(include_path:%=-I%)

# 定义源文件目录和目标文件目录
SRC_DIR = src
OBJ_DIR = objs
LIB_DIR = lib

# 使用 wildcard 函数自动获取所有源文件
cpp_srcs := $(wildcard $(SRC_DIR)/*.cpp)
# 使用 patsubst 函数生成目标文件列表
cpp_objs := $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(cpp_srcs))
# 过滤掉 main 目标文件，只编译库文件
so_objs := $(filter-out $(OBJ_DIR)/main.o, $(cpp_objs))

# 默认目标
all: compile dynamic

# 编译所有源文件
compile: $(cpp_objs)

# 创建目标文件
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) -c $< -o $@ $(compile_flags) $(I_options)

# 创建动态库
dynamic: lib/libfunction.so

lib/libfunction.so : $(so_objs)
	@mkdir -p $(dir $@)
	$(CXX) -shared $^ -o $@

# 清理生成的文件
clean:
	rm -rf $(OBJ_DIR)/*.o $(LIB_DIR)/*.so

# 伪目标
.PHONY: all compile dynamic clean