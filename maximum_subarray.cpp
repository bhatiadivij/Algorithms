/** Author - Divij Bhatia
  * Know more about author at http://www.divijbhatia.in
  */

#include<iostream>
using namespace std;

typedef struct subarray_info{
    int low, high, sum;
}subarray_info;

void print_subarray_info(subarray_info si)
{
    cout<<si.low<<" "<<si.high<<" "<<si.sum<<endl;
}

subarray_info find_max_mid_subarray(int low, int high, int* array){
    int left_sum=-INT_MIN;
    int right_sum=-INT_MIN;
    int sum=0;
    int left_index, right_index;
    int mid=(low+high)/2;
    subarray_info si;
    for(int i=mid; i>=low; i--)
    {
        sum=sum+array[i];
        if(left_sum<sum){
            left_sum=sum;
            left_index=i;
        }
    }
    sum=0;
    for(int i=mid+1; i<=high; i++)
        {
            sum=sum+array[i];
            if(right_sum<sum){
                right_sum=sum;
                right_index=i;
            }
        }
    si.low=left_index;
    si.high=right_index;
    si.sum=left_sum+right_sum;
    return si;
}

subarray_info find_max_subarray(int low, int high, int* array)
{
    subarray_info left_array, right_array, mid_array;
    int mid;
    if(high==low){
        subarray_info si;
        si.low=low;
        si.high=high;
        si.sum=array[low];
        return si;
    }
    else{
        mid=(low+high)/2;
        left_array=find_max_subarray(low, mid, array);
        right_array=find_max_subarray(mid+1, high, array);
        mid_array=find_max_mid_subarray(low, high, array);
    }

    if(left_array.sum>=right_array.sum && left_array.sum>=mid_array.sum)
        return left_array;
    else if(right_array.sum>=left_array.sum && right_array.sum>=mid_array.sum)
        return right_array; 
    else
        return mid_array;
}


int main()
{
    int size=0,*p ;
    cout<<"Enter Number of Array Elements"<<endl;
    cin>>size;
    p=new int(size);
    cout<<"Enter Array Elements"<<endl;
    for(int i=0;i<size;i++){
        cin>>p[i];
    }
    subarray_info si=find_max_subarray(0 , 15, p);
    cout<<"Max sub array is between indices ["<<si.low<<","<<si.high<<"] and their sum is "<<si.sum<<endl;
    cout<<"Max subarray is: [";
    for(int i=si.low; i<=si.high; i++){
        cout<<p[i]<<", ";
    }
    cout<<"\b\b]";
}