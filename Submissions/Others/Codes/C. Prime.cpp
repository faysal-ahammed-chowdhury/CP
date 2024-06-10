#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7, N = 5e4 + 9;
vector<bool> is_prime(N, 0);

void sieve() {
  for(int i = 2; i < N; i++)
  is_prime[i] = true;
  for(int i = 2; i < N; i++) {
    if(is_prime[i]) {
      for(int j = i + i; j < N; j += i) {
        is_prime[j] = false;
      }
    }
  }
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  sieve();
  int n; cin >> n;
  vector<int> primes;
  for(int i = 0; i < n; i++) {
    if(is_prime[i]) {
      primes.push_back(i);
    }
  }
  int len = (int)primes.size();
  long long ans = 0;
  for(int i = 0; i < len; i++) {  
    for(int j = i; j < len; j++) {
      int sum = primes[i] + primes[j];
      int need = n - sum;
      if(need >= primes[j] && is_prime[need]) {
        ans++;
      }
    }
  }
  cout << ans << '\n';
        
  return 0;
}