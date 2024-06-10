#include <bits/stdc++.h>
using namespace std;

// @author: faysalahammedchowdhury

#define ll long long

void solve() {
  ll n, x; cin >> n >> x;
  if(__lg(x) > __lg(n)) {
    cout << -1 << '\n';
    return;
  }
  ll m = n;
  int pos = -1;
  for(int k = 0; k < 64; k++) {
    if((n & (1ll << k)) && (x & (1ll << k)) == 0) {
      m -= (1ll << k);
      pos = k;
    }
    if((n & (1ll << k)) == 0 && (x & (1ll << k))) {
      cout << -1 << '\n';
      return;
    }
  }
  if(pos != -1) {
    for(int k = pos; k < 64; k++) {
      if((n & (1ll << k)) == 0) {
        m += (1ll << k);
        break;
      }
    }
  }
  for(int k = 0; k < 64; k++) {
    if((x & (1ll << k))) {
      ll new_x = m;
      new_x -= (1ll << k);
      if(new_x >= n && new_x <= m) {
        cout << -1 << '\n';
        return;
      }
    }
  }
  cout << m << '\n';
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