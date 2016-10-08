//*****************************************
//书P86页 第9题 （递归算法）
// 计算机类15-6班 邓小佳 学号：151002616 
//*****************************************

#include <iostream>
using namespace std;

int Ack(int m, int n)
{

	if (m == 0)
	{
		return n = n + 1;
	}
	if (m != 0)
	{
		if (n == 0)
		{
			return Ack(m - 1, 1);
		}
		else
			return Ack(m - 1, Ack(m, n - 1));
	}
}
int main(int argc, char const *argv[])
{
	int m, n;
	cin >> m >> n;
	cout << Ack(m, n) << endl;
	return 0;
}
