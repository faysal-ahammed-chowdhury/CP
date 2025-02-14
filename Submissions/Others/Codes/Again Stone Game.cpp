#include <bits/stdc++.h>
using namespace std;

int f(int x) {
  if (x == 1) return 0;
  if (x % 2 == 0) return x / 2;
  return f(x / 2);
}

int cs;
void solve() {
  int n; cin >> n;
  int xr = 0;
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    xr ^= f(x);
  }
  cout << "Case " << ++cs << ": ";
  if (xr) cout << "Alice\n";
  else cout << "Bob\n";
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