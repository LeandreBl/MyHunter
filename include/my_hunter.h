/*
** EPITECH PROJECT, 2017
** my_hunter
** File description:
** header
*/

#ifndef MY_HUNTER_H_
# define MY_HUNTER_H_

# include <stdint.h>

# include "csfml.h"

# define NB_EVENT	(4)
# define FRAMERATE	(60)

# define CLOCK_ERROR	("[%sError%s] CLOCK(2) error\n")
# define MEM_ERROR	("[%sError%s] Not enough memory\n")

# define SOUND_SHOT	("sounds/Duck Hunt SFX (13).ogg")

# define SPAWN_PERC	(100)

enum		status_e
{
  dead,
  falling,
  alive,
};

struct		vect_s
{
  sfVector2f	pos;
  float		angle;
  enum status_e	status;
  int		type;
  int		id;
};

struct		duck_s
{
  int		size;
  struct vect_s	*ducks;
};

struct		misc_s
{
  struct duck_s	ducks;
  sfImage	*capture;
  sprite_t	**misc;
  sprite_t	***duck;
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
typedef struct vect_s vect_t;
typedef struct duck_s duck_t;

/* General functions */
int		usage(int ac, char **av);
int		start_game(void);
int		init_misc(misc_t *misc);
int		init_sounds(window_t *window);
int		init_ducks(sprite_t ***ducks);
int		spawn_duck(duck_t *ducks);
void		auto_remove_ducks(duck_t *ducks);
int		ingame(window_t *window, misc_t *misc);
int		pollevent(window_t *window, misc_t *misc);
int		refresh_clock(clocker_t *timer);
int		start_clock(clocker_t *timer);
int		set_clock(clocker_t *timer);
void		display_grass(window_t *wnidow, misc_t *misc);
void		display_ducks(window_t *window, misc_t *misc);
void		display_background(window_t *window, misc_t *misc);
void		display_cursor(window_t *window, misc_t *misc);
void		display_bushes(window_t *window, misc_t *misc);
void		dopause(window_t *window, misc_t *misc);
int		check_alloc(void **ptrs, int total);
int		start_ducks_ia_thread(duck_t *ducks, sfThread **thread);
void		shot_duck(misc_t *misc, sfVector2i pos);

/* Poll event ptr functions */
int		poll_event_close(window_t *window,
				 misc_t *misc, sfEvent *event);
int		poll_event_cursor(window_t *window,
				  misc_t *misc, sfEvent *event);
int		poll_event_click(window_t *window,
				 misc_t *misc, sfEvent *event);
int		poll_event_resize(window_t *window,
				  misc_t *misc, sfEvent *event);

#endif /* !MY_HUNTER_H_ */
