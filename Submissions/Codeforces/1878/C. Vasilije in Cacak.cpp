#include <bits/stdc++.h>
using namespace std;

#define int long long

int get_sum(int n) {
  return (n * (n + 1)) / 2;
}

void solve() {
  int n, k, x; cin >> n >> k >> x;
  int mn = get_sum(k);
  int mx = get_sum(n) - get_sum(n - k);
  if(x >= mn && x <= mx) {
    cout << "Yes\n";
    return;
  }

  cout << "No\n";
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