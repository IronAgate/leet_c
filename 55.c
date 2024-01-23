//leetcode 55: Jump Game - 9/150
//https://leetcode.com/problems/jump-game/description/?envType=study-plan-v2&envId=top-interview-150

#include <stdbool.h>

bool canJump(int* nums, int numsSize) {
	
	int countdown = 0;

	for (int i = 0; i < numsSize; i++) {

		countdown--;
		if (nums[i] > countdown)
			countdown = nums[i];
		
		if (!countdown)
			return (i+1 == numsSize);
	}
	return true;

}


/*
Initially
	One way to look at it is as branching paths from each index to others, but that is not very efficient
	
	maybe increase a counter to the current index, and decrease it when going forwards? Then, if next index is larger than the count, the count can be set to that value.

Afterword
	countdown method was sound, but implementation was flawed at first. just had to reorganize some stuff conceptually

	I feel like there has to be a way to write this simpler, though
		I see someone who went backwards through it and was faster. Had fewer if checks and did more math instead
			and it makes sense that backwards could be faster since you find out sooner if there are no paths to the end
				and didnt need to de-increment counter in a way by making it all relative to position 0 in list (or position -1 since backwards)
				
				NO THIS IS WRONG was thinking about it as though could go backwards and check from those indexes whether they can be reached, but have to go forwards for that.
				still think there is a better way, know there is cuz see other ppl doing stuff, but dont know it myself.
*/

