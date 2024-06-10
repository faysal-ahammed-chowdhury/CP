#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cout << "YES\n";
  ll l, r; cin >> l >> r;
  for(ll i = l; i <= r; i += 2) {
    cout << i << ' ' << i + 1 << '\n';
  }

  return 0;
}
