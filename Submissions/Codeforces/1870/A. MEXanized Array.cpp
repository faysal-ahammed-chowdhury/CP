#include <bits/stdc++.h>
using namespace std;

// @author: faysalahammedchowdhury

void solve() {
  int n, k, x; cin >> n >> k >> x;
  if(n < k || x < (k - 1)) {
    cout << -1 << '\n';
    return;
  }
  int sum = (k * (k - 1)) / 2;
  int need = n - k;
  if(k == x) x--;
  sum += (need * x);
  cout << sum << '\n';
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