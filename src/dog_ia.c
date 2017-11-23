/*
** EPITECH PROJECT, 2017
** myHunter
** File description:
** dog ia
*/

#include "my_hunter.h"

#include "my.h"
#include "defines.h"

static void	chase_duck(data_t *datas, int target, clocker_t *timer)
{
  sfVector2f	pos;

  pos = datas->ducks.ducks[target].pos;
  datas->dog.status = walking;
  while (datas->dog.pos.x < pos.x && datas->ducks.ducks[target].status == falling)
  {
    datas->dog.pos.x += 1.5;
    datas->dog.id = ((int)(datas->dog.pos.x) / 5) % 5;
    wait_timer(timer);
  }
}

static int	find_duck(duck_t *ducks)
{
  int		i;

  i = 0;
  while (i < ducks->size)
  {
    if (ducks->ducks[i].status == falling)
      return (i);
    ++i;
  }
  return (-1);
}

static void	dog_ia(void *data)
{
  data_t	*datas;
  int		target;
  clocker_t	timer;

  datas = (data_t *)data;
  if (start_clock(&timer) == -1 ||
      set_clock(&timer) == -1)
    return;
  while (datas->dog.status >= 0)
  {
    datas->dog.status = waiting;
    target = -1;
    while (target < 0)
    {
      wait_timer(&timer);
      target = find_duck(&datas->ducks);
    }
    chase_duck(datas, target, &timer);
  }
}

int		start_dog_ia_thread(data_t *datas, sfThread **thread)
{
  datas->dog.status = waiting;
  datas->dog.id = 0;
  datas->dog.pos.x = 50;
  *thread = sfThread_create(dog_ia, (void *)datas);
  if (*thread == NULL)
    return (-1);
  sfThread_launch(*thread);
  return (0);
}
