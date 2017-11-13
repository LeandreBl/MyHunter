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

int      check_alloc(void **ptrs, int total)
{
  int      i;

  i = 0;
  while (i < total)
  {
    if (ptrs == NULL || ptrs[i] == NULL)
    {
      mdprintf(2, "[%sError%s] Missing file\n",
	       RED, RESET);
      return (-1);
    }
    ++i;
  }
  return (0);
}


static int	add_misc(misc_t *sprites)
{
  sprites->misc = create_sprites(3);
  if (sprites->misc == NULL)
  {
    mdprintf(2, MEM_ERROR, RED, RESET);
    return (-1);
  }
  sprites->misc[0] = create_sprite_rect("sprites/misc.png",
			    simple_int_rect(383, 5, 256, 240));
  sprites->misc[1] = create_sprite_rect("sprites/misc.png",
			    simple_int_rect(469, 259, 25, 23));
  sprites->misc[2] = create_sprite("sprites/parallax.png");
  if (check_alloc((void **)sprites->misc, 3) == -1)
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
