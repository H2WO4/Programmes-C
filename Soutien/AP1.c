# include <stdio.h>
# include <stdbool.h>

bool isImposable(int age, char sex) {
	return sex == 'h' && age >= 20 || sex == 'f' && sex >= 18 && sex <= 35;
}

int power(int a, int b) {
	int out = 1;
	for (; b > 0; b--)
		out *= a;
	return a;
}

bool onlyNegatives(int* arr, int size) {
	for (; size > 0; size--)
		if (arr[size] >= 0)
			return false;
	return true;
}

int main() {
	return 0;
}