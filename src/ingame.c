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

const uint8_t	NB_THREADS = 3;

static void	display(window_t *window, misc_t *misc)
{
  display_grass(window, misc);
  display_cursor(window, misc);
  display_bushes(window, misc);
  display_score(window, misc);
  display_time(window, misc);
  display_ammo(window, misc);
}

static void    	countdown(misc_t *misc, clocker_t *timer)
{
  double	elapsed;

  elapsed = timer->time / CLOCKS_PER_SEC * 10000 / NB_THREADS;
  misc->datas.countdown -= elapsed;
  refresh_clock(timer);
}

int		ingame(window_t *window, misc_t *misc)
{
  sfThread	*ducks;
  clocker_t	timer;

  if (start_ducks_ia_thread(&misc->datas.ducks, &ducks) == -1)
    return (-1);
  start_clock(&timer);
  while (sfRenderWindow_isOpen(window->window) &&
	 misc->datas.countdown > 0)
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
    countdown(misc, &timer);
  }
  free_thread(ducks);
  mprintf("[%sScore%s] : %s%f%s\n",
	  BOLDYELLOW, RESET, misc->datas.score, BOLDCYAN, RESET);
  return (0);
}
