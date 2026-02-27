#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e6 + 9;
int spf[N];

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


void solve() {
  int n; cin >> n;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  if (is_sorted(a + 1, a + n + 1)) {
    cout << "Bob\n";
    return;
  }

  for (int i = 1; i <= n; i++) {
    int x = a[i];
    int cnt = 0;
    while (x > 1) {
      cnt++;
      int p = spf[x];
      while (x % p == 0) {
        x /= p;
      }
    }
    if (cnt >= 2) {
      cout << "Alice\n";
      return;
    }
  }

  for (int i = 1; i <= n; i++) {
    a[i] = spf[a[i]];
  }

  if (is_sorted(a + 1, a + n + 1)) {
    cout << "Bob\n";
    return;
  }

  cout << "Alice\n";
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  spf_sieve();

  int t = 1; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}