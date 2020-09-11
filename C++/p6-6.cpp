/*指针。指针数组*/
#include<iostream>
using namespace std;

int main() {

	int line1[]={1,2,3};
	int line2[]={1,2,3};
	int line3[]={1,2,3};

	int *pline[3] = {line1, line2, line3};

	for(int i=0; i<3; i++)
	{
		for(int j=0; j<3; j++)
		{
			//cout<<pline[i][j]<<" ";   //两个等价
			cout<< *(*(pline+i)+j) <<" ";
		}
		cout<<endl;
	}

	return 0;
}