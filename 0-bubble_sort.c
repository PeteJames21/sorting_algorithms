#include "sort.h"

/**
 * bubble_sort - sort an array in ascending order using Bubble sort
 * @array: a pointer to the array to be sorted
 * @size: the length of the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i;
	int tmp, is_sorted;

	if (!array)
		return;

	while (1)
	{
		is_sorted = 1;

		for (i = 0; i < size - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				tmp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = tmp;
				is_sorted = 0;
				print_array(array, size);
			}
		}
		if (is_sorted == 1)
			break;
	}
}
