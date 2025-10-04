#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 2e5 + 9;
int n, a[N];

void solve() {
  cin >> n;
  vector<int> pos[205];
  int freq[n + 1][205];
  memset(freq, 0, sizeof freq);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    pos[a[i]].push_back(i);
    for (int j = 1; j <= 200; j++) {
      freq[i][j] = freq[i - 1][j];
    }
    freq[i][a[i]]++;
  }

  int ans = 1;
  for (int i = 1; i <= n; i++) {
    int cnt1 = freq[i][a[i]];
    int j = pos[a[i]][pos[a[i]].size() - cnt1];
    if (i < j) ans = max(ans, cnt1 * 2);
    if (i + 1 <= j - 1) {
      for (int k = 1; k <= 200; k++) {
        int cnt2 = freq[j - 1][k] - freq[i][k];
        ans = max(ans, cnt1 * 2 + cnt2);
      }
    }
  }

  cout << ans << '\n';
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