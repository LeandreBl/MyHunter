##
## EPITECH PROJECT, 2017
## 
## File description:
## makefile
##

NAME            = my_hunter

CC              = gcc

MAKE            = make -C

LIB             = -L./lib/C -lmy
LIB             += -lmy_csfml
LIB             += -lcsfml-window -lcsfml-graphics -lcsfml-system -lcsfml-audio
# Comment above and uncomment below for Epitech configuration
#LIB             += -lc_graph_prog
LIB             += -lm

SRCS            = src/main.c
SRCS            += src/usage.c
SRCS            += src/start_game.c
SRCS            += src/init_misc.c
SRCS            += src/init_sounds.c
SRCS            += src/init_ducks.c
SRCS            += src/ingame.c
SRCS            += src/poll_event.c
SRCS            += src/poll_event_close.c
SRCS            += src/poll_event_cursor.c
SRCS            += src/poll_event_click.c
SRCS            += src/poll_event_resize.c
SRCS            += src/pause.c
SRCS            += src/timer.c
SRCS            += src/display.c
SRCS            += src/display_score.c
SRCS            += src/ducks_ia.c
SRCS            += src/spawn_duck.c
SRCS            += src/shot_duck.c

OBJ             = $(SRCS:.c=.o)

RM              = rm -f

CFLAGS          = -W -Werror -Wall -Wextra
CFLAGS          += -I ./include
CFLAGS          += -g3 -O3

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) lib/C
	$(MAKE) lib/C/CSFML
	$(CC) $(OBJ) -o $(NAME) $(CFLAGS) $(LIB)
	@       tput setaf 2; cat include/signature; tput sgr0

clean:
	$(MAKE) lib/C clean
	$(MAKE) lib/C/CSFML clean
	$(RM) $(OBJ)

fclean: clean
	$(MAKE) lib/C fclean
	$(MAKE) lib/C/CSFML fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
