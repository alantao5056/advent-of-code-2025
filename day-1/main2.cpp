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
    int turn = stoi(s.substr(1));
    int v = turn % 100;
    int rounds = turn / 100;
    res += rounds;

    if (s[0] == 'L') {
      cur -= v;
      if (cur == 0) res++;
      else if (cur < 0) {
        if (cur + v != 0) res++;
        cur += 100;
      }
    } else {
      cur += v;
      if (cur >= 100) res++;
      cur %= 100;
    }
  }

  cout << res << endl;

  return 0;
}