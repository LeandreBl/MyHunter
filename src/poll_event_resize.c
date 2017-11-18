/*
** EPITECH PROJECT, 2017
** yHunter
** File description:
** event resize
*/

#include "my_hunter.h"

int		poll_event_resize(window_t *window,
				  __attribute__ ((unused)) misc_t *misc,
				  sfEvent *event)
{
  sfree(window->pixels);
  sfTexture_destroy(window->frame->texture);
  window->width = event->size.width;
  window->height = event->size.height;
  window->pixels = pixels_buffer(window->width, window->height);
  window->frame->texture = sfTexture_create(window->width, window->height);
  sfSprite_setTexture(window->frame->sprite, window->frame->texture, sfTrue);
  return (0);
}
