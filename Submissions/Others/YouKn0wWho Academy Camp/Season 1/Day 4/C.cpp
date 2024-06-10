#include <bits/stdc++.h>
using namespace std;

// @author: faysalahammedchowdhury

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t, cs = 0; cin >> t;
  while(t--) {
    cout << "Case #" << ++cs << ": ";
    int n; cin >> n;
    int a[n], b[n];
    for(int i = 0; i < n; i++) {
      cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
      cin >> b[i];
    }
    sort(a, a + n);
    sort(b, b + n);
    reverse(b, b + n);
    long long ans = 0;
    for(int i = 0; i < n; i++) {
      ans += 1ll * a[i] * b[i];
    }
    cout << ans << '\n';
  }

  return 0;
}