#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const int MOD = 1e9 + 7;

int main() {
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);
  freopen("1.in", "r", stdin);
  freopen("1.out", "w", stdout);

  string s;

  set<pll> seg;
  
  int ans = 0;
  while (cin >> s) {
    auto f = s.find('-');
    if (f == string::npos) {
      ll cur = stoll(s);
      if (cur < seg.begin()->first) {
        continue;
      }

      auto it = seg.upper_bound({cur, LLONG_MAX}); it--;

      if (cur <= it->second) {
        ans++;
      }
    } else {
      ll start = stoll(s.substr(0, f));
      ll end = stoll(s.substr(f+1));

      if (seg.size() == 0) {
        seg.insert({start, end});
        continue;
      }

      auto it = seg.upper_bound({start, end});

      if (it != seg.begin()) {
        auto p = prev(it);
        if (p->second + 1 >= start) {
          start = p->first;
          end = max(end, p->second);
          seg.erase(p);
        }
      }

      while (it != seg.end() && it->first <= end + 1) {
        end = max(end, it->second);
        it = seg.erase(it);
      }

      seg.insert({start, end});
    }
  }

  cout << ans << endl;

  return 0;
}