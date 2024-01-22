//leetcode 80: remove duplicates from array 2

#include <stdio.h>
#include <stdlib.h>


int unduplify(int* nums, int numc) {
	//prolly better to have if(c<=2)return c; at start to catch edge cases
		//then run loop later so is faster for longer arrays
	int pos = 0;

	for (int i = 1; i < numc; i++) {
		if (nums[i] != nums[pos]) {

			pos++; //couldve put this in the line below
			nums[pos] = nums[i];
			
		} else if (pos==0 || nums[i] != nums[pos-1]) {
			
			pos++;
			nums[pos] = nums[i];

		}
	}

	return pos+1; //ERR: CANT return 0 if empty / but restraints say is >= 1
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
