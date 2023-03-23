
// Header Files
#include<iostream>
#include<string>
#include<vector>
using namespace std;

/*
 * inputArr, represents the given array of element of size inputArr_size.
 */
void funcTwins (vector<int> inputArr)
{
    // Write your code here
    for (int i = 0; i < inputArr.size() - 1; ++i)
        for (int j = 0; j < inputArr.size() - 1; ++j)
            if (inputArr[j] > inputArr[j + 1])
                swap(inputArr[j], inputArr[j + 1]);
    for (int i = 0; i < inputArr.size(); i += 2)
        if (inputArr[i] != inputArr[i + 1])
        {
            cout << inputArr[i] << endl;
            return;
        }
    cout << -1 << endl;
}

int main()
{
    
	//input for inputArr
	int inputArr_size;
	cin >> inputArr_size;
	vector<int> inputArr;
	for ( int idx = 0; idx < inputArr_size; idx++ )
	{
		int temp;
		cin >> temp;
		inputArr.push_back(temp);
	}
	
    
	funcTwins(inputArr);
	
    return 0;
}
