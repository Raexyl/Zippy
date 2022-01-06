PROJECT_NAME := GLADtest

#Directories
BUILD_DIR := build
OBJ_DIR := int
SRC_DIR := src
INC_DIR := ./include
LIB_DIR := ./lib

#Flags
LDFLAGS := -L$(LIB_DIR)/ -lglfw3 -lGL -lX11 -lpthread -lXrandr -lXi -ldl #Libraries go here
INCLUDEFLAGS := -I$(INC_DIR)/
CPP_FLAGS := -Wall -g

#What obj files do we need?
SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp) $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRC_FILES))
OBJ_FILES := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(OBJ_FILES))


#Check OS and Processor
ifeq ($(OS),Windows_NT)
    exit 1
else
    UNAME_S := $(shell uname -s)
    ifeq ($(UNAME_S),Linux)
        CPP_FLAGS += -D LINUX
    endif
    ifeq ($(UNAME_S),Darwin)
        CPP_FLAGS += -D OSX
    endif
    UNAME_P := $(shell uname -p)
    ifeq ($(UNAME_P),x86_64)
        CPP_FLAGS += -D AMD64
    endif
    ifneq ($(filter %86,$(UNAME_P)),)
        CPP_FLAGS += -D IA32
    endif
    ifneq ($(filter arm%,$(UNAME_P)),)
        CPP_FLAGS += -D ARM
    endif
endif

#link .o files
$(PROJECT_NAME): $(OBJ_FILES) 				
	g++ $(LDFLAGS) -o $@ $^
	mv $@ $(BUILD_DIR)/

#compile .cpp files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	g++ $(CPP_FLAGS) -fPIC $(INCLUDEFLAGS) -c -o $@ $<

#compile .c files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	g++ $(CPP_FLAGS) -fPIC $(INCLUDEFLAGS) -c -o $@ $<

clean:
	rm $(OBJ_DIR)/* -f
	rm $(BUILD_DIR)/* -f

run:
	sudo LD_LIBRARY_PATH=LD_LIBRARY_PATH:$(LIB_DIR)/ ./build/$(PROJECT_NAME)