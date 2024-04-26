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

  int n, a, b, c;

  cin >> n >> a >> b >> c;
  vi dp(n, 0);
  if (a <= n) dp[a-1] = 1;
  if (b <= n) dp[b-1] = 1;
  if (c <= n) dp[c-1] = 1;
  int d = max(a, max(b, c));
for (int i = 0; i < n; ++i) {
  if (i-a >= 0 && dp[i-a] > 0) dp[i] = max(dp[i-a]+1, dp[i]); 
  if (i-b >= 0 && dp[i-b] > 0) dp[i] = max(dp[i-b]+1, dp[i]); 
  if (i-c >= 0 && dp[i-c] > 0) dp[i] = max(dp[i-c]+1, dp[i]);
  }

  cout << dp[n-1];
  

  return 0;
}