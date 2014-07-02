/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   power4.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarty <mdarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 07:06:11 by mdarty            #+#    #+#             */
/*   Updated: 2014/03/09 22:21:08 by mdarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POWER4_H
# define POWER4_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <time.h>

typedef struct		s_place
{
	int				human[7][2];
	int				ai[7][2];
}					t_place;

typedef struct		s_map
{
	char			**tab;
	char			*coor;
	int				max_weight;
	int				x_max;
	int				max;
	int				count;
	int				size_x;
	int				size_y;
	int				last_x;
	int				last_human_x;
}					t_map;

int			ft_human_max(t_map *map, int x, t_place *check);
int			ft_ai_max(t_map *map, int x, t_place *check);
int			ft_check_win(t_map *map, int i, char c);
int			ft_check_count_win(int count, char c);
int			ft_check_bad_slash(t_map *map, int y, int x, char c);
int			ft_check_slash(t_map *map, int y, int x, char c);
int			ft_check_token(t_map *map, int y, int x, char c);
int			ft_check_number(char *av);
int			ft_error_argv(int ac);
int			ft_error_malloc(void);
int			ft_error_number(int nb, char c);
int			ft_error_too_memory(void);
int			ft_place_piece(t_map *map, int x, int y, char c);
int			ft_first_player(void);
int			ft_ai(t_map *map);
int			ft_ai_search_max(t_map *map, t_place *check);
int			ft_player_line_1(t_map *map, char **line, int x, int y);
void		ft_check_turn_human(t_map *map, int x, t_place *check);
void		ft_game_human(t_map *map, int y, int x);
void		ft_check_place_ai_up(t_map *map, int y, t_place *check, char c);
void		ft_print_turn_ai(int x);
void		ft_print_map(t_map *map, int last, char c, int y);
void		ft_read_ai(t_map *map, int x, int y);
void		ft_ai_weight_left_down(t_map *map, int y, int x, t_place *check);
void		ft_ai_weight_left(t_map *map, int y, int x, t_place *check);
void		ft_ai_weight_left_up(t_map *map, int y, int x, t_place *check);
void		ft_ai_weight_right_down(t_map *map, int y, int x, t_place *check);
void		ft_ai_weight_right(t_map *map, int y, int x, t_place *check);
void		ft_ai_weight_right_up(t_map *map, int y, int x, t_place *check);
void		ft_human_weight_left_up(t_map *map, int y, int x, t_place *check);
void		ft_human_weight_left(t_map *map, int y, int x, t_place *check);
void		ft_human_weight_left_down(t_map *map, int y, int x, t_place *check);
void		ft_human_weight_right_up(t_map *map, int y, int x, t_place *check);
void		ft_human_weight_right(t_map *map, int y, int x, t_place *check);
void		ft_human_weight_right_down(t_map *map, int y,
										int x, t_place *check);
char		**ft_create_map(int y, int x);

#endif /* !POWER4_H */
