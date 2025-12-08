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
  int ans = 0;
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
      if (cnt <= 4) ans++;
    }
  }

  cout << ans << endl;

  return 0;
}