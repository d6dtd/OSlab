
BUILD_DIR = ./build
CC = gcc
CFLAGS = -c
LD = gcc
LIB = -I ../include/
OBJS = $(BUILD_DIR)/main.o $(BUILD_DIR)/disk.o

$(BUILD_DIR)/main.o: main.c
	$(CC) $(CFLAGS) $(LIB) $< -o $@
	
$(BUILD_DIR)/disk.o: disk.c
	$(CC) $(CFLAGS) $(LIB) $< -o $@
	
schedule: $(OBJS)
	$(LD) $^ -o $@
	
.PHONY : mk_dir clean all

mk_dir:
		if [ ! -d $(BUILD_DIR) ]; then mkdir $(BUILD_DIR); fi
		
clean:
		rm -rf $(BUILD_DIR)
		
build: schedule

all: mk_dir build
