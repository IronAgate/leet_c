#include <stdio.h>
#include <stdlib.h> 

int setify(int* nums, int numc) {
	
	int prev = nums[0];
	int pos = 0;

	for (int i = 1; i < numc; i++) {
		
		if (nums[i] != prev) {

			prev = nums[i];
			pos++;
			nums[pos] = nums[i];

		}

	}
	return pos+1; //ERR: cant return 0 if empty / but constraints say is >=1 so
}


int main(int argc, char** argv) {

	int nums[] = {0,0,0,1,1,3,3,4,4,4,5,5,6};
	int numc = sizeof(nums)/sizeof(int);

	int uniques = setify(nums, numc);

	for (int i = 0; i < numc; i++) {

		printf("%d, ", nums[i]);

	}

	printf("\n%d\n", uniques);

	return 0;
}
