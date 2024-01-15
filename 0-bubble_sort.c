#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order with BSA
 * @array: array
 * @size: size of array
 *
 * Return: sort in ascending order
 *
 */
void bubble_sort(int *array, size_t size)
{
	void bubble_sort(int* array, size_t size)
	{
		for (size_t i = 0; i < size - 1; i++)
		{
			for (size_t j = 0; j < size - i - 1; j++)
			{
				if (array[j] > array[j + 1])
				{
					int temp = array[j];
					array[j] = array[j + 1];
					array[j + 1] = temp;

					printf("After swap: ");

					for (size_t k = 0; k < size; k++)
					{
						printf("%d ", array[k]);
					}
					printf("\n");
				}
			}
		}
	}
}
