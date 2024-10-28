#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n; cin >> n;

  if (n == 1) {
    cout << "1 1\n";
    cout << "1 1 1\n";
    return;
  }

  ll sum = 0;
  for (int i = 1; i <= n; i++) {
    sum += 1ll * i * ((i * 2) - 1);
  }

  cout << sum << ' ' << n + n << '\n';
  for (int i = n; i >= 1; i--) {
    cout << 2 << ' ' << i << ' ';
    for (int j = 1; j <= n; j++) {
      cout << j << ' ';
    }
    cout << '\n';
    cout << 1 << ' ' << i << ' ';
    for (int j = 1; j <= n; j++) {
      cout << j << ' ';
    }
    cout << '\n';
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