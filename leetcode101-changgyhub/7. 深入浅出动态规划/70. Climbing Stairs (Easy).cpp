int climbStairs(int n) {
    if (n <= 2) return n;
    vector<int> dp(n + 1, 1);
    for (int i = 2; i <= n; ++i) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

// 空间压缩
int climbStairs(int n) {
    if (n <= 2) return n;
    int pre2 = 1, pre1 = 2, cur;
    for (int i = 2; i < n; ++i) {
        cur = pre1 + pre2;
        pre2 = pre1;
        pre1 = cur;
    }
    return cur;
}

// 动态规划保存子问题的解，避免重复计算
// 动态规划可以看成是带有状态记录（memoization）的优先搜索
// 如果要求的是最终状态，那么使用动态搜索比较方便
// 如果需要输出所有的路径，那么使用带有状态记录的优先搜索会比较方便

