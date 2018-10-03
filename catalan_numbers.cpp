/** Author - Divij Bhatia
  * Know more about me at http://www.divijbhatia.in
  */

#include <iostream>
using namespace std;

int find_nth_catalan_number(int n)
{
    int*  cat=new int(n+1);
    cat[0]=cat[1]=1;
       for(int i=2; i<=n; i++)
       {
            cat[i]=0;
            for(int j=0; j<i; j++)
                cat[i]+=cat[j]*cat[i-j-1];
       } 
    return cat[n-1];
}

int main()
{
    int n;
    cout<<"Enter n: ";
    cin>>n;
    cout<<"\n";
    for(int i=1;i<=n;i++)
    {
        cout<<find_nth_catalan_number(i)<<" ";
    }
    return 0;
}