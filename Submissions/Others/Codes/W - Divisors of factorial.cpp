#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7, N = 50000 + 9;
int spf[N];

void spf_sieve() {
  for(int i = 2; i < N; i++) {
    spf[i] = i;
  }
  for(int i = 2; i < N; i++) {
    for(int j = i; j < N; j += i) {
      spf[j] = min(spf[j], i);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  spf_sieve();
  
  int t; cin >> t;
  while(t--) {
    int n; cin >> n;
    vector<int> cnt(n + 1, 0);
    for(int i = 1; i <= n; i++) {
      int x = i;
      while(x > 1) {
        cnt[spf[x]]++;
        x /= spf[x];
      }
    }
    int ans = 1;
    for(auto e: cnt) {
      ans = 1ll * ans * (e + 1) % mod;
    }
    cout << ans << '\n';
  }

  return 0;
}