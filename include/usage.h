/*
** EPITECH PROJECT, 2017
** my_hunter
** File description:
** usage header
*/

#ifndef USAGE_H_
# define USAGE_H_

# define NB_TAB	(3)

struct		usage_s
{
  const char	*trig;
  void		(* fction)(void);
};

typedef struct usage_s usage_t;

#endif /* !USAGE_H_ */
