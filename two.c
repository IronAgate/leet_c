#include <stdio.h>
#include <stdlib.h>

int removify(int* nums, int val, int c) {
	
	int valc = 0;

	for (int i = 0; i < c; i++) {
		if (nums[i] != val) {
			nums[valc] = nums[i];
			valc++;
		}
	}
	return valc;
}

int main(int argc, char** argv) {
	
	int nums[] = {1,2,3,4,2,5,2,7,2};
	int val = 2;

	int removed = removify(nums, val, sizeof(nums)/sizeof(int));

	for (int i = 0; i < sizeof(nums)/sizeof(int); i++) {
		printf("%d, ", nums[i]);
	}
	printf("\n%d\n", removed);

	return 0;
}
