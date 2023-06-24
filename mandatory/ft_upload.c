/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_upload.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabachi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 18:18:51 by ahabachi          #+#    #+#             */
/*   Updated: 2022/10/29 18:18:52 by ahabachi         ###   ########.fr       */
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

#include <signal.h>
#include <unistd.h>
#include "minitalk.h"

t_server	g_server;

void	ft_client_error(t_server *srv)
{
	if (srv->bit_offset == 0 && srv->message_pos == 0)
		ft_putstr_fd("[PIDError] : "
			"This Process is Unavailable!\n", 2);
	else
		ft_putstr_fd("[CommunicationError] : "
			"The server die!\n", 2);
	srv->running = 0;
}

void	ft_send_bit(void)
{
	unsigned char	sig;

	if (g_server.bit_offset < 8)
	{
		sig = SIGUSR1;
		if (g_server.message_bit % 2)
			sig = SIGUSR2;
		if (kill(g_server.pid, sig) < 0)
			return (ft_client_error(&g_server));
		g_server.message_bit = g_server.message_bit / 2;
		g_server.bit_offset++;
	}
}

void	ft_send(int s)
{
	usleep(USLEEP_DT);
	if (g_server.message_pos >= g_server.message_len)
	{
		g_server.running = 0;
		return ;
	}
	if (s == SIGUSR2)
	{
		g_server.bit_offset = 0;
		g_server.message_pos++;
		if (g_server.message_pos >= g_server.message_len)
		{
			g_server.running = 0;
			return ;
		}
		g_server.message_bit = g_server.message[g_server.message_pos];
		return (ft_send_bit());
	}
	if (s == SIGUSR1)
		return (ft_send_bit());
}

void	ft_server_reset(t_server *server, int pid, const char *msg)
{
	server->pid = pid;
	server->bit_offset = 0;
	server->message_bit = msg[0];
	server->message_pos = 0;
	server->message_len = ft_strlen(msg);
	server->message = msg;
	server->running = 1;
}

int	ft_upload(unsigned int pid, const char *message)
{
	ft_server_reset(&g_server, pid, message);
	signal(SIGUSR1, ft_send);
	signal(SIGUSR2, ft_send);
	ft_send(SIGUSR1);
	while (g_server.running)
		usleep(30 * 1000);
	return (0);
}
