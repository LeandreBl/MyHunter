/*
** EPITECH PROJECT, 2017
** myHunter
** File description:
** shot a duck
*/

#include "my_hunter.h"

#include "my.h"
#include "defines.h"

static int	__hit(sfVector2f duck, sfVector2i hit)
{
  if (hit.x < duck.x ||
      hit.x > duck.x + 42 ||
      hit.y < duck.y ||
      hit.y > duck.y + 42)
    return (0);
  return (1);
}

static int	__try(misc_t *misc, vect_t *duck, sfVector2i pos)
{
  if (__hit(duck->pos, pos))
  {
    duck->status = falling;
    duck->id = 6;
    misc->datas.score += (double)((duck->type + 1) * 10) / 2;
    return (1);
  }
  return (0);
}

void		shot_duck(misc_t *misc, sfVector2i pos)
{
  int		i;
  vect_t	*duck;
  sfVector2f	fpos;
  int		shot;

  i = 0;
  shot = 0;
  fpos = xy_vectorf(pos.x, pos.y);
  while (i < misc->datas.ducks.size)
  {
    duck = &misc->datas.ducks.ducks[i];
    if (distance(fpos, duck->pos) < 60 &&
	__try(misc, duck, pos) == 1)
      ++shot;
    ++i;
  }
  if (shot == 0)
    misc->datas.score -= 10;
}
