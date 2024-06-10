#include <bits/stdc++.h>
using namespace std;

set<int> get_pf(int n) {
  set<int> pf;
  int lim = sqrt(n + 1);
  for (int i = 2; i <= lim; i++) {
    while (n % i == 0) {
      pf.insert(i);
      n /= i;
    }
  }
  if (n > 1) pf.insert(n);
  return pf;
}

bool is_prime(int n) {
  if (n == 1) return false;
  for (int i = 2; 1ll * i * i <= n; i++) {
    if (n % i == 0) return false;
  }
  return true;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  vector<int> ans;
  int k = 0;
  for (int i = 1; i + 1 <= n; i++) {
    int g = __gcd(a[i], a[i + 1]);
    ans.push_back(a[i]);
    if (g != 1) {
      set<int> pf = get_pf(a[i]);
      set<int> pf2 = get_pf(a[i + 1]);
      for (auto x : pf2) {
        pf.insert(x);
      }

      bool ok = false;
      for (int num = 2; num <= 100; num++) {
        if (is_prime(num) and pf.find(num) == pf.end()) {
          k++;
          ans.push_back(num);
          ok = true;
          break;
        }
      }

      if (!ok) {
        k += 2;
        ans.push_back(a[i] + 1);
        ans.push_back(a[i + 1] - 1);
      }
    }
  }

  ans.push_back(a[n]);

  cout << k << '\n';
  for (auto x : ans) {
    cout << x << ' ';
  }
  cout << '\n';

  return 0;
}