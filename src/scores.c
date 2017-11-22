/*
** EPITECH PROJECT, 2017
** myHunter
** File description:
** scores menu
*/

#include "my_hunter.h"

#include "my.h"
#include "defines.h"

static int	is_sorted(save_t *scores, int size)
{
  int		i;

  i = 0;
  while (i < size - 1)
  {
    if (scores[i].score < scores[i + 1].score)
      return (0);
    ++i;
  }
  return (1);
}

static void	__sort(save_t *scores, int size)
{
  int		i;
  save_t	swp;

  while (is_sorted(scores, size) == 0)
  {
    i = 0;
    while (i < size - 1)
    {
      if (scores[i].score < scores[i + 1].score)
      {
	swp = scores[i];
	scores[i] = scores[i + 1];
	scores[i + 1] = swp;
      }
      ++i;
    }
  }
}

static int	load_scores(save_t **scores)
{
  char		*pathname;
  int		size;

  pathname = catalloc("/home/%s/%s", getenv("USER"), SAVE_FILENAME);
  if (pathname == NULL)
    return (-1);
  size = file_size(pathname);
  if (size == -1)
    return (-1);
  *scores = file_data(pathname);
  if (*scores == NULL)
    return (-1);
  crypting((void *)*scores, size);
  sfree(&pathname);
  return (size);
}

static void	display_scores(window_t *window, save_t *scores, int size)
{
  int		i;
  char		*format;
  int		height;
  int		width;

  i = 0;
  width = 50;
  height = 50;
  while (i < size && i < 6)
  {
    if (i == 3)
    {
      width = 450;
      height = 50;
    }
    format = catalloc("[%s]\n\tSpeed : %f\n\tSpawnrate : %f\n\tScore : %d",
		      scores[i].name, scores[i].speed,
		      scores[i].spawn, scores[i].score);
    put_word(format, xy_vectorf(width, height), window, sfWhite);
    sfree(&format);
    height += 175;
    ++i;
  }
}

int		scores(window_t *window, misc_t *misc)
{
  save_t	*scores;
  sfVector2f	scale;
  int		size;

  size = load_scores(&scores) / sizeof(save_t);
  if (size < 0)
    return (-1);
  __sort(scores, size);
  while (sfRenderWindow_isOpen(window->window)
	 && !key_released(sfKeyEscape))
  {
    scale.x = (double)window->width / 800.0;
    scale.y = (double)window->height / 600.0;
    window_clear(window);
    put_sprite_resize(window, misc->misc[8], ORIGIN, scale);
    display_scores(window, scores, size);
    window_refresh(window);
  }
  return (0);
}
