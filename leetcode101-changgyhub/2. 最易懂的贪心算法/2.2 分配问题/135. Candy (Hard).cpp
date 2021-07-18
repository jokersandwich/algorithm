int candy(vector<int>& ratings) {
    int size = rating.size();
    if (size < 2) {
        return size;
    }
    vector<int> num(size, 1);
    for (int i = 1; i < size; ++i) {
        if (ratings[i] > rattings[i - 1]) {
            num[i] = num[i - 1] + 1
        }
    }
    for (int i = size - 1; i > 0; --i) {
        if (ratings[i - 1] > ratings[i]) {
            num[i - 1] = max(num[i - 1], num[i] + 1);
        }
    }
    return accumulate(num.begin(), num.end(), 0);
}

// 思路：先从左往右遍历一次数组，对左右两边都比较，对比较大的数+1。
// 然后发现只有左边的比较有效，因为左边的数在累加，右边的数始终是1。
// 所以想到要遍历两次，第一次从左往右，只和左边对比；第二次从右往左，只和右边对比。

// 细节：数组num开始填充1，而非填充0，因为每个小朋友至少发1颗糖。

// javascript
/**
 * @param {number[]} ratings
 * @return {number}
 */
// var candy = function(ratings) {
//     const length = ratings.length
//     const num = new Array(length).fill(1);

//     for (let i = 1; i < length; i++) {
//         if (ratings[i] > ratings[i - 1]) {
//             num[i] = num[i - 1] + 1;
//         }
//     }
//     for (let i = length - 1; i > 0; i--) {
//         if (ratings[i - 1] > ratings[i]) {
//             num[i - 1] = Math.max(num[i - 1], num[i] + 1);
//         }
//     }

//     let sum = 0;
//     for (i = 0; i < num.length; i++) {
//         sum += num[i]
//     }
//     return sum;
// };