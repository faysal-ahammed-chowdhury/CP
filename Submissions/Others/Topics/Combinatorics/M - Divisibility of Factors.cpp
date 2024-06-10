#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 105;
vector<bool> is_prime(N, true);

void sieve() {
  is_prime[1] = false;
  int lim = sqrt(N + 1);
  for (int i = 2; i <= lim; i++) {
    if (is_prime[i]) {
      for (int j = i + i; j <= N; j += i) {
        is_prime[j] = false;
      }
    }
  }
}

int legendre(int n, int p) {
  int ex = 0;
  while (n) {
    ex += (n / p);
    n /= p;
  }
  return ex;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  sieve();

  int n, d;
  while (cin >> n >> d and !(n == 0 and d == 0)) {
    map<int, int> pf, pf2;
    for (int i = 1; i <= n; i++) {
      if (is_prime[i]) {
        int ex = legendre(n, i);
        pf[i] = ex;
      }
    }

    for (int i = 2; i * i <= d; i++) {
      while (d % i == 0) {
        pf2[i]++;
        d /= i;
      }
    }
    if (d > 1) pf2[d]++;

    bool done = false;
    for (auto [p, pw] : pf2) {
      if (pf.find(p) == pf.end() or pf[p] < pw) {
        done = true;
        cout << 0 << '\n';
        break;
      }
    }
    if (done) continue;
    int ans = 1;
    for (auto [p, pw] : pf) {
      if (pf2.find(p) == pf2.end()) {
        ans *= (pw + 1);
      }
      else {
        ans *= pw - pf2[p] + 1;
      }
    }
    cout << ans << '\n';
  }

  return 0;
}