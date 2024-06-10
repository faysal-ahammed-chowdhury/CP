#include <bits/stdc++.h>
using namespace std;

// @author: faysalahammedchowdhury

bool is_sorted(int a[], int n) {
  for(int i = 0; i + 1 < n; i++) {
    if(a[i] >= a[i + 1]) return false;
  }
  return true;
}

void solve() {
  int n; cin >> n;
  int a[n];
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  if(!is_sorted(a, a + n)) {
    cout << "1\n";
    return;
  }

  int idx = -1;
  for(int i = n - 1; i > 0; i--) {
    if(a[i] - a[i - 1] != 1) {
      idx = i;
      break;
    }
  }
  cout << (idx == -1 ? n : n - idx) << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}