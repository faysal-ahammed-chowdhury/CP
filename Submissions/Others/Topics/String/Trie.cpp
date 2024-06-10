#include <bits/stdc++.h>
using namespace std;

const int N = 10; // change here
const char base_char = '0';  // change here
struct TrieNode {
  int cnt;
  TrieNode * nxt[N];
  TrieNode() {
    cnt = 0;
    for (int i = 0; i < N; i++) nxt[i] = NULL;
  }
} *root;

void insert(const string &s) {
  TrieNode *cur = root;
  int n = (int)s.size();
  for (int i = 0; i < n; i++) {
    int idx = s[i] - base_char;
    if (cur -> nxt[idx] == NULL) cur -> nxt[idx] = new TrieNode();
    cur = cur -> nxt[idx];
    cur -> cnt++;
  }
}
void rem(TrieNode *cur, string &s, int pos) { // free :: De Alloactes Memory
  if (pos == s.size()) return;
  int idx = s[pos] - base_char;
  rem(cur -> nxt[idx], s, pos + 1);
  cur -> nxt[idx] -> cnt--;
  if (cur -> nxt[idx] -> cnt == 0) {
    free(cur -> nxt[idx]);
    cur -> nxt[idx] = NULL;
  }
}
int query(const string &s) { // "s" is a prefix of some element or not
  int n = (int)s.size();
  TrieNode *cur = root;
  for (int i = 0; i < n; i++) {
    int idx = s[i] - base_char;
    if (cur -> nxt[idx] == NULL) return 0;
    cur = cur -> nxt[idx];
  }
  return cur -> cnt;
}
void del(TrieNode *cur) {
  for (int i = 0; i < N; i++) if (cur -> nxt[i]) del(cur -> nxt[i]);
  delete(cur);
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  root = new TrieNode(); // init new trie
  del(root); // clear trie

  return 0;
}