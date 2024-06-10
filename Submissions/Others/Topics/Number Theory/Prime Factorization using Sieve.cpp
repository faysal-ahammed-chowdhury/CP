#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 9;
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
#ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  spf_sieve();

  int n = 24;
  vector<int> prime_factors;
  while(n > 1) {
    prime_factors.push_back(spf[n]);
    n /= spf[n];
  }

  sort(prime_factors.begin(), prime_factors.end());
  for(auto i: prime_factors) {
    cout << i << ' ';
  }
  cout << '\n';
        
  return 0;
}