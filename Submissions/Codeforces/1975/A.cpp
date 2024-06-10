#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int cnt = 0;
  for (int i = 2; i <= n; i++) {
    cnt += a[i] < a[i - 1];
  }
  if (cnt >= 2) {
    cout << "No\n";
    return;
  }

  if (cnt == 1 and a[n] > a[1]) {
    cout << "No\n";
    return;
  }

  cout << "Yes\n";
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