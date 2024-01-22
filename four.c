//leetcode 80: remove duplicates from array 2

#include <stdio.h>
#include <stdlib.h>


int unduplify(int* nums, int numc) {
	
	int uniques = 0;
	int position = 1;

}


int main(int argc, char** argv) {
	
	int nums[] = {0,0,1,1,1,1,2,3,3,3,4};
	int c = sizeof(nums)/sizeof(int);


	int uniques = unduplify(nums, c);

	for (int i = 0; i < numc; i++) {

		printf("%d, ", nums[i]);

	}
	printf("\n%d\n", uniques);

	return 0;
}
