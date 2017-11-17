/*
** EPITECH PROJECT, 2017
** myHunter
** File description:
** reload pop up
*/

#include "my_hunter.h"

void			reload_alert(window_t *window, misc_t *misc)
{
  static float		rel;

  if (misc->datas.ammo == 0)
  {
    if ((int)rel % 4)
    {
      put_word("RELOAD [R]", xy_vectorf(window->width / 2 - 50,
					window->height / 2 - 15),
	       window, sfRed);
    }
    rel += 0.1;
  }
}
