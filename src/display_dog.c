/*
** EPITECH PROJECT, 2017
** myHunter
** File description:
** display dog
*/

#include "my_hunter.h"

void		display_dog(window_t *window, misc_t *misc)
{
  
  misc->datas.dog.pos.y = window->height * 2.7 / 4.0;

  if (misc->datas.dog.id >= 0)
  {
    put_sprite(window, misc->dog[misc->datas.dog.id],
	       misc->datas.dog.pos);
  }
}
