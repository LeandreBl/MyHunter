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

static int	add_duck(misc_t *sprites)
{
  int		i;

  sprites->duck = my_calloc(sizeof(sprite_t **) * 4);
  if (sprites->duck == NULL)
  {
    mdprintf(2, MEM_ERROR, RED, RESET);
    return (-1);
  }
  i = 0;
  while (i < 3)
    sprites->duck[i++] = my_calloc(sizeof(sprite_t *) * 13);
  if (check_alloc((void **)sprites->duck, 3) == -1)
  {
    mdprintf(2, MEM_ERROR, RED, RESET);
    return (-1);
  }
  return (init_ducks(sprites->duck));
}

static int	add_misc(misc_t *sprites)
{
  sprites->misc = my_calloc(sizeof(sprite_t *) * 11);
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
  sprites->misc[3] = create_sprite("sprites/grass.png");
  sprites->misc[4] = create_sprite("sprites/hitbox.png");
  sprites->misc[5] = create_sprite("sprites/ammo.png");
  sprites->misc[6] = create_sprite("sprites/save.png");
  sprites->misc[7] = create_sprite("sprites/menu.png");
  sprites->misc[8] = create_sprite("sprites/score_bg.png");
  sprites->misc[9] = create_sprite("sprites/rain.png");
  if (check_alloc((void **)sprites->misc, 9) == -1)
    return (-1);
  return (0);
}

int		init_misc(misc_t *misc)
{
  if (add_misc(misc) == -1)
    return (-1);
  if (add_duck(misc) == -1)
    return (-1);
  misc->dog = NULL;
  return (0);
}
