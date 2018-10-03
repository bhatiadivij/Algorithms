/** Author - Divij Bhatia
  * Know more about me at http://www.divijbhatia.in
  */

#include <iostream>
using namespace std;

int calculate_nth_fib_number(int n, int* fib)
{
    if(fib[n-1]!=-1)
    {
        return fib[n-1];
    }
    else{
        return fib[n-1]=calculate_nth_fib_number(n-1,fib)+calculate_nth_fib_number(n-2,fib);
    }
}

int fibonacci(int n)
{
    int* fib=new int(n);
    int i=2;
    fib[0]=fib[1]=1;
    while(i<n)
    {
        fib[i]=-1;
        i++;
    }
    return calculate_nth_fib_number(n,fib);
}

int main()
{
    int n;
    cout<<"Enter n: ";
    cin>>n;
    cout<<fibonacci(n);
    return 0;
}