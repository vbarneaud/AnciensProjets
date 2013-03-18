/*
** operations.h for temp_operations in /home/fest/Epitech/bistromathique/temp_operations
** 
** Made by maxime ginters
** Login   <ginter_m@epitech.eu>
** 
** Started on  Tue Nov 06 16:21:12 2012 maxime ginters
** Last update Sun Nov 11 18:46:09 2012 maxime ginters
*/

#ifndef OPERTIONS_H_
# define OPERTIONS_H_

#include "bistromathique.h"

#define gcfv get_char_for_value

/*
** operations.c
*/
char	*do_op_add(char *tab[2], t_base *base, char ops[7]);
char	*do_op_sub(char *tab[2], t_base *base, char ops[7]);
char	*do_op_mult(char *tab[2], t_base *base, char ops[7]);
char	*do_op_div(char *tab[2], t_base *base, char ops[7]);
char	*do_op_mod(char *tab[2], t_base *base, char ops[7]);

/*
** str_utils.c
*/
char	**remove_operator_from_second_str(char *tab[2], char ops[7], int t);
char	**swap_tab(char *tab[2]);
char	get_char_for_value(int val, t_base *base);
int	min_ref(char *c, char ops[7]);
int	a_is_high_b(char *a, char *b, t_base *base, char ops[7]);

/*
** op_sub.c
*/
char	*op_sub(char *tab[2], t_base *base, char ops[7], int neg[2]);

/*
** op_div.c
*/
char	*absolute(char *str, char ops[7]);
int	is_null(char *str, t_base *base);
char	*clean_zero(char *str, t_base *base, char ops[7]);
char	**compute_tab(char *s1, char *s2);

/*
** op_add.c
*/
int	get_op_add_ret(int len[2], char *tab[2], t_base *base, char ops[7]);
char	*op_add(char *tab[2], t_base *base, char ops[7], int len[2]);

/*
** op_mult.c
*/
char	*op_mult(char *tab[2], t_base *base, char ops[7], int var[6]);

#endif /* !OPERTIONS_H_ */
