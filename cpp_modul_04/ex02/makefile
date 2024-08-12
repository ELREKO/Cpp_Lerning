SRC_DIR = src
INCLUDES_DIR = includes

OBJ_DIR = build
CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -I$(INCLUDES_DIR)
CXX = c++
RM = rm -f

# Automatically find all source files in SRC_DIR
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)

# Derive object file names from source file names
OBJECTS = $(patsubst %.cpp,$(OBJ_DIR)/%.o,$(notdir $(SOURCES)))

# Executable name
EXECUTABLE = Abstract_Class

# Include main.cpp directly
MAIN_SRC = main.cpp
MAIN_OBJ = $(OBJ_DIR)/main.o

all: $(OBJ_DIR) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) $(MAIN_OBJ)
	$(CXX) $(CPPFLAGS) $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CPPFLAGS) -c $< -o $@

$(MAIN_OBJ): $(MAIN_SRC) | $(OBJ_DIR)
	$(CXX) $(CPPFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	$(RM) -r $(OBJ_DIR)

fclean: clean
	$(RM) $(EXECUTABLE)

re: fclean all
