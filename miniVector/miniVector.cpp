// miniVector.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "iostream"
#include "MyMiniVector.h"
using namespace std;

int main()
{
	//miniVector主要函数测试
	MyMiniVector<int> v(6); //创建一个长度为6的miniVector，元素值为0-5
	for (int i = 0; i < 6; i++) { v[i] = i; };

	cout << "miniVector主要函数测试" << "(元素长度/容器容量)" << endl;
	cout << "初始状态"<<endl;
	v.display(); 
	cout << "在五号元素前插入'7'" << endl;
	v.insert(7,5);
	v.display(); 
	cout << "删去第三个元素"<< endl;
	v.erase(3);
	v.display();
	cout << "末尾添加‘10’"<< endl;
	v.push_back(10);
	v.display();
	cout << "删去末尾元素"<< endl;
	v.pop_back();
	v.display();

	return 0;
}

