//leetcode 189: Rotate Array / 6/150
	//DOESNT WORK

void rotate(int* nums, int numsSize, int k) {

	char dir = 0;
	if (k*2 < numsSize) {
		k = numsSize - k;
		dir = -1;
	} else {
		dir = 1;
		k %= numsSize;
	}
	
	int buffer = 0;
	int swap = 0;
	
	int start = (numsSize-1)*(dir<0);
	int end = (numsSize-k-1)*(dir<0) + (k-1)*(dir>0);
	for (int i = start; i != end; i += dir) {
		swap = (i + k*dir) % numsSize;

		buffer = nums[swap];
		nums[swap] = nums[i];
		nums[i] = buffer;
	}

	if (numsSize % 2 && k % 2) {
		swap = (k + k*dir) % numsSize;

		buffer = nums[swap];
		nums[swap] = nums[k];
		nums[k] = buffer;
	} else {
		swap = (k - 2*dir);

		buffer = nums[swap];
		nums[swap] = nums[k-1*dir];
		nums[k-1*dir] = buffer;
	}


}
/*

thought I could swap in-place without reversing or anything, but I cant figure out a way to do it
	and evidently nobody else can either

darn, wanted to shift it while only iterating once, and being in-place
	I wonder if its even possible and I just cant find it online?

I explored a bunch of stuff, but its been hours (i didnt even notice) so imma call it here and use the reversing technique I saw abt

Good luck future me, if you're seeing this. Heres some of what I found out at the moment

	was trying to do it by swapping an index with itself+k, wrapping at end of list
	works for many cases, but some edge cases break this^
		also, unless length and k are both even, have to do something special for the last action
		
		but, if this could work somehow, can rotate w/ only iterating through 'k' elements in the list, when 'k' must be > length/2
			to ensure is big enough 'k', can allow it to go either left or right by the equivalent amt

	problem is certain odd-length arrays with 'k' length of half, +- 0.5
		for ex, cant manage to rotate by 3 or 4 with a length of 7 using this method.
		unsure which other length values this effects, but I assume there are more.

		ofc, leetcode knew to add a problem like this in the checks. I wouldnt expect any less
	
	well, gl figuring it out
*/
