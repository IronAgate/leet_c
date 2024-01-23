//leetcode 45: Jump game 2 - 10/150
// https://leetcode.com/problems/jump-game-ii/description/?envType=study-plan-v2&envId=top-interview-150

#include <stdio.h>

int jump(int* nums, int numsSize) {


	int steps = 0;
	int checked = 0;
	
	for (int i = 0; i < numsSize-1; steps++) {
		int x = checked + 1;
		checked = nums[i]+i;
		if (checked >= numsSize-1) {
			return steps+1;
		}
		for (0; x < checked+1; x++) {
			
			i = (nums[x] + x > nums[i] + i)? x:i;


		}
	}
	return steps;
}

/*

Initial
	first, try to conceptualize moving through in same was as I did for previous
		at each index:
			if current index was reachable, see how far forwards I can go from this index and continue
			else, return t/f of this index == last index
			
			afterloop, return true 

		in hindsight, could have only done the loop up to the second to last index, then returned true if counter > 0

After
	it checks its current position and sees how far forwards it can look. Then it looks that far forwards, seeing which of those indexes can reach the furthest. Then it moves to whichever can. then increment steps and repeat
		I added a 'checked' variable so it doesnt iterate back over indexes it has already checked
		
		and an if statement after the checked set notices if the current index can already reach the end. If it can, it returns there with the appropriate step count

	Improving
		An outer while loop instead of for loop could be cleaner

		the inner for loop has a '0' for the setting line since i wasnt able to use it there. Is this bad practice or?

		technically, ig you don't really need an inner loop. I am still just iterating through it once, but I have larger overhead because of my inner loop.

->			THIS is the main thing to improve imo.
			however, i did have lower memory use than 99.84%

*/

int main(int argc, char** argv) {
	
	int nums[] = {2,3,1,1,4};
	int numsSize = sizeof(nums)/sizeof(int);

	int js = jump(nums, numsSize);

	printf("final: %d\n", js);
	return 0;
}
