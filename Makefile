NAME := ./sudoku

SRCS := main.c \
casevide.c\
solver.c\
testchiffre.c\
strsplit.c\
shuffle.c\
remove.c\
clib_nu.c\
clib_cache.c\
idiot_solver.c\
segment.c\

OBJS := $(SRCS:.c=.o)

CC := gcc
CFLAGS := -Wall -Wextra
RM := rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

test : $(NAME)
	$(NAME) chiffre.txt

clean:
	$(RM) $(OBJS)

fclean : clean$(RM) $(NAME)

re: fclean all