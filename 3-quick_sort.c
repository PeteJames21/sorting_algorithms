#include "sort.h"

/**
  * lomuto_partition - the Lomuto partition scheme
  * @array: pointer to the array to be sorted
  * @lower: lower bound of the Lomuto scheme
  * @higher: upper bound of the Lomuto scheme
  * @size: length of the array
  * Return: the result of the Lomuto partition
  */
int lomuto_partition(int *array, int lower, int higher, size_t size)
{
	int i = 0, j = 0, pivot = 0, aux = 0;

	pivot = array[higher];
	i = lower;

	for (j = lower; j < higher; ++j)
	{
		if (array[j] < pivot)
		{
			aux = array[i];
			array[i] = array[j];
			array[j] = aux;

			if (aux != array[i])
				print_array(array, size);

			++i;
		}
	}

	aux = array[i];
	array[i] = array[higher];
	array[higher] = aux;

	if (aux != array[i])
		print_array(array, size);

	return (i);
}

/**
  * _quick_sort - recursive Quick sort function (Lomuto Scheme)
  * @array: pointer to the array to be sorted
  * @lower: lower bound of the Lomuto scheme
  * @higher: upper bound of the Lomuto scheme
  * @size: length of the array
  */
void _quick_sort(int *array, int lower, int higher, size_t size)
{
	int l_p = 0;

	if (lower < higher)
	{
		l_p = lomuto_partition(array, lower, higher, size);
		_quick_sort(array, lower, l_p - 1, size);
		_quick_sort(array, l_p + 1, higher, size);
	}
}

/**
  * quick_sort - sort an array of integers using Quick sort (Lomuto Scheme)
  * @array: pointer to the array to be sorted
  * @size: length of the array
  */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	_quick_sort(array, 0, size - 1, size);
}
