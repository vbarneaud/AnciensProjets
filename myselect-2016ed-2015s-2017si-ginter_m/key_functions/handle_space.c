/*
** handle_space.c for key_functions in /home/fest/Epitech/MySelect/key_functions
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Wed Nov 21 17:16:33 2012 maxime ginters
** Last update Fri Nov 23 16:08:44 2012 maxime ginters
*/

#include "key.h"
#include "my.h"
#include "list.h"
#include "my_select.h"

void	handle_space(t_list **list)
{
  t_list	*elem;

  elem = get_focus_elem(*list);
  if (elem != NULL)
    elem->selected = !elem->selected;
  down_focus(*list);
  print_args(*list);
}
