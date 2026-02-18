#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n; cin >> n;
  vector<int> even, odd;
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    if (x & 1) odd.push_back(x);
    else even.push_back(x);
  }

  if (odd.size() == 0) {
    for (int i = 1; i <= n; i++) {
      cout << 0 << ' ';
    }
    cout << '\n';
    return;
  }

  sort(odd.rbegin(), odd.rend());
  sort(even.rbegin(), even.rend());
  int mx_odd = odd.front();
  if (even.size() == 0) {
    for (int i = 1; i <= n; i++) {
      cout << ((i & 1) ? mx_odd : 0) << ' ';
    }
    cout << '\n';
    return;
  }

  vector<ll> pref;
  for (int i = 0; i < even.size(); i++) {
    if (i == 0) pref.push_back(even[i]);
    else pref.push_back(pref.back() + even[i]);
  }

  for (int i = 1; i <= n; i++) {
    int odd_cnt = 1;
    int even_need = (i - odd_cnt);
    if (even_need <= even.size()) {
      ll ans = even_need > 0 ? (pref[even_need - 1] + mx_odd) : mx_odd;
      cout << ans << ' ';
    }
    else {
      int even_cnt = even.size();
      int odd_need = i - even_cnt;
      if (odd_need & 1) {
        ll ans = even_cnt > 0 ? (pref[even_cnt - 1] + mx_odd) : mx_odd;
        cout << ans << ' ';
      }
      else {
        even_cnt--;
        odd_need++;
        if (odd_need <= odd.size()) {
          ll ans = even_cnt > 0 ? (pref[even_cnt - 1] + mx_odd) : mx_odd;
          cout << ans << ' ';
        }
        else cout << 0 << ' ';
      }
    }
  }
  cout << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}