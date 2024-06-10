#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 2e5 + 9;
int a[N];
pair<ll, ll> pref[N];

void solve() {
  int n; cin >> n;
  for (int i = 0; i <= n; i++) {
    pref[i].first = 0;
    pref[i].second = 0;
  }
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (i & 1) {
      pref[i].first = a[i] + pref[i - 1].first;
      pref[i].second = pref[i - 1].second;
    }
    else {
      pref[i].first = pref[i - 1].first;
      pref[i].second = a[i] + pref[i - 1].second;
    }
  }

  map<ll, bool> mp;
  for (int i = 1; i <= n; i++) {
    if (pref[i].first == pref[i].second) {
      cout << "YES\n";
      return;
    }
    if (mp.find(pref[i].first - pref[i].second) != mp.end()) {
      cout << "YES\n";
      return;
    }
    mp[pref[i].first - pref[i].second] = true;
  }
  cout << "NO\n";
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