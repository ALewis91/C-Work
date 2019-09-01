#pragma once
#include <algorithm>


template <class T>
class ArrayVector
{
private:
	int capacity;
	int n;
	T* A;
public:
	ArrayVector();
	ArrayVector(const ArrayVector& av);
	int size() const;
	bool empty() const;
	T& operator[](int i);
	T& at(int i);
	void erase(int i);
	void resize();
	void insert(int i, const T& e);
	void reserve(int N);
	ArrayVector& operator=(const ArrayVector& av);
	~ArrayVector();
	int cap() const;
};

template <class T>
ArrayVector<T>::ArrayVector<T>()
{
	capacity = 1;
	n = 0;
	A = new T[capacity];
}

template <class T>
ArrayVector<T>::ArrayVector<T>(const ArrayVector& av)
{
	capacity = av.capacity;
	A = new T[capacity];
	n = av.n;
	for (int x = 0; x < n; x++)
		A[x] = av.A[x];
}

template <class T>
ArrayVector<T>& ArrayVector<T>::operator=(const ArrayVector& av)
{
	if (this != &av)
	{
		capacity = av.capacity;
		delete[] A;
		A = new T[capacity];
		n = av.n;
		for (int x = 0; x < n; x++)
			A[x] = av.A[x];
	}
	return *this;
}

template <class T>
T& ArrayVector<T>::operator[](int i)
{
	return A[i];
}

template <class T>
int ArrayVector<T>::size() const
{
	return n;
}

template <class T>
bool ArrayVector<T>::empty() const
{
	return size() == 0;
}

template <class T>
T& ArrayVector<T>::at(int i)
{
	if (i < 0 || i >= n)
		return A[0];
	return A[i];
}

template <class T>
void ArrayVector<T>::erase(int i)
{
	for (int j = i + 1; j < n; j++)
		A[j - 1] = A[j];
	n--;
}

template <class T>
void ArrayVector<T>::reserve(int N)
{
	if (capacity >= N) return;
	T* B = new T[N];
	for (int j = 0; j < n; j++)
		B[j] = A[j];
	if (A != NULL)
		delete[] A;
	A = B;
	capacity = N;
}

template <class T>
void ArrayVector<T>::insert(int i, const T& e)
{
	if (n >= capacity)
		reserve(std::max(1, 2 * capacity));
	for (int j = n - 1; j >= i; j--)
		A[j + 1] = A[j];
	A[i] = e;
	n++;
}

template <class T>
ArrayVector<T>::~ArrayVector()
{
	if (A != nullptr)
		delete[] A;
}

template <class T>
void ArrayVector<T>::resize()
{
	if (capacity / 4 >= n)
	{
		while (capacity / 4 >= n)
		{
			T* B = new T[capacity / 2];
			capacity /= 2;
			for (int x = 0; x < n; x++)
				B[x] = A[x];
			delete[] A;
			A = B;
		}
	}
}

template <class T>
int ArrayVector<T>::cap() const
{
	return capacity;
}
