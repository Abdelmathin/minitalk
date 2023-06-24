/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabachi ahabachi@student.1337.ma          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 20:45:24 by ahabachi          #+#    #+#             */
/*   Updated: 2022/10/29 20:45:25 by ahabachi         ###   ########.fr       */
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

#include "minitalk.h"

size_t	ft_strlen(const char *s)
{
	if (s[0] == 0)
		return (0);
	return (1 + ft_strlen(s + 1));
}
