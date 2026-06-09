/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 17:30:29 by mattcarniel       #+#    #+#             */
/*   Updated: 2026/06/09 12:22:44 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <vector>

int main(int argc, char** argv)
{
	// Allow seed override: ./test_sort [seed] [count]
	unsigned	seed  = (argc > 1) ? std::atoi(argv[1]) : 42;
	size_t		count = (argc > 2) ? std::atoi(argv[2]) : 3000;

	std::srand(seed);

	// Build argv-style input
	std::vector<std::string>	args;

	args.push_back("test");
	for (size_t i = 0; i < count; ++i)
	{
		std::ostringstream os;
		os << (std::rand() % 100000 + 1);
		args.push_back(os.str());
	}
	
	std::vector<char*>	argv2;
	
	for (size_t i = 0; i < args.size(); ++i)
		argv2.push_back(const_cast<char*>(args[i].c_str()));

	// Reference sort with std::sort
	std::vector<int>	reference;
	for (size_t i = 1; i < args.size(); ++i)
		reference.push_back(std::atoi(args[i].c_str()));
	std::sort(reference.begin(), reference.end());

	// Run PmergeMe
	try
	{
		PmergeMe pm;
		pm.parse((int)argv2.size(), &argv2[0]);
		pm.run();

		const std::vector<int>& vec = pm.getVector();
		if (vec.size() != reference.size())
		{
			std::cerr << "FAIL: size mismatch (" << vec.size()
					  << " vs " << reference.size() << ")\n";
			return (1);
		}
		for (size_t i = 0; i < vec.size(); ++i)
		{
			if (vec[i] != reference[i]) {
				std::cerr << "FAIL at index " << i
						  << ": got " << vec[i]
						  << ", expected " << reference[i] << '\n';
				return (1);
			}
		}

		const std::list<int>&	lst = pm.getList();
		std::vector<int>		lstAsVec(lst.begin(), lst.end());
		
		if (lstAsVec != reference)
		{
			std::cerr << "FAIL: list output differs from reference\n";
			return (1);
		}

		std::cout << "PASS (" << count << " elements, seed " << seed << ")\n";
	}
	catch (std::exception& e)
	{
		std::cerr << "EXC: " << e.what() << '\n';
		return (1);
	}

	return (0);
}
