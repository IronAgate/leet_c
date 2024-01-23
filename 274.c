//leetcode 274: H-Index - 11/150
// https://leetcode.com/problems/h-index/description/?envType=study-plan-v2&envId=top-interview-150

#include <stdio.h>
#include <stdlib.h>

int sortNonAscending(const void* a, const void* b) {
	return *(int*)b - *(int*)a;
}

int hIndex(int* citations, int citationsSize) {
	
	qsort(citations, citationsSize, sizeof(int), sortNonAscending);

	int max = 0;
	for (int i = 0; i < citationsSize; i++) {
		if (citations[i] <= i+1) {
			return fmax(citations[i], max);
		}
		
		max = i+1;
			

	}
	return max;
}


/*

Initial
	Slowest: go through and check rest of list for each element. Dont do that

	Slow, but all i got at the moment?
		Sort the list
		then iterate backwards:
			size-indexnum == amt of papers with at least that many citations

WIP
	sort ascending so can go forwards

	now index+1 = amt of papers

	if end loop, return citationsSize. For ex: 1 paper with 5 citations, len=1, h=1

Debugging
	casted to an (*int) instead of (int*) in sortNonAscending

	forgot sizeof(int) in qsort

	error: 30615 returned 5 instead of 3
		was returning length instead  because of incorrect if statement
		also, sortNonAscending was set up wrong. was a+b instead of b-a
	
	
	Conceptual oversight:
		4400
		returns '0' instead
		(also I left the printf function in the submission oops)

		prioritizes num of citations over num of cited works
		
		[0] would return 1 / WRONG
		
		fix: track maxsofar and return that at the end
			dont have to check if citation[i] >= citedamt because place it after the check if is less
			
			AND have to return fmax(citations[i], max) in loop instead
				for one like 4400, when it hit 0, it wouldve returned citations[0], which is 0, instead of max, which was 2 at that point
		
		I still left the print statement in...
			and I got a faster time w/ it lmao

Improvement
	I got a good score memory-usage wise
	performance wise, only in top 26%
		there are a lot fo 0s, but their code examples use other techniques that are presumably faster than sorting
	
	there is some sort of wizardry afoot with allocating more memory for something instead of sorting
		not sure what this is / it gets worse memory score, but maybe thats fine here since its still low

->		on re-visit, explore this
	
	somehow, someone was able to submit without catching the 'max' thing I had to fix?
		their solution is identical to mine before fixing
		maybe the test sets changed?
		or?
	
	for neatness, somebody #define-d max() and min() with ternary. I wonder if this is faster than fmax?

*/

int main(int argc, char** argv) {
	
	int nums[] = {3,0,6,1,5};
	int numsSize = sizeof(nums)/sizeof(int);
	//65310
	int h = hIndex(nums, numsSize);

	printf("h: %d\n", h);

	return 0;
}
