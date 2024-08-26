#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  int a[n + 1];
  for (int i =  1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1);
  int half = n / 2;
  half++;
  cout << a[half] << '\n';
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