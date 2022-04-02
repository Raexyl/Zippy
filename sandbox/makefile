PROJECT_NAME := Sandbox

#Directories
BUILD_DIR := build
OBJ_DIR := int
SRC_DIR := src
INC_DIR := Zippy/includes
LIB_DIR := Zippy

#Flags
LIBS := -lZippy
INCLUDEFLAGS := -I$(INC_DIR)
LDFLAGS := -L$(LIB_DIR) $(LIBS) -Wl,-rpath,./
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
$(PROJECT_NAME): $(OBJ_FILES) | buildDirCheck
	g++ -o $@ $^ $(LDFLAGS) 
	mv $@ $(BUILD_DIR)/

#compile .cpp files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | objDirCheck updateZippy
	g++ $(CPP_FLAGS) -fPIC $(INCLUDEFLAGS) -c -o $@ $<

#compile .c files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | objDirCheck updateZippy
	g++ $(CPP_FLAGS) -fPIC $(INCLUDEFLAGS) -c -o $@ $<

buildDirCheck:
	mkdir -p $(BUILD_DIR)

objDirCheck:
	mkdir -p $(OBJ_DIR)

#Update Zippy includes, etc
updateZippy:
	mkdir -p Zippy
	cp ../build/libZippy.so Zippy
	cp Zippy/libZippy.so build
	mkdir -p Zippy/includes
	cp ../src/*.h Zippy/includes
	cp ../vendor/includes/ -r Zippy
	mkdir -p build/shaders
	cp ../build/shaders/* build/shaders

clean:
	rm $(OBJ_DIR)/* -f
	rm $(BUILD_DIR)/* -f -r