#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <vector>

using namespace std;

template <class T>
void printTab(T* begin, T* end)
{
	for(T* i=begin; i<=end; ++i)
	{
		cout<<*i<<" ";
	}
	cout<<endl;
}


template <class T>
void swap(T* a, T* b)
{
	T tmp = *a;
	*a = *b;
	*b = tmp;
} 


template <class T>
void printVector(vector<T> vec)
{
	cout<<"Vector: ";
	for(auto elem: vec)
		cout<<elem<<" ";
	cout<<endl;
}

#endif