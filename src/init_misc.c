/*
** EPITECH PROJECT, 2017
** my_hunter
** File description:
** init misc
*/

#include "my_hunter.h"

#include "my.h"
#include "colors.h"
#include "defines.h"

static int	check_alloc(sprite_t **sprites, int total)
{
  int		i;

  i = 0;
  while (i < total)
  {
    if (sprites == NULL || sprites[i] == NULL)
    {
      mdprintf(2, "[%sError%s] Missing sprites\n",
	       RED, RESET);
      return (-1);
    }
    ++i;
  }
  return (0);
}

static int	add_misc(misc_t *sprites)
{
  sprites->misc = create_sprites(1);
  sprites->misc[0] = create_sprite_rect("sprites/misc.png",
			    simple_int_rect(383, 5, 256, 240));
  if (check_alloc(sprites->misc, 1) == -1)
    return (-1);
  return (0);
}

int		init_misc(misc_t *sprites)
{
  if (add_misc(sprites) == -1)
    return (-1);
  sprites->duck = NULL;
  sprites->dog = NULL;
  return (0);
}
