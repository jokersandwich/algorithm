vector<int> twoSum(vector<int>& numbers, int target) {
    int l = 0, r = numbers.size() - 1, sum;
    while ( l < r) {
        sum = numbers[l] + numbers[r];
        if (sum == target) break;
        if (sum < target) ++l;
        else --r;
    }
    return vector<int>{l + 1, r + 1};
}

// javascript
/**
 * @param {number[]} numbers
 * @param {number} target
 * @return {number[]}
 */
// var twoSum = function(numbers, target) {
//     let l = 0, r = numbers.length - 1, sum;
//     while (l < r) {
//         sum = numbers[l] + numbers[r];
//         if (sum === target) break;
//         if (sum < target) {
//             l++;
//         } else {
//             r--;
//         }
//     }
//     return [l + 1, r + 1];
// };
