/*
** EPITECH PROJECT, 2017
** MyHunter
** File description:
** poll event close
*/

#include "my_hunter.h"

int		poll_event_close(window_t *window,
				 misc_t *misc,
				 __attribute__ ((unused)) sfEvent *event)
{
  sfSprite_setColor(misc->misc[0]->sprite, sfColor_fromRGB(100, 100, 100));
  while (sfRenderWindow_isOpen(window->window))
  {
    window_clear(window);
    display_background(window, misc);
    put_word("Press ESCAPE to cancel or\nENTER to leave\n",
	     ORIGIN, window, sfWhite);
    if (key_released(sfKeyEscape))
      break;
    if (key_released(sfKeyReturn))
      sfRenderWindow_close(window->window);
    window_refresh(window);
  }
  sfSprite_setColor(misc->misc[0]->sprite, sfWhite);
  return (0);
}
