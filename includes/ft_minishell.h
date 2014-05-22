/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetit <apetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/03 14:59:59 by apetit            #+#    #+#             */
/*   Updated: 2014/05/18 16:07:38 by apetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINISHELL_H
# define FT_MINISHELL_H

# include <unistd.h>
# include <sys/types.h>

typedef struct	s_shell
{
	char		**env;
	pid_t		pid;
	char		*input;
	int			argc;
	char		**argv;
	char		**path;
	char		*pwd;
	char		*oldpwd;
	char		*binpath;
}				t_shell;

char			**ft_dup_environ(const char **environ);
void			ft_display_prompt(t_shell **shell);
void			ft_print_environ(t_shell *shell);
int				ft_fork(t_shell **shell);
void			ft_parse_input(t_shell **shell);
int				ft_count_arg(char **argv);
int				ft_setenv(t_shell **shell);
int				ft_unsetenv(t_shell **shell);
void			ft_exit(t_shell **shell);
char			**ft_get_envpath(char **env);
int				ft_exec_bin(t_shell **shell);
char			*ft_get_envpwd(char **env);
char			*ft_get_envoldpwd(char **env);
char			*ft_get_envhome(char **env);
int				ft_cd(t_shell **shell);
char			*ft_get_pwd(void);

#endif
