/*
** EPITECH PROJECT, 2017
** myHunter
** File description:
** time
*/

#include <time.h>

#include "my_hunter.h"

#include "my.h"
#include "defines.h"
#include "colors.h"

int		refresh_clock(clocker_t *timer)
{
  timer->refresh = clock();
  if (timer->refresh == -1)
  {
    mdprintf(2,"[%sError%s] Error : CLOCK(2) syscall failed\n",
	     RED, RESET);
  }
  timer->time =timer->refresh - timer->prev;
  timer->prev =timer->refresh;
  return (0);
}

int		set_clock(clocker_t *timer)
{
  timer->prev = clock();
  if (timer->prev == -1)
  {
    mdprintf(2,"[%sError%s] Error : CLOCK(2) syscall failed\n",
	     RED, RESET);
    return (-1);
  }
  return (refresh_clock(timer));
}
