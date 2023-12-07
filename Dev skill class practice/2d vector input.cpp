#include <iostream>
#include <vector>
using namespace std;
int main()
{

	int row = 5;
	int column[] = {7, 3, 4, 2, 1};

	vector<vector<int>> vec;
    //vector<vector<int>> vec(row);//(i)

	for(int i = 0; i < row; i++)
	{
		int col = column[i];
		//vec[i] = vector<int>(col);//(i)

		vector<int> v2(col);
		vec.push_back(v2);

		for(int j = 0; j < col; j++)
		{
			vec[i][j] = j + 1;
			//cin>>vec[i][j];
		}
	}
    cout<<"size = "<<vec[0].size()<<endl;
	for(int i = 0; i < row; i++)
	{
		for (int j = 0; j < vec[i].size(); j++)
		{
			cout << vec[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
