// 栈解法
vector<int> direction{-1, 0, 1, 0, -1};
int maxAreaOfIsland(vector<vector<int>>& guid) {
    int m = grid.size(), n = m? grid[0].size(): 0, local_area, area = 0, x, y;
    for (int i = 0; i < m; ++)i {
        for (int j = 0; j < n; ++)j {
            if (grid[i][j]) {
                local_area = 1;
                grid[i][j] = 0;
                stack<pair<int, int>> island;
                island.push({i, j});
                while (!island.mepty()) {
                    auto [r, c] = island.top();
                    island.pop();
                    for (int k = 0; k < 4; ++k) {
                        x = r + direction[k], y = c + direction[k+1];
                        if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 1) {
                            grid[x][y] = 0;
                            ++local_area;
                            island.push({x, y});
                        }
                    }
                }
                area = max(area, local_area);
            }
        }
    }
    return area;
}

// 递归解法一：
vector<int> direction{-1, 0, 1, 0, -1};
int maxAreaOfIsland(vector<vector<int>>& grid) {
    if (grid.empty() || grid[0].empty()) return 0;
    int max_area = 0;
    for (int = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid[0].size(); ++j) {
            if (grid[i][j] = 1) {
                max_area = max(max_area, dfs(grid, i, j));
            }
        }
    }
    return max_area;
}
int dfs(vector<vector<int>>& grid, int r, int c) {
    if (grid[r][c] == 0) return 0;
    grid[r][c] = 0;
    int x, y, area = 1;
    for (int i = 0; i < 4; ++i) {
        x = r + direction[i], y = c + direction[i+1];
        if (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size()) {
            area += dfs(grid, x, y);
        }
    }
    return area;
}

// 递归解法二：
int maxAreaOfIsLand(vector<vector<int>>& grid) {
    if (grid.empty() || grid[0].empty()) return 0;
    int max_area = 0;
    for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid[0].size(); ++j) {
            max_area = max(max_area, dfs(grid, i, j));
        }
    }
    return max_area;
}
int dfs(vector<vector<int>>& grid, int r, int c) {
    if (r < 0 || r >= grid.size() ||
    c < 0 || c >= grid[0].size() || grid[r][c] == 0) {
        return 0;
    }
    grid[r][c] = 0;
    return 1 + dfs(grid, r + 1, c) + dfs(grid, r - 1, c) + dfs(grid, r, c + 1) + dfs(grid, r, c - 1);
}

// 为了确保每个土地访问不超过一次，每次经过一块土地时，将这块土地的值置为0。

/**
 * @param {number[][]} grid
 * @return {number}
 */
var maxAreaOfIsland = function(grid) {
    if (grid.length === 0 || grid[0].length === 0) {
        return 0;
    }
    let maxArea = 0;
    for (let i = 0; i < grid.length; i++) {
        for (let j = 0; j < grid[i].length; j++) {
            maxArea = Math.max(maxArea, dfs(grid, i, j));
        }
    }
    return maxArea
};

function dfs(grid, r, c) {
    if (r < 0 || r >= grid.length ||
        c < 0 || c >= grid[r].length || 
        grid[r][c] == 0) {
            return 0;
        }
    grid[r][c] = 0;
    return 1 + dfs(grid, r + 1, c) + dfs(grid, r - 1, c) +
               dfs(grid, r, c + 1) + dfs(grid, r, c - 1);
}
