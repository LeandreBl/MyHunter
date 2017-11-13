/*
** EPITECH PROJECT, 2017
** my hunter
** File description:
** start game
*/

#include "my_hunter.h"

#include "my.h"
#include "colors.h"
#include "defines.h"

int		start_game(void)
{
  window_t	*window;
  misc_t	misc;

  window = init_window(600, 4.0 / 3.0, "MyHunter", sfResize | sfClose);
  if (init_misc(&misc) == -1 || init_sounds(window) == -1)
  {
    free_window(window);
    return (-1);
  }
  window->font = my_strdup("fonts/audims.ttf");
  sfRenderWindow_setFramerateLimit(window->window, FRAMERATE);
  if (ingame(window, &misc) == -1)
    mdprintf(2, "[%sWarning%s] An error occured ingame\n",
	     GREEN, RESET);
  free_window(window);
  free_sprites(misc.misc);
  free_sprites_only(misc.duck);
  return (0);
}
