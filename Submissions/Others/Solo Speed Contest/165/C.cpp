#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 9;
vector<bool> is_prime(N, true);

void sieve() {
  is_prime[1] = false;
  int lim = sqrt(N + 1);
  for (int i = 2; i <= lim; i++) {
    if (is_prime[i]) {
      for (int j = i + i; j < N; j += i) {
        is_prime[j] = false;
      }
    }
  }
}

void solve() {
  int h; cin >> h;
  if (is_prime[h]) {
    cout << 1 << '\n';
    return;
  }
  int now = 1;
  int cnt = 0;
  while (h > 0) {
    h -= now;
    cnt++;
    now *= 2;
    if (h > 0 and is_prime[h]) {
      cout << cnt + 1 << '\n';
      return;
    }
  }
  if (h == 0) cout << cnt << '\n';
  else cout << -1 << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  sieve();

  int t; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}