#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m; cin >> n >> m;
  int a[n + 1], b[n + 1], c[n + 1];
  map<int, int> mp1, mp2, mp3;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (m % a[i] == 0) {
      mp1[m / a[i]]++;
    }
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
    mp2[b[i]]++;
  }
  for (int i = 1; i <= n; i++) {
    cin >> c[i];
    mp3[c[i]]++;
  }

  long long ans = 0;
  for (auto [x, cnt] : mp1) {
    int lim = sqrt(x + 1);
    for (int i = 1; i <= lim; i++) {
      if (x % i == 0) {
        if (mp2.find(i) != mp2.end() and mp3.find(x / i) != mp3.end()) {
          ans += 1ll * cnt * mp2[i] * mp3[x / i];
        }
        if (i != (x / i)) {
          if (mp3.find(i) != mp3.end() and mp2.find(x / i) != mp2.end()) {
            ans += 1ll * cnt * mp3[i] * mp2[x / i];
          }
        }
      }
    }
  }

  cout << ans << '\n';

  return 0;
}