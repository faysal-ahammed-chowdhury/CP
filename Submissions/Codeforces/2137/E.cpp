#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 2e5 + 9;
int n, k, a[N], b[N], c[N];

void solve() {
  cin >> n >> k;
  map<int, int> mp;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    mp[a[i]]++;
  }

  set<int> missing_numbers;
  for (int i = 0; i <= n + 5; i++) {
    missing_numbers.insert(i);
  }

  for (int i = 1; i <= n; i++) {
    missing_numbers.erase(a[i]);
  }

  for (int i = 1; i <= n; i++) {
    if (mp[a[i]] == 1) missing_numbers.insert(a[i]);
    b[i] = *missing_numbers.begin();
    // cout << b[i] << ' ';
    if (mp[a[i]] == 1) missing_numbers.erase(a[i]);
  }

  if (k == 1) {
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
      ans += b[i];
    }
    cout << ans << '\n';
    return;
  }

  mp.clear();
  for (int i = 1; i <= n; i++) {
    mp[b[i]]++;
  }

  missing_numbers.clear();
  for (int i = 0; i <= n + 5; i++) {
    missing_numbers.insert(i);
  }

  for (int i = 1; i <= n; i++) {
    missing_numbers.erase(b[i]);
  }

  for (int i = 1; i <= n; i++) {
    if (mp[b[i]] == 1) missing_numbers.insert(b[i]);
    c[i] = *missing_numbers.begin();
    // cout << c[i] << ' ';
    if (mp[b[i]] == 1) missing_numbers.erase(b[i]);
  }

  if (k == 2) {
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
      ans += c[i];
    }
    cout << ans << '\n';
    return;
  }

  mp.clear();
  for (int i = 1; i <= n; i++) {
    mp[c[i]]++;
  }

  missing_numbers.clear();
  for (int i = 0; i <= n + 5; i++) {
    missing_numbers.insert(i);
  }

  for (int i = 1; i <= n; i++) {
    missing_numbers.erase(c[i]);
  }

  for (int i = 1; i <= n; i++) {
    if (mp[c[i]] == 1) missing_numbers.insert(c[i]);
    b[i] = *missing_numbers.begin();
    // cout << b[i] << ' ';
    if (mp[c[i]] == 1) missing_numbers.erase(c[i]);
  }

  ll ans1 = 0, ans2 = 0;
  for (int i = 1; i <= n; i++) {
    ans1 += b[i];
    ans2 += c[i];
  }

  if (k & 1) cout << ans1 << '\n';
  else cout << ans2 << '\n';
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