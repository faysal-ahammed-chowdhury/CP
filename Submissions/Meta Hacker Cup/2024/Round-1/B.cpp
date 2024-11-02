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

int cs;
void solve() {
  int n; cin >> n;
  cout << "Case #" << ++cs << ": "; 
  if (n < 5) {
    cout << 0 << '\n';
    return;
  }
  int ans = 1;
  for (int i = 2; i < primes.size(); i++) {
    if (primes[i] > n) break;
    if (is_prime[primes[i] - 2]) {
      ans++;
    }
  }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  sieve();

  for (int i = 1; i <= 10000000; i++) {
    if (is_prime[i]) primes.push_back(i);
  }

  int t; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}