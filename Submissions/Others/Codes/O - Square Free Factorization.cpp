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
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  spf_sieve();

  int t; cin >> t;
  while(t--) {
    int n; cin >> n;
    int ans = 0;
    while(n > 1) {
      int p = spf[n], ex = 0;
      while(n % p == 0) {
        ex++;
        n /= p;
      }
      ans = max(ans, ex);
    }

    cout << ans << '\n';
  }

  return 0;
}