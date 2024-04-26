#include <bits/stdc++.h>

#ifndef cpheader
#define F0R(i,a,b) for (int i = a; i < b; ++i)
#define f0r(i,b) F0R(i,0,b)
#define F0Rd(i,a,b) for (int i = a; i >= b; --i)
typedef long long ll;
typedef std::vector<int> vi;
template <class T, class U>
constexpr bool chmax(T& a, U&& b) {
  return a < b ? a = std::forward<U>(b), true : false;
}
#define cpheader
#endif


using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, s, a, b, m = -1;
  cin >> n >> s;
  
  for (int i = 0; i < n; ++i) {
    cin >> a >> b;
    if (a <= s) {
      if (b == 0)
     { m = max(m, 0); }
      if (a < s && b > 0) {
        m = max(100-b, m);
      }
    }
  }

  cout << m;

  return 0;
}
