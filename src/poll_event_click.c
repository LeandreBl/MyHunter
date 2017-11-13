/*
** EPITECH PROJECT, 2017
** myHunter
** File description:
** event when clicking
*/

#include "my_hunter.h"

int		poll_event_click(window_t *window,
				 __attribute__ ((unused)) misc_t *misc,
				 sfEvent *event)
{
  if (event->mouseButton.button == sfMouseLeft)
  {
    sfMusic_play(window->musics[0]);
  }
  return (0);
}
