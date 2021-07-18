void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int pos = m-- + n-- - 1;
    while (m >= 0 && n >= 0) {
        nums1[pos--] = nums1[m] > nums2[n] ? nums1[m--] : nums2[n--];
    }
    while (n >= 0) {
        nums1[pos--] = nums2[n--];
    }
}


// c++版本更好，因为如果n先复制完，剩下几个m是排好序的，不需要再遍历
// javascript版本无论如何都会遍历完，可能会浪费一些操作（原地复制）
// 不过javascript版本更简单，更容易理解？

// javascript
/**
 * @param {number[]} nums1
 * @param {number} m
 * @param {number[]} nums2
 * @param {number} n
 * @return {void} Do not return anything, modify nums1 in-place instead.
 */
// var merge = function(nums1, m, nums2, n) {
//     let i = m - 1, j = n - 1, pos = m + n - 1;
//     while (pos >= 0) {
//         if (nums1[i] > nums2[j] || j < 0) {
//             nums1[pos] = nums1[i]
//             i--;
//         } else {
//             nums1[pos] = nums2[j]
//             j--;
//         }
//         pos--;
//     }
// };