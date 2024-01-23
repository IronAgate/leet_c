//leetcode 80: remove duplicates from array 2
	//refactored to simplify

#include <stdio.h>
#include <stdlib.h>


int unduplify(int* nums, int numsSize) {

	if (numsSize <= 2) {
		return numsSize;
	}

	int pos = 2;

	for (int i = 2; i < numsSize; i++) {
		if (nums[i] != nums[pos-2]) {
			nums[pos++] = nums[i];
		}
	}

	return pos; //ERR: CANT return 0 if empty / but restraints say is >= 1
}


int main(int argc, char** argv) {
	
	int nums[] = {0,0,1,1,1,1,2,3,3,3,4};
	int c = sizeof(nums)/sizeof(int);


	int uniques = unduplify(nums, c);

	for (int i = 0; i < c; i++) {

		printf("%d, ", nums[i]);

	}
	printf("\n%d\n", uniques);

	return 0;
}
