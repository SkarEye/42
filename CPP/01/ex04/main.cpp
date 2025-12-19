/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 22:25:02 by mattcarniel       #+#    #+#             */
/*   Updated: 2025/12/09 15:02:30 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstddef>
#include <string>
#include <iostream>
#include <fstream>

#include "log.hpp"

int	main(int argc, char **argv)
{
	std::string	in_path;
	std::string	out_path;
	std::string	s1;
	std::string	s2;

	if (argc != 4)
	{
		LOG_ERROR("Usage: ./sed_is_for_losers <filename> <s1> <s2>");
		return (1);
	}
	
	in_path = argv[1];
	s1 = argv[2];
	s2 = argv[3];
	
	if (in_path.empty())
	{
		LOG_ERROR("File name is empty");
		return (1);
	}

	out_path = in_path + ".replace";
	
	std::ifstream	infile(in_path);
	
	if (!infile)
	{
		LOG_ERROR("Could not open input file '" << in_path << "'");
		return (1);
	}

	std::ofstream	outfile(out_path);
	
	if (!outfile)
	{
		LOG_ERROR("Could not open output file '" << out_path << "'");
		return (1);
	}
	
	std::string line;
	int			occurrences = 0;
	#ifdef SILENT
		(void) occurrences;
	#endif
	bool		replace = !s1.empty();

	if (!replace)
		LOG_WARNING("s1 is empty. No replacement can be done");

	while (std::getline(infile, line))
	{
		if (replace)
		{
			size_t	pos = 0;
			while ((pos = line.find(s1, pos)) != std::string::npos)
			{
				line.erase(pos, s1.length());
				line.insert(pos, s2);
				pos += s2.length();
				occurrences++;
				
			}
		}
		outfile << line << '\n';
	}
	
	LOG_SUCCESS("Replaced each occurrence of '" << s1 << "' with '" << s2 <<"' (" << occurrences << " found)");
	
	return (0);
}
