/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:05:28 by macarnie          #+#    #+#             */
/*   Updated: 2025/04/23 17:31:17 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	ft_sort_params(char **params)
{
	int		i;
	char	*temp;

	if (!params)
		return ;
	i = 0;
	while (params[i + 1])
	{
		if (ft_strcmp(params[i], params[i + 1]) > 0)
		{
			temp = params[i];
			params[i] = params[i + 1];
			params[i + 1] = temp;
			i = 0;
		}
		else
			i++;
	}
}

int	main(int argc, char **argv)
{
	int	i;
	int	j;

	if (argc > 1)
	{
		ft_sort_params(&argv[1]);
		i = 1;
		while (i < argc)
		{
			j = 0;
			while (argv[i][j])
				ft_putchar(argv[i][j++]);
			ft_putchar('\n');
			i++;
		}
	}
	return (0);
}
