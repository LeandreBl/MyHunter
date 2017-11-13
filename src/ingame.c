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
    if (pollevent(window, misc) == -1)
      return (-1);
    window_refresh(window);
  }
  return (0);
}
