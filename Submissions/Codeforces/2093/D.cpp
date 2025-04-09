#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

int n, q;

void f(ll val) {
  ll st = 1, en = (1ll << (2 * n));
  int r1 = 1, r2 = (1ll << n), c1 = 1, c2 = (1ll << n);
  // cout << st << ' ' << en << '\n';
  while (st != en) {
    ll per = (en - st + 1) / 4;
    // cout << per << '\n';
    if (val <= st + per - 1) {
      en = st + per - 1;
      int d1 = (r2 - r1 + 1) / 2;
      r2 -= d1; 
      int d2 = (c2 - c1 + 1) / 2;
      c2 -= d2;      
    }
    else if (val <= st + per + per - 1) {
      en = st + per + per - 1;
      st = st + per;
      int d1 = (r2 - r1 + 1) / 2;
      r1 += d1; 
      int d2 = (c2 - c1 + 1) / 2;
      c1 += d2;  
    }
    else if (val <= st + per + per + per - 1) {
      // cout << "here\n";
      en = st + per + per + per - 1;
      st = st + per + per;
      int d1 = (r2 - r1 + 1) / 2;
      r1 += d1; 
      int d2 = (c2 - c1 + 1) / 2;
      c2 -= d2;  
      // cout << d1 << ' ' << d2 << '\n';
    }
    else {
      en = st + per + per + per + per - 1;
      st = st + per + per + per;
      int d1 = (r2 - r1 + 1) / 2;
      r2 -= d1; 
      int d2 = (c2 - c1 + 1) / 2;
      c1 += d2;
    }

    // cout << r1 << ' ' << r2 << '\n';
    // cout << c1 << ' ' << c2 << '\n';
  }

  cout << r1 << ' ' << c1 << '\n';

  assert(r1 == r2);
  assert(c1 == c2);
}

void f(int i, int j) {
  ll st = 1, en = (1ll << (2 * n));
  int r1 = 1, r2 = (1ll << n), c1 = 1, c2 = (1ll << n);
  // cout << st << ' ' << en << '\n';
  while (!(r1 == r2 and r1 == i and c1 == c2 and c2 == j)) {
    ll per = (en - st + 1) / 4;
    // cout << per << '\n';
    if (i >= r1 and i <= (r2 - ((r2 - r1 + 1) / 2)) and j >= c1 and j <= (c2 - ((c2 - c1 + 1) / 2))) {
      en = st + per - 1;
      int d1 = (r2 - r1 + 1) / 2;
      r2 -= d1; 
      int d2 = (c2 - c1 + 1) / 2;
      c2 -= d2;      
    }
    else if (i >= (r1 + (r2 - r1 + 1) / 2) and i <= r2 and j >= (c1 + ((c2 - c1 + 1) / 2)) and j <= c2) {
      en = st + per + per - 1;
      st = st + per;
      int d1 = (r2 - r1 + 1) / 2;
      r1 += d1; 
      int d2 = (c2 - c1 + 1) / 2;
      c1 += d2;  
    }
    else if (i >= (r1 + (r2 - r1 + 1) / 2) and i <= r2 and j >= c1 and j <= (c2 - (c2 - c1 + 1) / 2)) {
      // cout << "here\n";
      en = st + per + per + per - 1;
      st = st + per + per;
      int d1 = (r2 - r1 + 1) / 2;
      r1 += d1; 
      int d2 = (c2 - c1 + 1) / 2;
      c2 -= d2;  
      // cout << d1 << ' ' << d2 << '\n';
    }
    else {
      en = st + per + per + per + per - 1;
      st = st + per + per + per;
      int d1 = (r2 - r1 + 1) / 2;
      r2 -= d1; 
      int d2 = (c2 - c1 + 1) / 2;
      c1 += d2;
    }
  }

  cout << st << '\n';
  assert(st == en);
}

void solve() {
  cin >> n >> q;
  // f(4);
  // f(4, 3);
  while (q--) {
    string s; cin >> s;
    if (s == "->") {
      int i, j; cin >> i >> j;
      f(i, j);
    }
    else {
      int val; cin >> val;
      f(val);
    }
  }
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