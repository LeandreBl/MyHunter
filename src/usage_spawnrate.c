/*
** EPITECH PROJECT, 2017
** myHunter
** File description:
** spawnrate
*/

#include "usage.h"

#include "my.h"
#include "defines.h"
#include "colors.h"

int		spawnrate(char **av, misc_t *misc)
{
  int		spawnrate;

  if (av[1] != NULL)
  {
    spawnrate = my_getnbr(av[1]);
    if (spawnrate > 100 || spawnrate <= 0)
    {
      mdprintf(2, ERR_SP, RED, RESET);
      return (-1);
    }
    misc->datas.ducks.spawnrate = spawnrate;
    mprintf("[%sInfo%s] Spawnrate set to %d%\n",
	    YELLOW, RESET, spawnrate);
    return (0);
  }
  mdprintf(2, ERR_AR, RED, RESET, av[0]);
  return (-1);
}
