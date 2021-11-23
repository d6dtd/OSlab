
BUILD_DIR = ./build
CC = gcc
LD = ld
LIB = -I ../include/
OBJS = $(BUILD_DIR)/main.o $(BUILD_DIR)/disk.o

$(BUILD_DIR)/main.o: main.c disk.h
	$(CC) $(LIB) $< -o $@
	
$(BUILD_DIR)/disk.o: disk.c disk.h 
	$(CC) $(LIB) $< -o $@
	
$(BUILD_DIR)/schedule: $(OBJS)
	$(LD) $^ -o $@
	
.PHONY : mk_dir clean all

mk_dir:
		if[! -d $(BUILD_DIR)]; then mkdir $(BUILD_DIR); fi
		
clean:
		rm -rf $(BUILD_DIR)
		
build: $(BUILD_DIR)/schedule

all: mk_dir build