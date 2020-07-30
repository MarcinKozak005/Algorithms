#include <iostream>
#include "../utils/utils.h"

using namespace std;

template <class T>
void quickSort(T* begin, T* end)
{
    if(begin >= end) return;
    T pivot = *(begin + (end-begin)/2);
    T tmp;
	T* left = begin;
    T* right = end;
    while(true)
    {
        while(*left<pivot && left<end) left++;
        while(pivot<*right && right>begin) right--;
        if(left<right)
        {
            swap(left,right);
            left++; right--;
        }
        else break;
    }
    quickSort(begin,left-1);
    quickSort(right+1,end);
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
	quickSort(intTab, *(&intTab+1)-1 );
	cout<<"Sorted"<<endl;
	printTab(intTab, *(&intTab+1)-1 );

	return 0;
}

