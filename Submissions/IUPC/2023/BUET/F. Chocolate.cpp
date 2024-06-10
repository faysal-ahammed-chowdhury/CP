#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, p, q, x, y; cin >> n >> p >> q >> x >> y;
  long long cost1 = (1LL * p * n) - (x * (1LL * n * (n - 1)) / 2);
  long long cost2 = (1LL * q * n) - (y * (1LL * n * (n - 1)) / 2);
  if(cost1 <= cost2) {
    cout << cost1 << '\n';
  }
  else {
    cout << cost2 << '\n';
  }
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}