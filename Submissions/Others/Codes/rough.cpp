#include <bits/stdc++.h>
using namespace std;

const int N = 10000000 + 9;
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

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  sieve();

  for (int i = 1; i <= 10000000; i++) {
    if (is_prime[i]) primes.push_back(i);
  }
  int n = primes.size();
  // int ans = 0;
  // for (int i = 1; i < n; i++) {
  //   ans = max(ans, primes[i] - primes[i - 1]);
  // }
  // cout << ans << '\n';
  // cout << n << '\n';
  // return 0;

  set<int> se;
  for (int i = 0; i < n; i++) {
    if (is_prime[i] > 7879) break;
    for (int j = i + 1; j < 1000; j++) {
      if (is_prime[j] > 7879) break;
      int x = primes[j] - primes[i];
      if (is_prime[x]) se.insert(x);
    }
  }
  cout << se.size() << '\n';
  for (auto x : se) {
    cout << x << ' ';
  }
  cout << '\n';

  return 0;
}