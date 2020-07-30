#include <iostream>
#include "../utils/utils.h"

using namespace std;

int parent(int i) {return (i-1)/2;}

int left(int i) {return 2*i+1;}

int right(int i) {return 2*(i+1);}

template <class T>
void makeHeap(T* tab, int i)
{
    while(*(tab+ parent(i)) < *(tab+i) )
    {
        swap(*(tab+ parent(i)), *(tab+i));
        i = parent(i);
    }
}

template <class T>
void heapify(T* begin, int i, T* end)
{
    int maxPos=i;
    T max = *(begin+i);
    if(begin+left(i) <= end && *(begin+left(i)) > max)
    {
        max = *(begin+left(i));
        maxPos = left(i);
    }
    if(begin+right(i) <= end && *(begin+right(i)) > max)
    {
        max = *(begin+right(i));
        maxPos = right(i);
    }

    if(maxPos != i)
    {
        swap(begin+maxPos, begin+i);
        heapify(begin,maxPos,end);
    }
}


template <class T>
void heapSort(T* begin, T* end)
{
    for(int i=1;i <= (end - begin);i++) makeHeap(begin,i);
    for(T* finish = end; finish>begin;)
    {
        swap(begin,finish--);
        heapify(begin, 0, finish);
    }
}


int main()
{
	int intTab[] = 
	{
	87,52,58,14,100,27,66,47,99,42,
	1,80,16,65,35,44,64,60,21,9,
	46,19,37,94,75,62,88,10,98,40,
	74,55,18,96,83,11,50,79,13,77,
	68,76,90,92,91,17,26,57,23,34,
	82,86,78,28,33,93,3,89,53,24,
	43,39,56,36,22,48,51,2,30,69,
	95,6,73,67,81,5,97,59,63,12,
	31,41,15,25,70,71,32,54,29,49,
	8,20,84,72,45,7,4,85,38,61
	};

	printTab(intTab, *(&intTab+1)-1 );
	heapSort(intTab, *(&intTab+1)-1 );
	cout<<"Sorted"<<endl;
	printTab(intTab, *(&intTab+1)-1 );

	return 0;
}