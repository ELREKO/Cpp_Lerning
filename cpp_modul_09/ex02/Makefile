# Compiler und Flags
CXX = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

# Verzeichnisse
INCLUDES_DIR = include
OBJ_DIR = build

# Quell-Dateien
SRC_FILES = main.cpp  # Nur main.cpp als Quell-Datei

# Objekt-Dateien
OBJECTS = $(patsubst %.cpp,$(OBJ_DIR)/%.o,$(notdir $(SRC_FILES)))

# Ausführbare Datei
EXECUTABLE = PmergeMe

# Targets
all: $(OBJ_DIR) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(CPPFLAGS) $^ -o $@

$(OBJ_DIR)/%.o: %.cpp | $(OBJ_DIR)
	$(CXX) $(CPPFLAGS) -I$(INCLUDES_DIR) -c $< -o $@

# Rule to create the object directory
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Clean up build artifacts
clean:
	$(RM) -r $(OBJ_DIR)

fclean: clean
	$(RM) $(EXECUTABLE)

# Rebuild everything
re: fclean all

.PHONY: all clean fclean re
