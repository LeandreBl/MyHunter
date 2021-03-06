/*
** key_released.c for csfml in /home/leandre/C_graphical_prog/tekadventure/sprites
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Wed Apr  5 18:48:38 2017 Léandre Blanchard
** Last update Sat Jun  3 16:48:20 2017 Léandre Blanchard
*/

#include "csfml.h"
/*
** Return 1 if the sfKey "key" has been released
*/
int		key_released(int key)
{
  if (sfKeyboard_isKeyPressed(key))
    {
      while (sfKeyboard_isKeyPressed(key));
      return (1);
    }
  return (0);
}
