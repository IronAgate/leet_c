#include <stdio.h>
#include <stdlib.h>


int setify(int* nums, int numc) {
	
	int prev = nums[0];
	int uniquec = 1;

	for (int i = 1; i < numc; i++) {
		
		if (nums[i] != prev) {

			prev = nums[i];

			nums[uniquec] = nums[i];

			uniquec++;

		}

	}
	return uniquec;
}


int main(int argc, char** argv) {

	int nums[] = {0,0,0,2,2,5,5,5,7};
	int numc = sizeof(nums)/sizeof(int);

	int uniques = setify(nums, numc);

	for (int i = 0; i < numc; i++) {

		printf("%d, ", nums[i]);

	}

	printf("\n%d\n", uniques);

	return 0;
}
