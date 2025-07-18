#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n, k; cin >> n >> k;
  int a[n + 1];
  a[0] = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    a[i] += a[i - 1];
  }

  int ans = 0;
  for (int i = 1; i + k - 1 <= n; i++) {
    int j = i + k - 1;
    if (a[j] - a[i - 1] == 0) {
      ans++;
      i = j + 1;
    }
  }

  cout << ans << '\n';
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