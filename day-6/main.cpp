#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MOD = 1e9 + 7;

vector<int> pnum(string line) {
  line += " ";
  vector<int> res;
  string s = "";
  for (int i = 0; i < line.size(); i++) {
    if (line[i] != ' ') {
      s += line[i];
    } else {
      if (s.size() != 0) {
        res.push_back(stoi(s));
        s = "";
      }
    }
  }

  return res;
}

vector<char> pops(string line) {
  vector<char> res;
  for (int i = 0; i < line.size(); i++) {
    if (line[i] != ' ') {
      res.push_back(line[i]);
    }
  }

  return res;
}

int main() {
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);
  ifstream in("1.in");

  string line1;
  getline(in, line1);

  string line2;
  getline(in, line2);

  string line3;
  getline(in, line3);

  string line4;
  getline(in, line4);

  vector<int> n1 = pnum(line1);
  vector<int> n2 = pnum(line2);
  vector<int> n3 = pnum(line3);
  vector<int> n4 = pnum(line4);

  string ops;
  getline(in, ops);

  vector<char> o = pops(ops);

  ll res = 0;
  for (int i = 0; i < o.size(); i++) {
    if (o[i] == '+') {
      res += n1[i] + n2[i] + n3[i] + n4[i];
    } else if (o[i] == '*') {
      res += (ll) n1[i] * (ll)n2[i] * (ll)n3[i] * (ll)n4[i];
    }
  }

  cout << res << endl;

  return 0;
}