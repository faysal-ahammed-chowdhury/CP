#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  vector<int> v;
  v.push_back(0);
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    int last = v.back();
    if (x >= 10) {
      int y = x;
      int sec = y % 10;
      y /= 10;
      int fir = y;
      if (fir >= last and fir <= sec) {
        v.push_back(fir);
        v.push_back(sec);
      }
      else {
        v.push_back(x);
      }
    } 
    else {
      v.push_back(x);
    }
  }

  if (is_sorted(v.begin(), v.end())) {
    cout << "YES\n";
  }
  else {
    cout << "NO\n";
  }
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