# VARIABLE DECLARATION ############################################################################

NAME =			BureaucratForm

CC =			c++

CFLAGS =		-Wall -Werror -Wextra -std=c++98

HEADERS =		./includes

BLACK	= 		\033[0;30m
RED		= 		\033[0;91m
GREEN	= 		\033[0;92m
YELLOW	= 		\033[0;93m
BLUE	= 		\033[0;94m
PURPLE	= 		\033[0;35m
CYAN	= 		\033[0;96m
WHITE	= 		\033[0;37m

SRCS =			./srcs/main.cpp \
				./srcs/Bureaucrat.cpp \
				./srcs/Form.cpp \

OBJS =			$(SRCS:.cpp=.o)

# RULES ###########################################################################################

all: $(NAME)
$(NAME): $(OBJS)
	echo "$(CYAN)Compiling BureaucratForm :$(WHITE)"
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	echo "$(GREEN)BureaucratForm successfully compiled !$(WHITE)"

./srcs/%.o: ./srcs/%.cpp $(HEADERS)/Bureaucrat.hpp $(HEADERS)/Form.hpp
	$(CC) $(CFLAGS) -I$(HEADERS) -c $< -o $@

clean:
	echo "$(YELLOW)Deleting all files exept binaries$(WHITE)"
	rm -rf $(OBJS)

fclean: clean
	echo "$(PURPLE)Deleting binaries$(WHITE)"
	rm -rf $(NAME)

re:
	make -s fclean
	make -s all

.SILENT:

.PHONY: all clean fclean re
