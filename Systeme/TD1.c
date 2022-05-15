# include <stdio.h>
# include <stdlib.h>

int productArrays(int* arr1, int* arr2)
{
	
}

int main()
{
	int* arr1 = (int*)malloc(sizeof(int) * 10) ,* arr2 = (int*)malloc(sizeof(int) * 10);
	
	for (int* i = arr1; scanf("%d", i) || scanf("%*s"); i++);

	int* i = arr2;
	while (scanf("%d", i)) {++i;}
	*i = -1; scanf("%*s");

	for (int* i = arr1; *i > 0; printf("%d ", *i++));

	printf("The result is: %d", productArrays(arr1, arr2));

	exit(0);
}