#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long

const int N = 1e5 + 9;
int n, a[N];

void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  int ans = 0;
  map<int, int> freq;
  for (int i = 1; i <= n; i++) {
    ans += (i - 1) - freq[a[i]];
    freq[a[i]]++;
  }

  bool ok = true;
  for (auto [x, cnt] : freq) {
    ok &= cnt == 1;
  }

  if (!ok) ans++;

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