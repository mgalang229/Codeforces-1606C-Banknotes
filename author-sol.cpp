#include <bits/stdc++.h>
using namespace std;

/*

1 10 100

k = 14
10 / 1 - 1 = 9
min(14, 9)
res += 1 * 9
= 14 - 9
= 5

k = 5
100 / 10 - 1 = 9
min(5, 9)
res += 10 * 5
= 5 - 5
= 0

final answer: 59

------------------------------------

1 10000

k = 778
10000 / 1 - 1 = 9999
min(778, 9999)
res += 1 * 778
= 778 - 778
= 0

final answer: 778

------------------------------------

1 10 1000

k = 256
10 / 1 - 1 = 9
min(256, 9)
res += 1 * 9
= 256 - 9
= 247

k = 247
1000 / 10 - 1 = 99
min(247, 99)
res += 10 * 99
= 247 - 99
= 148

k = 148
(skipped if condition)
res += 1000 * 148
= 148000

final answer: 1489999

*/

void test_case() {
	int n, k;
	cin >> n >> k;
	k += 1;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		int cur = 1;
		while (a[i]--) {
			cur *= 10;
		}
		a[i] = cur;
	}
	long long res = 0;
	for (int i = 0; i < n; i++) {
		int cnt = k;
		if (i + 1 < n) {
			cnt = min(cnt, a[i+1] / a[i] - 1);
		}
		res += a[i] * 1LL * cnt;
		k -= cnt;
	}
	cout << res << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T = 1;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		test_case();
	}
}
