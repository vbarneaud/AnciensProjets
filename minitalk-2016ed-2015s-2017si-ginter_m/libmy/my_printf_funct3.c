/*
** my_printf_funct3.c for libmy in /home/fest/Epitech/my_printf/libmy
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Wed Nov 14 17:57:58 2012 maxime ginters
** Last update Sun Nov 18 12:48:24 2012 maxime ginters
*/

#include <stdarg.h>
#include "my.h"

int	print_float(va_list ap)
{
  double	d;
  char	buffer[sizeof(double) + 1];
  int	i;

  i = 0;
  if ((d = (double)va_arg(ap, double)) == 0)
    return (0);
  return (my_put_float(d, 6));
}
