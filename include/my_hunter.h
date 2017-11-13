/*
** EPITECH PROJECT, 2017
** my_hunter
** File description:
** header
*/

#ifndef MY_HUNTER_H_
# define MY_HUNTER_H_

# include "csfml.h"

# define NB_EVENT	(1)
# define FRAMERATE	(60)

struct		misc_s
{
  sprite_t	**misc;
  sprite_t	**duck;
  sprite_t	**dog;
};

struct		poll_s
{
  sfEventType	type;
  int		(* fction)(window_t *window,
			   struct misc_s *misc,
			   sfEvent *event);
};

struct		clocker_s
{
  clock_t	prev;
  clock_t	refresh;
  double	time;
};

typedef struct misc_s misc_t;
typedef struct poll_s poll_t;
typedef struct clocker_s clocker_t;

/* General functions */
int		usage(int ac, char **av);
int		start_game(void);
int		init_misc(misc_t *misc);
int		ingame(window_t *window, misc_t *misc);
int		pollevent(window_t *window, misc_t *misc);
int		refresh_clock(clocker_t *timer);
int		set_clock(clocker_t *timer);
void		display_background(window_t *window, misc_t *misc);

/* Poll event ptr functions */
int		poll_event_close(window_t *window,
				 misc_t *misc, sfEvent *event);

#endif /* !MY_HUNTER_H_ */
