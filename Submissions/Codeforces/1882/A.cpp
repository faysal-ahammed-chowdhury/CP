#include <bits/stdc++.h>
using namespace std;

// @author: faysalahammedchowdhury

void solve() {
  int n; cin >> n;
  int a[n], b[n];
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int val = 1;
  for(int i = 0; i < n; i++) {
    if(a[i] == val) {
      val++;
    }
    b[i] = val++;
  }

  cout << b[n - 1] << '\n';
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