/*
** EPITECH PROJECT, 2017
** myHunter
** File description:
** event when clicking
*/

#include "my_hunter.h"

#include "my.h"
#include "defines.h"

int		poll_event_click(window_t *window,
				 misc_t *misc,
				 sfEvent *event)
{
  if (event->mouseButton.button == sfMouseLeft)
  {
    shot_duck(misc, window->mouse);
    sfMusic_play(window->musics[0]);
  }
  return (0);
}
