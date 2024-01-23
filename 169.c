// leetcode 169 find majority element 5/150

#include <stdio.h>
#include <stdlib.h>
//#include <math.h>

int sortNondescending(const void* a, const void* b) {
	return *(int*)a - *(int*)b;
}

int fptp(int* nums, int numsSize) {

	qsort(nums, numsSize, sizeof(int), sortNondescending);

	return nums[numsSize/2];

}

int main(int argc, char** argv) {

	int nums[] = {4,4,4,2,3,6,2,4,4};
	int numsSize = sizeof(nums)/sizeof(int);

	int president = fptp(nums, numsSize);

	printf("\n%d\n", president);

	return 0;
}
