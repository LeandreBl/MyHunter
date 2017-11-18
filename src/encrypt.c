/*
** EPITECH PROJECT, 2017
** myHunter
** File description:
** encrypt save scores
*/

void		crypting(void *data, int size)
{
  char		*datas;
  int		i;

  i = 0;
  datas = (char *)data;
  while (i < size)
  {
    datas[i] = -datas[i];
    ++i;
  }
}
