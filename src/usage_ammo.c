/*
** EPITECH PROJECT, 2017
** myHunter
** File description:
** ammo init
*/

#include "usage.h"

#include "my.h"
#include "defines.h"
#include "colors.h"

int		default_ammo(char **av, misc_t *misc)
{
  int		ammo;

  if (av[1] != NULL)
  {
    ammo = my_getnbr(av[1]);
    if (ammo <= 0)
    {
      mdprintf(2, ERR_AM, RED, RESET);
      return (-1);
    }
    misc->datas.ammo = ammo;
    misc->datas.mag_size = ammo;
    mprintf("[%sInfo%s] Gun magazine size set to %d\n",
	    YELLOW, RESET, ammo);
    return (0);
  }
  mdprintf(2, ERR_AR, RED, RESET, av[0]);
  return (-1);
}
