#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n, m; cin >> n >> m;
  int a[m + 1];
  for (int i = 1; i <= m; i++) {
    cin >> a[i];
  }

  for (int i = 1; i + 1 <= m; i++) {
    if (a[i] >= a[i + 1]) {
      cout << 1 << '\n';
      return;
    }
  }

  int last = a[m];
  cout << n - last + 1 << '\n';
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