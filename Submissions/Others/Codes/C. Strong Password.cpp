#include <bits/stdc++.h>
using namespace std;
#define len(x) (int) x.size();

int my_find(string s, char c, int last) {
  for (int i = last; i >= 0; i--) {
    if (s[i] == c) return i;
  }
  return -1;
}

void solve() {
  string s; cin >> s;
  int n = len(s);
  int m; cin >> m;
  string start, end; cin >> start >> end;
  int idx = n - 1;
  for (int i = 0, j = m - 1; i < m; i++, j--) {
    int x = 10000000;
    for (int c = start[j]; c <= end[j]; c++) {
      int curr = my_find(s, c, idx);
      if (curr == -1) {
        cout << "Yes\n";
        return;
      }
      x = min(x, curr);
    }
    idx = x;
    idx--;
  }
  cout << "No\n";
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}