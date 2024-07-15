#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX = 2e5 + 9, N = 1e5 + 9;
int cnt[MAX], tmp_cnt[MAX], a[N];

void solve() {
  int n, x; cin >> n >> x;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  vector<int> divisors;
  for (int i = 1; i * i <= x; i++) {
    if (x % i == 0) {
      divisors.push_back(i);
      if (i != (x / i)) divisors.push_back(x / i);
    }
  }
  int ans = 1;
  for (int i = 1; i <= n; i++) {
    if (x % a[i]) continue;
    if (cnt[x / a[i]]) {
      ans++;
      for (auto val : divisors) cnt[val] = 0;
      cnt[a[i]] = 1;
    }
    else {
      for (auto val : divisors) {
        if (cnt[val] and x % (1ll * val * a[i]) == 0) {
          tmp_cnt[val * a[i]] = 1;
        }
      }
      cnt[a[i]] = 1;
      for (auto val : divisors) {
        if (tmp_cnt[val]) {
          cnt[val] = 1;
          tmp_cnt[val] = 0;
        }
      }
    }
  }
  cout << ans << '\n';
  for (auto val : divisors) {
    cnt[val] = 0;
    tmp_cnt[val] = 0;
  }
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