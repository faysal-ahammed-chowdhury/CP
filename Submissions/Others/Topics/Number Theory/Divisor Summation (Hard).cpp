#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int N = 1e8 + 9;
vector<bool> is_prime(N, true);
vector<int> primes;

void sieve() {
  is_prime[1] = false;
  for(int i = 2; 1LL * i * i < N; i++) {
    if(is_prime[i]) {
      for(int j = i * i; j < N; j += i) {
        is_prime[j] = false;
      }
    }
  }

  primes.push_back(2);
  for(int i = 3; i < N; i += 2) {
    if(is_prime[i]) {
      primes.push_back(i);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  sieve();

  int t; cin >> t;
  while(t--) {
    ll n; cin >> n;
    ll sum = 1, x = n;
    for(ll i: primes) {
      if(1LL * i * i > x) break;
      ll p = i, pw = p;
      while(x % i == 0) {
        pw *= p;
        x /= p;
      }
      sum *= (pw - 1) / (p - 1);
    }
    if(x > 1) {
      ll p = x, pw = x * x;
      sum *= (pw - 1) / (p - 1);
    }

    cout << sum - n << '\n';
  }

  return 0;
}