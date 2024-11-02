#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, k; cin >> n >> k;
  int freq[k + 1];
  memset(freq, 0, sizeof freq);
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    freq[x]++;
  }
  ull ans = 1;
  for (int i = 1; i <= k; i++) {
    if (freq[i] > 0) ans *= (1ll << freq[i]) - 1;
  }
  cout << ans << '\n';

  return 0;
}