#include <bits/stdc++.h>
using namespace std;

// @author: faysalahammedchowdhury

#define int long long

void solve() {
  int n; cin >> n;
  int a[n], b[n];
  for(int i = 0; i < n; i++) {
    cin >> a[i];
    b[i] = abs(a[i]);
  }
  sort(a, a + n);
  sort(b, b + n);
  cout << b[n - 1] * b[n - 1] << ' ';
  cout << b[0] * b[0] << ' ';
  cout << a[n - 1] + a[n - 1] << ' ';
  cout << a[0] + a[0] << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}