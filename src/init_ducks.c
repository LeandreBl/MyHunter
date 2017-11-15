/*
** EPITECH PROJECT, 2017
** myHunter
** File description:
** init ducks sprites
*/

#include "my_hunter.h"

#include "my.h"
#include "colors.h"
#include "defines.h"

static int	__add_fall(sprite_t **duck, int y)
{
  int		i;
  int		x;

  i = 7;
  x = 276;
  while (i < 12)
  {
    duck[i] = create_sprite_rect("sprites/misc.png",
				 simple_int_rect(x, y, 24, 42));
    if (duck[i] == NULL)
      return (-1);
    x += 24;
    ++i;
  }
  return (0);
}

static int	__add_fly_hit(sprite_t **duck, int y)
{
  duck[6] = create_sprite_rect("sprites/misc.png",
			       simple_int_rect(237, y, 37, 42));
  if (duck[6] == NULL)
    return (-1);
  return (0);
}

static int	__add_fly_up(sprite_t **duck, int y)
{
  int		x;
  int		i;

  i = 3;
  x = 136;
  while (i < 6)
  {
    duck[i] = create_sprite_rect("sprites/misc.png",
				 simple_int_rect(x, y, 32, 42));
    if (duck[i] == NULL)
      return (-1);
    x += 32;
    ++i;
  }
  return (0);
}

static int	__add_flying(sprite_t **duck, int y)
{
  int		x;
  int		i;

  i = 0;
  x = 4;
  while (i < 3)
  {
    duck[i] = create_sprite_rect("sprites/misc.png",
				 simple_int_rect(x, y, 42, 42));
    if (duck[i] == NULL)
      return (-1);
    x += 42;
    ++i;
  }
  return (0);
}

int		init_ducks(sprite_t ***ducks)
{
  int		i;

  i = 0;
  while (i < 3)
  {
    if (__add_flying(ducks[i], 126 + 42 * i) == -1 ||
	__add_fly_up(ducks[i], 126 + 42 * i) == -1 ||
	__add_fly_hit(ducks[i], 130 + 42 * i) == -1 ||
	__add_fall(ducks[i], 126 + 42 * i) == -1)
      return (-1);
    ++i;
  }
  return (0);
}
