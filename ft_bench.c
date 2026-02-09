/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bench.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrien- <iarrien-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 13:19:20 by iarrien-          #+#    #+#             */
/*   Updated: 2026/02/09 13:26:41 by iarrien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void ft_print_disorder(float disorder)
{
	char *result;

	disorder = disorder * 100000;
	result = ft_itoa(disorder);
	write(2, result, 2);
	write(2, ".", 1);
	write(2, &result[2], 2);
	ft_putstr_fd("%%", 2);
}

void	ft_print_bench_moves(t_moves *bench)
{
	ft_putstr_fd("[bench] total_ops: ", 2);
	ft_putnbr_fd(bench->all, 2);
	ft_putstr_fd("\n[bench] sa: ", 2);
	ft_putnbr_fd(bench->sa, 2);
	ft_putstr_fd(" sb: ", 2);
	ft_putnbr_fd(bench->sb, 2);
	ft_putstr_fd(" ss: ", 2);
	ft_putnbr_fd(bench->ss, 2);
	ft_putstr_fd(" pa: ", 2);
	ft_putnbr_fd(bench->pa, 2);
	ft_putstr_fd(" pb: ", 2);
	ft_putnbr_fd(bench->pb, 2);
	ft_putstr_fd("\n[bench] ra: ", 2);
	ft_putnbr_fd(bench->ra, 2);
	ft_putstr_fd(" rb: ", 2);
	ft_putnbr_fd(bench->rb, 2);
	ft_putstr_fd(" rr: ", 2);
	ft_putnbr_fd(bench->rr, 2);
	ft_putstr_fd(" rra: ", 2);
	ft_putnbr_fd(bench->rra, 2);
	ft_putstr_fd(" rrb: ", 2);
	ft_putnbr_fd(bench->rrb, 2);
	ft_putstr_fd(" rrr: ", 2);
	ft_putnbr_fd(bench->rrr, 2);
	write(2, "\n", 1);
}

void	ft_check_bench(t_moves *bench, char *result)
{
	if (!(bench->bench))
		ft_printf("%s\n", result);
	else if (ft_strnstr(result, "pa", 2))
		bench->pa++;
	else if (ft_strnstr(result, "pb", 2))
		bench->pb++;
	else if (ft_strnstr(result, "sa", 2))
		bench->sa++;
	else if (ft_strnstr(result, "sb", 2))
		bench->sb++;
	else if (ft_strnstr(result, "ss", 2))
		bench->ss++;
	else if (ft_strnstr(result, "ra", 2))
		bench->ra++;
	else if (ft_strnstr(result, "rb", 2))
		bench->rb++;
	else if (ft_strnstr(result, "rr", 2))
		bench->rr++;
	else if (ft_strnstr(result, "rra", 3))
		bench->rra++;
	else if (ft_strnstr(result, "rrb", 3))
		bench->rrb++;
	else if (ft_strnstr(result, "rrr", 3))
		bench->rrr++;
	bench->all++;
}

void	ft_put_in_bench(int algorithm, float disorder)
{
	ft_putstr_fd("[bench] disorder: ", 2);
	ft_print_disorder(disorder);
	write(2, "\n", 1);
	ft_putstr_fd("[bench] algorithm: ", 2);
	if (algorithm == 0)
		ft_putstr_fd("Simple / O(n^2)", 2);
	if (algorithm == 1)
		ft_putstr_fd("Medium / O(n√2)", 2);
	if (algorithm == 2)
		ft_putstr_fd("Complex / O(n log n)", 2);
	if (algorithm == 3)
	{
		ft_putstr_fd("Adaptative / ", 2);
		if (disorder < 0.2)
			ft_putstr_fd("O(n^2)", 2);
		else if (disorder < 0.5)
			ft_putstr_fd("O(n√2)", 2);
		else
			ft_putstr_fd("O(n log n)", 2);
	}
	ft_putchar_fd('\n', 2);
}
