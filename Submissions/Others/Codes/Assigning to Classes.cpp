#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  int x = n + n;
  int a[x + 1];
  for (int i = 1; i <= x; i++) {
    cin >> a[i];
  } 
  sort(a + 1, a + x + 1);
  int mid = n;
  cout << abs(a[mid] - a[mid + 1]) << '\n';
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