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

  string s;
  ll res = 0;
  while (cin >> s) {
    int curMax = 0;
    int maxIdx = 0;
    for (int i = 0; i < s.size()-1; i++) {
      if (s[i]-'0' > curMax) {
        curMax = s[i]-'0';
        maxIdx = i;
      }
    }

    int max2 = 0;
    for (int i = maxIdx+1; i < s.size(); i++) {
      max2 = max(max2, s[i] - '0');
    }

    res += (curMax * 10 + max2);
  }
  
  cout << res << endl;

  return 0;
}