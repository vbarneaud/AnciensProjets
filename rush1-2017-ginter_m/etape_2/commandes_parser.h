/*
** commandes_parser.h for etape_2 in /home/fest/Epitech/rush1-2017-ginter_m/etape_2
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Fri Nov 30 22:58:29 2012 maxime ginters
** Last update Sat Dec 01 17:25:50 2012 maxime ginters
*/

#ifndef COMMANDES_PARSER_H_
# define COMMANDES_PARSER_H_

struct s_command
{
  char	**commands;
  int	index;
};

typedef struct s_command t_command;

t_command	*read_commands();

#endif /* !COMMANDES_PARSER_H_ */
