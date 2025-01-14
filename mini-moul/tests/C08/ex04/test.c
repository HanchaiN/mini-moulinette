#include "../../../utils/constants.h"
#include "ft_stock_str.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	char				*strs[] = {"hello", "world", "this", "is", "a", "test"};
	int					size = sizeof(strs) / sizeof(char *);
	struct s_stock_str	*result = ft_strs_to_tab(size, strs);

	if (result == NULL)
	{
		printf("Error: ft_strs_to_tab returned NULL\n");
		return (1);
	}
	printf("  " GREEN CHECKMARK GREY " File was able to compile.\n" DEFAULT);
	for (int i = 0; i < size; i++)
	{
		free(result[i].copy);
	}
	free(result);

	return (0);
}


