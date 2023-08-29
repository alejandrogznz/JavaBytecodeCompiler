GCC=g++ -std=c++17
EXE := a.out

SRC_DIR = Source
OBJ_DIR = Obj
BIN_DIR = bin

SRC := main.cpp $(wildcard $(SRC_DIR)/*cpp)
OBJ := $(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

run: $(BIN_DIR)/$(EXE)
	$(BIN_DIR)/$(EXE) Test.class

$(BIN_DIR)/$(EXE) : $(OBJ) $(BIN_DIR)
	$(GCC) $(OBJ) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(GCC) -c $< -o $@


$(BIN_DIR) $(OBJ_DIR):
	mkdir -p $@

clean: 
	rm -f $(OBJ_DIR)/*
	rm -f $(BIN_DIR)/* 


$(info $(SRC))
$(info $(OBJ))