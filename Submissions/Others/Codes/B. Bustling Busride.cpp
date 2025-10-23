#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
#define int long long

struct custom_hash {
  static uint64_t splitmix64(uint64_t x) {
    // http://xorshift.di.unimi.it/splitmix64.c
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }

  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};

const int N = 1e5 + 9;
int n, stop, interval, w;
int time_need[N], nambe[N], pref[N];

struct ST {
  pair<int, int> tree[4 * N];
  void build(int n, int b, int e) {
    if(b == e) {
      tree[n] = {0, 0};
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    tree[n].first = tree[l].first + tree[r].first; 
    tree[n].second = tree[l].second + tree[r].second; 
  }
  void upd(int n, int b, int e, int i, int x) {
    if(b > i || e < i) return;
    if(b == e && b == i) {
      tree[n].first += x;
      tree[n].second = 1;
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    upd(l, b, mid, i, x);
    upd(r, mid + 1, e, i, x);
    tree[n].first = tree[l].first + tree[r].first; 
    tree[n].second = tree[l].second + tree[r].second; 
  }
  void upd2(int n, int b, int e, int i, int x) {
    if(b > i || e < i) return;
    if(b == e && b == i) {
      tree[n].first = x;
      tree[n].second = x;
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    upd2(l, b, mid, i, x);
    upd2(r, mid + 1, e, i, x);
    tree[n].first = tree[l].first + tree[r].first; 
    tree[n].second = tree[l].second + tree[r].second; 
  }
  pair<int, int> query(int n, int b, int e, int i, int j) {
    if(b > j || e < i) return {0, 0};
    if(b >= i && e <= j) return tree[n];
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    pair<int, int> L = query(l, b, mid, i, j);
    pair<int, int> R = query(r, mid + 1, e, i, j);
    return {L.first + R.first, L.second + R.second};
  }
} st;

bool ok(int mx) {
  int last = 1, cnt = 0;
  st.build(1, 1, stop);
  while (last <= n) {
    if ((cnt * interval) > mx) return false;
    int here = (cnt * interval);
    int last_stop = -1;
    vector<int> v;
    gp_hash_table<int, int, custom_hash> mp;
    for (int i = last; i <= n; i++) {
      last_stop = max(last_stop, nambe[i]);
      int ami_nambo = nambe[i];
      int x = st.query(1, 1, stop, 1, ami_nambo - 1).second;
      int y = st.query(1, 1, stop, ami_nambo + 1, stop).first;
      if (mp.find(ami_nambo) != mp.end()) {
        // x = 0;
        y = 0;
      }
      mp[ami_nambo] = 1;
      int cur = w + w + (2 * x * w) + (2 * y * w) + pref[last_stop];
      int cur2 = cur + here;
      // if (cnt == 3 and i == 4) {
        // cout << cnt << ' ' << i << ' ' << ami_nambo << ' ' << cur2 << '\n';
      // }
      if (cur2 > mx) {
        if (i == last) return false;
        last = i;
        break;
      }
      if (i == n) return true;
      v.push_back(ami_nambo);
      here = cur2 - pref[last_stop];
      st.upd(1, 1, stop, ami_nambo, 1);
    }
    for (auto x : v) {
      st.upd2(1, 1, stop, x, 0);
    }
    cnt++;
  }

  return true;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> stop >> interval >> w;
  for (int i = 1; i <= stop; i++) {
    cin >> time_need[i];
    pref[i] = pref[i - 1] + time_need[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> nambe[i];
  }

  int l = 1, r = 1e14, ans = -1;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (ok(mid)) {
      ans = mid;
      r = mid - 1;
    }
    else {
      l = mid + 1;
    }
  }
  assert(ans != -1);

  cout << ans << '\n';

  // for (int i = 1; i <= 100; i++) {
  //   cout << ok(i) << '\n';
  // }
  // cout << ok(32) << '\n';

  return 0;
}