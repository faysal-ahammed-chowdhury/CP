#include <bits/stdc++.h>
using namespace std;

const int N = 1e7 + 9;
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
}

int cs = 0;
void solve() {
  int n; cin >> n;  
  int ways = 0;
  for(auto i: primes) {
    int need = n - i;
    if(i <= need && is_prime[need]) {
      ways++;
    }
  }
  cout << "Case " << ++cs << ": ";
  cout << ways << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  sieve();
  for(int i = 2; i < N; i++) {
    if(is_prime[i]) primes.push_back(i);
  }

  int t = 1;
  cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}