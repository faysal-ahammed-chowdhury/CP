#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, m, q; cin >> n >> m >> q;
  int a, b; cin >> a >> b;
  if (a > b) swap(a, b);
  int c; cin >> c;
  if (a <= c and c <= b) {
    cout << (b - a) / 2 << '\n'; 
  }
  else if (c <= a) {
    cout << a - 1 << '\n';
  }
  else {
    cout << n - b << '\n';
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