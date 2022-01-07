PROJECT_NAME := LearnOpenGL

#Directories
BUILD_DIR := build
OBJ_DIR := int
SRC_DIR := src
INC_DIR := ./include
LIB_DIR := ./libs

#Flags
LIBS := -lglfw3 -lGL -lX11 -lpthread -lXrandr -lXi -ldl
INCLUDEFLAGS := -I$(INC_DIR)
LDFLAGS := -L$(LIB_DIR) $(LIBS)
CPP_FLAGS := -Wall -g

#What .o files do we need for final exectuable?
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
	g++ -o $@ $^ $(LDFLAGS) 
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

#DON'T USE THIS! must cd into build directory first
run:
	./build/$(PROJECT_NAME)