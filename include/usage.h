/*
** EPITECH PROJECT, 2017
** my_hunter
** File description:
** usage header
*/

#ifndef USAGE_H_
# define USAGE_H_

# define NB_TAB	(7)
# define ERR_SP	("[%sError%s] Spawnrate should be between 1% and 100%\n")
# define ERR_FL ("[%sError%s] Ducks's fly speed should be positive\n")
# define ERR_FA ("[%sError%s] Ducks's fall speed should be positive\n")
# define ERR_AR	("[%sError%s] No argument given after %s\n")

# include "my_hunter.h"

struct		usage_s
{
  const char	*trig;
  int		(* fction)(char **av, misc_t *misc);
};

typedef struct usage_s usage_t;

int		spawnrate(char **av, misc_t *misc);
int		fly_speed(char **av, misc_t *misc);
int		fall_speed(char **av, misc_t *misc);
int		hitbox_debug(char **av, misc_t *misc);

#endif /* !USAGE_H_ */
