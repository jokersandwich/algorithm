int maxProfit(vector<int>& prices) {
    int sell = 0, buy = INT_MIN;
    for (int i = 0; i < prices.size(); ++i) {
        buy = max(buy, -prices[i]);
        sell = max(sell, buy + prices[i]);
    }
    return sell;
}

// javascript
/**
 * @param {number[]} prices
 * @return {number}
 */
// var maxProfit = function(prices) {
//     let buy = prices[0], profit = 0;
//     for (i = 1; i < prices.length; i++) {
//         if (prices[i] < buy) {
//             buy = prices[i];
//         } else {
//             profit = Math.max(profit, prices[i] - buy)
//         }
//     }
//     return profit;
// };