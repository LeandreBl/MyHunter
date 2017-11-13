/*
** EPITECH PROJECT, 2017
** myhunter
** File description:
** init of sounds
*/

#include "my_hunter.h"

#include "my.h"
#include "defines.h"
#include "colors.h"

static sfMusic	*add_music(const char *pathname)
{
  sfMusic	*music;

  mprintf("[%sInfo%s] Loading %s%s%s\n",
	  YELLOW, RESET, CYAN, pathname, RESET);
  music = sfMusic_createFromFile(pathname);
  if (music == NULL)
    mdprintf(2, "[%sError%s] Could not open %s%s%s\n",
	     RED, RESET, BLUE, pathname, RESET);
  return (music);
}

int		init_sounds(window_t *window)
{
  window->musics = my_calloc(sizeof(sfMusic *) * 2);
  if (window->musics == NULL)
  {
    mdprintf(2, MEM_ERROR, RED, RESET);
    return (-1);
  }
  window->musics[0] = add_music(SOUND_SHOT);
  if (check_alloc((void **)window->musics, 1) == -1)
    return (-1);
  return (0);
}
