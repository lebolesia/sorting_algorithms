#include "sort.h"

/**
 * swap_ints - Exchange 2 integ in arr.
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
 * bubble_sort - Arrange arr of integ in progressive sequence
 * @array: Arr integ to arrange
 * @size: Dimension of arr
 * Description: Prints arr following every exchange
 */
void bubble_sort(int *array, size_t size)
{
	size_t m, len = size;
	bool bubbly = false;

	if (array == NULL || size < 2)
		return;

	while (bubbly == false)
	{
		bubbly = true;
		for (m = 0; m < len - 1; m++)
		{
			if (array[m] > array[m + 1])
			{
				swap_ints(array + m, array + m + 1);
				print_array(array, size);
				bubbly = false;
			}
		}
		len--;
	}
}
