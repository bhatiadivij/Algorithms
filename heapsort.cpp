/** Author - Divij Bhatia
  * Know more about the author at http://www.divijbhatia.in
  */

#include <iostream>
#include <math.h>
using namespace std;

class Heap
{
  private:
    int* element_array;
    int heap_size;          //total elements in the array which follow properties of heap
    int element_array_size; // total elements

  public:
    Heap();
    Heap(int size);
    int get_parent(int child);
    int get_left_child(int parent);
    int get_right_child(int parent);
    void max_heapify(int index);
    void build_max_heap();
    void min_heapify(int index);
    void build_min_heap();
    void increasing_heapsort();
    void decreasing_heapsort();
    void display_heap();
    void display_element_array();
};

/*Default constructor*/
Heap::Heap(){
    heap_size=-1;
    element_array_size=0;
}

/*Parameterized constructor which takes size of element array as argument*/
Heap::Heap(int size)
{
    heap_size=-1;
    element_array_size=size-1;
    element_array=new int(element_array_size);
    cout<<"Input elements : "<<endl;
    for(int i=0; i<=element_array_size; i++)
    {
        cin>>element_array[i];
    }
    heap_size=9;
}

/*this function returns index of the parent*/
int Heap::get_parent(int child)
    {
        return child / 2;
    }

/*this function returns index of the left child*/
int Heap::get_left_child(int parent)
    {
        return parent * 2+1;
    }

/*this function returns index of the right child*/
int Heap::get_right_child(int parent)
    {
        return parent * 2 + 2;
    }

/*this function ensures that the property of max_heap is retained*/
/*starting from the index it takes as argument*/
/*this function considers that the left and right children are already max_heaps*/
void Heap::max_heapify(int index)
    {
        int left=get_left_child(index);
        int right=get_right_child(index);
        int largest=index;
        if(left<=heap_size && element_array[index]<element_array[left]){
            largest=left;
        }
        if(right<=heap_size && element_array[largest]<element_array[right]){
            largest=right;
        }

        if(largest!=index){
            int temp=element_array[index];
            element_array[index]=element_array[largest];
            element_array[largest]=temp;
            max_heapify(largest);
        }
    }    

/*this function ensures that the property of min_heap is retained*/
/*starting from the index it takes as argument*/
/*this function considers that the left and right children are already min_heaps*/
void Heap::min_heapify(int index)
    {
        int left=get_left_child(index);
        int right=get_right_child(index);
        int smallest=index;
        if(left<=heap_size && element_array[index]>element_array[left]){
            smallest=left;
        }
        if(right<=heap_size && element_array[smallest]>element_array[right]){
            smallest=right;
        }

        if(smallest!=index){
            int temp=element_array[index];
            element_array[index]=element_array[smallest];
            element_array[smallest]=temp;
            min_heapify(smallest);
        }
    }    

/*this function is used to create a max heap for the very first time*/
/*in bottom up approach*/
void Heap::build_max_heap()   
 {
    heap_size=element_array_size;
    for(int i=element_array_size/2; i>=0; i--)
    {
        max_heapify(i);
    }
 }

/*this function is used to create a min heap for the very first time*/
/*in bottom up approach*/
void Heap::build_min_heap()   
 {
    heap_size=element_array_size;
    for(int i=element_array_size/2; i>=0; i--)
    {
        min_heapify(i);
    }
 }


/*this function is used to display the heap*/
void Heap::display_heap()
{
    cout<<"\n\n";
    int i=0, height=0; 
    while(i<=heap_size)
    {
        int elements_at_current_height=pow(2,height);
        while(elements_at_current_height>0 && i<=heap_size)
        {
            cout<<element_array[i]<<"\t";
            i++;
            elements_at_current_height--;
        }
        height++;
        cout<<endl;
    }
 }   

/*this function is used to display the element array*/
void Heap::display_element_array(){
    for(int i=0;i<=element_array_size; i++)
    {
        cout<<element_array[i]<<" ";
    }
}

/*heapsort() function will arrange the elements in an increasing order*/ 
void Heap::increasing_heapsort()
{
    while(heap_size>0)
    {
        int temp=element_array[0];
        element_array[0]=element_array[heap_size];
        element_array[heap_size]=temp;
        heap_size--;
        max_heapify(0);
    }
    display_element_array();
}

/*heapsort() function will arrange the elements in an decreasing order*/ 
void Heap::decreasing_heapsort()
{
    while(heap_size>0)
    {
        int temp=element_array[0];
        element_array[0]=element_array[heap_size];
        element_array[heap_size]=temp;
        heap_size--;
        min_heapify(0);
    }
    display_element_array();
}


