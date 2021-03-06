/*
** do_setenv.c for do in /home/fest/Epitech/MiniShell1/do
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Thu Nov 08 18:41:00 2012 maxime ginters
** Last update Thu Dec 06 17:23:04 2012 maxime ginters
*/

#include <stdlib.h>
#include "my.h"
#include "chaine.h"
#include "mysh.h"

char	*trim_quote(char *str)
{
  int	size;

  size = my_strlen(str) - 1;
  if ((str[0] == '\'' && str[size] == '\'') ||
    (str[0] == '"' && str[size] == '"'))
    return (my_substr(str, 1, size - 1));
  return (my_strdup(str));
}

int	do_setenv(t_command *t, t_env *env)
{
  char	*value;
  int	i;

  if (t->commands[0][1] == NULL || t->commands[0][2] == NULL)
    return (1);
  i = 3;
  value = my_strdup(t->commands[0][2]);
  while (t->commands[0][i] != NULL)
  {
    value = my_strcat(value, my_strdup(" "));
    value = my_strcat(value, my_strdup(t->commands[0][i++]));
  }
  value = trim_quote(value);
  create_or_update_value(env, t->commands[0][1], value);
  free(value);
  return (0);
}
