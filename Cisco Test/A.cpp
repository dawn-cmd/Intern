// Header Files
#include<iostream>
#include<string>
#include<vector>
using namespace std;


/*
 * inputNum, represents the given number.
 */
void funcFizzBuzz (int inputNum)
{
    // Write your code here
    for (int i = 1; i <= inputNum; ++i)
    {
        if (i % 5 == 0 && i % 3 == 0)
        {
            cout << "FizzBuzz" << endl;
            continue;
        }
        if (i % 5 == 0)
        {
            cout << "Buzz" << endl;
            continue;
        }
        if (i % 3 == 0)
        {
            cout << "Fizz" << endl;
            continue;
        }
        cout << i << endl;
    }
}

int main()
{
    //input for inputNum
	int inputNum;
	cin >> inputNum;

    funcFizzBuzz(inputNum);
	
    return 0;
}
