/*
** EPITECH PROJECT, 2017
** my hunter
** File description:
** start game
*/

#include <time.h>

#include "my_hunter.h"

#include "my.h"
#include "colors.h"
#include "defines.h"

const uint8_t	FRAMERATE = 60;

static void	free_ducks(sprite_t ***sprites)
{
  int		i;

  i = 0;
  while (sprites != NULL && sprites[i] != NULL)
  {
    free_sprites(sprites[i]);
    ++i;
  }
  sfree(&sprites);
}

static void	free_memory(window_t *window, misc_t *misc)
{
  mprintf("[%sFree%s] free %sWindow%s\n", BOLDMAGENTA, RESET,
	  CYAN, RESET);
  free_window(window);
  mprintf("[%sFree%s] free %sMiscs%s\n", BOLDMAGENTA, RESET,
	  CYAN, RESET);
  free_sprites(misc->misc);
  mprintf("[%sFree%s] free %sDucks%s\n", BOLDMAGENTA, RESET,
	  CYAN, RESET);
  free_ducks(misc->duck);
  sfree(&misc->datas.ducks.ducks);
  mprintf("[%sMemory Freed%s]\n", YELLOW, RESET);
}

static void	misc_pre_config(misc_t *misc)
{
  misc->hitbox_debug = 0;
  misc->datas.ducks.up_speed = 0;
  misc->datas.ducks.fly_speed = 1;
  misc->datas.ducks.fall_speed = 2;
  misc->datas.ducks.spawnrate = 1;
  misc->datas.countdown = 200;
  misc->datas.mag_size = 7;
  misc->datas.ammo = misc->datas.mag_size;
  misc->datas.ducks.size = 0;
  misc->datas.ducks.ducks = NULL;
  misc->datas.score = 0;
  misc->misc = NULL;
  misc->duck = NULL;
  misc->dog = NULL;
}

int		start_game(int ac, char **av)
{
  window_t	*window;
  misc_t	misc;

  misc_pre_config(&misc);
  if (usage(ac, av, &misc))
    return (-1);
  srand(time(NULL));
  window = init_window(600, 4.0 / 3.0, "MyHunter", sfResize | sfClose);
  if (init_misc(&misc) == -1 || init_sounds(window) == -1)
  {
    free_window(window);
    return (-1);
  }
  pos_mouse(window);
  window->font = my_strdup("fonts/audims.ttf");
  sfRenderWindow_setFramerateLimit(window->window, FRAMERATE);
  sfRenderWindow_setMouseCursorVisible(window->window, sfFalse);
  if (menu(window, &misc) == -1)
  {
    mdprintf(2, "[%sWarning%s] An error occured ingame\n",
	     GREEN, RESET);
    free_memory(window, &misc);
    return (-1);
  }
  free_memory(window, &misc);
  return (0);
}
