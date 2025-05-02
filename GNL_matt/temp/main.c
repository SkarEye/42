/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 17:17:17 by mattcarniel       #+#    #+#             */
/*   Updated: 2025/05/01 17:19:50 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h" // Include your header file for get_next_line

// A simple helper function to open a file and call get_next_line
void test_file(const char *filename)
{
    int fd = open(filename, O_RDONLY);  // Open the file in read-only mode
    if (fd == -1)
    {
        perror("Error opening file");
        return;
    }

    char *line;
    while ((line = get_next_line(fd)) != NULL)  // Read a line
    {
        printf("Line: %s", line); // Print the line (get_next_line already includes the newline)
        free(line); // Don't forget to free the line after usage
    }

    close(fd); // Close the file
}

int main(void)
{
    // Test with a simple file "testfile.txt" containing multiple lines.
    printf("Test 1: File with multiple lines\n");
    test_file("testfile.txt");

    // Test with a file containing only newlines "only_nl.txt"
    printf("\nTest 2: File with only newlines\n");
    test_file("only_nl.txt");

    // Test with a file containing multiple newlines "multiple_nl.txt"
    printf("\nTest 3: File with multiple newlines\n");
    test_file("multiple_nl.txt");

    // Test with a file with varying lengths of lines "variable_nls.txt"
    printf("\nTest 4: File with variable newlines\n");
    test_file("variable_nls.txt");

    return 0;
}
