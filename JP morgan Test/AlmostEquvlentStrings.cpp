//
// Created by LightString on 1/8/2023.
//
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'areAlmostEquivalent' function below.
 *
 * The function is expected to return a STRING_ARRAY.
 * The function accepts following parameters:
 *  1. STRING_ARRAY s
 *  2. STRING_ARRAY t
 */

vector<string> areAlmostEquivalent(vector<string> s, vector<string> t) {
    vector<string> ans(s.size());
    unordered_map<char, int> hS;
    unordered_map<char, int> hT;
    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i].size() != t[i].size())
        {
            ans[i] = "NO";
            continue;
        }
        hS.clear();
        hT.clear();
        for (const auto &c: s[i])
            hS[c]++;
        for (const auto &c: t[i])
            hT[c]++;
        ans[i] = "YES";
        for (const auto &item: hS)
            if (abs(item.second - hT[item.first]) > 3)
            {
                ans[i] = "NO";
                break;
            }
        for (const auto &item: hT)
            if (abs(item.second - hS[item.first]) > 3)
            {
                ans[i] = "NO";
                break;
            }
    }
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s_count_temp;
    getline(cin, s_count_temp);

    int s_count = stoi(ltrim(rtrim(s_count_temp)));

    vector<string> s(s_count);

    for (int i = 0; i < s_count; i++) {
        string s_item;
        getline(cin, s_item);

        s[i] = s_item;
    }

    string t_count_temp;
    getline(cin, t_count_temp);

    int t_count = stoi(ltrim(rtrim(t_count_temp)));

    vector<string> t(t_count);

    for (int i = 0; i < t_count; i++) {
        string t_item;
        getline(cin, t_item);

        t[i] = t_item;
    }

    vector<string> result = areAlmostEquivalent(s, t);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
            s.begin(),
            find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
            find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
            s.end()
    );

    return s;
}
