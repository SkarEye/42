/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 14:04:41 by mattcarniel       #+#    #+#             */
/*   Updated: 2026/05/25 13:46:35 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_TPP
# define MUTANTSTACK_TPP

# include "MutantStack.hpp"

template <typename T, typename Container>
typename MutantStack<T, Container>::iterator				MutantStack<T, Container>::begin(void)
{	return (this->c.begin());}

template <typename T, typename Container>
typename MutantStack<T, Container>::const_iterator			MutantStack<T, Container>::begin(void) const
{	return (this->c.begin());}

template <typename T, typename Container>
typename MutantStack<T, Container>::iterator				MutantStack<T, Container>::end(void)
{	return (this->c.end());}

template <typename T, typename Container>
typename MutantStack<T, Container>::const_iterator			MutantStack<T, Container>::end(void) const
{	return (this->c.end());}

template <typename T, typename Container>
typename MutantStack<T, Container>::reverse_iterator		MutantStack<T, Container>::rbegin(void)
{	return (this->c.rbegin());}

template <typename T, typename Container>
typename MutantStack<T, Container>::const_reverse_iterator	MutantStack<T, Container>::rbegin(void) const
{	return (this->c.rbegin());}

template <typename T, typename Container>
typename MutantStack<T, Container>::reverse_iterator		MutantStack<T, Container>::rend(void)
{	return (this->c.rend());}

template <typename T, typename Container>
typename MutantStack<T, Container>::const_reverse_iterator	MutantStack<T, Container>::rend(void) const
{	return (this->c.rend());}

#endif
