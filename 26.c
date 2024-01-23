//leetcode 26 / remove duplicates from array 1 / 3/150
#include <stdio.h>
#include <stdlib.h> 

int setify(int* nums, int numSize) {

	int position = 1;

	for (int i = position; i < numsSize; i++) {

		if (nums[i] != nums[position-1]) {
			nums[position] = nums[i];
			position++;
		}
	}
	return position;

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
