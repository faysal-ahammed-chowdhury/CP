#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int inf = 1e9 + 9;

void solve() {
  int n, k; cin >> n >> k;
  int a[n + 1], pref[n + 1], suff[n + 2];
  memset(pref, 0, sizeof pref);
  memset(suff, 0, sizeof suff);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    pref[i] += pref[i - 1] + (a[i] <= k ? 1 : -1);
    // cout << pref[i]  << ' ';
  }
  // cout << '\n';

  suff[n + 1] = 0;
  for (int i = n; i >= 1; i--) {
    suff[i] += suff[i + 1] + (a[i] <= k ? 1 : -1);
    // cout << suff[i] << ' ';
  }
  // cout << '\n';

  int idx1 = inf, idx2 = inf;
  for (int i = 1; i <= n; i++) {
    if (pref[i] >= 0) {
      idx1 = i;
      break;
    }
  }
  for (int i = n; i >= 1; i--) {
    if (suff[i] >= 0) {
      idx2 = i;
      break;
    }
  }

  // cout << idx1 << ' ' << idx2 << '\n';

  if (max(idx1, idx2) < inf and idx2 - idx1 > 1) {
    cout << "Yes\n";
    return;
  }

  set<int> se;
  for (int i = 2; i < n; i++) {
    if ((a[i] <= k or se.find(pref[i]) != se.end()) and pref[n] - pref[i] >= 0) {
      cout << "Yes\n";
      return;
    }
    se.insert(pref[i]);
  }

  reverse(a + 1, a + n + 1);
  memset(pref, 0, sizeof pref);
  for (int i = 1; i <= n; i++) {
    pref[i] += pref[i - 1] + (a[i] <= k ? 1 : -1);
    // cout << pref[i] << ' ';
  }
  // cout << '\n';
  se.clear();
  for (int i = 2; i < n; i++) {
    if ((a[i] <= k or se.find(pref[i]) != se.end()) and pref[n] - pref[i] >= 0) {
      cout << "Yes\n";
      // cout << i << ' ' << pref[n] << ' ' << pref[i] << '\n';
      return;
    }
    se.insert(pref[i]);
  }

  cout << "No\n";
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