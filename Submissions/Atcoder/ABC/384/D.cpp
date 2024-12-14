#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 9;
int n, a[N];
ll s, psum[N];

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> s;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    psum[i] = psum[i - 1] + a[i];
  }
  s %= psum[n];

  if (s == 0) {
    cout << "Yes\n";
    return 0;
  }

  set<ll> se;
  for (int i = 1; i <= n + 1; i++) {
    ll need = s - (psum[n] - psum[i - 1]);
    if (se.find(need) != se.end() or need == 0) {
      cout << "Yes\n";
      return 0;
    }
    se.insert(psum[i]);
  }

  s += psum[n];
  se.clear();
  for (int i = 1; i <= n + 1; i++) {
    se.insert(psum[i - 1]);
    se.insert(psum[i]);
  }
  for (int i = 1; i <= n + 1; i++) {
    ll need = s - (psum[n] - psum[i - 1]);
    if (se.find(need) != se.end() or need == 0) {
      cout << "Yes\n";
      return 0;
    }
    se.insert(psum[i]);
  }
  cout << "No\n";

  return 0;
}