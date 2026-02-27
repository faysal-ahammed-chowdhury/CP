#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

const int inf = 1e18;
set<int> se;

bool flag;
bool comp(vector<int> &v1, vector<int> &v2) {
  // if (flag) {
  //   cout << "here----\n";
  // }
  int i = 0, j = 0;
  while (i < v1.size() and j < v2.size()) {
    while (i < v1.size() and se.find(v1[i]) != se.end()) {
      i++;
    }
    while (j < v2.size() and se.find(v2[j]) != se.end()) {
      j++;
    }
    // if (flag) cout << "look: " << i << ' ' << j << '\n';

    if (i < v1.size() and j < v2.size()) {
      if (v1[i] == v2[j]) {
        i++, j++;
        continue;
      }
      else {
        return v2[j] < v1[i];
      }
    }
    else {
      return j >= v2.size();
    }
  }

  return j >= v2.size();
}

void solve() {
  se.clear();
  int n; cin >> n;
  vector<int> a[n + 1];
  for (int i = 1; i <= n; i++) {
    int m; cin >> m;
    for (int j = 0; j < m; j++) {
      int x; cin >> x;
      a[i].push_back(x);
    }
    set<int> se2;
    vector<int> tmp;
    for (int j = m - 1; j >= 0; j--) {
      if (se2.find(a[i][j]) == se2.end()) tmp.push_back(a[i][j]);
      se2.insert(a[i][j]);
    }
    a[i] = tmp;
  }

  vector<int> ans;
  int it = 2;
  set<int> done;
  while (true) {
    // cout << it << '\n';
    vector<int> v = { inf};
    int idx = -1;
    for (int i = 1; i <= n; i++) {
      if (done.find(i) != done.end()) continue;
      // if (it == 0 and idx == 1 and i == 4) {
      //   cout << "okay\n";
      //   flag = true;
      // }
      if (comp(v, a[i])) {
        v = a[i];
        idx = i;
      }
    }

    if (v[0] == inf) break;
    a[idx] = { inf};

    done.insert(idx);

    // cout << "idx: " << idx << '\n';

    for (int j = 1; j <= v.size(); j++) {
      int x = v[j - 1];
      if (se.find(x) == se.end()) ans.push_back(x);
      se.insert(x);
      // cout << x << ' ';
    }
    // cout << '\n';

  }

  // reverse(ans.begin(), ans.end());
  for (auto x : ans) {
    cout << x << ' ';
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