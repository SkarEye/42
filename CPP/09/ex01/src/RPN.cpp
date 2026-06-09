/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 16:20:15 by mattcarniel       #+#    #+#             */
/*   Updated: 2026/05/22 17:17:54 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstddef>
#include <sstream>
#include <stack>
#include <string>

#include "RPN.hpp"


static inline bool	isDigit(char c)
{
	return (c >= '0' && c <= '9');
}

static inline bool	isOperator(char c)
{
	return (c == '+' || c == '-' || c == '*' || c == '/');
}

int	RPN::calculate(const std::string& str)
{
	std::stack<int>		s;
	std::istringstream	iss(str);
	std::string			tok;

	while (iss >> tok)
	{
		if (tok.size() != 1)
			throw RPNException("Tokens must be single-digit numbers or a single operator.");

		if (isDigit(tok[0]))
			s.push(tok[0] - '0');
		else if (isOperator(tok[0]))
		{
			if (s.size() < 2)
				throw RPNException("Insufficient operands for operator.");

			int	b = s.top(); s.pop();
			int	a = s.top(); s.pop();

			switch (tok[0])
			{
				case '+': s.push(a + b); break;
				case '-': s.push(a - b); break;
				case '*': s.push(a * b); break;
				case '/':
				{
					if (b == 0)
						throw RPNException("Division by zero.");
					s.push(a / b); break;
				}
			}
		}
		else
			throw RPNException("Unrecognized character: valid characters are '0'-'9' and '+-*/'.");
	}

	if (s.size() != 1)
		throw RPNException("Invalid RPN expression: stack must contain exactly one value at end.");
	return (s.top());
}