/*
** EPITECH PROJECT, 2017
** myHunter
** File description:
** save scores
*/

#include "my_hunter.h"

#include "my.h"
#include "defines.h"
#include "colors.h"

static int	__save(save_t *pkt)
{
  char		*pathname;
  void		*data;

  pathname = catalloc("/home/%s/%s", getenv("USER"), SAVE_FILENAME);
  if (pathname == NULL)
    return (-1);
  data = (void *)pkt;
  crypting(data, sizeof(save_t));
  if (save_as(pathname, data, sizeof(save_t)) == -1)
  {
    mdprintf(2, "[%sError%s] Could not save scores in %s\n",
	     RED, RESET, pathname);
    return (-1);
  }
  sfree(&pathname);
  return (0);
}

static void	display(window_t *window, misc_t *misc,
			save_t *pkt, char *format)
{
  sfVector2f	scale;

  scale.x = (double)window->width / 800.0;
  scale.y = (double)window->height / 600.0;
  put_sprite_resize(window, misc->misc[6], ORIGIN, scale);
  put_word("Enter your nickname :",
	   xy_vectorf(100, window->height / 2 - 60), window, sfWhite);
  put_word(pkt->name,
	   xy_vectorf(window->width / 2 - my_strlen(pkt->name) / 2 * 12,
		      window->height / 2 - 15), window, sfYellow);
  put_word(format, xy_vectorf(100, window->height / 2 + 60), window, sfWhite);
}

static int	__init(char **format, misc_t *misc, save_t *pkt)
{
  pkt->score = misc->datas.score;
  pkt->spawn = misc->datas.ducks.spawnrate;
  pkt->speed = misc->datas.ducks.fly_speed;
  zeros(pkt->name, 20);
  *format = catalloc("Speed : %f\nSpawnrate : %f\nScore : %d",
		    pkt->score, pkt->speed, pkt->spawn);
  if (*format == NULL)
  {
    mdprintf(2, MEM_ERROR, RED, RESET);
    return (-1);
  }
  return (0);
}

int		save_score(window_t *window, misc_t *misc)
{
  save_t	pkt;
  sfEvent	event;
  char		*format;

  if (__init(&format, misc, &pkt) == -1)
    return (-1);
  while (sfRenderWindow_isOpen(window->window))
  {
    window_clear(window);
    display(window, misc, &pkt, format);
    while (sfRenderWindow_pollEvent(window->window, &event))
    {
      if (event.type == sfEvtTextEntered)
      {
	if (my_strlen(pkt.name) < 19 &&
	    event.text.unicode < 127 && event.text.unicode >= ' ')
	  my_strncat(pkt.name, (char *)&event.text.unicode, 1);
	if (event.text.unicode == '\b')
	  shift_right(pkt.name, 1);
      }
      if (event.type == sfEvtKeyPressed)
      {
	if (event.key.code == sfKeyReturn &&
	    my_strlen(pkt.name) > 0)
	{
	  sfree(&format);
	  return (__save(&pkt));
	}
      }
      if (event.type == sfEvtClosed)
	sfRenderWindow_close(window->window);
    }
    window_refresh(window);
  }
  sfree(&format);
  return (0);
}
