#include <bits/stdc++.h>
using namespace std;

const int N = 5e6 + 9;
int spf[N];
unsigned long long phi[N];

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

  for(int i = 2; i < N; i++) {
    int x = i, res = 1;
    while(x > 1) {
      int p = spf[x], pw = 1;
      while(x % p == 0) {
        pw *= p;
        x /= spf[x];
      }
      res *= pw - (pw / p);
    }
    phi[i] = 1LL* res * res;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  spf_sieve();
  for(int i = 1; i < N; i++) {
    phi[i] += phi[i - 1];
  }
  int t, cs= 0; cin >> t;
  while(t--) {
    int a, b; cin >> a >> b;
    cout << "Case " << ++cs << ": ";
    cout << phi[b] - phi[a - 1] << '\n';
  }

  return 0;
}