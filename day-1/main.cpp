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

  int cur = 50;
  string s;
  int res = 0;
  while (cin >> s) {
    int v = stoi(s.substr(1))%100;
    if (s[0] == 'L') {
      cur -= v;
      if (cur < 0) {
        cur += 100;
      }
    } else {
      cur += v;
      cur %= 100;
    }

    if (cur == 0) {
      res++;
    }
  }

  cout << res << endl;

  return 0;
}