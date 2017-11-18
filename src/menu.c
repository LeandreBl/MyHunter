/*
** EPITECH PROJECT, 2017
** myHunter
** File description:
** menu
*/

#include "my_hunter.h"

#include "my.h"
#include "defines.h"

static const char *words[] =
{
  "Jouer !",
  "Scores",
};

static void	display(window_t *window, misc_t *misc, int cur)
{
  sfColor	color;
  sfVector2f	scale;
  int		i;

  i = 0;
  scale.x = (double)window->width / 800.0;
  scale.y = (double)window->height / 600.0;
  put_sprite_resize(window, misc->misc[7], ORIGIN, scale);
  while (i < 2)
  {
    color = sfWhite;
    if (i == cur)
      color = sfYellow;
    put_word(words[i], xy_vectorf(100, 100 + i * 30),
	     window, color);
    ++i;
  }
  put_sprite(window, misc->misc[1],
	     xy_vectorf(95, 100 + cur * 30));
}

static void	poll(window_t *window, misc_t *misc, int *cur)
{
  sfEvent	event;

  while (sfRenderWindow_pollEvent(window->window, &event))
  {
    if (event.type == sfEvtClosed)
      sfRenderWindow_close(window->window);
    if (event.type == sfEvtKeyPressed)
    {
      if (event.key.code == sfKeyReturn)
      {
	if (*cur == 0)
	{
	  sfMusic_stop(window->musics[1]);
	  sfMusic_play(window->musics[3]);
	  ingame(window, misc);
	}
	if (*cur == 1)
	  scores(window, misc);
      }
      else if (event.key.code == sfKeyUp)
	*cur = (*cur + 1) % 2;
      else if (event.key.code == sfKeyDown)
	*cur = *cur - 1;
    }
  }
  if (*cur < 0)
    *cur = 1;
}

int		menu(window_t *window, misc_t *misc)
{
  int		cursor;

  cursor = 0;
  sfMusic_setLoop(window->musics[1], sfTrue);
  sfMusic_setLoop(window->musics[3], sfTrue);
  sfMusic_play(window->musics[1]);
  while (sfRenderWindow_isOpen(window->window))
  {
    window_clear(window);
    poll(window, misc, &cursor);
    display(window, misc, cursor);
    if (key_released(sfKeyEscape))
      break;
    window_refresh(window);
  }
  return (0);
}
