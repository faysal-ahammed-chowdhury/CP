#include <bits/stdc++.h>
using namespace std;

const int N = 1e7 + 105;
int spf[N];
long long f[N];

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
  for(int i = 1; i <= n; i++) {
    int x; cin >> x;
    while(x > 1) {
      int p = spf[x];
      f[p]++;
      while(x % p == 0) {
        x /= spf[x];
      }
    }
  }

  for(int i = 2; i < N; i++) {
    f[i] += f[i - 1];
  }

  int m; cin >> m;
  while(m--) {
    int l, r; cin >> l >> r;
    l = min(l, 10000000);
    r = min(r, 10000000);
    long long ans = f[r] - f[l - 1];
    cout << ans << '\n';
  }

  return 0;
}