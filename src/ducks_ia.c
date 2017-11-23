/*
** EPITECH PROJECT, 2017
** myHunter
** File description:
** ducks ia
*/

#include <time.h>

#include "my_hunter.h"

#include "my.h"
#include "defines.h"
#include "colors.h"

static int	__init_clock(clocker_t *timer)
{
  if (start_clock(timer) == -1
      || set_clock(timer) == -1)
  {
    mdprintf(2, CLOCK_ERROR, RED, RESET);
    return (-1);
  }
  return (0);
}

int		wait_timer(clocker_t *timer)
{
  while (timer->time < CLOCKS_PER_SEC / FRAMERATE)
    if (refresh_clock(timer) == -1)
    {
      mdprintf(2, CLOCK_ERROR, RED, RESET);
      return (-1);
    }
  if (set_clock(timer) == -1)
  {
    mdprintf(2, CLOCK_ERROR, RED, RESET);
    return (-1);
  }
  return (0);
}

static void	move_ducks(duck_t *ducks)
{
  int		i;

  i = 0;
  while (i < ducks->size)
  {
    if (ducks->ducks[i].status == alive)
    {
      ducks->ducks[i].pos.x += ducks->fly_speed;
      ducks->ducks[i].pos.y += ducks->ducks[i].angle + ducks->up_speed;
      ducks->ducks[i].id = ((int)ducks->ducks[i].pos.x / 8) % 3;
    }
    else if (ducks->ducks[i].status == falling)
    {
      ducks->ducks[i].pos.y += ducks->fall_speed;
      ducks->ducks[i].id = 7 + (int)(ducks->ducks[i].pos.y / 20) % 4;
    }
    auto_remove_ducks(ducks);
    ++i;
  }
}

static void	duck_ia(void *data)
{
  duck_t	*ducks;
  clocker_t	timer;

  if (__init_clock(&timer) == -1)
    return;
  ducks = (duck_t *)data;
  while (ducks->size >= 0)
  {
    if (rand() % 100 < ducks->spawnrate)
    {
      if (spawn_duck(ducks) == -1)
	break;
    }
    move_ducks(ducks);
    if (wait_timer(&timer) == -1)
      break;
  }
}

int		start_ducks_ia_thread(duck_t *ducks, sfThread **thread)
{
  *thread = sfThread_create(duck_ia, (void *)ducks);
  if (*thread == NULL)
    return (-1);
  sfThread_launch(*thread);
  return (0);
}
