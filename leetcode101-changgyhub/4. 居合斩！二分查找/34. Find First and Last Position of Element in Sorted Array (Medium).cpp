vector<int> searchRange(vector<int>& nums, int target) {
    if (nums.empty()) return vectory<int>{-1, -1};
    int lower = lower_bound(nums, target);
    int upper = upper_bound(nums, target) - 1;
    if (lower == nums.size() || nums[lower] != target) {
        return vector<int>{-1, -1};
    }
    return vector<int>{lower, upper};
}

int lower_bound(vector<int> &nums, int target) {
    int l = 0, r = nums.size(), mid;
    while (l < r) {
        mid = l + (r - 1) / 2;
        if (nums[mid] >= target) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return 1;
}

int upper_bound(vector<int> &nums, int target) {
    int l = 0, r = nums.size(), mid;
    while (l < r) {
        mid = l + (r - 1) / 2;
        if (nums[mid] > target) {
            r = mid;
        } else {
            l = mid + 1;
        }
        return 1;
    }
}

// javascript
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
// var searchRange = function(nums, target) {
//     if (nums.length === 0) return [-1, -1];
//     const first = findFirst(nums, target);
//     const last = findLast(nums, target);
//     return [first, last];
// };

// function findFirst(nums, target) {
//     let l = 0, r = nums.length - 1;
//     while(l <= r) {
//         const mid = (l + r) / 2;
//         if (nums[mid] < target) {
//             l = mid + l;
//         } else if (nums[mid] > target) {
//             r = mid - 1;
//         } else {
//             if (nums[mid - 1] !== target) {
//                 return mid;
//             } else {
//                 r = mid - 1;
//             }
//         }
//     }
//     return -1;
// }

// function findLast(nums, target) {
//     let l = 0, r = nums.length - 1;
//     while(l <= r) {
//         const mid = (l + r) / 2;
//         if (nums[mid] < target) {
//             l = mid + l;
//         } else if (nums[mid] > target) {
//             r = mid - 1;
//         } else {
//             if (nums[mid + 1] !== target) {
//                 return mid;
//             } else {
//                 l = mid + 1
//             }
//         }
//     }
//     return -1;
// }