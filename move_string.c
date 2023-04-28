#include "shell.h"

/**
 *n_length - a function for number
 *@nth: the number
 * Return: returns digit count
 */

int n_length(int nth)
{
	int sum, number = nth;

	for (sum = 0; number > 9 || number < -9; sum++)
	{
		sum /= 10;
	}
	return (sum);
}


/**
 *integ_string - change integer to string
 *@nm: the integer
 * Return: returns the int as a string. returns NULL if failed
 */

char *integ_string(int nm)
{
	int snet, numbers;
	int j = 0, q = 0;
	int y;
	char *result;

	numbers = nm;
	snet = 1;
	if (nm < 0)
		q = 1;
	result = malloc(sizeof(char) * (n_length(numbers) + 2 + q));
	if (result == NULL)
		return (NULL);
	if (nm < 0)
	{
		result[j] = '-';
		j++;
	}
	for (y = 0; numbers > 9 || numbers < -9; y++)
	{
		numbers	/= 10;
		snet *= 10;
	}
	for (numbers = nm; y >= 0; y--)
	{
		if (numbers < 0)
		{
			result[j] = (numbers / snet) * -1 + '0';
			j++;
		}
		else
		{
			result[j] = (numbers / snet) + '0';
			j++;
		}
		numbers %= snet;
		snet /= 10;
	}
	result[j] = '\0';
	return (result);
}
