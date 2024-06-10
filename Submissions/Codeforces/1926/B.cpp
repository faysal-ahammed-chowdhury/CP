#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  int cnt = 0, line = 0;
  set<int> se;
  for (int i = 1; i <= n; i++) {
    bool ok = false;
    int cnt2 = 0;
    for (int j = 1; j <= n; j++) {
      char c; cin >> c;
      int x = c - '0';
      cnt += x;
      cnt2 += x;
      ok |= x == 1;
    }
    if (cnt2) se.insert(cnt2);
    if (ok) line++;
  }

  
  int x = round(sqrt(cnt));
  if (x == line and se.size() == 1) {
    cout << "SQUARE\n";
  }
  else {
    cout << "TRIANGLE\n";
  }
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