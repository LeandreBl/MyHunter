/*
** EPITECH PROJECT, 2017
** myHunter
** File description:
** poll 
*/

#include "my_hunter.h"

#include "my.h"
#include "colors.h"
#include "defines.h"

static void	__add(poll_t *index, sfEventType type,
		      int (* fction)(window_t *window,
				     misc_t *misc,
				     sfEvent *event))
{
  index->type = type;
  index->fction = fction;
}
		      

static void	__init(poll_t tab[])
{
  __add(&tab[0], sfEvtClosed, poll_event_close);
}

int		pollevent(window_t *window, misc_t *misc)
{
  static poll_t	tab[NB_EVENT];
  static int	calls = 0;
  sfEvent	event;
  int		i;

  if (calls == 0)
  {
    __init(tab);
    calls = 1;
  }
  while (sfRenderWindow_pollEvent(window->window, &event))
  {
    i = 0;
    while (i < NB_EVENT)
    {
      if (event.type == tab[i].type)
	if (tab[i].fction(window, misc, &event) == -1)
	  return (-1);
      ++i;
    }
  }
  return (0);
}
