/*
** EPITECH PROJECT, 2017
** myHunter
** File description:
** reload key
*/

#include "my_hunter.h"

int		poll_event_reload(__attribute__ ((unused)) window_t *window,
				  misc_t *misc,
				  sfEvent *event)
{
  if (event->key.code == sfKeyR)
  {
    misc->datas.score -= misc->datas.ammo;
    misc->datas.ammo = misc->datas.mag_size;
  }
  return (0);
}
