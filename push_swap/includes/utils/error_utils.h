/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarnie <macarnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 18:13:37 by macarnie          #+#    #+#             */
/*   Updated: 2025/08/13 18:36:34 by macarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_UTILS_H
# define ERROR_UTILS_H

typedef enum e_result
{
	SUCCESS,
	FAILURE,
	ERROR,
	UNKNOWN
}	t_result;

void	print_error(t_result res);

#endif