NAME = MutantStack

all : $(NAME)

CXX = clang++ 

CPPFLAGS = -std=c++98 -Wall -Wextra -Werror 

TRAP = -Wshadow -Wno-shadow

SRCS = 

OBJS = 

$(OBJS) : $(SRCS)

$(NAME) : $(OBJS)
	$(CXX) $(CPPFLAGS) $(OBJS) -o $@


# - - - - - - - - - - - - - - - - - #
# - - - - C L E A N I N G - - - - - #
# - - - - - - - - - - - - - - - - - #


make fclean:
	@rm -f $(NAME)
	@rm -f $(OBJS)

re:	fclean all