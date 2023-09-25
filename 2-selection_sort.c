#include "sort.h"

/**
 * selection_sort - sort an array in ascending order using selection sort
 * @array: pointer to array to be sorted
 * @size: the length of the array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min_index;
	int min, tmp;

	if (!array)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min_index = i;
		min = array[i];
		/* Look for the min value in the sublist to the right */
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < min)
			{
				min = array[j];
				min_index = j;
			}
		}
		if (min_index != i)
		{
			/* Swap array[i] with the min value */
			tmp = array[i];
			array[i] = array[min_index];
			array[min_index]  = tmp;
			print_array(array, size);
		}
	}
}
