#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

const int N = 2e5 + 9;
int a[N], b[N], pref_xor[N];

void solve() {
  int n; cin >> n;
  pref_xor[0] = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    pref_xor[i] = pref_xor[i - 1] ^ a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }

  int last = n;
  for (int i = n; i >= 1; i--) {
    int need = b[i] ^ pref_xor[i - 1];
    if (pref_xor[last] == need) {
      continue;
    }
    if (i + 1 <= n and (a[i] ^ a[i + 1]) == b[i]) {
      last = i + 1;
      continue;
    }

    if (a[i] == b[i]) {
      last = i;
      continue;
    }

    cout << "NO\n";
    return;
  }

  cout << "YES\n";
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1; cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}