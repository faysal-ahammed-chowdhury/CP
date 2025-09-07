#include <bits/stdc++.h>
using namespace std;
#define int long long

using ll = long long;
using i128 = __int128;
const int N = 1e5 + 9;
vector<bool> is_prime(N, true);
vector<int> primes;

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
  int n; ll l; cin >> n >> l;

  if (n > 17) {
    cout << -1 << '\n';
    return;;
  }

  ll ans[n + 1];
  for (int i = 1; i <= n; i++) {
    i128 x = 1;
    for (int j = 0; j < n; j++) {
      if (i - 1 == j) continue;
      x *= primes[j];
      if (x > l) {
        cout << -1 << '\n';
        return;
      }
    }

    ans[i] = x;
  }

  i128 x = 1;
  for (int i = 0; i < n; i++) {
    x *= primes[i];
    if (x > l) {
      cout << -1 << '\n';
      return;
    }
  }

  for (int i = 1; i <= n; i++) {
    cout << ans[i] << ' ';
  }
  cout << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  sieve();

  for (int i = 1; i < N; i++) {
    if (is_prime[i]) {
      primes.push_back(i);
    }
  }


  int t = 1; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}