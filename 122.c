//leetcode 122: best time to buy and sell stock 2 - 8/150
//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/?envType=study-plan-v2&envId=top-interview-150
#include <stdio.h>
#include <stdlib.h>

int maxProfit(int* prices, int pricesSize) {
	
	int heldAt = -1;
	int totalProfit = 0;

	for (int i = 0; i < pricesSize; i++) {
		if (heldAt < 0) {
			
			//force set heldAt if not holding anything (-1)

			heldAt = prices[i];

			continue;
		}

		if (prices[i] < heldAt) {
			//reduce heldAt if price goes down, but havent had chance to sell

			heldAt = prices[i];
			continue;
		}

		if (i == pricesSize-1 || prices[i] > prices[i+1]) {
			
			//sell today, buy tomorrow

			totalProfit += prices[i] - heldAt;
			heldAt = -1;

			continue;
		}

	}
	return totalProfit;
}

/*
Initial thoughts
	was confused at how to approach this without it being exponental.

	then I realized, i think any time the price drops, you wanted to sell the previous day and buy at the new lower price

	so I'm going to walk through it, from the front (?) this time, until I find a good place to buy
		then, if I've already bought something, sell whenever right-before the price drops, and begin searching to buy again (wont buy again until price is abt to rise)

		can signal if have bought or not because prices cannot be negative so can store as -1

Afterward
	My idea worked, but it was actually more complicated than necessary
	
	BECAUSE you can sell and buy again on the same day, you can just sell every time the price goes up, then immediately 'buy' (but not actually since you are just holding that value for later use) again. If it goes up the next day, you can sell. If it doesnt, you move on and didn't actually 'buy'.
		There were other ppl with examples of this, but future me, if you are reading this, I didn't include it so you would have something to improve on here yourself. You're welcome.
		also, you don't need the 'heldAt' var for this one
	
	basically, my solution didn't take into account that you can buy+sell on the same day.
*/

int main(int argc, char** argv) {
	
	int nums[] = {7,1,5,3,6,4};
	int numsSize = sizeof(nums) / sizeof(int);

	int profitability = maxProfit(nums, numsSize);

	printf("%d\n", profitability);

	return 0;
}
