GXX = gcc

GXX_FLAGS = -g

BUILD = build
OBJ = $(BUILD)/obj
EXEC = solver

SRC = $(wildcard src/*.c)
OBJS = $(subst src/, $(OBJ)/, $(addsuffix .o, $(basename $(SRC))))

all: clean compile

compile: $(BUILD)/$(EXEC)

$(BUILD)/$(EXEC): $(OBJS)
	$(GXX) $(OBJS) -o $@

$(OBJ)/%.o: src/%.c
	$(GXX) $(GXX_FLAGS) -c $< -o $@

.PHONY: clean
clean: mkbuild
	del /Q /S $(BUILD)\*

mkbuild:
	if not exist "$(BUILD)" mkdir "$(BUILD)"
	if not exist "$(OBJ)" mkdir "$(OBJ)"