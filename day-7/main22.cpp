#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MOD = 1e9 + 7;

int main() {
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);
  // 53916299384254
  freopen("1.in", "r", stdin);
  freopen("1.out", "w", stdout);

  vector<string> arr;
  string s;
  while (cin >> s) {
    arr.push_back(s);
  }

  int N = arr.size();
  int M = arr[0].size();

  vector<ll> dp(M);
  dp[M/2] = true;

  for (int i = 1; i < N; i++) {
    vector<ll> dp2(M);
    for (int j = 0; j < M; j++) {
      if (arr[i][j] == '^') {
        dp2[j-1] += dp[j];
        dp2[j+1] += dp[j];
      } else {
        dp2[j] += dp[j];
      }
    }

    dp = dp2;
  }

  ll ans = 0;
  for (int i = 0; i < M; i++) {
    ans += dp[i];
  }
  cout << ans << endl;

  return 0;
}