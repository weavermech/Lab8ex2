/*--------------------------------------------------------------------------*/

#include <string.h>
#include <iostream>
using namespace std;

#include "LList.h"

/*--------------------------------------------------------------------------*/
/*-------- NodeC             -----------------------------------------------*/
/*--------------------------------------------------------------------------*/
// Null Constructor 

template<class T>
NodeC<T>::NodeC() 
{
}

/*--------------------------------------------------------------------------*/
// Copy constructor

template<class T>
NodeC<T>::NodeC(const NodeC<T> & s)
{
  data = s.data;
  next = s.next;
  prev = s.prev;
}

/*--------------------------------------------------------------------------*/
// Assignment 

// =

/*--------------------------------------------------------------------------*/
// Destructor

template<class T>
NodeC<T>::~NodeC()
{
}

/*--------------------------------------------------------------------------*/







/*--------------------------------------------------------------------------*/
/*-------- Constructors, etc -----------------------------------------------*/
/*--------------------------------------------------------------------------*/
// Null Constructor 

template<class T>
ListC<T>::ListC() 
{
  head = new NodeC<T>;
  
  head->next=head;
  head->prev=head;
}

/*--------------------------------------------------------------------------*/
// Copy constructor

template<class T>
ListC<T>::ListC(const ListC<T> & s)
{
  head = s.head;
}

/*--------------------------------------------------------------------------*/
// Assignment 

template<class T>
ListC<T> & 
ListC<T>::operator=(const ListC<T> & s)
{
  if (this != &s) {
    head = s.head;
  }
  return *this;
}

/*--------------------------------------------------------------------------*/

// Destructor, use an iterator!



/*--------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------*/

template<class T>    
void
ListC<T>::InsFirst(T & d)
{
  InsAfter(head, d);
}

/*--------------------------------------------------------------------------*/

template<class T>    
void
ListC<T>::InsLast(T & d)
{
  InsAfter(head->prev, d);
}

/*--------------------------------------------------------------------------*/

template<class T>    
int
ListC<T>::FindPos(T & d)
{
  IterC<T>     it(*this);
  int          pos=0;
  
  for (it.First(); it.IsElem(); it.Next() ) {
    pos++;
    //if (it.Data() == d) return pos;
    if (strcmp(it.Data().ps,d.ps)==0) return pos;
  }
  return 0;
}

/*--------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------*/

template<class T>
void
ListC<T>::InsAfter(NodeC<T>* pnode, T & d)
{
  NodeC<T>* pn = new NodeC<T>;
  
  pn->next=pnode->next;
  pn->prev=pnode;
  pn->data=d;
  
  pnode->next->prev=pn;
  pnode->next=pn;
}    

/*--------------------------------------------------------------------------*/

// Delete


/*--------------------------------------------------------------------------*/




/*--------------------------------------------------------------------------*/
/*-------- Constructors, etc -----------------------------------------------*/
/*--------------------------------------------------------------------------*/
// Constructor 

template<class T>
IterC<T>::IterC(ListC<T> & s) : list(s)
{
  First();
}

/*--------------------------------------------------------------------------*/
// Copy constructor

template<class T>
IterC<T>::IterC(const IterC<T> & s) : list(s.list)
{
  pnode = s.pnode;
}

/*--------------------------------------------------------------------------*/
// Assignment 

template<class T>
IterC<T> & 
IterC<T>::operator=(const IterC<T> & s)
{
  if (this != &s) {
    list  = s.list;
    pnode = s.pnode;
  }
  return *this;
}

/*--------------------------------------------------------------------------*/
// Destructor

template<class T>
IterC<T>::~IterC()
{  
}

/*--------------------------------------------------------------------------*/
/*------Operations----------------------------------------------------------*/
/*--------------------------------------------------------------------------*/

//Data()

/*--------------------------------------------------------------------------*/

template<class T>
IterC<T> &
IterC<T>::Delete(void)
{
  this->Next();
  list.Delete(this->pnode->prev);
  
  return *this;
}

/*--------------------------------------------------------------------------*/

//InsAfter  use list.InsAfter


/*--------------------------------------------------------------------------*/

template<class T>
IterC<T> &
IterC<T>::First()
{
  this->pnode = list.head;
  
  return this->Next();
}

/*--------------------------------------------------------------------------*/

template<class T>
IterC<T> &
IterC<T>::Nth(int n)
{
  int i=0;
  
  for (First(); IsElem(); Next()) {
    i++;
    if (i==n) return (*this);
  }
  
  First();
  Prev();
  
  return (*this);
}

/*--------------------------------------------------------------------------*/

template<class T>
IterC<T> &
IterC<T>::Last()
{
  this->pnode = list.head;
  
  return this->Prev();
}

/*--------------------------------------------------------------------------*/

template<class T>
IterC<T> &
IterC<T>::Next()
{
  this->pnode = this->pnode->next;
  
  return *this;
}

/*--------------------------------------------------------------------------*/

template<class T>
IterC<T> &
IterC<T>::Prev()
{
  this->pnode = this->pnode->prev;
  
  return *this;
}

/*--------------------------------------------------------------------------*/

template<class T>
int 
IterC<T>::IsElem(void)
{
  return (pnode != list.head);
}

/*--------------------------------------------------------------------------*/
