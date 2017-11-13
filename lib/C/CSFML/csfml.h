/*
** csfml.h for csfml_h_lib in /home/leandre/Rushs/scroller/lib/CSFML
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Fri Mar 31 13:58:23 2017 Léandre Blanchard
** Last update Tue Nov  7 20:06:25 2017 Léandre Blanchard
*/

#ifndef MY_CSFML_H_
# define MY_CSFML_H_

#ifdef __cplusplus
extern "C" {
#endif
#ifdef __horriblethingwithemacs
}
#endif

# include <SFML/Audio.h>
# include <SFML/Network.h>
# include <SFML/Graphics.h>
# include <SFML/System.h>
# include <SFML/Window.h>

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stddef.h>
# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <time.h>
# include <termios.h>
# include <curses.h>
# include <dirent.h>

# include "my.h"

# define KP(key)	(sfKeyboard_isKeyPressed(key))
# define MP		(sfMouse_isButtonPressed(sfMouseLeft))
# define ORIGIN		(xy_vectorf(0, 0))

/*
** Simple sprite structure, saving the texture and the sprite,
** can be easely used with pusprite_t, and create via a call
** of create_sprite(<pathname>)
*/
struct			sprite_s
{
  sfSprite              *sprite;
  sfTexture             *texture;
};

/*
** A window structure, containing it's size,
** the position of the mouse using pos_mouse
** a char * containing the name of the font for
** put_text fcontions
** an array of pixels, of the size of the window
** an array of sfMusics *ptr
** a texture linked to the array of pixels, same for the sprite
*/
struct			window_s
{
  int			width;
  int			height;
  sfVector2i		mouse;
  sfRenderWindow	*window;
  sfUint8		*pixels;
  char			*font;
  sfMusic		**musics;
  struct sprite_s      	*frame;
};

typedef struct window_s window_t;
typedef struct sprite_s sprite_t;

void		my_draw_line(window_t *window, sfVector2f from,
			     sfVector2f to, sfColor color);

void		free_sprite(sprite_t *sprite);

void		free_sprites_only(sprite_t **sprites);

sfUint8		*pixels_buffer(int width, int height);

void		free_thread(sfThread *thread);

void		free_window(window_t *window);

void		free_sprites(sprite_t **sprites);

sprite_t	**create_sprites(int nb);

int		is_in_rect(window_t *window, sfVector2f origin, sfVector2f size);

void		window_clear(window_t *window);

int		key_released(int key);

void		window_update(window_t *window);

void		window_refresh(window_t *window);

void		put_sprite(window_t *window, sprite_t *sprite, sfVector2f pos);

void		put_sprite_resize(window_t *window, sprite_t *sprite,
				  sfVector2f pos, sfVector2f resize);

void		close_win(window_t *window);

sfVector2i	xy_vectori(int x, int y);

sfVector2f	xy_vectorf(float x, float y);

sfVector3f	xyz_vector(float x, float y, float z);

sfVector2i	pos_mouse(window_t *window);

void		put_square(sfVector2i pos, sfColor color,
			   window_t *window, int size);

void		draw_circle(window_t *window, sfVector2f pos,
			    int size, sfColor color);

void		put_png_resize(window_t *window, sfVector2f pos,
			       const char *name, sfVector2f resize);

void		put_png(window_t *window, sfVector2f pos, const char *name);

int		my_put_pixel(window_t *window, int x, int y, sfColor color);

void		clear_color(window_t *window, sfColor color);

void		clear_white(window_t *window);

void		put_word(char *word, sfVector2f pos,
			 window_t *window, sfColor color);

void		put_number(int nb, sfVector2f pos,
			   window_t *window, sfColor color);

window_t	*init_window(int height, float dim, char *name, int bar);

sprite_t	*create_sprite(const char *pathname);

#ifdef __cplusplus
}
#endif

#endif /* !MY_CSFML_H_ */
