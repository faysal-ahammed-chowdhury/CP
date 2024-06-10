#include <bits/stdc++.h>
using namespace std;

// @author: faysalahammedchowdhury

void solve() {
  int n; cin >> n;
  int a[n];
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  reverse(a, a + n);
  int j = 1;
  for(int i = n - 1; i >= 0; i--, j++) {
    auto it = lower_bound(a, a + n, j);
    if(a[i] != (&a[n] - it)) {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}