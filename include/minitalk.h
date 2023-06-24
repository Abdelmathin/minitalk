/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabachi ahabachi@student.1337.ma          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 17:40:34 by ahabachi          #+#    #+#             */
/*   Updated: 2022/10/29 17:40:34 by ahabachi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*  .___  ___.  __  .__   __.  __  .__________.    ___       __       __  ___ */
/*  |   \/   | |  | |  \ |  | |  | |          |   /   \     |  |     |  |/  / */
/*  |  \  /  | |  | |   \|  | |  | `---|  |---`  /  ^  \    |  |     |  '  /  */
/*  |  |\/|  | |  | |  . `  | |  |     |  |     /  /_\  \   |  |     |    <   */
/*  |  |  |  | |  | |  |\   | |  |     |  |    /  _____  \  |  `----.|  .  \  */
/*  |__|  |__| |__| |__| \__| |__|     |__|   /__/     \__\ |_______||__|\__\ */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/* ************************************************************************** */
/*  █████████            ██████████         ██████████         ██████████     */
/*  ██     ██                    ██                 ██         ██      ██     */
/*         ██                    ██                 ██         ██      ██     */
/*         ██                    ██                 ██                 ██     */
/*         ██            ██████████         ██████████                 ██     */
/*         ██                    ██                 ██                 ██     */
/*         ██                    ██                 ██                 ██     */
/*         ██                    ██                 ██                 ██     */
/*      ████████         ██████████         ██████████                 ██     */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stddef.h>
# include <signal.h>

# define USLEEP_DT 100

typedef struct s_client
{
	int		pid;
	size_t	offset;
	char	message[4];
	int		nbites;
	size_t	base;
}	t_client;

typedef struct s_server
{
	size_t			pid;
	unsigned char	bit_offset;
	size_t			message_bit;
	size_t			message_pos;
	size_t			message_len;
	const char		*message;
	int				running;
}	t_server;

unsigned int	ft_loadpid(const char *str);
size_t			ft_unicode_len(const char *c);
void			ft_put_client_message(t_client *c);
void			ft_putchar_fd(char c, int fd);
void			ft_putpid_fd(unsigned int nbr, int fd);
void			ft_putstr_fd(const char *str, int fd);
void			ft_reset_client(t_client *client);
size_t			ft_strlen(const char *s);
void			ft_client_error(t_server *srv);
void			ft_send_bit(void);
void			ft_send(int s);
void			ft_server_reset(t_server *server, int pid, const char *msg);
int				ft_upload(unsigned int pid, const char *message);
void			ft_receive(int s, siginfo_t *info, void *context);

#endif//MINITALK_H