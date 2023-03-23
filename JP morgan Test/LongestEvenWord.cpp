#include <bits/stdc++.h>

using namespace std;



/*
 * Complete the 'longestEvenWord' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING sentence as parameter.
 */

string longestEvenWord(string sentence) {
    int curWordLength = 0;
    int lengthOfLongestWord = 0;
    int id = 0;
    int keyId = 0;
    sentence += ' ';  // dummy character
    for (const auto &c: sentence)
    {
        if (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z'))
        {
            curWordLength++;
            id++;
            continue;
        }
        if (!(curWordLength & 1) && curWordLength > lengthOfLongestWord)
        {
            lengthOfLongestWord = curWordLength;
            keyId = id - curWordLength;
        }
        curWordLength = 0;
        id++;
    }
    if (!lengthOfLongestWord)
        return "00";
    return sentence.substr(keyId, lengthOfLongestWord);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string sentence;
    getline(cin, sentence);

    string result = longestEvenWord(sentence);

    fout << result << "\n";

    fout.close();

    return 0;
}
