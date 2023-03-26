NAME = ft_containers

all : $(NAME)

ifdef WSL_DISTRO_NAME
	
CXX = g++ #for linux
CPPFLAGS = -std=c++98 -Wall -Wextra -Werror

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
# - - - - - - T E S T - - - - - - - #
# - - - - - - - - - - - - - - - - - #

test: test_ft test_std
	@./test_ft > ft ; ./test_std > std ; diff ft std ; echo " "

test_ft : $(OBJS)
	$(CXX) $(CPPFLAGS) $(OBJS) -o $@

test_std:
	@mv ./containers/type.hpp					./type.hpp
	@mv ./containers/utils/type.hpp				./containers/type.hpp
	@clang++ -std=c++98 -Wall -Wextra -Werror	main.cpp -o $@
	@mv ./containers/type.hpp					./containers/utils/type.hpp
	@mv ./type.hpp								./containers/type.hpp

test_vector:
	cd srcs/containers_test && bash do.sh vector

test_map:
	cd srcs/containers_test && bash do.sh map

test_stack:
	cd srcs/containers_test && bash do.sh stack

# - - - - - - - - - - - - - - - - - #
# - - - - C L E A N I N G - - - - - #
# - - - - - - - - - - - - - - - - - #


make fclean:
	@rm -f $(NAME)
	@rm -f $(OBJS)
	@rm -f test_ft
	@rm -f test_std
	@rm -f std
	@rm -f ft


re:	fclean all

rtest: fclean test
