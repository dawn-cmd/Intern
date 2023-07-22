#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);


/*
 * Complete the 'deleteProducts' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY ids
 *  2. INTEGER m
 */

int deleteProducts(vector<int> ids, int m) {
    int n = ids.size();
    map<int, int> h;
    for (const auto &id: ids) h[id]++;
    vector<int> cnts(n + 1, 0);
    for (const auto &item: h) cnts[item.second]++;
    int res = 0;
    for (int i = 1; i <= m && m > 0; ++i) {
        if (i * cnts[i] <= m) {
            res += cnts[i];
            m -= cnts[i] * i;
            continue;
        }
        res += m / i;
        break;
    }
    return h.size() - res;
}
