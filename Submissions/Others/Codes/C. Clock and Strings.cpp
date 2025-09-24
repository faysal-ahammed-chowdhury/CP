#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
  int a, b, c, d; cin >> a >> b >> c >> d;
  if (a > b) swap(a, b);
  if (!(a <= c and c <= b) and (a <= d and d <= b)) cout << "YES\n";
  else if ((a <= c and c <= b) and !(a <= d and d <= b)) cout << "YES\n";
  else cout << "NO\n";
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