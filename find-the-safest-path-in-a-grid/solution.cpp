class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        queue<pair<int,int>> q;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) {
                    dist[i][j] = 0;
                    q.push({i,j});
                }
            }
        }

        int dirs[5] = {-1,0,1,0,-1};

        while (!q.empty()) {
            auto [x,y] = q.front();
            q.pop();

            for (int k = 0; k < 4; k++) {
                int nx = x + dirs[k];
                int ny = y + dirs[k+1];

                if (nx < 0 || ny < 0 || nx >= n || ny >= n)
                    continue;

                if (dist[nx][ny] > dist[x][y] + 1) {
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx,ny});
                }
            }
        }

        auto can = [&](int val) {
            if (dist[0][0] < val || dist[n-1][n-1] < val)
                return false;

            queue<pair<int,int>> q;
            vector<vector<int>> vis(n, vector<int>(n,0));

            q.push({0,0});
            vis[0][0] = 1;

            while (!q.empty()) {
                auto [x,y] = q.front();
                q.pop();

                if (x == n-1 && y == n-1)
                    return true;

                for (int k = 0; k < 4; k++) {
                    int nx = x + dirs[k];
                    int ny = y + dirs[k+1];

                    if (nx < 0 || ny < 0 || nx >= n || ny >= n)
                        continue;

                    if (!vis[nx][ny] && dist[nx][ny] >= val) {
                        vis[nx][ny] = 1;
                        q.push({nx,ny});
                    }
                }
            }

            return false;
        };

        int lo = 0, hi = 2 * n, ans = 0;

        while (lo <= hi) {
            int mid = (lo + hi) / 2;

            if (can(mid)) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        return ans;
    }
};