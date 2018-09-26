/** Author - Divij Bhatia
  * Know more about me at http://www.divijbhatia.in
  */

#include <iostream>
using namespace std;
/*this function swaps element of a & b indexes*/
void exchange_elements(int* array, int a, int b)
{
    int temp=array[a];
    array[a]=array[b];
    array[b]=temp;
}

/*this funtion creates a partition and returns the pivot element's index*/
int find_pivot_index(int* array, int low, int high)
{
    int pivot_element=array[high];
    int i=low-1; //i denotes the index upto where the elements are smaller than the pivot element
    for(int j=low; j<=high-1; j++)
    {
        if(array[j]<=pivot_element) //change < to > for decreasing order
        {
            i++;
            if(i!=j)
            {
                exchange_elements(array, i, j);
            }
        }
    }
    exchange_elements(array, i+1, high);
    return i+1; //pivot index
}

/*main quicksort function*/
void quicksort(int* array, int low, int high)
{
    if(low<high)
    {
        int pivot_index=find_pivot_index(array, low, high);
        quicksort(array, low, pivot_index-1);
        quicksort(array, pivot_index+1, high);
    }    
}
