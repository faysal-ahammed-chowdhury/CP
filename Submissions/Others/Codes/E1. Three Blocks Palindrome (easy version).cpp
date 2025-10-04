#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
  int n; cin >> n;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int freq[n + 1][30];
  memset(freq, 0, sizeof freq);

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= 26; j++) {
      freq[i][j] = freq[i - 1][j];
    }
    freq[i][a[i]]++;
  }

  int ans = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      int cnt1 = 0;
      for (int k = 1; k <= 26; k++) {
        int tmp = freq[n][k] - freq[j - 1][k];
        cnt1 = max(cnt1, min(freq[i][k], tmp));
      }
      int cnt2 = 0;
      if (i + 1 <= j - 1) {
        for (int k = 1; k <= 26; k++) {
          int tmp = freq[j - 1][k] - freq[i][k];
          cnt2 = max(cnt2, tmp);
        }
      }
      ans = max(ans, cnt1 * 2 + cnt2);
    }
  }

  cout << ans << '\n';
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