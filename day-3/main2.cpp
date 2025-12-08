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
  int K = 12;
  while (cin >> s) {

    set<pii> pos;
    for (int i = 0; i <= s.size() - K; i++) {
      pos.insert({'0'-s[i], i});
    }

    ll cur = 0;
    for (int i = 0; i < K; i++) {
      cur += (-pos.begin()->first) * pow(10, K-i-1);
      int idx = pos.begin()->second;

      pos.erase(pos.begin());

      while (!pos.empty() && pos.begin()->second < idx) {
        pos.erase(pos.begin());
      }
      int ins = s.size()-K+i+1;
      pos.insert({'0'-s[ins], ins});
    }

    res += cur;
  }

  cout << res << endl;
  
  return 0;
}