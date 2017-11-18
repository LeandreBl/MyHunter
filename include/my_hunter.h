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

extern const uint8_t	FRAMERATE;

# define CLOCK_ERROR	("[%sError%s] CLOCK(2) error\n")
# define MEM_ERROR	("[%sError%s] Not enough memory\n")

# define SOUND_SHOT	("sounds/Duck Hunt SFX (13).ogg")
# define SAVE_FILENAME	(".hunter_scores")

enum		status_e
{
  dead,
  hit,
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
  double	up_speed;
  double	fly_speed;
  double	fall_speed;
  int		spawnrate;
  struct vect_s	*ducks;
};

struct		data_s
{
  double        score;
  int		mag_size;
  int           ammo;
  double        countdown;
  struct duck_s ducks;
};

struct		misc_s
{
  struct data_s	datas;
  uint8_t	hitbox_debug;
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

struct		save_s
{
  char		name[20];
  int		score;
  double	spawn;
  double	speed;
};

typedef struct save_s save_t;
typedef struct misc_s misc_t;
typedef struct poll_s poll_t;
typedef struct clocker_s clocker_t;
typedef struct vect_s vect_t;
typedef struct duck_s duck_t;

/* General functions */
void		crypting(void *data, int size);
int		scores(window_t *window, misc_t *misc);
int		usage(int ac, char **av, misc_t *misc);
int		start_game(int ac, char **av);
int		init_misc(misc_t *misc);
int		init_sounds(window_t *window);
int		init_ducks(sprite_t ***ducks);
int		spawn_duck(duck_t *ducks);
void		auto_remove_ducks(duck_t *ducks);
int		menu(window_t *window, misc_t *misc);
int		ingame(window_t *window, misc_t *misc);
int		pollevent(window_t *window, misc_t *misc);
int		refresh_clock(clocker_t *timer);
int		start_clock(clocker_t *timer);
int		set_clock(clocker_t *timer);
void		reload_alert(window_t *window, misc_t *misc);
void		display_ammo(window_t *window, misc_t *misc);
void		display_time(window_t *window, misc_t *misc);
void		display_grass(window_t *wnidow, misc_t *misc);
void		display_ducks(window_t *window, misc_t *misc);
void		display_background(window_t *window, misc_t *misc);
void		display_cursor(window_t *window, misc_t *misc);
void		display_bushes(window_t *window, misc_t *misc);
void		display_score(window_t *window, misc_t *misc);
void		dopause(window_t *window, misc_t *misc);
int		check_alloc(void **ptrs, int total);
int		start_ducks_ia_thread(duck_t *ducks, sfThread **thread);
void		shot_duck(misc_t *misc, sfVector2i pos);
int		save_score(window_t *window, misc_t *misc);

/* Poll event ptr functions */
# define NB_EVENT	(5)
int		poll_event_close(window_t *window,
				 misc_t *misc, sfEvent *event);
int		poll_event_cursor(window_t *window,
				  misc_t *misc, sfEvent *event);
int		poll_event_click(window_t *window,
				 misc_t *misc, sfEvent *event);
int		poll_event_resize(window_t *window,
				  misc_t *misc, sfEvent *event);
int		poll_event_reload(window_t *window,
				 misc_t *misc, sfEvent *event);

#endif /* !MY_HUNTER_H_ */
