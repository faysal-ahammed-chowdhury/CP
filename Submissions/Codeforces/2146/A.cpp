#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
  int n; cin >> n;
  int freq[n + 1];
  memset(freq, 0, sizeof freq);
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    freq[x]++;
  }

  int ans = 0;
  for (int occ = 1; occ <= n; occ++) {
    int tmp = 0;
    for (int val = 1; val <= n; val++) {
      int cnt = freq[val];
      if (cnt >= occ) tmp += occ;
    }
    ans = max(ans, tmp);
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