#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);


/*
 * Complete the 'funWithAnagrams' function below.
 *
 * The function is expected to return a STRING_ARRAY.
 * The function accepts STRING_ARRAY text as parameter.
 */

vector<string> funWithAnagrams(vector<string> text) {
    vector<string> sortedtext;
    for (auto s: text) {
        sort(s.begin(), s.end());
        sortedtext.emplace_back(s);
    }
    vector<string> res;
    set<string> h;
    for (int i = 0; i < text.size(); ++i) {
        if (h.find(sortedtext[i]) != h.end()) continue;
        res.emplace_back(text[i]);
        h.emplace(sortedtext[i]);
    }
    sort(res.begin(), res.end());
    return res;
}
