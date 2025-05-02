#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool CHECK(int N, int pos) { return (bool)(N & (1ll << pos)); }
void SET(int &N, int pos) { (N |= (1ll << pos)); }
void CLEAR(int &N, int pos) { (N &= ~(1ll << pos)); }

int query(string s, int i, int j) {
  cout << s << ' ' << i << ' ' << j << endl;
  int ans; cin >> ans;
  return ans;
}

int32_t main() {
  int n; cin >> n;
  int q1 = query("AND", 1, 2);
  int q2 = query("OR", 1, 2);
  int q3 = query("AND", 2, 3);
  int q4 = query("OR", 2, 3);
  int q5 = query("AND", 1, 3);

  int a = 0, b = 0, c = 0;

  for (int k = 0; k < 30; k++) {
    if (CHECK(q1, k) == 1) {
      SET(a, k);
      SET(b, k);
    }

    if (CHECK(q3, k)) {
      SET(b, k);
      SET(c, k);
    }
  }

  for (int k = 0; k < 30; k++) {
    if (CHECK(q3, k) == CHECK(q4, k) and CHECK(q4, k) == 0) {
      if (CHECK(q1, k) == 0 and CHECK(q2, k) == 1) {
        SET(a, k);
      }
    }
  }


  for (int k = 0; k < 30; k++) {
    if (CHECK(q1, k) == CHECK(q2, k) and CHECK(q1, k) == 0) {
      if (CHECK(q3, k) == 0 and CHECK(q4, k) == 1) {
        SET(c, k);
      }
    }
  }

  // cout << "HI" << endl;
  // cout << a << ' ' << b << ' ' << c << endl;

  for (int k = 0; k < 30; k++) {
    if (CHECK(q3, k) == 0 and CHECK(q4, k) == 1) {
      if (CHECK(q1, k) == 0 and CHECK(q2, k) == 1) {
        if (CHECK(q5, k)) {
          SET(a, k);
          SET(c, k);
        }
        else SET(b, k);
      }
    }
  }

  int ans[n + 1];
  ans[1] = a;
  ans[2] = b;
  ans[3] = c;
  for (int i = 4; i <= n; i++) {
    int x = query("XOR", 1, i);
    ans[i] = (a ^ x);
  }

  cout << "! ";
  for (int i = 1; i <= n; i++) {
    cout << ans[i] << ' ';
  }
  cout << endl;

  return 0;
}