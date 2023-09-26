#include "sort.h"
#include <stdlib.h>

/**
 * counting_sort - sort an array of integers using Counting sort
 * @array: pointer to the array of integers to be sorted
 * @size: the length of the array
 */
void counting_sort(int *array, size_t size)
{
	int *count_array, max;
	size_t i, j, j_prev;

	if (!array || size < 2)
		return;

	max = array[0];
	for (i = 0; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	count_array = calloc(max + 1, sizeof(int));
	if (!count_array)
		return;

	/* Make counts */
	for (i = 0; i < size; i++)
		count_array[array[i]]++;

	/* Compute the cumulative sum of the counts */
	for (i = 1; i < (size_t)max + 1; i++)
		count_array[i] += count_array[i - 1];
	print_array(count_array, max + 1);

	/* Sort the original array */
	for (i = 0; i < (size_t)max + 1; i++)
	{
		if (i == 0)
			j_prev = 0;
		else
			j_prev = count_array[i - 1];
		for (j = j_prev; j < (size_t)count_array[i]; j++)
			array[j] = i;
	}

	free(count_array);
}
