#include "../../../utils/constants.h"
#include "../../../utils/stdout_proxy.h"
#include "ft_print_reverse_alphabet.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

int	test1(void)
{
	const char	*expected_output = "zyxwvutsrqponmlkjihgfedcba";
	char		*buffer;
	int			saved_stdout;
	int			ret;

	saved_stdout = stdout_open();
	ft_print_reverse_alphabet();
	buffer = stdout_read();
	stdout_close(saved_stdout);
	ret = -1;
	if (strcmp(buffer, expected_output) != 0)
		printf("    " RED "[1] ft_print_reverse_alphabet() Expected \"%s\", got \"%s\"\n" DEFAULT, expected_output, buffer);
	else
	{
		printf("  " GREEN CHECKMARK GREY " [1] ft_print_reverse_alphabet() output \"%s\" as expected\n" DEFAULT, buffer);
		ret = 0;
	}
	free(buffer);
	return (ret);
}

int	main(void)
{
	return (test1());
}
