//leetcode 169 majority element
//	follow-up: linear time + 0(1) space
//		I researched these terms for this, but I think my original algorithm achieved this as well?
//		no, it wasnt. I dont know why, but ppl in comments are saying that sorting is O(nlogn)
//		this brings me back to the #1 sorting alg solution I didnt understand
//		https://leetcode.com/problems/merge-sorted-array/solutions/4207230/o-m-n-solution-backwards-approach-any-language-can-use/?envType=study-plan-v2&envId=top-interview-150
//
//	my implementation of another answer that seemed like a superior way of checking

#include <stdio.h>
//#include <stdlib.h>

int fptp(int* nums, int numsSize) {

	int candidate = nums[0];
	int voteCtr = 1;
	
	for (int i = 1; i < numsSize; i++) {

		if (voteCtr == 0) {
			candidate = nums[i];
		}

		if (nums[i] == candidate) {
			voteCtr++;
		} else {
			voteCtr--;
		}
	}
	return candidate;
	// apparently this is "Booye-Moore's" voting alg
	// to be proper, you would traverse the array a second time to verify that the candidate actually has >50%
	// 	dont need in this case
	// 	would make the alg 2*O(n) which is still 0(n)
	// also, can make it an if-else with first if, and set votectr directly, to make a bit more efficient.
		// I did that in the final submission
}

int main(int argc, char** argv) {

	int nums[] = {3,3,4,4,3,5,4,4,4};
	int numsSize = sizeof(nums)/sizeof(int);

	int president = fptp(nums, numsSize);

	printf("\n%d\n", president);

	return 0;

}
