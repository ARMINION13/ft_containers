NAME = VectorTest

all : $(NAME)

ifdef WSL_DISTRO_NAME
	
CXX = g++ #for linux
CPPFLAGS = -std=c++11 -Wall -Wextra -Werror

else 
	
CXX = clang++ #for mac
CPPFLAGS = -std=c++98 -Wall -Wextra -Werror

endif

TRAP = -Wshadow -Wno-shadow

SRCS = main.cpp

OBJS = main.o

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
