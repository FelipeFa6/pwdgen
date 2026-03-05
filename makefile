
CC    = cc
FLAGS = -Wall -Wextra
NAME  = test

all:
	$(CC) $(FLAGS) -o $(NAME) main.c 

debug:

	$(CC) $(FLAGS) -DDEBUG -o $(NAME) main.c 
