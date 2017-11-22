/*
** EPITECH PROJECT, 2017
** MyHunter
** File description:
** poll event close
*/

#include "my_hunter.h"

static int	__resume(void *action)
{
  *(int *)action = 0;
  return (0);
}

static int	__quit(void *action)
{
  *(int *)action = 1;
  return (0);
}

static int	create_buttons(sfbutton_t **resume, sfbutton_t **quit,
			       misc_t *misc, window_t *window)
{
  *resume = sfbutton_create("Resume", misc->misc[10], NULL,
			    __resume);
  *quit = sfbutton_create("Quit", misc->misc[10], NULL,
			  __quit);
  if (*resume == NULL || *quit == NULL)
    return (-1);
  (*resume)->pos = xy_vectorf(window->width / 2 - 80,
			      window->height / 2 - 80);
  (*quit)->pos = xy_vectorf((*resume)->pos.x,
			    window->height / 2);
  return (0);
}

static void	try_buttons(int *action, sfbutton_t *resume,
			    sfbutton_t *quit, sfVector2i pos)
{
  sfbutton_exec(resume, pos, action);
  sfbutton_exec(quit, pos, action);
}

int		poll_event_close(window_t *window,
				 misc_t *misc,
				 __attribute__ ((unused)) sfEvent *event)
{
  sfEvent	evt;
  int		action;
  sfbutton_t	*resume;
  sfbutton_t	*quit;

  action = -1;
  sfSprite_setColor(misc->misc[0]->sprite,
		    sfColor_fromRGB(100, 100, 100));
  sfRenderWindow_setMouseCursorVisible(window->window, sfTrue);
  if (create_buttons(&resume, &quit, misc, window) == -1)
    return (-1);
  sfMusic_pause(window->musics[3]);
  while (sfRenderWindow_isOpen(window->window))
  {
    window_clear(window);
    display_background(window, misc);
    sfbutton_draw_name(window, resume, sfWhite);
    sfbutton_draw_name(window, quit, sfWhite);
    while (sfRenderWindow_pollEvent(window->window, &evt))
    {
      if (evt.type == sfEvtMouseButtonPressed)
	try_buttons(&action, resume, quit, xy_vectori(
		      evt.mouseButton.x, evt.mouseButton.y));
      if (evt.type == sfEvtClosed)
	sfRenderWindow_close(window->window);
    }
    if (action == 0)
      break;
    if (action == 1)
      sfRenderWindow_close(window->window);
    window_refresh(window);
  }
  sfRenderWindow_setMouseCursorVisible(window->window, sfFalse);
  sfMusic_play(window->musics[3]);
  sfSprite_setColor(misc->misc[0]->sprite, sfWhite);
  return (0);
}
