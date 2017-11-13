/*
** EPITECH PROJECT, 2017
** myHunter
** File description:
** pause
*/

#include "my_hunter.h"

static void	middle_window(window_t *window, sfVector2f *pos)
{
  pos->x = (window->width - (15 * 30)) / 2;
  pos->y = window->height / 2 - 15;
}

void		dopause(window_t *window, misc_t *misc)
{
  sfVector2f	pos;

  middle_window(window, &pos);
  sfSprite_setColor(misc->misc[0]->sprite,
		    sfColor_fromRGB(100, 100, 100));
  while (sfRenderWindow_isOpen(window->window))
  {
    window_clear(window);
    display_background(window, misc);
    put_word("Pause, press ESCAPE to resume",
	     pos, window, sfYellow);
    pollevent(window, misc);
    if (key_released(sfKeyEscape) || key_released(sfKeyP))
      break;
    window_refresh(window);
  }
  sfSprite_setColor(misc->misc[0]->sprite, sfWhite);
}
