// miniVector.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "iostream"
#include "MyMiniVector.h"
using namespace std;

int main()
{
	//miniVector��Ҫ��������
	MyMiniVector<int> v(6); //����һ������Ϊ6��miniVector��Ԫ��ֵΪ0-5
	for (int i = 0; i < 6; i++) { v[i] = i; };

	cout << "miniVector��Ҫ��������" << "(Ԫ�س���/��������)" << endl;
	cout << "��ʼ״̬"<<endl;
	v.display(); 
	cout << "�����Ԫ��ǰ����'7'" << endl;
	v.insert(7,5);
	v.display(); 
	cout << "ɾȥ������Ԫ��"<< endl;
	v.erase(3);
	v.display();
	cout << "ĩβ��ӡ�10��"<< endl;
	v.push_back(10);
	v.display();
	cout << "ɾȥĩβԪ��"<< endl;
	v.pop_back();
	v.display();

	return 0;
}

