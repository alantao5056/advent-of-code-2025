#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MOD = 1e9 + 7;

bool check(ll num) {
  int digits = floor(log10(num))+1;

  if (digits % 2 == 1) return false;

  ll temp = pow(10, digits/2);

  return (num / temp) == (num % temp);
}

bool check2(ll num) {
  int digits = floor(log10(num))+1;
  string s = to_string(num);

  for (int i = 1; i <= digits/2; i++) {
    if (digits%i != 0) continue;

    string first = s.substr(0, i);
    bool works = true;
    for (int j = i; j < digits; j+=i) {
      if (first != s.substr(j, i)) {
        works = false;
        break;
      }
    }
    if (works) return true;
  }

  return false;
}

int main() {
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);
  freopen("1.in", "r", stdin);
  freopen("1.out", "w", stdout);

  string s; cin >> s; s += ',';

  vector<pair<ll, ll>> arr;
  string cur = "";

  for (char c : s) {
    if (c == ',') {
      arr[arr.size()-1].second = stoll(cur);
      cur = "";
    } else if (c == '-') {
      arr.push_back({stoll(cur), 0});
      cur = "";
    } else {
      cur += c;
    }
  }

  ll res = 0;
  for (pair<ll, ll> p : arr) {
    for (ll i = p.first; i <= p.second; i++) {
      if (check2(i)) {
        res += i;
      }
    }
  }

  cout << res << endl;

  return 0;
}