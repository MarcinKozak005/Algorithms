#include <iostream>
#include "../utils/utils.h"

using namespace std;

template <class T>
void mergeSort(T* begin, T* end)
{
    if(begin >= end) return;
    else
    {
        T* divisor = begin + (end-begin)/2;
        mergeSort(begin,divisor);
        mergeSort(divisor+1,end);
        // merge
        T* tab = new T[end-begin];
        T* tmp = tab;
        T* i=begin, *j=divisor+1;
        for( ;i<=divisor && j<=end; )
        {
            if(*i<*j) *tmp++ = *i++;
            else *tmp++ = *j++;
        }
        while(i <= divisor) *tmp++ = *i++;
        while(j <= end) *tmp++ = *j++;
        tmp=tab;
        for(T* pointer=begin; pointer<=end;pointer++,tmp++) *pointer = *tmp;
        free(tab);
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
	mergeSort(intTab, *(&intTab+1)-1 );
	cout<<"Sorted"<<endl;
	printTab(intTab, *(&intTab+1)-1 );

	return 0;
}

