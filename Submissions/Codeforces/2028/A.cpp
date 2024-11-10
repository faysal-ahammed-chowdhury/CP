#include <bits/stdc++.h>
using namespace std;

void go(char c, int &x, int &y) {
  if (c == 'N') y++;
  else if (c == 'E') x++;
  else if (c == 'S') y--;
  else x--;
}

void solve() {
  int n, a, b; cin >> n >> a >> b;
  string s; cin >> s;
  string tmp = "";
  for (int i = 1; i <= 15; i++) {
    tmp += s;
  }
  n = tmp.size();
  int x = 0, y = 0;
  for (int i = 0; i < n; i++) {
    go(tmp[i], x, y);
    if (x == a and y == b) {
      cout << "YES\n";
      return;
    }
  }
  cout << "NO\n";
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1; cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}