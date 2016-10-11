//*****************************************
//书P86页 第9题 （非递归算法）
// 
//*****************************************

#include <iostream>
#include <math.h>
using namespace std;
long long m, n;


int solve(long m, long n)
{
	if (m == 1)
	{
		return n + 1;
	}
	if (m == 2)
	{
		return 2 * n + 3;
	}
	if (m == 3)
	{
		return pow(2, n + 3) - 3;
	}
	if (m == 4)
	{
		if (n == 0)
		{
			return 13;
		}
		else
			return 0; // Ack(4,1)开始数据太大，已经无法计算！
	}
}
int main(int argc, char const *argv[])
{
	cin >> m >> n;
	cout << solve(m, n) << endl;
	return 0;
}