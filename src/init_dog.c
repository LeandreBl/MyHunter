/*
** EPITECH PROJECT, 2017
** myHunter
** File description:
** dog sprites
*/

#include "my_hunter.h"

static int	__add_walking(sprite_t **dog)
{
  int		x;
  int		i;

  x = 0;
  i = 0;
  while (i < 5)
  {
    dog[i] = create_sprite_rect("sprites/misc.png",
				simple_int_rect(x, 19, 59, 43));
    if (dog[i] == NULL)
      return (-1);
    x += 59;
    ++i;
  }
  return (0);
}

static int	__add_found(sprite_t **dog)
{
  dog[5] = create_sprite_rect("sprites/misc.png",
			 simple_int_rect(0, 70, 58, 49));
  dog[6] = create_sprite_rect("sprites/misc.png",
			 simple_int_rect(61, 69, 69, 49));
  if (dog[5] == NULL || dog[6] == NULL)
    return (-1);
  return (0);
}

static int	__add_jump(sprite_t **dog)
{
  dog[7] = create_sprite_rect("sprites/misc.png",
			 simple_int_rect(217, 72, 53, 45));
  dog[8] = create_sprite_rect("sprites/misc.png",
			 simple_int_rect(283, 69, 44, 49));
  dog[9] = create_sprite_rect("sprites/misc.png",
			 simple_int_rect(333, 75, 42, 41));
  if (dog[7] == NULL || dog[8] == NULL || dog[9] == NULL)
    return (-1);
  return (0);
}

int		init_dog(sprite_t ***dog)
{
  *dog = my_calloc(sizeof(sprite_t *) * 13);
  if (*dog == NULL)
    return (-1);
  if (__add_walking(*dog) == -1 ||
      __add_found(*dog) == -1 ||
      __add_jump(*dog) == -1)
    return (-1);
  return (0);
}
