int findKthLargest(vector<int>& nums, int k) {
    int l = 0, r = nums.size() - 1, target = nums.size() - k;
    while(l < r) {
        int mid = quickSelection(nums, l, r);
        if (mid == target) {
            return nums[mid];
        }
        if (mid < target) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return nums[l];
}

int quickSelection(vector<int>& nums, int l, int r) {
    int i = l + 1, j = r;
    while (true) {
        while (i < r && nums[i] <= nums[.l]) {
            ++i;
        }
        while (l < j && nums[j] >= nums[l]) {
            --j;
        }
        if (i >= j) {
            break;
        }
        swap(nums[i], nums[j]);
    }
    swap(nums[l], nums[j]);
    return j;
}

// 思路：怎么把冗余的部分节约下来。
// 基础解法。首先有一个基础解法，快速排序。
// 信息冗余。然后题目只需要知道第k大的数字，而快排可以知道所有位置的数字，所以快排信息冗余。
// 操作冗余。每一次切分后，快排会对两边都排序，但是这里只需要对k所在的一边排序，所以快排操作冗余。

// *冗余信息和冗余操作，是可以优化速度的一个点。


