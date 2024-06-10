#include <bits/stdc++.h>
using namespace std;

// @author: faysalahammedchowdhury

const int N = 1e7 + 9;
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

  int t; cin >> t;
  while(t--) {
    int n; cin >> n;
    map<int, int> mp;
    for(int i = 1; i <= n; i++) {
      int x; cin >> x;
      while(x > 1) {
        mp[spf[x]]++;
        x /= spf[x];
      }
    }

    int ans = 0, cnt = 0;
    for(auto i: mp) { 
      ans += i.second / 2;
      cnt += (i.second) % 2;
    }
    ans += (cnt) / 3;
    cout << ans << '\n';
  }

  return 0;
}