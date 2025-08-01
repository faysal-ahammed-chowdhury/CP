#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, open_idx, close_idx;

int query(int i, int j) {
  cout << "? 6 " << i << " " << close_idx << " " << j << " " << close_idx << " " << open_idx << " " << close_idx << endl;
  int x; cin >> x;
  return x;
}

void solve() {
  cout.flush();
  cin >> n;

  open_idx = -1, close_idx = -1;
  int l = 2, r = n;
  while (l <= r) {
    int mid = (l + r) >> 1;
    cout << "? " << mid << " ";
    for (int j = 1; j <= mid; j++) {
      cout << j << " ";
    }
    cout << endl;
    int x; cin >> x;
    if (x >= 1) {
      close_idx = mid;
      r = mid - 1;
    }
    else {
      l = mid + 1;
    }
  }

  open_idx = close_idx - 1;
  if (close_idx == -1) {
    close_idx = 1;
    open_idx = n;
  }

  string s = "";
  for (int i = 1; i + 1 <= n; i += 2) {
    int x = query(i, i + 1);
    if (x == 6) s += "((";
    else if (x == 2) s += "()";
    else if (x == 3) s += ")(";
    else if (x == 1) s += "))";
    else assert(false);
  }

  if (n & 1) {
    cout << "? 2 " << open_idx << " " << n << endl;
    int x; cin >> x;
    if (x) s += ")";
    else s += "(";
  }

  cout << "! " << s << endl;
}

int32_t main() {

  int t = 1; cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}