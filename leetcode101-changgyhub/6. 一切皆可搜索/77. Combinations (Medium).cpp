vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> ans;
    backtracking(nums, 0, ans);
    return ans;
}

void backtracking(vector<vector<int>>& ans, vector<int>& comb, int& count, int pos, int n, int k) {
    if (count == k) {
        ans.push_back(comb);
        return;
    }
    for (int i = pos; i <= n; ++i) {
        comb[count++] = i;
        backtracking(ans, comb, count, i + 1, n, k);
        --count;
    }
}