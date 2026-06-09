/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 14:05:18 by mattcarniel       #+#    #+#             */
/*   Updated: 2026/06/09 11:59:40 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>
#include <cstddef>
#include <iostream>
#include <iterator>
#include <ostream>
#include <string>
#include <sstream>
#include <climits>
#include <vector>
#include <utility>
#include <sys/time.h>

#include "PmergeMe.hpp"

static bool	stringToPositiveInt(const std::string &s, int &out)
{
	if (s.empty())
		return (false);
	for (size_t i = 0; i < s.size(); ++i)
	{
		if (s[i] < '0' || s[i] > '9')
			return (false);
	}

	std::stringstream	ss(s);
	long				tmp;

	ss >> tmp;
	if (ss.fail() || !ss.eof())
		return (false);
	if (tmp <= 0 || tmp > (long)INT_MAX)
		return (false);

	out = (int)tmp;
	return (true);
}

void PmergeMe::mergeVectorPairs(vector_pair& vec, size_t lo, size_t mid, size_t hi, vector_pair& scratch)
{
	if (vec[mid - 1].first <= vec[mid].first)
		return ;

	size_t	i = lo, j = mid, k = lo;

	while (i < mid && j < hi)
	{
		if (vec[i].first <= vec[j].first)
			scratch[k++] = vec[i++];
		else
			scratch[k++] = vec[j++];
	}

	while (i < mid)
		scratch[k++] = vec[i++];
	while (j < hi)
		scratch[k++] = vec[j++];

	for (size_t x = lo; x < hi; ++x)
		vec[x] = scratch[x];
}

void PmergeMe::mergeSortVectorPairs(vector_pair& vec, size_t lo, size_t hi, vector_pair& scratch)
{
	if (hi - lo < 2)
		return;

	size_t	mid = lo + (hi - lo) / 2;

	mergeSortVectorPairs(vec, lo,  mid, scratch);
	mergeSortVectorPairs(vec, mid, hi,  scratch);
	mergeVectorPairs(vec, lo, mid, hi, scratch);
}

void PmergeMe::mergeSortVectorPairs(vector_pair& vec)
{
	if (vec.size() < 2)
		return;

	vector_pair	scratch(vec.size());
	mergeSortVectorPairs(vec, 0, vec.size(), scratch);
}


std::vector<size_t> PmergeMe::jacobsthalInsertionOrderVector(size_t pendSize)
{
	std::vector<size_t>	order;

	if (pendSize <= 1)
		return (order);

	size_t	prev = 1,
			curr = 1,
			next,
			lastInserted = 0;

	while (lastInserted + 1 < pendSize)
	{
		size_t	target = (curr < pendSize - 1) ? curr : pendSize - 1;
		
		for (size_t k = target; k > lastInserted; --k)
			order.push_back(k);
		lastInserted = target;

		next = curr + 2 * prev;
		prev = curr;
		curr = next;
	}

	return (order);
}

void	PmergeMe::fordJohnsonVector(void)
{
	if (this->_vec.size() < 2)
		return ;

	vector_pair	pairs;

	pairs.reserve(this->_vec.size() / 2);

	for (size_t i = 0; i + 1 < this->_vec.size(); i += 2)
	{
		int	a = this->_vec[i],
			b = this->_vec[i + 1];
		
		if (a < b)
			std::swap(a, b);

		pairs.push_back(std::make_pair(a, b));
	}


	bool	hasLeftover = (this->_vec.size() % 2 != 0);
	int		leftover    = hasLeftover ? this->_vec.back() : 0;
	
	mergeSortVectorPairs(pairs);

	std::vector<int>	main, pend;

	main.reserve(pairs.size());
	pend.reserve(pairs.size());

	for (size_t i = 0; i < pairs.size(); ++i)
	{
		main.push_back(pairs[i].first);
		pend.push_back(pairs[i].second);
	}

	std::vector<int>	chain;

	chain.reserve(this->_vec.size());

	chain.push_back(pend[0]);
	chain.insert(chain.end(), main.begin(), main.end());

	std::vector<size_t>	order = jacobsthalInsertionOrderVector(pend.size());

	for (size_t i = 0; i < order.size(); ++i)
	{
		size_t	k = order[i];
		int		value = pend[k];

		std::vector<int>::iterator	hi  = std::find(chain.begin(), chain.end(), main[k]);
		std::vector<int>::iterator	pos = std::lower_bound(chain.begin(), hi, value);

		chain.insert(pos, value);
	}

	if (hasLeftover)
	{
		std::vector<int>::iterator pos = std::lower_bound(chain.begin(), chain.end(), leftover);

		chain.insert(pos, leftover);
	}

	this->_vec.swap(chain);
}

// Merge two already-sorted ranges [first, mid) and [mid, last) in place.
// Uses splice — no copies, no scratch. Returns the new head of the range,
// because the smallest element may come from the right half and get spliced
// to the front (invalidating `first` as the head marker).
PmergeMe::list_pair::iterator PmergeMe::mergeListPairs(
	list_pair& lst,
	list_pair::iterator first,
	list_pair::iterator mid,
	list_pair::iterator last)
{
	list_pair::iterator	head  = (first->first <= mid->first) ? first : mid;
	list_pair::iterator	left  = first;
	list_pair::iterator	right = mid;

	while (left != right && right != last)
	{
		if (left->first <= right->first)
			++left;
		else
		{
			// Move *right just before *left; advance right first
			// because splice invalidates only the node being moved.
			list_pair::iterator	next = right;
			++next;
			lst.splice(left, lst, right);
			right = next;
		}
	}
	return (head);
}

PmergeMe::list_pair::iterator PmergeMe::mergeSortListPairs(
	list_pair& lst,
	list_pair::iterator first,
	list_pair::iterator last,
	size_t size)
{
	if (size < 2)
		return (first);

	size_t				half = size / 2;
	list_pair::iterator	mid  = first;
	std::advance(mid, half);

	first = mergeSortListPairs(lst, first, mid, half);
	mid   = mergeSortListPairs(lst, mid, last, size - half);
	return (mergeListPairs(lst, first, mid, last));
}

void PmergeMe::mergeSortListPairs(list_pair& lst)
{
	if (lst.size() < 2)
		return ;
	
	mergeSortListPairs(lst, lst.begin(), lst.end(), lst.size());
}

std::list<size_t> PmergeMe::jacobsthalInsertionOrderList(size_t pendSize)
{
	std::list<size_t>	order;

	if (pendSize <= 1)
		return (order);

	size_t	prev = 1,
			curr = 1,
			next,
			lastInserted = 0;

	while (lastInserted + 1 < pendSize)
	{
		size_t	target = (curr < pendSize - 1) ? curr : pendSize - 1;
		
		for (size_t k = target; k > lastInserted; --k)
			order.push_back(k);
		lastInserted = target;

		next = curr + 2 * prev;
		prev = curr;
		curr = next;
	}

	return (order);
}

void	PmergeMe::fordJohnsonList(void)
{
	if (this->_lst.size() < 2)
		return ;

	list_pair	pairs;
	size_t		size = this->_lst.size();

	{
		std::list<int>::iterator	it = this->_lst.begin();

		for (size_t i = 0; i + 1 < size; i += 2)
		{
			int	a = *it;
			++it;
			int	b = *it;
			++it;

			if (a < b)
				std::swap(a, b);

			pairs.push_back(std::make_pair(a, b));
		}
	}

	bool	hasLeftover = (this->_lst.size() % 2 != 0);
	int		leftover = hasLeftover ? this->_lst.back() : 0;

	mergeSortListPairs(pairs);

	std::vector<int>	main, pend;

	main.reserve(pairs.size());
	pend.reserve(pairs.size());

	for (list_pair::iterator it = pairs.begin(); it != pairs.end(); ++it)
	{
		main.push_back(it->first);
		pend.push_back(it->second);
	}

	std::list<int>	chain;

	chain.push_back(pend[0]);
	chain.insert(chain.end(), main.begin(), main.end());

	std::list<size_t>	order = jacobsthalInsertionOrderList(pend.size());

	for	(std::list<size_t>::iterator it = order.begin(); it != order.end(); ++it)
	{
		size_t	k     = *it;
		int		value = pend[k];
		int		bound = main[k];

		std::list<int>::iterator	hi  = std::find(chain.begin(), chain.end(), bound);
		std::list<int>::iterator	pos = std::lower_bound(chain.begin(), hi, value);

		chain.insert(pos, value);
	}

	if (hasLeftover)
	{
		std::list<int>::iterator	pos = std::lower_bound(chain.begin(), chain.end(), leftover);

		chain.insert(pos, leftover);
	}

	this->_lst.swap(chain);
}

PmergeMe::PmergeMe(void)
{}

PmergeMe::PmergeMe(const PmergeMe& other) :
	_vec(other._vec),
	_lst(other._lst)
{}

PmergeMe::~PmergeMe()
{}

PmergeMe&	PmergeMe::operator=(const PmergeMe& other)
{
	if (this != &other)
	{
		this->_vec = other._vec;
		this->_lst = other._lst;
	}
	return (*this);
}

const std::vector<int>&	PmergeMe::getVector(void) const
{
	return (this->_vec);	
}

const std::list<int>&	PmergeMe::getList(void) const
{
	return (this->_lst);	
}

void PmergeMe::parse(int argc, char** argv)
{
	if (argc < 2)
		throw PmergeMe::PmergeMeException("no arguments given to process.");

	this->_vec.reserve((size_t)argc - 1);

	for (int i = 1; i < argc; ++i)
	{
		int v;
		if (!stringToPositiveInt(argv[i], v))
			throw PmergeMe::PmergeMeException("invalid argument processed.");
		this->_vec.push_back(v);
		this->_lst.push_back(v);
	}
}

void PmergeMe::run(void)
{
	std::cout << "Before:";
	for (size_t i = 0; i < this->_vec.size(); ++i)
	{
		std::cout << " " << this->_vec[i];
		if (i > 2 && i + 2 < this->_vec.size())
		{
			std::cout << " [...]";
			break ;
		}
	}
	std::cout << std::endl;

	struct timeval begin, end;
	double vecElapsed, lstElapsed;

	gettimeofday(&begin, 0);
	fordJohnsonVector();
	gettimeofday(&end, 0);
	vecElapsed = (end.tv_sec - begin.tv_sec) * 1e6
			+ (end.tv_usec - begin.tv_usec);

	gettimeofday(&begin, 0);
	fordJohnsonList();
	gettimeofday(&end, 0);
	lstElapsed = (end.tv_sec - begin.tv_sec) * 1e6
			+ (end.tv_usec - begin.tv_usec);

	std::cout << "After :";
	for (size_t i = 0; i < this->_vec.size(); ++i)
	{
		std::cout << " " << this->_vec[i];
		if (i > 2 && i + 2 < this->_vec.size())
		{
			std::cout << " [...]";
			break ;
		}
	}
	std::cout << std::endl;

	std::cout << "Time to process a range of " << this->_vec.size()
			<< " elements with std::vector : " << vecElapsed << " us" << std::endl;
	std::cout << "Time to process a range of " << this->_lst.size()
			<< " elements with std::list   : " << lstElapsed << " us" << std::endl;
}
