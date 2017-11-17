/*
** EPITECH PROJECT, 2017
** myHunter
** File description:
** debug hitbox
*/

#include "usage.h"

#include "my.h"
#include "defines.h"
#include "colors.h"

int             hitbox_debug(__attribute__ ((unused)) char **av,
			     misc_t *misc)
{
  misc->hitbox_debug = 1;
  mprintf("%s[Info%s] Debug mode enabled\n",
	  YELLOW, RESET);
  return (0);
}
