/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfradj <yfradj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:14:28 by yfradj            #+#    #+#             */
/*   Updated: 2024/11/26 17:02:18 by yfradj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_arg(char type, va_list arg)
{
	int	i;

	i = 0;
	if (type == 'c')
		i = ft_putchar(va_arg(arg, int));
	else if (type == 'd')
		i = ft_putnbr(va_arg(arg, long long));
	else if (type == 'x')
		i = ft_putnbr_base(va_arg(arg, unsigned int), "0123456789abcdef");
	else if (type == 'X')
		i = ft_putnbr_base(va_arg(arg, unsigned int), "0123456789ABCDEF");
	else if (type == 'p')
		i = ft_putptr(va_arg(arg, void *));
	else if (type == 's')
		i = ft_putstr(va_arg(arg, char *));
	else if (type == 'u')
		i = ft_putunsigned_nbr(va_arg(arg, unsigned int));
	else if (type == 'i')
		i = ft_putnbr(va_arg(arg, int));
	else
		i = ft_putchar('%');
	return (i);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		len;
	int		j;

	len = 0;
	j = 0;
	if (!str)
		return (-1);
	va_start(args, str);
	while (str[j])
	{
		if (str[j] == '%')
		{
			j++;
			if (str[j] == '%')
				len += ft_putchar('%');
			else
				len += print_arg(str[j], args);
		}
		else
			len += ft_putchar(str[j]);
		j++;
	}
	va_end(args);
	return (len);
}

// #include <limits.h>
// #include <stdio.h>
// #include <stdint.h>
// int main()
// {
// 	uint64_t valeur = 18446744073709551615ULL;
// 	uint64_t *ptr = &valeur;

// 	int i = ft_printf("%p\n", ptr);
// 	int j = printf("%p\n", ptr);
// 	printf("%d\t%d\n");

// long a = LONG_MIN;
// long b = LONG_MAX;
// unsigned long c = ULONG_MAX;
// unsigned long d = -ULONG_MAX;
// int i = ft_printf("%p %p ", &a);
// int j = ft_printf("%p\t", &b);
// int k = ft_printf("%p\t", &c);
// int f = ft_printf("%p\n", &d);
// int w = printf("%p\t", &a);
// int x = printf("%p\t", &b);
// int y = printf("%p\t", &c);
// int z = printf("%p\n", &d);
// printf("%d, %d, %d, %d, \n", i, j, k, f);
// ft_printf("%d, %d, %d, %d, \n", i, j, k, f);
// int	main(void)
// {
// 	int i = 0;
// 	int j = 0;
// 	int a = 42;
// 	int *pa = &a;

// 	i += ft_printf("%sadcde%s", "hello", "world");
// 	i += ft_printf("%sadcde%sabcde", "hello", "world");
// 	i += ft_printf("abcde%sadcde%s", "hello", "world");
// 	i += ft_printf("blblbl");
// 	i += ft_printf("%cnkla%p", 'A', NULL);
// 	i += ft_printf("%d%x", 255, 124443);
// 	i += ft_printf("    bcbc%u dgdgd  ", UINT_MAX);
// 	i += ft_printf("%i", INT_MIN);
// 	i += ft_printf("%%%%%%");
// 	i += ft_printf("%p", pa);
// 	i += ft_printf("\n");

// 	j += printf("%sadcde%s", "hello", "world");
// 	j += printf("%sadcde%sabcde", "hello", "world");
// 	j += printf("abcde%sadcde%s", "hello", "world");
// 	j += printf("blblbl");
// 	j += printf("%cnkla%p", 'A', NULL);
// 	j += printf("%d%x", 255, 124443);
// 	j += printf("    bcbc%u dgdgd  ", UINT_MAX);
// 	j += printf("%i", INT_MIN);
// 	j += printf("%%%%%%");
// 	j += printf("%p", pa);
// 	j += printf("\n");

// 	printf("\n%d\n%d", i, j);
// }