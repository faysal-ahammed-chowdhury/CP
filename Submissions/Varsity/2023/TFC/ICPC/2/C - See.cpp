#include <bits/stdc++.h>
using namespace std;

// @author: faysalahammedchowdhury

#define int unsigned long long

const int N = 300 + 9;
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

void solve() {
  int n; cin >> n;
  map<int, int> mp1;
  map<string, int> mp2;
  long long ans = 0;
  bitset<N> b(0);
  string prime = "";
  for(int i = 0; i < N; i++) {
    prime += '0';
  }
  for(int i = 1; i <= n; i++) {
    int x; cin >> x;
    while(x > 1) {
      int p = spf[x], pw = 0;
      while(x % p == 0) {
        pw++;
        x /= spf[x];
      }
      mp1[p] += pw;
      if(mp1[p] & 1) {
        prime[p] = '1';
        b[p] = 1;
      }
      else {
        prime[p] = '0';
        b[p] = 0;
      }
    }
    if(b == 0) {
      ans++;
    }
    ans += mp2[prime];
    mp2[prime]++;
  }
  cout << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  spf_sieve();

  int t = 1;
  cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}