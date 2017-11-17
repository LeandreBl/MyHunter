/*
** EPITECH PROJECT, 2017
** myHunter
** File description:
** usage countdown
*/

#include "usage.h"

#include "my.h"
#include "defines.h"
#include "colors.h"

int		set_countdown(char **av, misc_t *misc)
{
  double	countdown;

  if (av[1] != NULL)
  {
    countdown = my_getnbr(av[1]);
    if (countdown <= 0)
    {
      mdprintf(2, ERR_CD, RED, RESET);
      return (-1);
    }
    misc->datas.countdown = countdown;
    mprintf("[%sInfo%s] Countdown set to %f seconds.\n",
	    YELLOW, RESET, countdown);
    return (0);
  }
  mdprintf(2, ERR_AR, RED, RESET, av[0]);
  return (-1);
}
