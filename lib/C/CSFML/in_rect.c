/*
** in_rect.c for CSFML in /home/leandre/C_graphical_prog/tekadventure
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Thu Apr 20 09:14:16 2017 Léandre Blanchard
** Last update Sat Jun  3 16:47:45 2017 Léandre Blanchard
*/

#include "csfml.h"

/*
** This function refresh the position of the mouse in window_t->mouse
** and return 0 if the mouse is located in the rectangle 
** of size size.x * size.y who upper-left corner is at (origin.x, origin.y)
*/

int		in_rect(sfVector2i pos, sfVector2f origin, sfVector2f size)
{
  if (pos.x >= origin.x && pos.x <= (origin.x + size.x)
      && pos.y >= origin.y && pos.y <= (origin.y + size.y))
    return (0);
  return (1);
}

int		is_in_rect(window_t *window, sfVector2f origin, sfVector2f size)
{
  pos_mouse(window);
  return (in_rect(window->mouse, origin, size));
}
