#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

void solve() {
  int n; cin >> n;
  int a[n + 1], L[n + 1], R[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> L[i] >> R[i];
  }

  for (int i = 1; i <= n; i++) {
    if (i > 1) {
      L[i] = max(L[i], L[i - 1]);
      if (R[i] < L[i]) {
        cout << -1 << '\n';
        return;
      }
    }
  }

  for (int i = n; i >= 1; i--) {
    if (i < n) {
      L[i] = max(L[i], L[i + 1] - 1);
      if (R[i] < L[i]) {
        cout << -1 << '\n';
        return;
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    if (i > 1) {
      R[i] = min(R[i], R[i - 1] + 1);
      if (R[i] < L[i]) {
        cout << -1 << '\n';
        return;
      }
    }
  }

  for (int i = n; i >= 1; i--) {
    if (i < n) {
      R[i] = min(R[i], R[i + 1]);
      if (R[i] < L[i]) {
        cout << -1 << '\n';
        return;
      }
    }
  }

  stack<int> st;

  int must = 0, free = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] == -1) {
      free++;
      st.push(i);
    }
    else if (a[i] == 1) must++;

    if (must > R[i]) {
      cout << -1 << '\n';
      return;
    }
    if (must + free < L[i]) {
      cout << -1 << '\n';
      return;
    }

    if (must >= L[i]) {
      // no problem
    }
    else if (must + free >= L[i]) {
      int need = L[i] - must;
      must += need;
      free -= need;
      for (int j = 1; j <= need; j++) {
        int top = st.top(); st.pop();
        a[top] = 1;
      }
    }
  }

  bool ok = true;
  int cur = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] == -1) a[i] = 0;
    cur += a[i];
    ok &= cur >= L[i] and cur <= R[i];
  }
  if (!ok) {
    cout << -1 << '\n';
    return;
  }
  // cout << 1 << '\n';
  for (int i = 1; i <= n; i++) {
    cout << a[i] << ' ';
  }
  cout << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}