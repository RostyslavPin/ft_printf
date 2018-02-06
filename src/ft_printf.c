/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpin <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 13:44:47 by rpin              #+#    #+#             */
/*   Updated: 2018/02/05 12:27:03 by rpin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
// #include <locale.h>

int g_ret;

int	str_contains(char c)
{
	static char conversions [] = "sSpdDioOuUxXcC";
	int i;

	i = 0;
	while(conversions[i])
	{
		if(c == conversions[i++])
			return (1);
	}
	return (0);
}

int flags(char flag, char *search)
{
	while(*search)
	{
		if(*search == flag)
			return (1);
		search++;
	}
	return(0);
}
//#0-+ and space

int	handle_d_i(char *f, int d_i)
{
	int i;
	int l_justfy;
	int force_pos;
	int num_digits;

	l_justfy = flags('-', f);
	force_pos = flags('+', f);
	i = ft_atoi(f + (l_justfy + force_pos));
	num_digits = ft_strlen(ft_itoa(i));
	if(force_pos)
		i = i - (num_digits + 1);
	if (l_justfy)
	{
		if(force_pos)
			ft_putchar('+');
		ft_putnbr(d_i);
		while(--i > 0)
			ft_putchar(' ');
	}
	else
	{
		while(--i > 0)
			ft_putchar(' ');
		if (force_pos)
			ft_putchar('+');
		ft_putnbr(d_i);
	}
	g_ret = num_digits;
	return(g_ret);
}

int ft_printf(const char *format, ...)
{
	const char *traverse;
	va_list arg;
	int i;
	char *flags;

	va_start(arg, format);
	i = 0;
	flags = malloc(ft_strlen(format));
	traverse = format;
	while(*traverse)
	{
		if(*traverse == '%')
		{
			i = 0;
			traverse++;
			ft_bzero(flags, ft_strlen(flags));
			while(!str_contains(*traverse))
				flags[i++] = *traverse++;
			if (*traverse == 'd' || *traverse == 'i')
				handle_d_i(flags, va_arg(arg, int));
			else if (*traverse == 'c')
				ft_putchar((unsigned char)(va_arg(arg, int)));
			else if (*traverse == 'C')
				ft_putchar_unicode(va_arg(arg, int));
			else if(*traverse == '%')
				ft_putchar('%');
			else if (*traverse == 's')
				ft_putstr(va_arg(arg, char *));
			//sSpdDioOuUxXcC
		}
		else
			ft_putchar(*traverse);
		traverse++;
	}
	va_end(arg);
	free(flags);
	return(1);
}

// int main(void)
// {
// 	// setlocale(LC_CTYPE, "");
//     // wchar_t star = 0x2605;
//     // wprintf(L"%lc\n", star);
//     ft_printf("|%s|", NULL);
// 	ft_printf("|%-+9d|%13d\n", 18,9);
// 	printf("|%s|", NULL);
// 	return (0);
// }
