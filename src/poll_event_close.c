/*
** EPITECH PROJECT, 2017
** MyHunter
** File description:
** poll event close
*/

#include "my_hunter.h"

int		poll_event_close(window_t *window,
				 __attribute__ ((unused)) misc_t *misc,
				 __attribute__ ((unused)) sfEvent *event)
{
  sfRenderWindow_close(window->window);
  return (0);
}
