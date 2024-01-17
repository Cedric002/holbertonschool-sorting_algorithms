#include "sort.h"

/**
 * partition - function that implements the lomuto partition
 * @array: array on which we want to execute the partition
 * @size: size of the array
 * @start: start index of the array
 * @end: end index of the array
 *
 * Return: the position of the pivot
*/

static int partition(int *array, size_t size, int start, int end)
{
	int pivot = array[end];
	int i = (start - 1); /*variable positionned before*/
			       /*the starting point of the array*/
	int j, temp;

	for (j = start; j <= end - 1; j++) /*use the j index to loop*/
					     /*through the array*/
	{
		if (array[j] <= pivot) /*partition condition and implementation of*/
					/* the swaping process (move smaller elements to the left)*/
		{
			i++;
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			if (i != j)
				print_array(array, size);
		}
	}
	temp = array[i + 1]; /*once index j has reached the end of the array,*/
			      /* the value it points to is being swaped with the element*/
			      /*at the right of index i : new position of the pivot*/
	array[i + 1] = array[end];
	array[end] = temp;
	if (end != (i + 1))
		print_array(array, size);

	return (i + 1); /*returns the (new) location of the pivot*/
}

/**
 * quick_sort_partionning - function that calls the partition function
 * @array: array on which we want to execute the partition
 * @size: size of the array
 * @start: start index of the array
 * @end: end index of the array
 *
 * Return: void
 */

static void quick_sort_partionning(int *array, size_t size, int start, int end)
{
	int pivot;

	if (end <= start) /*means we cannot divide the array any further:*/
			    /*no more partitionning needed thus return*/
		return;

	pivot = partition(array, size, start, end);

	quick_sort_partionning(array, size, start, pivot - 1);
	quick_sort_partionning(array, size, pivot + 1, end);
}

/**
 * quick_sort - main function that sorts an array of integers
 * @array: array on which we want to execute the partition
 * @size: size of the array
 *
 * Return: void
 */

void quick_sort(int *array, size_t size)
{
	int start = 0;
	int end = size - 1;

	if (array == NULL || size < 2)
		return;

	quick_sort_partionning(array, size, start, end);
}
