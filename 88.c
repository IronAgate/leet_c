//leetcode 88 / arg names incorrect for actual submission
#include <stdio.h>
#include <stdlib.h>

int compare(const void *x, const void *y) {
	
	return (*(int*)x - *(int*)y);

}

void joinsort(int* num1, int *num2, int m, int n) {
	
	for (int i = m; i < m+n; i++) {
		
		num1[i] = num2[i-m];

	}

	qsort(num1, m+n, sizeof(int), compare);

}

int main(int argc, char** argv) {
	
	
	int num1[6] = {10,34,3,0,0,0};
	int m = 3;

	int num2[3] = {24,5,15};
	int n = 3;



	joinsort(num1,num2, m,n);

	for (int i = 0; i < m+n; i++) {
		printf("%d, ", num1[i]);
	}

	printf("\n");

	return 0;
}
