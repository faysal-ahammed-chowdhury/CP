#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll fact[20];
void prec() {
  fact[1] = 1;
  for (int i = 2; i <= 15; i++) {
    fact[i] = fact[i - 1] * i;
  }
}

int n, d;

void solve() {
  cin >> n >> d;
  cout << 1 <<  ' ';

  if (n >= 3) {
    cout << 3 << ' ';
  }
  else {
    ll x = 1ll * (fact[n] % 3) * d % 3;
    if (x % 3 == 0) cout << 3 << ' ';
  }

  if (d == 5) cout << 5 << ' ';

  if (n >= 6) {
    cout << 7 << ' ';
  }
  else {
    if (d == 7) cout << 7 << ' ';
    else {
      if (fact[n] % 6 == 0) {
        cout << 7 << ' ';
      }
    }
  }

  if (n >= 9) {
    cout << 9 << ' ';
  }
  else {
    ll x = 1ll * (fact[n] % 9) * d % 9;
    if (x % 9 == 0) cout << 9 << ' ';
  }
  cout << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  prec();

  int t = 1; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}