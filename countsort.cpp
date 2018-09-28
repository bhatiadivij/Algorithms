/** Author - Divij Bhatia
  * Know more about me at http://www.divijbhatia.in
  */


/*This algorithm is safe to use with negative numbers*/
#include <iostream>
#include <algorithm>
using namespace std;

/*function to print the array*/
void display_element_array(int* array, int size)
{
    for(int i=0;i<size; i++)
    {
        cout<<array[i]<<" ";
    }
}

/*Assuming that the number of elements in the array are in the range -m to n*/
/*This function returns the n or the maximum element from the array*/
int find_max(int* array, int size)
{
    return *std::max_element(array,array+size);
}

/*Assuming that the number of elements in the array are in the range -m to n*/
/*This function returns the n or the minimum element from the array*/
int find_min(int* array, int size)
{
    return *std::min_element(array,array+size);
}

/*find the range elements from the array*/
int find_range(int* array, int size)
{
    int max=find_max(array,size);
    int min=find_min(array,size);
    int range=max-min+1;
    return range;
}

/*run this function to sort using countsort*/
int* countsort(int* array, int size)
{
    int range=find_range(array, size);
    int min=find_min(array,size);
    int shift=-min;
    int* counter=new int(range-1);
    int* sorted_array=new int(size);
    cout<<range;
    for(int i=0; i<range; i++)
    {
        counter[i]=0;
    }

    for(int i=0; i<size; i++)
    {
        counter[array[i]+shift]++;
    }
    
    for(int i=1; i<range; i++)
    {
        counter[i]+=counter[i-1];
    }
    
    for(int i=0; i<size; i++)
    {
        sorted_array[counter[array[i]+shift]-1]=array[i];
        counter[array[i]+shift]--;
    }
    return sorted_array;
}