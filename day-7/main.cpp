#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MOD = 1e9 + 7;

vector<string> grid;
int ans = 0;

int main() {
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);
  freopen("1.in", "r", stdin);
  freopen("1.out", "w", stdout);

  string s;
  while (cin >> s) {
    grid.push_back(s);
  }

  set<int> places;
  places.insert(grid[0].size()/2);

  for (int i = 0; i < s.size(); i++) {
    set<int> newPlaces;
    for (int p : places) {
      if (grid[i][p] == '^') {
        newPlaces.insert(p+1);
        newPlaces.insert(p-1);
        ans++;
      } else {
        newPlaces.insert(p);
      }
    }

    places = newPlaces;
  }

  cout << ans << endl;

  return 0;
}