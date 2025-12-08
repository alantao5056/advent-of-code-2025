#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MOD = 1e9 + 7;

int main() {
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);
  ifstream in("1.in");

  string line1;
  getline(in, line1);
  line1 += ' ';

  string line2;
  getline(in, line2);
  line2 += ' ';

  string line3;
  getline(in, line3);
  line3 += ' ';

  string line4;
  getline(in, line4);
  line4 += ' ';

  string ops;
  getline(in, ops);
  ops += ' ';

  int i = 0;

  char op = ' ';
  ll res = 0;
  ll add = 1;

  while (i < ops.size()) {
    if (ops[i] != ' ') {
      op = ops[i];
    }

    string cur = "";

    if (line1[i] != ' ') {
      cur += line1[i];
    }
    if (line2[i] != ' ') {
      cur += line2[i];
    }
    if (line3[i] != ' ') {
      cur += line3[i];
    }
    if (line4[i] != ' ') {
      cur += line4[i];
    }

    if (cur == "") {
      // end
      if (op == '+') {
        add--;
      }

      res += add;
      add = 1;
    } else {
      if (op == '+') {
        add += stoi(cur);
      } else {
        add *= stoi(cur);
      }
    }

    i++;
  }

  cout << res << endl;

  return 0;
}