#include "sort.h"

/**
 * selection_sort - sorts an array in ascending and using Selection with BSA
 * @array: array
 * @size: size of array
 *
 * Return: sort in ascending order using the Selection
 *
 */
void selection_sort(int *array, size_t size)
{
	size_t i;
	size_t j;
	size_t minIndex;
	int temp;

	if (array == NULL || size < 2)
	{
		return;
	}

	for (i = 0; i < size - 1; i++)
	{
		minIndex = i;

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[minIndex])
			{

				minIndex = j;
			}
		}

		if (minIndex != i)
		{
			temp = array[i];

			array[i] = array[minIndex];
			array[minIndex] = temp;
			print_array(array, size);
		}
	}
}
