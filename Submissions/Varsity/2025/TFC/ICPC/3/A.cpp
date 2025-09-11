#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 1e5 + 9;
int n, a[N];

bool ok1() {
  bool asc = false, desc = false;
  for (int i = 2; i <= n; i++) {
    if (a[i] > a[i - 1]) {
      asc = true;
      if (desc) return false;
    }
    else {
      desc = true;
    }
  }

  return asc and desc;
}

bool ok2() {
  bool asc = false, desc = false;
  for (int i = 2; i <= n; i++) {
    if (a[i] < a[i - 1]) {
      desc = true;
      if (asc) return false;
    }
    else {
      asc = true;
    }
  }

  return asc and desc;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  if (ok1() or ok2()) cout << "YES\n";
  else cout << "NO\n";

  return 0;
}