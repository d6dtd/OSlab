
BUILD_DIR = ./build
CC = gcc
CFLAGS = -c
LD = gcc
LIB = -I ../include/
OBJS = $(BUILD_DIR)/main.o $(BUILD_DIR)/my_memory.o

$(BUILD_DIR)/main.o: main.c
	$(CC) $(CFLAGS) $(LIB) $< -o $@
	
$(BUILD_DIR)/my_memory.o: my_memory.c
	$(CC) $(CFLAGS) $(LIB) $< -o $@
	
$(BUILD_DIR)/allocate: $(OBJS)
	$(LD) $^ -o $@
	
.PHONY : mk_dir clean all

mk_dir:
		if[ ! -d $(BUILD_DIR) ]; then mkdir $(BUILD_DIR); fi
		
clean:
		rm -rf $(BUILD_DIR)
		
build: $(BUILD_DIR)/schedule

all: mk_dir build