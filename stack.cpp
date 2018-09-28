/** Author - Divij Bhatia
  * Know more about me at http://www.divijbhatia.in
  */

#include <iostream>
using namespace std;

class Stack{
    private:
        int* array;
        int top;
        int length;
    public:
        Stack();
        Stack(int length);
        bool is_empty();
        bool overflow();
        bool push(int element);
        bool pop();
        int get_popped_element();
        void display();
};  

/*Default Constructor. Assuming default length of stack to be 10*/
Stack::Stack()
{
    array = new int(10);
    top = -1;
    length = 10;
}

/*Parameterized Constructor for user-defiend length of stack*/
Stack::Stack(int length)
{
    array = new int(length);
    top=-1;
    this->length=length;
}

/*Function to check if stack is empty*/
bool Stack::is_empty()
{
    return top==-1 ? true : false;
}

/*Function to check if stack is overflowed*/
bool Stack::overflow()
{
    return top==length ? true : false;
}

/*Function to push an element to stack*/
bool Stack::push(int element)
{
    top++;
    if(overflow()==false)
    {
        array[top]=element;
        return true;
    }
    else
    {
        top--;
        return false;
    }
}

/*Function to pop an element from stack*/
bool Stack::pop()
{
    if(is_empty()==false)
    {
        top--;
        return true;
    }
    else
    {
        return false;
    }
}

/*Function to display elements of stack*/
void Stack::display()
{
    cout<<"\n\n";
    for(int i=0; i<=top; i++)
    {
        cout<<array[i]<<"  ";
    }
    cout<<"\n\n";
}


/*Function to get the last popped element from the stack*/
int Stack::get_popped_element()
{
    return array[top+1];
}

/*Menu driven UI to implement stack operations*/
int main(){
    Stack stack;
    int choice=-1;
    bool status;
    int x;
    while(choice!=3){
        cout<<"1 Push\n";
        cout<<"2 Pop\n";
        cout<<"3 Exit\n";
        cout<<"\nEnter Choice: ";
        cin>>choice;
        switch(choice)
        {
            case 1: 
                cout<<"Enter element to push: ";
                cin>>x;
                status=stack.push(x);
                if(status==true)
                    cout<<"\npush successful";
                else
                    cout<<"\npush failed";
                stack.display();
                break;
            case 2:
                status=stack.pop();
                if(status==true)
                {
                    cout<<"\npopped element is "<<stack.get_popped_element();
                    stack.display();
                }
                else
                {
                    cout<<"\nPop failed\n\n";
                }
                break;
        }
    }
}