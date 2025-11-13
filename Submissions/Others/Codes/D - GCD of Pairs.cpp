#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

const int N = 1e5 + 9;
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
  int a[n + 1], b[n + 1];
  int freq1[n + 1], freq2[n + 1];
  memset(freq1, 0, sizeof freq1);
  memset(freq2, 0, sizeof freq2);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    freq1[a[i]]++;
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
    freq2[b[i]]++;
  }

  int multiple1[n + 1], multiple2[n + 1];
  memset(multiple1, 0, sizeof multiple1);
  memset(multiple2, 0, sizeof multiple2);
  for (int i = 1; i <= n; i++) {
    for (int j = i; j <= n; j += i) {
      multiple1[i] += freq1[j];
      multiple2[i] += freq2[j];
    }
  }

  int ans = 0;
  int f[n + 1], g[n + 1];
  for (int i = n; i >= 1; i--) {
    f[i] = multiple1[i] * multiple2[i];
    g[i] = f[i];
    for (int j = i + i; j <= n; j += i) {
      g[i] -= g[j];
    }
    if (spf[i] == i) ans += g[i];
  }

  cout << ans << '\n';
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