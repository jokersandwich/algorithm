string minWindow(string S, string T) {
    vector<int> chars(128, 0);
    vector<bool> flag(128, false);
    // 先统计T中的字符情况
    for (int i = 0; i < T.size(); ++i) {
        flag[T[i]] = true;
        ++chars[T[i]];
    }
    int cnt = 0, l = 0, min_l = 0, min_size = S.size() + 1;
    for (int r = 0; r < S.size(); ++r) {
        if (flag[S[r]]) {
            if (--chars[S[r]] >= 0) {
                ++cnt;
            }
        }
        while (cnt == T.size()) {
            if (r - 1 + 1 < min_size) {
                min_1 = 1;
                min_size = r - 1 + 1;
            }
            if (flag[S[1]] && ++chars[S[1]] > 0) {
                --cnt;
            }
            ++1;
        }
    }
    return min_size > S.size() ? "" : S.substr(min_1, min_size);
}

