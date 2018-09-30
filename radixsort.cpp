/** Author - Divij Bhatia
  * Know more about me at http://www.divijbhatia.in
  */

#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

/*This algorithm works only with positive numbers*/
int modulo(int a, int b)
{
    return (a%b + b)%b;
}

void display_array(int* array, int size)
{
    cout<<"\n";
    for(int i=0; i<size; i++)
    {
        cout<<array[i]<<" ";
    }
}

int digit_calculator(int key, int digit_position)
{
    digit_position=pow(10,digit_position);
    return modulo(key, digit_position)*10/digit_position;
}

int find_number_of_digits(int num)
{
    int digits=0;
    num=abs(num);
    while(num>=1)
    {
        num=num/10;
        digits++;
    }
    return digits;
}

int find_max(int* array, int size)
{
    return *std::max_element(array,array+size);
}

int find_min(int* array, int size)
{
    return *std::min_element(array,array+size);
}

int find_range(int* array, int size)
{
    int max=find_max(array,size);
    int min=find_min(array,size);
    int range=max-min+1;
    return range;
}

int* generate_digit_array(int* array, int size, int digit)
{
    int* digit_array=new int(size);
    for(int i=0; i<size; i++)
    {
        digit_array[i]=digit_calculator(array[i],digit);
    }
    return digit_array;
}

int* countsort(int* array, int* digit_array, int size, int digit)
{

    int range=find_range(digit_array, size);
    int min=find_min(digit_array,size);
    int shift=-min;
    int* counter=new int(range-1);
    int* cumulative_counter=new int(range-1);
    int* sorted_array=new int(size);
    for(int i=0; i<range; i++)
    {
        counter[i]=0;
        cumulative_counter[i]=0;
    }

    for(int i=0; i<size; i++)
    {
        counter[digit_array[i]+shift]++;
    }
    
    cumulative_counter[0]=counter[0];
    for(int i=1; i<range; i++)
    {
        cumulative_counter[i]=counter[i]+cumulative_counter[i-1];
    }
    
    for(int i=0; i<size; i++)
    {
        sorted_array[cumulative_counter[digit_array[i]+shift]-counter[digit_array[i]+shift]]=array[i];
        counter[digit_array[i]+shift]--;
    }
    return sorted_array;
}

void radix_sort(int* array, int size)
{
  int max=find_max(array,size);
  int max_digits=find_number_of_digits(max);
  for(int i=1; i<=max_digits; i++)
  {
      int* digit_array=generate_digit_array(array,size,i);   
      array=countsort(array, digit_array, size, i);
  }
    display_array(array,size);
}

int main()
{
    int a[]={215,148,401,320,190};
    radix_sort(a,5);
}