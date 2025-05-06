# Search the source files in the current directory
# and store them in the variable SRC
aux_source_directory(. LIB_SRC)

# Create a static library named MyFunction
add_library(MyFunction STATIC ${LIB_SRC})