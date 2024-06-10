#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7, N = 1e6 + 9;
vector<bool> is_prime(N, true);
vector<int> primes;

void sieve() {
  is_prime[1] = false;
  int lim = sqrt(N + 1);
  for(int i = 2; i <= lim; i++) {
    if(is_prime[i]) {
      for(int j = i + i; j <= N; j += i) {
        is_prime[j] = false;
      }
    }
  }

  for(int i = 2; i < N; i++) {
    if(is_prime[i]) {
      primes.push_back(i);
    }
  }
}

int cs = 0;
void solve() {
  ll n; cin >> n;
  int number_of_divisors = 1;
  for(auto p: primes) {
    if(1LL * p * p > n) break;
    int power_of_p = 0;
    while(n % p == 0) {
      power_of_p++;
      n /= p;
    }
    number_of_divisors *= (power_of_p + 1);
  }
  if(n > 1) {
    int power_of_p = 1;
    number_of_divisors *= (power_of_p + 1);
  }
  cout << "Case " << ++cs << ": ";
  cout << number_of_divisors - 1 << '\n';
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  sieve();

  int t = 1;
  cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}
