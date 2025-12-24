#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  ll n; cin >> n;
  if (n <= 4) {
    cout << "Yes\n";
    return;
  }
  int cnt = 0;
  while (n % 2 == 0) {
    cnt++;
    n /= 2;
  }

  if (cnt >= 2) {
    cout << "Yes\n";
    return;
  }

  if (n == 1 or n == 3) cout << "Yes\n";
  else cout << "No\n";
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