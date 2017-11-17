/*
** EPITECH PROJECT, 2017
** myHunter
** File description:
** save scores
*/

#include "my_hunter.h"

#include "my.h"
#include "defines.h"
#include "colors.h"

static void	add_letter(save_t *pkt, sfEvent *event)
{
  if (((event->key.code <= sfKeyZ && event->key.code >= sfKeyA) ||
       event->key.code == sfKeySpace) &&
      my_strlen(pkt->name) < 19)
    {
      pkt->name[my_strlen(pkt->name)] = event->key.code + 'a';
    }
  if (event->key.code == sfKeyBack)
    shift_right(pkt->name, 1);
}

int		save_score(window_t *window, misc_t *misc)
{
  save_t	pkt;
  sfEvent	event;

  pkt.score = misc->datas.score;
  pkt.spawn = misc->datas.ducks.spawnrate;
  pkt.speed = misc->datas.ducks.fly_speed;
  zeros(pkt.name, 20);
  while (sfRenderWindow_isOpen(window->window))
  {
    window_clear(window);
    put_word(pkt.name, xy_vectorf(window->width / 2 - my_strlen(pkt.name) / 2 * 10,
				  window->height / 2 - 15),
	     window,
	     sfBlack);
    while (sfRenderWindow_pollEvent(window->window, &event))
    {
      if (event.type == sfEvtKeyPressed)
      {
	add_letter(&pkt, &event);
	if (event.key.code == sfKeyReturn)
	{
	  mprintf("%s\n", pkt.name);
	  //save;
	  return (0);
	}
      }
    }
    window_refresh(window);
  }
  return (0);
}
