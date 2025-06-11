GXX = g++

GXX_FLAGS = -g -std=c++17

BUILD = build
OBJ = $(BUILD)/obj
EXEC = solver

SRC = $(wildcard src/*.cpp)
OBJS = $(subst src/, $(OBJ)/, $(addsuffix .o, $(basename $(SRC))))

all: clean compile

compile: $(BUILD)/$(EXEC)

$(BUILD)/$(EXEC): $(OBJS)
	$(GXX) $(OBJS) -o $@

$(OBJ)/%.o: src/%.cpp
	$(GXX) $(GXX_FLAGS) -c $< -o $@

.PHONY: clean
clean: mkbuild
	del /Q /S $(BUILD)\*

mkbuild:
	if not exist "$(BUILD)" mkdir "$(BUILD)"
	if not exist "$(OBJ)" mkdir "$(OBJ)"