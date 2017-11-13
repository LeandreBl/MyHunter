/*
** EPITECH PROJECT, 2017
** myHunter
** File description:
** ingame
*/

#include "my_hunter.h"

int		ingame(window_t *window, misc_t *misc)
{
  while (sfRenderWindow_isOpen(window->window))
  {
    window_clear(window);
    display_background(window, misc);
    if (key_released(sfKeyEscape) || key_released(sfKeyP))
      dopause(window, misc);
    if (pollevent(window, misc) == -1)
      return (-1);
    display_cursor(window, misc);
    display_bushes(window, misc);
    window_refresh(window);
  }
  return (0);
}
