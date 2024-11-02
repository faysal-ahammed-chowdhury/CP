#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
int spf[N];
vector<array<int, 2>> a;

void spf_sieve() {
  for (int i = 2; i < N; i++) {
    spf[i] = i;
  }
  for (int i = 2; i < N; i++) {
    if (spf[i] == i) {
      for (int j = i; j < N; j += i) {
        spf[j] = min(spf[j], i);
      }
    }
  }
}

void prec() {
  for (int i = 1; i <= 1000; i++) {
    int n = i;
    int nod = 1;
    while (n > 1) {
      int p = spf[n], ex = 0;
      while (n % p == 0) {
        ex++;
        n /= p;
      }
      nod *= ex + 1;
    }
    a.push_back({nod, -i});
  }
  sort(a.begin(), a.end());
}

int cs;
void solve() {
  int n; cin >> n;
  int ans = -a[n - 1][1];
  cout << "Case " << ++cs << ": " << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  spf_sieve();
  prec();

  int t = 1; cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}