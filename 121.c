//leetcode 121: Best time to buy and sell stock - 7/150

int maxProfit(int *prices, int pricesSize) {

	int maxSell = prices[pricesSize-1];
	int maxProfit = 0;

	for (int i = pricesSize-1; i >= 0; i--) {
		
		if (prices[i] > maxSell) 
			maxSell = prices[i];

		if (maxSell - prices[i] > maxProfit)
			maxProfit = maxSell - prices[i];
			
	}

	return maxProfit;

}

/*

Initial Thoughts
	Was thinking this seemed to easy. I could just track the max/min and subtract.
	BUT I didn't consider the real-world consideration of the date. I cant buy low and sell high if high is before low.

Wip
	now thoughts are checking each subsequent-price for each price, but that is exponential time
		how else can I do it?

	what if I go backwards??
		that was one way to do it

To Improve:
	A lot of other ppl seemed to get faster scores, although leetcode performance measures are famously inaccurate
	still, my solution feels pretty rudimentary. I wonder what other fancy tricks there are here.

	I seem to have overthought it, going backwards is unnecessary.
		You can just log the lowest prices so far & the maxprofit, rather than maxSell and maxProfit
			ofc, Im stupid
	
	Not quite sure why the faster ones are faster
		Maybe has to do with using the ternary operator?
		some of the very fastest use fancy compiler tricks, so I see why that would help.
*/

int maxProfit(int *prices, int pricesSize) {

	int maxSell = prices[pricesSize-1];
	int maxProfit = 0;

	for (int i = pricesSize-1; i >= 0; i--) {
		
		maxSell = (prices[i] > maxSell)? prices[i] : maxSell;

		maxProfit = (maxSell - prices[i] > maxProfit)? maxSell - prices[i] : maxProfit;
			
	}

	return maxProfit;

}

/*
The ternary expressions dont seem to be any faster, and I dont see why they would be? again, not using exactly the most accurate measuring tool here, either, so idk. Maybe just abt compiler manipulation and reducing how often I perform calculations, like how maxSell-Prices[i] is done twice.
*/
