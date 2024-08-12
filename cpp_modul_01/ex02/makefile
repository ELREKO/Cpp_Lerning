SRC = src/main.cpp
OBJDIR = build
OBJ = $(OBJDIR)/main.o
CC = c++
RM = rm -f
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = Zombie

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CPPFLAGS) $(OBJ) -o $(NAME)

$(OBJDIR)/%.o: $(SRC) | $(OBJDIR)
	$(CC) $(CPPFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	$(RM) -r $(OBJDIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

