#include <bits/stdc++.h>
using namespace std;

bool CHECK(int N, int pos) { return (bool)(N & (1 << pos)); }
void SET(int &N, int pos) { (N |= (1 << pos)); }
void CLEAR(int &N, int pos) { (N &= ~(1 << pos)); }
const int K = 20;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1);
  vector<int> zeros[K];
  for (int k = 0; k < K; k++) {
    for (int i = 1; i <= n; i++) {
      if (!CHECK(a[i], k)) {
        zeros[k].push_back(i);
        // cout << k << ' ' << i << '\n';
      }
    }
  }

  for (int k = 0; k < K; k++) {
    for (int i = 1; i <= n; i++) {
      while (!zeros[k].empty() and zeros[k].back() <= i) {
        zeros[k].pop_back();
      }
      if (CHECK(a[i], k) and !zeros[k].empty()) {
        int idx = zeros[k].back();
        zeros[k].pop_back();
        SET(a[idx], k);
        CLEAR(a[i], k);
      }
    }
  }

  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    // cout << a[i] << ' ';
    ans += 1ll * a[i] * a[i];
  }
  cout << ans << '\n';

  return 0;
}