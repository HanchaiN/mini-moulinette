#include "../../../utils/constants.h"
#include "ft_ten_queens_puzzle.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

int	test1(void);

int	main(void)
{
	if (test1() != 0)
		return (-1);
	return (0);
}

int	test1(void)
{
	char	buffer[1024];
	int		saved_stdout;
	int		output_fd;
	int		result;
	int		expected;
	FILE	*fp;

	// Flush the standard output buffer
	fflush(stdout);
	// Clear the buffer used to capture the output of the function being tested
	memset(buffer, 0, sizeof(buffer));
	// Redirect the output to a file
	saved_stdout = dup(STDOUT_FILENO);
	output_fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC,
			S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	dup2(output_fd, STDOUT_FILENO);
	close(output_fd);
	result = ft_ten_queens_puzzle();
	expected = 724;
	// Restore the original output
	fflush(stdout);
	dup2(saved_stdout, STDOUT_FILENO);
	close(saved_stdout);
	// Open the output file and check its contents
	fp = fopen("output.txt", "r");
	fgets(buffer, sizeof(buffer), fp);
	fclose(fp);
	if (result != expected)
	{
		printf("    " RED "[1] ft_ten_queens_puzzle() Expected %d, got %d\n",
				expected,
				result);
		return (-1);
	}
	else
	{
		printf("  " GREEN CHECKMARK GREY
				" [1] ft_ten_queens_puzzle() Expected %d, got %d\n" DEFAULT,
				expected,
				result);
		return (0);
	}
	// Delete the output file
	remove("output.txt");
}
