/*
** EPITECH PROJECT, 2017
** myHunter
** File description:
** fly_speed and fall_speed
*/

#include "usage.h"

#include "my.h"
#include "defines.h"
#include "colors.h"

int		up_speed(char **av, misc_t *misc)
{
  double        speed;

  if (av[1] != NULL)
  {
    speed = my_get_float(av[1]);
    if (speed <= 0)
    {
      mdprintf(2, ERR_UP, RED, RESET);
      return (-1);
    }
    misc->datas.ducks.up_speed = speed;
    mprintf("[%sInfo%s] Vertical speed set to %f\n",
	    YELLOW, RESET, speed);
    return (0);
  }
  mdprintf(2, ERR_AR, RED, RESET, av[0]);
  return (-1);
}

int		fly_speed(char **av, misc_t *misc)
{
  double	speed;

  if (av[1] != NULL)
  {
    speed = my_get_float(av[1]);
    if (speed <= 0)
    {
      mdprintf(2, ERR_FL, RED, RESET);
      return (-1);
    }
    misc->datas.ducks.fly_speed = speed;
    mprintf("[%sInfo%s] Fly speed set to %f\n",
	    YELLOW, RESET, speed);
    return (0);
  }
  mdprintf(2, ERR_AR, RED, RESET, av[0]);
  return (-1);
}

int		fall_speed(char **av, misc_t *misc)
{
  double	speed;

  if (av[1] != NULL)
  {
    speed = my_get_float(av[1]);
    if (speed <= 0)
    {
      mdprintf(2, ERR_FA, RED, RESET);
      return (-1);
    }
    misc->datas.ducks.fall_speed = speed;
    mprintf("[%sInfo%s] Fall speed set to %f\n",
	    YELLOW, RESET, speed);
    return (0);
  }
  mdprintf(2, ERR_AR, RED, RESET, av[0]);
  return (-1);
}
