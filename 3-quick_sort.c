#include "sort.h"

void swap_ints(int *a, int *b);
int lomuto_partition(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

/**
 * swap_ints - Exchange integ in arr
 * @a: 1st integ to exchange
 * @b: 2nd integ to exchange
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * lomuto_partition - Arrange subset of arr of integ coherent with
 *                    lomuto partition scheme (last unit as focal point)
 * @array: Arr of integ
 * @size: Dimension of the arr
 * @left: Beginning indicator of subset to arange
 * @right: Closing indicator of subset to arrange
 * Return: Terminal partition indicator.
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *pivot, above, below;

	pivot = array + right;
	for (above = below = left; below < right; below++)
	{
		if (array[below] < *pivot)
		{
			if (above < below)
			{
				swap_ints(array + below, array + above);
				print_array(array, size);
			}
			above++;
		}
	}

	if (array[above] > *pivot)
	{
		swap_ints(array + above, pivot);
		print_array(array, size);
	}

	return (above);
}

/**
 * lomuto_sort - Apply quicksort algorithm across recursion.
 * @array: Arr of integ to arrange
 * @size: Dimension of the arr
 * @left: Beginning indicator of arr partition to arrange
 * @right: Closing indicator of arr partition to arrange
 * Description: Applies Lomuto partition scheme
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, part - 1);
		lomuto_sort(array, size, part + 1, right);
	}
}

/**
 * quick_sort - Arrange arr of integ in progressive
 *              sequence applying quicksort algorithm
 * @array: Array of integ
 * @size: Dimension of arr
 * Description: Applies Lomuto partition scheme. Prints
 *              arr following every exchange of two units
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
