#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MOD = 1e9 + 7;

int main() {
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);
  freopen("1.in", "r", stdin);
  freopen("1.out", "w", stdout);

  vector<string> grid;
  string s;
  while (cin >> s) {
    grid.push_back(s);
  }

  int N = grid.size();
  int M = grid[0].size();
  vector<vector<int>> adj(N, vector<int>(M));
  queue<pii> rem;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (grid[i][j] == '.') continue;
      int cnt = 0;
      for (int ii = -1; ii < 2; ii++) {
        for (int jj = -1; jj < 2; jj++) {
          int ni = i + ii;
          int nj = j + jj;

          if (ni > -1 && ni < N && nj > -1 && nj < M && grid[ni][nj] == '@') {
            cnt++;
          }
        }
      }

      adj[i][j] = cnt;
      if (cnt <= 4) {
        rem.push({i, j});
      }
    }
  }

  int ans = 0;
  while (!rem.empty()) {
    pii cur = rem.front(); rem.pop();
    ans++;

    for (int ii = -1; ii < 2; ii++) {
      for (int jj = -1; jj < 2; jj++) {
        int ni = cur.first + ii;
        int nj = cur.second + jj;
        if (ni > -1 && ni < N && nj > -1 && nj < M && grid[ni][nj] == '@') {
          adj[ni][nj]--;
          if (adj[ni][nj] == 4) {
            rem.push({ni, nj});
          }
        }
      }
    }
  }

  cout << ans << endl;

  return 0;
}