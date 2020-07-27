#ifndef UTILS_H
#define UTILS_H

#include <iostream>

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

#endif