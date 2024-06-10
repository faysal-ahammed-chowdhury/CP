#include <bits/stdc++.h>
using namespace std;

void solve() {
  int a, b, n; cin >> a >> b >> n;
  int x = n, pw1 = 0, pw2 = 0;
  while (x % a == 0) {
    x /= a;
    pw1++;
  }
  x = n;
  while (x % b == 0) {
    x /= b;
    pw2++;
  }

  set<int> se;
  for (int j = 0; j <= pw1; j++) {
    for (int k = 0; k <= pw2; k++) {
      if (n % int(pow(a, j) * pow(b, k)) == 0) {
        se.insert(n / (pow(a, j) * pow(b, k)));
      }
    }
  }

  cout << se.size() << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}