/*
** EPITECH PROJECT, 2017
** myHunter
** File description:
** ingame
*/

#include <time.h>

#include "my_hunter.h"

#include "my.h"
#include "defines.h"
#include "colors.h"

void		display(window_t *window, misc_t *misc)
{
  display_grass(window, misc);
  display_cursor(window, misc);
  display_bushes(window, misc);
  display_score(window, misc);
  display_time(window, misc);
  display_ammo(window, misc);
}

int		ingame(window_t *window, misc_t *misc)
{
  sfThread	*ducks;
  clocker_t	timer;

  if (start_ducks_ia_thread(&misc->ducks, &ducks) == -1)
    return (-1);
  start_clock(&timer);
  while (sfRenderWindow_isOpen(window->window) &&
	 misc->countdown > 0)
  {
    set_clock(&timer);
    window_clear(window);
    display_background(window, misc);
    display_ducks(window, misc);
    if (key_released(sfKeyEscape) || key_released(sfKeyP))
      dopause(window, misc);
    if (pollevent(window, misc) == -1)
      return (-1);
    display(window, misc);
    window_refresh(window);
    misc->countdown -= timer.time / CLOCKS_PER_SEC * 10000;
    refresh_clock(&timer);
  }
  free_thread(ducks);
  mprintf("[%sScore%s] : %s%f%s\n",
	  BOLDYELLOW, RESET, misc->score, BOLDCYAN, RESET);
  return (0);
}
