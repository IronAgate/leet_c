//leetcode 189: rotate array / 6/150
	//i just wasted a lot of time trying to make my own faster solution, but I dont know if its possible to do it the way I was trying. I will use the rotating method that I've seen elsewhere.

#include <stdio.h>
#include <stdlib.h>

void printArray(int* nums, int numsSize) {
	for (int i = 0; i < numsSize; i++) {
		printf("%d, ", nums[i]);
	}
	printf("\n");

}

////////////////////////
void reverse(int* nums, int numsSize) {
	int buffer = 0;
	int partner = 0;
	for (int i = 0; i < numsSize/2.0; i++) {
		
		partner = numsSize-i-1;
		
		buffer = nums[partner];
		nums[partner] = nums[i];
		nums[i] = buffer;

	}

}

void rotate(int* nums, int numsSize, int k) {
	
	k %= numsSize;

	reverse(nums, numsSize);
	reverse(nums, k);
	reverse(nums+k, numsSize-k);
	
}
/////////////////////////////////

int main(int argc, char** argv) {
	
	int nums[] = {1,2,3,4,5,6,7};
	int numsSize = sizeof(nums)/sizeof(int);

	rotate(nums, numsSize, 3);
	
	printArray(nums, numsSize);

	return 0;
}
