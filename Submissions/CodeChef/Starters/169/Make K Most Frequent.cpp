#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, k; cin >> n >> k;
  int a[n + 1], freq[25], pref[n + 1][25], suff[n + 2][25];
  memset(freq, 0, sizeof freq);
  memset(pref, 0, sizeof pref);
  memset(suff, 0, sizeof suff);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    freq[a[i]]++;
  }

  int mx = 0;
  for (int i = 1; i <= 20; i++) {
    mx = max(mx, freq[i]);
  }

  if (freq[k] == mx) {
    cout << "0\n";
    return;
  }

  for (int i = 1; i <= n; i++) {
    pref[i][a[i]] = 1;
    for (int j = 1; j <= 20; j++) {
      pref[i][j] += pref[i - 1][j];
    }
  }

  for (int i = n; i >= 1; i--) {
    suff[i][a[i]] = 1;
    for (int j = 1; j <= 20; j++) {
      suff[i][j] += suff[i + 1][j];
    }
  }

  for (int i = 1; i <= n; i++) {
    int mx = 0;
    for (int j = 1; j <= 20; j++) {
      mx = max(mx, pref[i][j]);
    }
    if (mx == pref[i][k]) {
      cout << "1\n";
      return;
    }
  }

  for (int i = n; i >= 1; i--) {
    int mx = 0;
    for (int j = 1; j <= 20; j++) {
      mx = max(mx, suff[i][j]);
    }
    if (mx == suff[i][k]) {
      cout << "1\n";
      return;
    }
  }

  cout << "2\n";
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