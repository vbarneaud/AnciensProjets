/*
** what_is_this_glue.c for bcpe042colle3-2017-ginter_m in /home/fest/Epitech/bcpe042colle3-2017-ginter_m
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Sat Oct 27 16:32:20 2012 maxime ginters
** Last update Sun Oct 28 14:00:03 2012 maxime ginters
*/

#include "what_is_this_glue.h"
#include "utils.h"

void	print_colle(int colle, int row, int col)
{
  int	i;
  int	prev;

  prev = 0;
  i = 0;
  while (i < 5)
  {
      if ((1 << i) & colle)
      {
        if (prev != 0)
          my_putstr(" || ");
        my_putstr("[colle1-");
        my_put_nbr(i + 1);
        my_putstr("] [");
        my_put_nbr(col);
        my_putstr("] [");
        my_put_nbr(row);
        my_putstr("]");
        prev = i + 1;
      }
    ++i;
  }
}

void	what_is_this_glue(char buff[4096 + 1])
{
  char	**t;
  int	row;
  int	col;
  int	result;

  row = 0;
  col = 0;
  t = my_str_to_wordtab(buff);
  if (is_tab_valid(t, &row, &col) == 0)
    my_putstr("Aucune\n");
  else
  {
    result = colle_searcher(t, row, col);
    if (result == 0)
      my_putstr("Aucune\n");
    else
    {
      my_putstr("\t");
      print_colle(result, row, col);
      my_putstr("\n");
    }
  }
}

int	is_tab_valid(char **t, int *row, int *col)
{
  int	i;
  int	temp;

  i = 0;
  *col = -1;
  while (t[i][0] != 0)
  {
    temp = my_strlen(t[i]);
    if (*col != -1)
      if (*col != temp)
        return (0);
    *col = temp;
    ++i;
  }
  *row = i;
  return (1);
}
