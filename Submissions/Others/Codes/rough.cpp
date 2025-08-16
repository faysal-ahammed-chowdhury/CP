#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n; cin >> n;
  int a[n + 1], nxt[n + 1], prv[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  memset(nxt, 0, sizeof nxt);
  memset(prv, 0, sizeof prv);

  set<int> odd, even;
  for (int i = 1; i <= n; i++) {
    if (i - 1 >= 1) prv[a[i]] = a[i - 1];
    if (i + 1 <= n) nxt[a[i]] = a[i + 1];
    if (i & 1) odd.insert(a[i]);
    else even.insert(a[i]);
  }

  int cur = a[1];
  for (int i = 1; i <= n; i++) {
    int who = 0;
    if (i & 1) {
      who = *odd.begin();
      odd.erase(odd.begin());
    }
    else {
      who = *even.begin();
      even.erase(even.begin());
    }

    if (who == cur) {
      cur = nxt[who];
      continue;
    }

    if (nxt[who] != 0) {
      nxt[prv[who]] = nxt[nxt[who]];
      prv[nxt[nxt[who]]] = prv[who];
      prv[who] = prv[cur];
      nxt[prv[cur]] = who;
      prv[cur] = nxt[who];
      nxt[nxt[who]] = cur;
    }
    else {
      if (prv[who] == nxt[cur]) {
        cur = nxt[who];
        continue;
      }

      int old_prv_who = prv[who];
      int old_nxt_who = nxt[who];
      int old_nxt_nxt_cur = nxt[nxt[cur]];
      int old_prv_cur = prv[cur];
      int old_nxt_cur = nxt[cur];

      nxt[prv[old_prv_who]] = old_nxt_who;

      prv[who] = prv[cur];
      nxt[prv[cur]] = who;
      nxt[who] = cur[nxt];

      prv[cur] = old_nxt_cur;
      nxt[cur] = old_prv_who;

      prv[old_nxt_cur] = who;
      nxt[old_nxt_cur] = cur;

      prv[old_prv_who] = cur;
      nxt[old_prv_who] = old_nxt_nxt_cur;

      prv[old_nxt_nxt_cur] = old_prv_who;
      if (nxt[old_nxt_nxt_cur] == old_prv_who) nxt[old_nxt_nxt_cur] = 0;
    }

    cur = nxt[who];
  }


  int head = 0;
  for (int i = 1; i <= n; i++) {
    if (prv[i] == 0) {
      head = i;
      break;
    }
  }

  cur = head;
  while (cur != 0) {
    cout << cur << ' ';
    cur = nxt[cur];
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