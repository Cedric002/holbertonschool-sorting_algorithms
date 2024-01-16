#include "sort.h"

/**
 * swap - swap integer
 * @a: number one
 * @b: number two
 *
 * Return: 0
 *
 */
void swap(int *a, int *b)
{
	int t = *a;

	*a = *b;
	*b = t;
}

/**
 * partition - sorts an array in ascending and using Quick sort algorithm
 * @array: array
 * @small: smaller number
 * @big: bigger number
 *
 * Return: 0
 *
 */
int partition(int array[], int small, int big)
{
	int pivot;
	int i;
	int j;

	pivot = array[big];
	i = (small - 1);

	for (j = small; j <= big - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			swap(&array[i], &array[j]);
		}
	}
	swap(&array[i + 1], &array[big]);

	return (i + 1);
}

/**
 * quick_sort - sorts an array in ascending and using Quick sort algorithm
 * @array: array
 * @size: size of array
 *
 * Return: sort in ascending order using the Quick
 *
 */
void quick_sort(int *array, size_t size)
{
	int pi;
	// In the context of the Quick Sort algorithm,
	// pi refers to the partitioning index

	if (size > 1)
	{
		pi = partition(array, 0, size - 1);

		quick_sort(array, pi);

		quick_sort(array + pi + 1, size - pi - 1);
	}
}
