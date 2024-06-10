#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 2e5 + 9;
int n, m, tot, a[N], b[N], pref1prog[N], pref1test[N], pref2prog[N], pref2test[N];
vector<int> progid, testid;
int sz1, sz2;

int calc(int idx) {
  int need_prog = n;
  int has_prog = progid.size();
  bool amithere = binary_search(progid.begin(), progid.end(), idx);
  int my_idx;
  if (amithere) my_idx = lower_bound(progid.begin(), progid.end(), idx) - progid.begin();
  else my_idx = lower_bound(testid.begin(), testid.end(), idx) - testid.begin();
  if (amithere) has_prog--;
  if (need_prog <= has_prog) {
    if (amithere and (my_idx + 1 <= n)) {
      int prog_sum = pref1prog[n + 1] - a[idx];
      int test_sum = pref2test[sz2] + (pref1test[sz1] - pref1test[n + 1]);
      return test_sum + prog_sum;
    }
    else {
      int prog_sum = pref1prog[n];
      int test_sum = pref2test[sz2] - b[idx] + (pref1test[sz1] - pref1test[n]);
      return prog_sum + test_sum;
    }
  }
  else {
    if (!amithere and (my_idx + 1 <= m)) {
      int test_sum = pref2test[m + 1] - b[idx];
      int prog_sum = pref1prog[sz1] + (pref2prog[sz2] - pref2prog[m + 1]);
      return test_sum + prog_sum;
    }
    else {
      int test_sum = pref2test[m];
      int prog_sum = pref1prog[sz1] - a[idx] + (pref2prog[sz2] - pref2prog[m]);
      return prog_sum + test_sum;
    }
  }
  return 0;
}

void solve() {
  progid.clear();
  testid.clear();
  cin >> n >> m;
  int tot = n + m + 1;
  for (int i = 1; i <= tot; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= tot; i++) {
    cin >> b[i];
    if (a[i] > b[i]) {
      progid.push_back(i);
    }
    else {
      testid.push_back(i);
    }
  }
  pref1prog[0] = 0, pref1test[0] = 0;
  int id = 1;
  for (auto i : progid) {
    pref1prog[id] = pref1prog[id - 1] + a[i];
    pref1test[id] = pref1test[id - 1] + b[i];
    id++;
  }
  sz1 = progid.size();
  sz2 = testid.size();
  id = 1;
  for (auto i : testid) {
    pref2prog[id] = pref2prog[id - 1] + a[i];
    pref2test[id] = pref2test[id - 1] + b[i];
    id++;
  }

  for (int i = 1; i <= tot; i++) {
    cout << calc(i) << ' ';
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