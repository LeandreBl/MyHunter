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

int		set_clock(clocker_t *timer)
{
  timer->prev = timer->refresh;
  return (refresh_clock(timer));
}

int		refresh_clock(clocker_t *timer)
{
  timer->refresh = clock();
  if (timer->refresh == -1)
  {
    mdprintf(2, "[%sError%s] Error : CLOCK(2) syscall failed\n",
	     RED, RESET);
  }
  timer->time = timer->refresh - timer->prev;
  return (0);
}

int		start_clock(clocker_t *timer)
{
  timer->prev = clock();
  if (timer->prev == -1)
  {
    mdprintf(2, "[%sError%s] Error : CLOCK(2) syscall failed\n",
	     RED, RESET);
    return (-1);
  }
  return (refresh_clock(timer));
}
