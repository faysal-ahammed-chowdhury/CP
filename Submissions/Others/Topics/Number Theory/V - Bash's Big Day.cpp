#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;
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

  int n; cin >> n;
  map<int, int> mp;
  for(int i = 1; i <= n; i++) {
    int x; cin >> x;
    while(x > 1) {
      int p = spf[x];
      mp[p]++;
      while(x % p == 0) {
        x /= p;
      }
    }
  }
  int ans = 1;
  for(auto i: mp) {
    ans = max(ans, i.second);
  }
  cout << ans << '\n';

  return 0;
}