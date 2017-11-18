/*
** EPITECH PROJECT, 2017
** my_hunter
** File description:
** usage
*/

#include "usage.h"

#include "my.h"
#include "colors.h"
#include "defines.h"

static int	help(__attribute__ ((unused)) char **av,
		     __attribute__ ((unused))misc_t *misc)
{
  mprintf("[%sUsage%s]\n", BOLDGREEN, RESET);
  mprintf("\t./my_hunter [%s--help%s] display this help.\n",
	  GREEN, RESET);
  mprintf("\t./my_hunter [%s-h%s] display this help.\n",
	  GREEN, RESET);
  mprintf("\t./my_hunter [%s--usage%s] display this help.\n",
	  GREEN, RESET);
  mprintf("\t./my_hunter [%s--start%s] to start the game.\n",
	  GREEN, RESET);
  mprintf("\t./my_hunter [%s--spawnrate%s] [int] change spawn \
rate percentage.\n",
	  GREEN, RESET);
  mprintf("\t./my_hunter [%s--fly-speed%s] [float] change ducks's \
fly speed.\n",
	  GREEN, RESET);
  mprintf("\t./my_hunter [%s--fall-speed%s] [float] change ducks's \
fall speed.\n",
	  GREEN, RESET);
  mprintf("\t./my_hunter [%s--debug%s] enable hitbox overview.\n",
	  GREEN, RESET);
  mprintf("\t./my_hunter [%s--vertical-speed%s] [float] change ducks's \
vertical speed.\n",
	  GREEN, RESET);
  mprintf("\t./my_hunter [%s--default-ammo%s] [int] change gun magazine \
size.\n",
	  GREEN, RESET);
  mprintf("\t./my_hunter [%s--set-countdown%s] Set the countdown.\n",
	  GREEN, RESET);
  return (0);
}

static void	__add(usage_t *index, const char *trig,
		      int (* fction)(char **av, misc_t *misc))
{
  index->fction = fction;
  index->trig = trig;
}

static void	__init(usage_t tab[])
{
  __add(&tab[0], "-h", help);
  __add(&tab[1], "--help", help);
  __add(&tab[2], "--usage", help);
  __add(&tab[3], "--spawnrate", spawnrate);
  __add(&tab[4], "--fly-speed", fly_speed);
  __add(&tab[5], "--fall-speed", fall_speed);
  __add(&tab[6], "--debug", hitbox_debug);
  __add(&tab[7], "--vertical-speed", up_speed);
  __add(&tab[8], "--default-ammo", default_ammo);
  __add(&tab[9], "--set-countdown", set_countdown);
}

static int	loop(usage_t tab[],
		     char **av, misc_t *misc)
{
  int		i;

  i = 0;
  while (i < NB_TAB)
  {
    if (my_strcmp(av[0], tab[i].trig) == 0)
      return (tab[i].fction(av, misc));
    ++i;
  }
  if (av[0][0] == '-' && my_strcmp(av[0], "--start"))
    mprintf("[%sWarning%s] Unknown parameter : %s%s%s\n",
	    GREEN, RESET, GREEN, av[0], RESET);
  return (0);
}

int		usage(int ac, char **av, misc_t *misc)
{
  usage_t	tab[NB_TAB];
  int		start;
  int		i;

  __init(tab);
  start = 1;
  if (ac < 2)
  {
    mdprintf(2, "[%sError%s] Type -h or --help for Usage\n",
	     BOLDRED, RESET);
    return (1);
  }
  i = 1;
  while (i < ac)
  {
    if (loop(tab, av + i, misc) == -1)
      return (1);
    if (my_strcmp(av[i], "--start") == 0)
    {
      mprintf("[%sStarting game%s]\n", YELLOW, RESET);
      start = 0;
    }
    ++i;
  }
  return (start);
}
