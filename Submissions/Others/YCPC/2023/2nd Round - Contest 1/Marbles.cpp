#include <bits/stdc++.h>
using namespace std;

// @author: faysalahammedchowdhury

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  int a[n];
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }

  long long prefix[n];
  memset(prefix, 0, sizeof(prefix));
  int q; cin >> q;
  while(q--) {
    int a, b, x; cin >> a >> b >> x;
    prefix[a] += x;
    if((b + 1) < n) {
      prefix[b + 1] -= x;
    }
  }

  for(int i = 1; i < n; i++) {
    prefix[i] += prefix[i - 1];
  }

  for(int i = 0; i < n; i++) {
    cout << a[i] + prefix[i] << ' ';
  }
  cout << '\n';

  return 0;
}