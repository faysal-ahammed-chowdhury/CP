#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  ll n; cin >> n;

  if (n == 1) {
    cout << "N\n";
    return 0;
  }

  ll sq = sqrtl(n);
  while (1ll * sq * sq < n) sq++;
  while (1ll * sq * sq > n) sq--;

  if (1ll * sq * sq == n) {
    cout << "N\n";
    return 0;
  }

  vector<int> primes;
  int tmp = n;
  for (int i = 2; 1ll * i * i <= n; i++) {
    int p = i;
    while (tmp % p == 0) {
      while (tmp % p == 0) {
        tmp /= i;
      }
      primes.push_back(i);
      if (primes.size() > 2) {
        cout << "N\n";
        return 0;
      }
    }
  }
  if (tmp > 1) primes.push_back(tmp);
  if (primes.size() > 2) {
    cout << "N\n";
    return 0;
  }

  if (primes.size() == 1) {
    cout << "Y\n";
    return 0;
  }

  int p1 = primes[0], p2 = primes[1];

  // cout << n << ' ' << p1 << ' ' << p2 << ' ' << ((n / p1) / p2) << '\n';

  if (((n / p1) / p2) == 1) cout << "Y\n";
  else cout << "N\n";

  return 0;
}