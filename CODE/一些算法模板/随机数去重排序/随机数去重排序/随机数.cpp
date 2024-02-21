#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdlib.h>

int main(void)
{
	srand((size_t)time(NULL));
	int arr[6] = { 0 };
	int value = 0;
	int flag = 0;
	int j;
	for (int i = 0; i < 6; i++)
	{
		value = rand() % 32 + 1;

		for (j = 0; j < flag; j++)
		{
			if (value == arr[j])
			{
				i--;
				break;
			}
		}
		if (j == flag)
		{
			arr[flag] = value;
			flag++;
		}
	}
	for (int i = 0; i < 6; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}
