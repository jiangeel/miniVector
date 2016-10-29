#pragma once
#include "iostream"
using namespace std;
template <class T>
class MyMiniVector
{
public:
	MyMiniVector(const int &size=0);//Ĭ�ϳ�ʼ��Ϊ��
	unsigned int size()const;//������������
	unsigned int capacity()const;//����������ǰ�������
	bool isEmpty()const;//���������Ƿ�Ϊ��
	void push_back(const T &value);//��Ԫ����������
	void pop_back();//������Ԫ��ɾȥ
	void insert(const T &value, const unsigned int &num);//��value���뵽��numλ��0<=num<=m_size;
	void erase(const unsigned int &num);//numΪҪɾ��Ԫ�ص��±�
	void display()const;//��ӡ������Ԫ��
	T& operator[](unsigned int i)const;//�����±�
	T& operator=(const MyMiniVector &v);//���صȺ�
	~MyMiniVector();

private:
	unsigned int m_size;//������Ԫ����
	unsigned int m_capacity;//�����������
	T *addr;//���λ��ָ��
	void reserve(const unsigned int &n,const bool &copy);
};

template<class T>
void MyMiniVector<T>::reserve(const unsigned int &n,const bool &copy)//�ı���������
{
	T *newAddr = new T[n];//�����µĿռ�
	if (copy)//��������½�������,��Ҫ��ԭ���Ŀ���һ��
	{
		for (unsigned int i = 0; i < m_size; i++)//����ԭ��������
		{*(newAddr + i) = *(addr + i);	}
	}
	if (addr != NULL)//ɾȥԭ��������
	{delete[]addr;}

	addr = newAddr;//����ָ��
	m_capacity = n;//��������
}

template<class T>
inline MyMiniVector<T>::MyMiniVector(const int &size) :
	m_size(0), m_capacity(0), addr(NULL)
{
	if (size == 0) { return; }//����Ϊ0ʱֱ��Ϊ��
	reserve(size, false);//�½����������ÿ���
	m_size = size;
	for (unsigned int i = 0; i < m_size; i++)
	{*(addr+i) = T();}				//��T�����ͳ�ʼ��Ĭ��ֵ
}

template<class T>
unsigned int MyMiniVector<T>::size()const
{return m_size;}

template<class T>
unsigned int MyMiniVector<T>::capacity()const
{return m_capacity;}

template<class T>
bool MyMiniVector<T>::isEmpty()const
{return m_size == 0;}

template<class T>
inline void MyMiniVector<T>::push_back(const T &value)
{
	if (m_size==m_capacity)//���ǰ�ж���������û
	{
		if (m_capacity == 0) reserve(1, false);
		else reserve(m_capacity * 2, true);
	}
	*(addr + m_size) = value;//��������
	m_size++;
}

template<class T>
inline void MyMiniVector<T>::pop_back()
{
	if (isEmpty())
	{
		cout << "����:����Ϊ��!" << endl;
		return;
	}
	m_size--;
}

template<class T>
void MyMiniVector<T>::insert(const T &value,const unsigned int &num) //��value���뵽��numλ��0<=num<=m_size;
{
	if (num>m_size)
	{
		cout << "���󣺲���ʧ�ܣ��±�Խ��" << endl;
		return;
	}

	if (num==m_size)//������ӵ����
	{
		push_back(value);
		return;
	}

	if (m_size == m_capacity)
	{
		if (m_capacity == 0) reserve(1, false);
		else reserve(m_capacity * 2, true);
	}

	T *newAddr = new T[m_capacity];//�����µĿռ�
	
		for (unsigned int i = 0; i < num; i++)//����ԭ����ǰ�벿������
		{*(newAddr + i) = *(addr + i);		}

		*(newAddr + num)= value;//����ֵ

		for (unsigned int i=num+1;i<=m_size;i++)//����ԭ���ĺ�벿������
		{*(newAddr + i) = *(addr + i-1);		}

	if (addr != NULL)//ɾȥԭ��������
	{delete[]addr;}

	addr = newAddr;//����ָ��
	m_size++;

}

template<class T>
void MyMiniVector<T>::erase(const unsigned int &num)//numΪҪɾ��Ԫ�ص��±�
{
	if (isEmpty())
	{
		cout << "����:����Ϊ��!" << endl;
		return;
	}
	if (num>=m_size||num<0)
	{
		cout << "����:�±�Խ��!" << endl;
		return;
	}
	
	if (num != m_size - 1) //�������һ���Ļ����ú����һ������,�����һ���Ļ���ֱ��ɾ�����һ��
	{
		for (unsigned int i=num;i<m_size-1;i++)
		{*(addr + i) = *(addr + i + 1); }
	}
	m_size--;
	return;
}

template<class T>
void MyMiniVector<T>::display()const
{
	for (unsigned int i = 0; i < m_size; i++)
	{
		cout << *(addr + i);
		if (i!=m_size-1)
		{cout << ",";}
	}
	cout << "  " <<'(' << m_size << '/' << m_capacity<<')'<<endl;
}

template<class T>
inline T & MyMiniVector<T>::operator[](unsigned int i)const
{
	if (i<0||i>=m_size)
	{cout << "����:�±�Խ��!" << endl;}

	return *(addr + i);
}

template<class T>
inline T & MyMiniVector<T>::operator=(const MyMiniVector &v)
{
	reserve(v.size, false);
	for (int i=0;i<v.size;i++)//��������Ԫ��
	{*(addr + i) = *(v + i);}
}

template<class T>
MyMiniVector<T>::~MyMiniVector()
{
	if (addr != NULL)
	{delete[]addr;}
}