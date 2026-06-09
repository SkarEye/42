/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 14:11:12 by mattcarniel       #+#    #+#             */
/*   Updated: 2026/05/21 14:25:44 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <algorithm>
#include <iostream>
#include <list>
#include <stack>
#include <vector>

#define ANSI_RESET	"\033[0m"
#define ANSI_BOLD	"\033[1m"
#define ANSI_CYAN	"\033[36m"
#define ANSI_GREEN	"\033[32m"
#define ANSI_RED	"\033[31m"
#define ANSI_YELLOW	"\033[33m"

#define LOG_INFO(x)	std::cout << ANSI_CYAN   << x << ANSI_RESET
#define LOG_TEST(x)	std::cout << std::endl << ANSI_YELLOW ANSI_BOLD << x <<  ANSI_RESET << std::endl
#define LOG_OK(x)	std::cout << ANSI_GREEN "[ OK ] " ANSI_RESET << x << std::endl
#define LOG_FAIL(x)	std::cout << ANSI_RED   "[FAIL] " ANSI_RESET << x << std::endl

int main()
{
	LOG_INFO("Starting test suite...\n");

	LOG_TEST("Subject's reference snippet (1/12)");
	{
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);

		if (mstack.top() == 17)
			LOG_OK("top() returned 17 as expected.");
		else
			LOG_FAIL("top() returned " << mstack.top() << " (expected 17).");

		mstack.pop();
		if (mstack.size() == 1)
			LOG_OK("size() returned 1 after pop().");
		else
			LOG_FAIL("size() returned " << mstack.size() << " (expected 1).");

		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);

		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		std::cout << "Iteration: ";
		while (it != ite)
		{
			std::cout << *it << " ";
			++it;
		}
		std::cout << std::endl;
		LOG_OK("Iterated bottom-to-top without crashing.");
	}

	LOG_TEST("Bottom-to-top iteration order matches push order (2/12)");
	{
		MutantStack<int> ms;
		ms.push(10);
		ms.push(20);
		ms.push(30);
		ms.push(40);

		int expected[] = {10, 20, 30, 40};
		size_t i = 0;
		bool ok = true;
		for (MutantStack<int>::iterator it = ms.begin(); it != ms.end(); ++it, ++i)
		{
			if (*it != expected[i])
			{
				ok = false;
				break;
			}
		}
		if (ok && i == 4)
			LOG_OK("Forward iteration produced 10 20 30 40.");
		else
			LOG_FAIL("Forward iteration mismatch.");
	}

	LOG_TEST("top() equals *(--end()) (3/12)");
	{
		MutantStack<int> ms;
		ms.push(1);
		ms.push(2);
		ms.push(99);

		MutantStack<int>::iterator it = ms.end();
		--it;
		if (*it == ms.top())
			LOG_OK("*(--end()) == top() == " << ms.top());
		else
			LOG_FAIL("*(--end())=" << *it << " differs from top()=" << ms.top());
	}

	LOG_TEST("Reverse iteration walks top-to-bottom (4/12)");
	{
		MutantStack<int> ms;
		ms.push(1);
		ms.push(2);
		ms.push(3);
		ms.push(4);

		int expected[] = {4, 3, 2, 1};
		size_t i = 0;
		bool ok = true;
		for (MutantStack<int>::reverse_iterator it = ms.rbegin(); it != ms.rend(); ++it, ++i)
		{
			if (*it != expected[i])
			{
				ok = false;
				break;
			}
		}
		if (ok && i == 4)
			LOG_OK("Reverse iteration produced 4 3 2 1.");
		else
			LOG_FAIL("Reverse iteration mismatch.");
	}

	LOG_TEST("const_iterator on a const MutantStack (5/12)");
	{
		MutantStack<int> ms;
		ms.push(7);
		ms.push(8);
		ms.push(9);

		const MutantStack<int>& cref = ms;
		int sum = 0;
		for (MutantStack<int>::const_iterator it = cref.begin(); it != cref.end(); ++it)
			sum += *it;

		if (sum == 24)
			LOG_OK("Sum via const_iterator = 24 as expected.");
		else
			LOG_FAIL("Sum via const_iterator = " << sum << " (expected 24).");
	}

	LOG_TEST("Mutating elements through a non-const iterator (6/12)");
	{
		MutantStack<int> ms;
		ms.push(1);
		ms.push(2);
		ms.push(3);

		for (MutantStack<int>::iterator it = ms.begin(); it != ms.end(); ++it)
			*it *= 10;

		if (ms.top() == 30)
			LOG_OK("top() after in-place x10 mutation == 30.");
		else
			LOG_FAIL("top() = " << ms.top() << " (expected 30).");
	}

	LOG_TEST("STL algorithm compatibility: std::find (7/12)");
	{
		MutantStack<int> ms;
		ms.push(11);
		ms.push(22);
		ms.push(33);
		ms.push(44);

		MutantStack<int>::iterator it = std::find(ms.begin(), ms.end(), 33);
		if (it != ms.end() && *it == 33)
			LOG_OK("std::find located 33 inside the stack.");
		else
			LOG_FAIL("std::find did not locate 33.");

		MutantStack<int>::iterator miss = std::find(ms.begin(), ms.end(), 999);
		if (miss == ms.end())
			LOG_OK("std::find returned end() for an absent value.");
		else
			LOG_FAIL("std::find should have returned end() for an absent value.");
	}

	LOG_TEST("std::distance equals size() (8/12)");
	{
		MutantStack<int> ms;
		for (int i = 0; i < 10; ++i)
			ms.push(i);

		std::ptrdiff_t d = std::distance(ms.begin(), ms.end());
		if (static_cast<size_t>(d) == ms.size())
			LOG_OK("distance(begin,end)=" << d << " matches size()=" << ms.size());
		else
			LOG_FAIL("distance=" << d << " size=" << ms.size());
	}

	LOG_TEST("Equivalence with std::list iteration (9/12)");
	{
		MutantStack<int> ms;
		std::list<int>   ref;
		for (int i = 1; i <= 5; ++i)
		{
			ms.push(i);
			ref.push_back(i);
		}

		MutantStack<int>::iterator mit = ms.begin();
		std::list<int>::iterator   lit = ref.begin();
		bool ok = true;
		while (mit != ms.end() && lit != ref.end())
		{
			if (*mit != *lit)
			{
				ok = false;
				break;
			}
			++mit;
			++lit;
		}
		if (ok && mit == ms.end() && lit == ref.end())
			LOG_OK("MutantStack and std::list yielded identical sequences.");
		else
			LOG_FAIL("Sequences diverged.");
	}

	LOG_TEST("Copy constructor preserves contents and iteration (10/12)");
	{
		MutantStack<int> a;
		a.push(1);
		a.push(2);
		a.push(3);

		MutantStack<int> b(a);
		if (b.size() != a.size())
			LOG_FAIL("Copied stack has a different size.");
		else
		{
			bool ok = true;
			MutantStack<int>::iterator ita = a.begin();
			MutantStack<int>::iterator itb = b.begin();
			while (ita != a.end() && itb != b.end())
			{
				if (*ita != *itb) { ok = false; break; }
				++ita; ++itb;
			}
			if (ok)
				LOG_OK("Copy constructor produced an identical iterable stack.");
			else
				LOG_FAIL("Copied stack diverged from the original.");
		}

		b.push(99);
		if (a.size() == 3 && b.size() == 4)
			LOG_OK("Mutating the copy did not affect the original (deep copy).");
		else
			LOG_FAIL("Original was affected by copy mutation.");
	}

	LOG_TEST("Assignment operator preserves contents (11/12)");
	{
		MutantStack<int> a;
		a.push(100);
		a.push(200);
		a.push(300);

		MutantStack<int> b;
		b.push(0);
		b = a;

		bool ok = (b.size() == 3);
		MutantStack<int>::iterator it = b.begin();
		int expected[] = {100, 200, 300};
		for (size_t i = 0; ok && it != b.end(); ++it, ++i)
			if (*it != expected[i])
				ok = false;

		if (ok)
			LOG_OK("Assigned stack matches the source.");
		else
			LOG_FAIL("Assigned stack diverged from the source.");
	}

	LOG_TEST("Behaviour parity with std::stack for push/pop/top (12/12)");
	{
		MutantStack<int> ms;
		std::stack<int>  ss;
		for (int i = 0; i < 6; ++i)
		{
			ms.push(i * i);
			ss.push(i * i);
		}

		bool ok = (ms.size() == ss.size()) && (ms.top() == ss.top());
		while (ok && !ms.empty() && !ss.empty())
		{
			if (ms.top() != ss.top()) { ok = false; break; }
			ms.pop();
			ss.pop();
		}
		if (ok && ms.empty() && ss.empty())
			LOG_OK("MutantStack mirrors std::stack for push/pop/top/empty/size.");
		else
			LOG_FAIL("Divergence between MutantStack and std::stack.");
	}

	std::cout << std::endl;
	LOG_INFO("Test suite finished.\n");
	return (0);
}
