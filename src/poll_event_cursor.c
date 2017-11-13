/*
** EPITECH PROJECT, 2017
** myHunter
** File description:
** cursor
*/

#include "my_hunter.h"

int		poll_event_cursor(window_t *window,
				  __attribute__ ((unused)) misc_t *misc,
				  sfEvent *event)
{
  window->mouse.x = event->mouseMove.x;
  window->mouse.y = event->mouseMove.y;
  return (0);
}
