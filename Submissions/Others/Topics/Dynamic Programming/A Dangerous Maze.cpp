#include <bits/stdc++.h>
using namespace std;

int cs;
void solve() {
  int n; cin >> n;
  int sum = 0, cnt = 0;
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    sum += abs(x);
    if (x < 0) cnt++;
  }

  cout << "Case " << ++cs << ": ";

  if (cnt == n) {
    cout << "inf\n";
    return;
  }

  int p = sum;
  int q = n - cnt;
  int g = __gcd(p, q);
  p /= g, q /= g;
  cout << p << '/' << q << '\n';
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