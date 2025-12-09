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

  vector<string> arr;
  string s;
  while (cin >> s) {
    arr.push_back(s);
  }

  int N = arr.size();
  int M = arr[0].size();

  vector<vector<ll>> dp(N, vector<ll>(M));
  dp[0][M/2] = true;

  for (int i = 1; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (arr[i][j] == '^') {
        if (dp[i-1][j]) {
          dp[i][j-1] += dp[i-1][j];
          dp[i][j+1] += dp[i-1][j];
        }
      } else {
        if (dp[i-1][j]) {
          dp[i][j] += dp[i-1][j];
        }
      }
    }
  }

  ll ans = 0;
  for (int i = 0; i < M; i++) {
    ans += dp[N-1][i];
  }
  cout << ans << endl;

  return 0;
}