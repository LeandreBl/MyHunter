/*
** EPITECH PROJECT, 2017
** my_hunter
** File description:
** main
*/

#include "my_hunter.h"

#include "my.h"
#include "defines.h"

int		main(int ac, char **av)
{
  if (usage(ac, av))
    return (0);
  return (start_game());
}
