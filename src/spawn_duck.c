/*
** EPITECH PROJECT, 2017
** myHunter
** File description:
** spawn duck
*/

#include "my_hunter.h"

#include "my.h"
#include "defines.h"
#include "colors.h"

static int	realloc_ducks(duck_t *ducks)
{
  vect_t	*new;

  ducks->size += 1;
  new = my_calloc(sizeof(vect_t) * ducks->size);
  if (new == NULL)
    return (-1);
  memcopy(new, ducks->ducks, sizeof(vect_t) * (ducks->size - 2));
  sfree(&ducks->ducks);
  ducks->ducks = new;
  return (0);
}

static int	__new(duck_t *ducks)
{
  int		i;

  i = 0;
  while (i < ducks->size && ducks->ducks[i].status != dead)
    ++i;
  if (i == ducks->size - 1)
    if (realloc_ducks(ducks) == -1)
    {
      mdprintf(2, MEM_ERROR, RED, RESET);
      return (-1);
    }
  return (i);
}

int		spawn_duck(duck_t *ducks)
{
  int		pos;

  pos = __new(ducks);
  if (pos == -1)
    return (-1);
  ducks->ducks[pos].status = alive;
  ducks->ducks[pos].pos = xy_vectorf(-42, 40 + rand() % 400);
  ducks->ducks[pos].angle = -1 + (rand() % 10 * 0.1);
  ducks->ducks[pos].type = rand() % 3;
  ducks->ducks[pos].id = rand() % 3;
  return (0);
}

void		auto_remove_ducks(duck_t *ducks)
{
  int		i;
  vect_t	*duck;

  i = 0;
  while (i < ducks->size)
  {
    duck = &ducks->ducks[i];
    if (duck->pos.x > 1980 || duck->pos.y < -42)
    {
      duck->status = dead;
    }
    ++i;
  }
}
