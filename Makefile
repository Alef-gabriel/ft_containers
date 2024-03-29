EXEC    = ft_test
EXEC2    = std_test
NAME = $(EXEC)
NAME2 = $(EXEC2)

CC      = g++
CFLAGS    = -g -Wall -Wextra -Werror -std=c++98
INCLUDE = $(addprefix -I ./includes, \
			/. \
			/stack \
			/vector \
			/map )

SRC = $(addprefix ./src/, \
          	main.cpp \
          	mapTestes.cpp \
          	stackTestes.cpp \
          	vectorTestes.cpp)

%_ft.o: %.cpp
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $(<:%.cpp=%_ft.o)

%_std.o: %.cpp
	$(CC) $(CFLAGS) $(INCLUDE) -DEFAULT=1 -c $< -o $(<:%.cpp=%_std.o)

all: $(EXEC) $(EXEC2)

ft: all
	./$(NAME)

std: all
	./$(NAME2)

OBJ_FT	= $(SRC:%.cpp=%_ft.o)

OBJ_STD	= $(SRC:%.cpp=%_std.o)

$(EXEC): $(OBJ_FT)
	$(CC) $(CFLAGS) $(OBJ_FT) -o $(EXEC)

$(EXEC2): $(OBJ_STD)
	$(CC) $(CFLAGS) $(OBJ_STD) -DEFAULT=1 -o $(EXEC2)

clean:
	rm -rf $(OBJ_STD) $(OBJ_FT)
fclean: clean
	rm -rf $(EXEC) $(EXEC2)

re: fclean all

.PHONY: all clean fclean re