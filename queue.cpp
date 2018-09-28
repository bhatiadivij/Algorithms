/** Author - Divij Bhatia
  * Know more about me at http://www.divijbhatia.in
  */

#include <iostream>
using namespace std;

class Queue
{
    private:
        int* array;
        int length;
        int head;
        int tail;
        int last_dequeued_element;
    
    public:
        Queue();
        Queue(int length);
        bool is_empty();
        bool is_full();
        bool enqueue(int element);
        bool dequeue();
        int get_dequeued_element();
};


int modulo(int a, int b)
{
    return (a%b + b)%b;
}

/*Default Constructor. Assuming default length of the queue to be 10*/
Queue::Queue()
{
    length=10;
    array=new int(length);
    head=0;
    tail=-1;
}

/*Parameterized constructor to initialize queue of user defined length*/
Queue::Queue(int length)
{
    this->length=length;
    array=new int(length);
    head=0;
    tail=-1;
}

/*function to check if queue is empty*/
bool Queue::is_empty()
{
    return head==tail ? true : false;
}

/*function to check if queue is full*/
bool Queue::is_full()
{
    return head==modulo(tail+1,length) && tail!=-1 ? true : false;
}

/*function to add an element to the queue*/
bool Queue::enqueue(int element)
{
    if(is_full()==false)
    {
        tail=modulo(tail+1,length);
        array[tail]=element;
        return true;
    }
    else
        return false;
}

/*function to remove an element from the queue*/
bool Queue::dequeue()
{
    if(is_empty()==false)
    {
        last_dequeued_element=array[head];
        head= modulo(head+1,length);
    }
    else
        return false;
}

/*function to get the last removed element*/
int Queue::get_dequeued_element()
{
    return last_dequeued_element;
}