/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabachi ahabachi@student.1337.ma          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 16:02:54 by ahabachi          #+#    #+#             */
/*   Updated: 2022/10/26 16:02:55 by ahabachi         ###   ########.fr       */
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

t_client	g_client;

void	ft_receive(int s, siginfo_t *info, void *context)
{
	usleep(USLEEP_DT);
	if (info->si_pid && info->si_pid != g_client.pid)
		ft_reset_client(&g_client);
	g_client.nbites++;
	if (s == SIGUSR2)
		g_client.message[g_client.offset] += g_client.base;
	g_client.base *= 2;
	if (info->si_pid)
		g_client.pid = info->si_pid;
	if (g_client.nbites == 8)
	{
		ft_put_client_message(&g_client);
		g_client.message[g_client.offset] = 0;
		g_client.nbites = 0;
		g_client.base = 1;
		kill(g_client.pid, SIGUSR2);
		return ;
	}
	kill(g_client.pid, SIGUSR1);
	(void)context;
}

int	main(void)
{
	struct sigaction	sa;

	ft_reset_client(&g_client);
	ft_putstr_fd("Server PID: ", 1);
	ft_putpid_fd(getpid(), 1);
	ft_putstr_fd("\n", 1);
	sa.sa_sigaction = ft_receive;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		usleep(1000 * 1000);
	return (0);
}
