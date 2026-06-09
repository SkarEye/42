/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 14:14:47 by mattcarniel       #+#    #+#             */
/*   Updated: 2026/06/09 11:16:00 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <cstddef>
# include <vector>
# include <list>
# include <string>
# include <exception>

class	PmergeMe
{
	private:
		typedef std::vector<std::pair<int, int> >	vector_pair;
		typedef std::list<std::pair<int, int> >		list_pair;

		std::vector<int>	_vec;
		std::list<int>		_lst;

		static void	mergeVectorPairs(
			vector_pair& vec,
			size_t lo, size_t mid,
			size_t hi,
			vector_pair& scratch);
		static void	mergeSortVectorPairs(
			vector_pair& vec,
			size_t lo,
			size_t hi,
			vector_pair& scratch);
		static void	mergeSortVectorPairs(vector_pair& vec);

		static list_pair::iterator mergeListPairs(
			list_pair& lst,
			list_pair::iterator first,
			list_pair::iterator mid,
			list_pair::iterator last);
		static list_pair::iterator mergeSortListPairs(
			list_pair& lst,
			list_pair::iterator first,
			list_pair::iterator last,
			size_t size);
		static void mergeSortListPairs(list_pair& lst);

		static std::vector<size_t>	jacobsthalInsertionOrderVector(size_t pendSize);
		static std::list<size_t>	jacobsthalInsertionOrderList(size_t pendSize);

		void	fordJohnsonVector(void);
		void	fordJohnsonList(void);

	public:
		PmergeMe(void);
		PmergeMe(const PmergeMe& other);
		~PmergeMe();

		PmergeMe&	operator=(const PmergeMe& other);

		const std::vector<int>&	getVector(void) const;
		const std::list<int>&	getList(void) const;

		void	parse(int argc, char** argv);
		void	run(void);

		class PmergeMeException : public std::exception
		{
			private:
				std::string	_msg;
			public:
				PmergeMeException(const std::string& msg) : _msg(msg) {}
				virtual ~PmergeMeException() throw() {}
				virtual const char* what() const throw() { return (_msg.c_str()); }
		};
};


#endif
