#include "sort.h"

/**
 * swap_ints - Exchange 2 integ in arr
 * @a: 1st integ to exchange
 * @b: 2nd integer to exchange
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * selection_sort - Arrange arr of integ in progressive sequence
 *                  applying option type algorithm
 * @array: Arr of integ
 * @size: Dimension of arr
 * Description: Prints arr following every swap
 */
void selection_sort(int *array, size_t size)
{
	int *min;
	size_t m, o;

	if (array == NULL || size < 2)
		return;

	for (m = 0; m < size - 1; m++)
	{
		min = array + m;
		for (o = m + 1; o < size; o++)
			min = (array[o] < *min) ? (array + o) : min;

		if ((array + m) != min)
		{
			swap_ints(array + m, min);
			print_array(array, size);
		}
	}
}
