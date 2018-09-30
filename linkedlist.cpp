/** Author - Divij Bhatia
  * Know more about me at http://www.divijbhatia.in
  */

#include <iostream>
#include <cstdlib>
using namespace std;

struct node{
    node* previous;
    node* next;
    int key;
};

struct linkedlist{
    node* head;
    node* tail;
};

linkedlist* create_linkedlist()
{
    linkedlist* ll=new linkedlist;
    ll->head=NULL;
    ll->tail=NULL;
    return ll;
}

node* create_node(int key)
{
    node* n=new node;
    n->key=key;
    n->previous=NULL;
    n->next=NULL;
    return n;
}

node* search_linkedlist(linkedlist* ll, int key){
    node* i=ll->head;
    while(i!=NULL)
    {
        if(i->key==key)
            return i;
        i=i->next;
    }
    return i;
}

void insert_at_beginning(linkedlist* ll, int key)
{
    node* n=create_node(key);
    if(ll->head==NULL)
    {
        ll->head=n;
        ll->tail=n;
        return;
    }
    n->next=ll->head;
    ll->head->previous=n;
    ll->head=n;
    return;
}

void insert_at_end(linkedlist* ll, int key)
{
    node* n=create_node(key);
    if(ll->tail==NULL)
    {
        ll->head=n;
        ll->tail=n;
        return;
    }
    ll->tail->next=n;
    n->previous=ll->tail;
    ll->tail=n;
}

void delete_node(linkedlist* ll, int key)
{
    node* i=search_linkedlist(ll,key);
    
    if(i==ll->head)
    {
        ll->head=i->next;
    }
    else if(i==ll->tail)
    {
        ll->tail=i->previous;
    }
    else if(i!=NULL)
    {
        i->previous->next=i->next;
        i->next->previous=i->previous;
    }
    free(i);
}

void print_linkedlist(linkedlist* ll)
{
    cout<<"\n\n";

    for(node* i=ll->head; i!=ll->tail; i=i->next)
    {
        cout<<i->key<<" <---> ";
    }
    cout<<ll->tail->key;
}

int main()
{
    linkedlist* ll=create_linkedlist();
    insert_at_end(ll,1);
    insert_at_end(ll,2);
    insert_at_end(ll,3);
    insert_at_end(ll,4);
    insert_at_end(ll,5);
    insert_at_beginning(ll,0);
    print_linkedlist(ll);
    delete_node(ll, 1);
    print_linkedlist(ll);
    delete_node(ll, 0);
    print_linkedlist(ll);
    delete_node(ll, 5);
    print_linkedlist(ll);
}