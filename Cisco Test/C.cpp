
// Header Files
#include<iostream>
#include<string>
#include<vector>
using namespace std;


/*
 * matrix, represents the elements in each cell of the matrix of size N*M.
 */
void funcHopSkipJump (vector<vector<int> > matrix)
{
    // Write your code here
    int x = 0;
    int y = 0;
    int dir = 0;
    int d[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    vector<vector<int> > h;
    for (int i = 0; i < matrix.size(); ++i)
    {
        vector<int> tmp;
        for (int j = 0; j < matrix[i].size(); ++j)
            tmp.push_back(0);
        h.push_back(tmp);
    }
    vector<int> nums;
    nums.push_back(matrix[0][0]);
    h[0][0] = 1;
    for (int i = 0; i < matrix.size() * matrix[0].size() - 1; ++i)
    {
        while (x + d[dir][0] < 0 || 
                x + d[dir][0] >= matrix.size() || 
                y + d[dir][1] < 0 ||
                y + d[dir][1] >= matrix[x].size() ||
                h[x + d[dir][0]][y + d[dir][1]] == 1)
            dir = (dir + 1) % 4;
        x += d[dir][0];
        y += d[dir][1];
        h[x][y] = 1;
        nums.push_back(matrix[x][y]);
    }
    cout << nums[nums.size() % 2 == 0 ? nums.size() - 2 : nums.size() - 1] << endl;
}

int main()
{
    //input for matrix
	int matrix_row;
	int matrix_col;
	cin >> matrix_row;
	cin >> matrix_col;
	
	vector<vector<int> > matrix;
	for ( int idx = 0; idx < matrix_row; idx++ )
	{
		vector<int> temp_vector;
		for ( int jdx = 0; jdx < matrix_col; jdx++ )
		{
			int temp;
			cin >> temp;
			temp_vector.push_back(temp);
		}
		matrix.push_back(temp_vector);
	}
	
	
    
	funcHopSkipJump(matrix);
	
    return 0;
}
