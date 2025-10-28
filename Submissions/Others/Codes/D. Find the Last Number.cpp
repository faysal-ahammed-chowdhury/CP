#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool CHECK(int N, int pos) { return (bool)(N & (1ll << pos)); }
void SET(int &N, int pos) { (N |= (1ll << pos)); }
void CLR(int &N, int pos) { (N &= ~(1ll << pos)); }

int query(int i, int x) {
  cout << "? " << i << ' ' << x << endl;
  int val; cin >> val;
  return val;
}

void solve() {
  int n; cin >> n;

  map<pair<string, char>, int> mp;

  for (int i = 1; i <= n; i++) {
    bitset<15> bs(i);
    string s = bs.to_string();
    reverse(s.begin(), s.end());
    // cout << s << '\n';
    for (int k = 0; k < 15; k++) {
      mp[ {s.substr(0, k), s[k]}]++;
      // cout << s.substr(0, k) << ' ' << s[k] << '\n';
    }
  }

  vector<int> v;
  for (int i = 1; i < n; i++) {
    v.push_back(i);
  }

  string s = "";
  int ans = 0, k = 0;
  while (true) {
    if (v.size() == 0) break;
    vector<int> zero, one;
    int cnt0 = 0, cnt1 = 0;
    for (auto idx : v) {
      int val = query(idx, (1 << k));
      if (val) {
        one.push_back(idx);
        cnt1++;
      }
      else {
        zero.push_back(idx);
        cnt0++;
      }
    } 

    if (mp[{s, '0'}] == cnt0) {
      SET(ans, k);
      s += '1';
      v = one;
    }
    else {
      s += '0';
      v = zero;
      if (v.size() == 0) {
        if (mp[{s, '1'}] > 0) {
          SET(ans, k + 1);
        }
      }
    }
    k++;
  }

  cout << "! " << ans << endl;
}

int32_t main() {

  int t = 1; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}