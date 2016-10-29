#pragma once
#include "iostream"
using namespace std;
template <class T>
class MyMiniVector
{
public:
	MyMiniVector(const int &size=0);//默认初始化为空
	unsigned int size()const;//返回容器长度
	unsigned int capacity()const;//返回容器当前最大容量
	bool isEmpty()const;//返回容器是否为空
	void push_back(const T &value);//将元素添加至最后
	void pop_back();//将最后的元素删去
	void insert(const T &value, const unsigned int &num);//把value插入到第num位，0<=num<=m_size;
	void erase(const unsigned int &num);//num为要删除元素的下标
	void display()const;//打印容器内元素
	T& operator[](unsigned int i)const;//重载下标
	T& operator=(const MyMiniVector &v);//重载等号
	~MyMiniVector();

private:
	unsigned int m_size;//容器内元素量
	unsigned int m_capacity;//容器最大容量
	T *addr;//标记位置指针
	void reserve(const unsigned int &n,const bool &copy);
};

template<class T>
void MyMiniVector<T>::reserve(const unsigned int &n,const bool &copy)//改变向量容量
{
	T *newAddr = new T[n];//创建新的空间
	if (copy)//如果不是新建的向量,就要把原来的拷贝一份
	{
		for (unsigned int i = 0; i < m_size; i++)//复制原来的向量
		{*(newAddr + i) = *(addr + i);	}
	}
	if (addr != NULL)//删去原来的向量
	{delete[]addr;}

	addr = newAddr;//更新指针
	m_capacity = n;//更新容量
}

template<class T>
inline MyMiniVector<T>::MyMiniVector(const int &size) :
	m_size(0), m_capacity(0), addr(NULL)
{
	if (size == 0) { return; }//长度为0时直接为空
	reserve(size, false);//新建的向量不用拷贝
	m_size = size;
	for (unsigned int i = 0; i < m_size; i++)
	{*(addr+i) = T();}				//按T的类型初始化默认值
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
	if (m_size==m_capacity)//添加前判断容器满了没
	{
		if (m_capacity == 0) reserve(1, false);
		else reserve(m_capacity * 2, true);
	}
	*(addr + m_size) = value;//添加至最后
	m_size++;
}

template<class T>
inline void MyMiniVector<T>::pop_back()
{
	if (isEmpty())
	{
		cout << "错误:容器为空!" << endl;
		return;
	}
	m_size--;
}

template<class T>
void MyMiniVector<T>::insert(const T &value,const unsigned int &num) //把value插入到第num位，0<=num<=m_size;
{
	if (num>m_size)
	{
		cout << "错误：插入失败，下标越界" << endl;
		return;
	}

	if (num==m_size)//等于添加到最后
	{
		push_back(value);
		return;
	}

	if (m_size == m_capacity)
	{
		if (m_capacity == 0) reserve(1, false);
		else reserve(m_capacity * 2, true);
	}

	T *newAddr = new T[m_capacity];//创建新的空间
	
		for (unsigned int i = 0; i < num; i++)//复制原来的前半部分向量
		{*(newAddr + i) = *(addr + i);		}

		*(newAddr + num)= value;//插入值

		for (unsigned int i=num+1;i<=m_size;i++)//复制原来的后半部分向量
		{*(newAddr + i) = *(addr + i-1);		}

	if (addr != NULL)//删去原来的向量
	{delete[]addr;}

	addr = newAddr;//更新指针
	m_size++;

}

template<class T>
void MyMiniVector<T>::erase(const unsigned int &num)//num为要删除元素的下标
{
	if (isEmpty())
	{
		cout << "错误:容器为空!" << endl;
		return;
	}
	if (num>=m_size||num<0)
	{
		cout << "错误:下标越界!" << endl;
		return;
	}
	
	if (num != m_size - 1) //不是最后一个的话，用后面的一个拷贝,是最后一个的话，直接删除最后一个
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
	{cout << "错误:下标越界!" << endl;}

	return *(addr + i);
}

template<class T>
inline T & MyMiniVector<T>::operator=(const MyMiniVector &v)
{
	reserve(v.size, false);
	for (int i=0;i<v.size;i++)//复制所有元素
	{*(addr + i) = *(v + i);}
}

template<class T>
MyMiniVector<T>::~MyMiniVector()
{
	if (addr != NULL)
	{delete[]addr;}
}