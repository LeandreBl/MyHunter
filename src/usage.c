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

static void	help(void)
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
}

static void	__add(usage_t *index, const char *trig, void (* fction)(void))
{
  index->fction = fction;
  index->trig = trig;
}

static void	__init(usage_t tab[])
{
  __add(&tab[0], "-h", help);
  __add(&tab[1], "--help", help);
  __add(&tab[2], "--usage", help);
}

static void	loop(usage_t tab[], const char *avi)
{
  int		i;

  i = 0;
  while (i < NB_TAB)
  {
    if (my_strcmp(avi, tab[i].trig) == 0)
    {
      tab[i].fction();
      return;
    }
    ++i;
  }
}

int		usage(int ac, char **av)
{
  usage_t	tab[NB_TAB];
  int		i;

  __init(tab);
  if (ac < 2)
  {
    mdprintf(2, "[%sError%s] Type -h or --help for Usage\n",
	     BOLDRED, RESET);
    return (1);
  }
  i = 0;
  while (i < ac)
  {
    loop(tab, av[i]);
    if (my_strcmp(av[i], "--start") == 0)
    {
      mprintf("[%sStarting game%s]\n", YELLOW, RESET);
      return (0);
    }
    ++i;
  }
  return (1);
}
