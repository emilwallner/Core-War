/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewallner <ewallner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 14:20:20 by ewallner          #+#    #+#             */
/*   Updated: 2017/03/18 18:16:12 by nsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include "../libft/libft.h"
# include "op.h"
# include <stdio.h>
# include <limits.h>

typedef struct	s_player
{
	char name[PROG_NAME_LENGTH + 1];
	char comment[COMMENT_LENGTH + 1];
	char inst[CHAMP_MAX_SIZE + 1];
	int	len;
	int	index_start;
	char string[CHAMP_MAX_SIZE + 1];
	int	inst_len;
}				t_player;

typedef struct		s_cursor{
	struct s_cursor	*next;
	int				player_id;
	int				carry;
	int				cycle;
}					t_cursor;

typedef struct	s_env
{
	t_player *player;
	char **strings;
	char	arena[MEM_SIZE];
	int		player_amount;
	char **files;
}				t_env;

void 		init_e(t_env *e, int ac, char **av);
void  		ft_files_to_string(t_env *e);
void 		ft_exit(t_env *e);
void 		ft_print_strings(t_env *e, int ac);
void		ft_parsing(t_env *e, int ac);
void		ft_build_vm(t_env *e, int ac);
void		ft_print_hexa(char *str, int len);

#endif