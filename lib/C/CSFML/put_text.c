/*
7** put_text.c for  in /home/leandre/Rushs/scroller/lib/CSFML
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Fri Mar 31 14:08:05 2017 Léandre Blanchard
** Last update Wed Nov  1 19:21:09 2017 Léandre Blanchard
*/

#include "csfml.h"

#include "my.h"
#include "defines.h"
#include "colors.h"

static void	__fill(char *str, int nb)
{
  int		size;
  int		i;

  i = 0;
  size = my_intlen(nb);
  if (nb == 0)
  {
    str[0] = '0';
    return;
  }
  if (nb < 0)
  {
    str[0] = '-';
    nb = -nb;
  }
  while (nb > 0)
  {
    str[size - i - 1] = 48 + nb % 10;
    nb /= 10;
    ++i;
  }
}

/*
** This function allows you to write text on your screen
** using window_t, it will get the font of window_t->font
** and display the word "word" at coordinates "pos"
** with color "color"
** This function does not return
*/
void            put_word(char *word, sfVector2f pos,
			 window_t *window, sfColor color)
{
  sfFont        *font;
  sfText        *text;

  if (window->font == NULL)
  {
    mdprintf(2, "[%sWarning%s] PutWord : font not set\n",
	     GREEN, RESET);
    return;
  }
  if (word != NULL)
    {
      font = sfFont_createFromFile(window->font);
      text = sfText_create();
      sfText_setString(text, word);
      sfText_setFont(text, font);
      sfText_setColor(text, color);
      sfText_setCharacterSize(text, 30);
      sfText_setPosition(text, pos);
      sfRenderWindow_drawText(window->window, text, NULL);
      sfText_destroy(text);
      sfFont_destroy(font);
    }
}
/*
** Same as above but to print a number, 
** first convert it into a char *
** then printing it on the screen
*/
void            put_number(int nb, sfVector2f pos,
			   window_t *window, sfColor color)
{
  char          *str;

  str = my_calloc(my_intlen(nb));
  __fill(str, nb);
  put_word(str, pos, window, color);
  sfree(&str);
}
