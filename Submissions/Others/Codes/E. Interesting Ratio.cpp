#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e7 + 9;
int cnt[N];

void sieve() {
  for (int i = 2; i < N; i++) {
    if (cnt[i] == 0) {
      for (int j = i; j < N; j += i) {
        cnt[j]++;
      }
    }
  }
}

void solve() {
  int n; cin >> n;
  ll ans = 0;
  for (int i = 2; i <= n; i++) {
    ans += cnt[i];
  }
  cout << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  sieve();

  int t = 1; cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}