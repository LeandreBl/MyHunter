/*
** EPITECH PROJECT, 2017
** myHunter
** File description:
** ingame
*/

#include "my_hunter.h"

static int	reset_capture(window_t *window, misc_t *misc)
{
  if (misc->capture != NULL)
    sfImage_destroy(misc->capture);
  misc->capture= sfRenderWindow_capture(window->window);
  if (misc->capture == NULL)
    return (-1);
  return (0);
}

int		ingame(window_t *window, misc_t *misc)
{
  sfThread	*ducks;

  if (start_ducks_ia_thread(&misc->ducks, &ducks) == -1)
    return (-1);
  while (sfRenderWindow_isOpen(window->window))
  {
    window_clear(window);
    display_background(window, misc);
    display_ducks(window, misc);
    reset_capture(window, misc);
    if (key_released(sfKeyEscape) || key_released(sfKeyP))
      dopause(window, misc);
    if (pollevent(window, misc) == -1)
      return (-1);
    display_grass(window, misc);
    display_cursor(window, misc);
    display_bushes(window, misc);
    window_refresh(window);
  }
  free_thread(ducks);
  return (0);
}
