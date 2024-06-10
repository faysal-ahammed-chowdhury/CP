#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll MAX = 1e10;
const int K = 1e4 + 9, N = 1e5 + 9;
vector<ll> factor[K];
int spf[N];

void spf_sieve() {
  for(int i = 2; i < N; i++) {
    spf[i] = i;
  }
  for(int i = 2; i < N; i++) {
    if(spf[i] == i) {
      for(int j = i; j < N; j += i) {
        spf[j] = min(spf[j], i);
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  spf_sieve();

  for(int i = 1; 1LL * i * i <= MAX; i++) {
    int x = i, number_of_divisors = 1;
    while(x > 1) {
      int p = spf[x], ex = 0;
      while(x % p == 0) {
        ex++;
        x /= p;
      }
      number_of_divisors *= (2 * ex + 1);
    }
    if(number_of_divisors > 1 && number_of_divisors < 10000) {
      factor[number_of_divisors].push_back(1LL * i * i);
    }
  }

  int t; cin >> t;
  while(t--) {
    int k; ll l, r; cin >> k >> l >> r;
    int ans = upper_bound(factor[k].begin(), factor[k].end(), r) - lower_bound(factor[k].begin(), factor[k].end(), l);
    cout << ans << '\n';
  }

  return 0;
}