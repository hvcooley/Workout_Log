/*
*  MTFL_v3.h
*
*  COSC 160 Spring 2020
*  Project #1b
*
*  Due on: JAN 27, 2020
*  Author: hvc3
*
*
*  In accordance with the class policies and Georgetown's
*  Honor Code, I certify that, with the exception of the
*  class resources and those items noted below, I have neither
*  given nor received any assistance on this project.
*
*  References not otherwise commented within the program source code.
*  Note that you should not mention any help from the TAs, the professor,
*  or any code taken from the class textbooks.
*/

#ifndef MTFL_h
#define MTFL_h

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <sstream>


#include "Exceptions_v3.h"




//#define DEBUG_MTFL_POP_BACK
//#define DEBUG_COPY_LIST
#define DEBUG_MTFL_INSERT

using std::invalid_argument;
using std::string;
using std::endl;
using std::cout;
using std::out_of_range;

const int LOOP_OUTPUT_FREQUENCY = 5000;
const int SORT_OUTPUT_FREQUENCY = 750;

/**********************************************************
 *                                                        *
 *                                                        *
 *                  Project #1 classes                    *
 *                                                        *
 *                                                        *
 **********************************************************/



/****************************************************************************
 *                                                                          *
 *                       class Node declaration                             *
 *                                                                          *
 ****************************************************************************/


template <typename T>
class Node
{
public:
    T info;
    Node<T> *next;
   
    Node(T = T()); //Node<T> *next = NULL);
    //T infoValue = T(), Node<T> *nPtr = NULL

}; //END declaration templatized class Node

/****************************************************************************
 *                                                                          *
 *                        class MTFL declaration                              *
 *                                                                          *
 ****************************************************************************/
//Move to Front List

template <typename T>
class MTFL
{
     template <typename F>
     friend std::ostream& operator<<(std::ostream& os, const MTFL<F> &rhsObj);
     
private:
    unsigned long count;
     Node<T> *header;
     Node<T> *trailer;
     //Node<T> *addMe;
     void copyList(const MTFL<T>&);
     void initialize();
     
     void remove(unsigned long ndx);
     
public:
    int traversals = 0;
    
    MTFL();
    ~MTFL();
    
    void insert(T);
    
    void pop_front();
    
    void clear();
    
    unsigned long size() const {return count;}
    
    void print();
    void query(T querable);
    
    T& at(unsigned long location) const;
    T& operator[](unsigned long ndx) const;

    
}; //END declaration templatized class MTFL


/****************************************************************************
 ****************************************************************************
 **                                                                        **
 **                      class Node implementation                         **
 **                                                                        **
 ****************************************************************************
 ****************************************************************************/



/****************************************************************************
 *                         default constructor                              *
 ****************************************************************************/

template <typename T>
Node<T>::Node(T infoValue)
{
    
    //Commented out the cout statements I used for debugging purposes
    
    //cout << "in the default node constructor" << endl;

    //when creating node all data members are set to the default values in the prototype in the
    //class declaration.
    
    //cout << "setting the info of the node to paramter infoValue" << endl;
    info = infoValue;
    
    //cout << "assigning the next pointer to paramter nPtr" << endl;
    //next = nPtr;

   //cout << "finished assigning pointer in node" << endl;

} //END Node<T>::Node(T infoValue, Node *nodePtr)

/****************************************************************************
****************************************************************************
**                                                                        **
**                       class MTFL implementation                          **
**                                                                        **
****************************************************************************
****************************************************************************/

/****************************************************************************
 *                 private method initialize of MTFL class                    *
 ****************************************************************************/

template <typename T>
void MTFL<T>::initialize()
{

    //commented out the cout statements used for debugging
    
    //cout << "creating header node" << endl;
    header = new Node<T>;
    
    //cout << "creating trailer node" << endl;
    trailer = new Node<T>;
    
    //these statements make the header and trailer node point to each other and their
    // dangling pointers point to themselves, which initializes the list to an empty list
    
    header->next = trailer;
    
    trailer->next = trailer;
    
    count = 0;
    
} //END private method MTFL<T>::initialize

/****************************************************************************
 *                         default constructor                              *
 ****************************************************************************/

template <typename T>
MTFL<T>::MTFL()
{
    
    this->initialize();

    
} //END default constructor for MTFL class


/****************************************************************************
 *                         destructor of MTFL class                           *
 ****************************************************************************/

template <typename T>
MTFL<T>::~MTFL()
{
    //destructor
    //std::cout << "MTFL<T>::~MTFL() Entered destructor for class MTFL<T>\n";
    
    this->clear();
    
    delete header;
    delete trailer;
    
    //delete addMe;
    
    
    //std::cout << "MTFL<T>::~MTFL() Exiting destructor for class MTFL<T>\n";
    
} //END MTFL<T>::~MTFL()

/****************************************************************************
 *                         member function clear                            *
 ****************************************************************************/

template <typename T>
void MTFL<T>::clear()
{
    
    std::cout << "\tMTFL<T>::clear() preparing to remove " << count;
    std::cout << " Nodes from the linked list\n";
    
    unsigned long deleteCount = 0;
    while ( header->next != trailer )
    {
        this->remove(0);
        deleteCount++;
    }//END while
    
    header->next = trailer;
    
    std::cout << "\tMTFL<T>::clear() removed " << deleteCount << " Nodes from the list\n";
    std::cout << "\tMTFL<T>::clear() new count is: " << count << std::endl;
    
} //END MTFL<T>::clear()

/****************************************************************************
 *                 private method remove of MTFL class                        *
 ****************************************************************************/
// Removes the object at the specified index (ndx) on the list.

template <typename T>
void MTFL<T>::remove(unsigned long ndx)
{
    
    cout << "About to remove index number " << ndx << endl;
    
    if (ndx<0 || ndx > count-1)
    {
        //cout << "out of range" << endl;
        throw out_of_range("parameter passed to the remove function not within range");
    }//END if
    else
    {
        
        Node<T> *current = header->next;
        Node<T> *trailCurrent = header;
        int compareNdx = 0;
        
        while (current != trailer && compareNdx != ndx) //current->info != ndx
        {
            trailCurrent = trailCurrent -> next;
            current = current->next;
            compareNdx++;
            
            //This portion moves the current pointer along the linked list until
            //current is pointing to the value I want to delete and trailCurrent is behind it
            
        }//END while
        if (compareNdx == ndx)
        {
            
            trailCurrent->next = current -> next;
            
            current -> next = NULL;
            
            current = NULL;
            trailCurrent = NULL;

            
            
            //This portion moves the next pointer of the object in front of the object getting
            // deleted to the object in front of the one getting deleted so no dangling pointers
            // or memory leaks occur. Then it deletes the desired object from the linked list.
            
            count--;
            //This decreases count by one because now the total number of objects on the linked list
            // has decreased by one
            
        }//END if
    }//END else
}//END function remove


/****************************************************************************
 *                         member function insert                           *
 ****************************************************************************/
// Inserts a new node object between two existing nodes already on the doubly-linked list.

template <typename T>
void MTFL<T>::insert(T infoToAdd)
{
 
#ifdef DEBUG_MTFL_INSERT
        cout << "Entered function MTFL<T>::insert() " << endl;
#endif

    //cout << "Entered function MTFL<T>::insert() " << endl;

        
    Node<T> *addMe = new Node<T>(infoToAdd);
    
    //addMe = new Node<T>(infoToAdd);
    
    addMe -> next = header -> next;
    
    //cout << "addMe's info is: " << addMe->info <<endl;
        
    header->next = addMe;
    //This connects header to the added node (since it is now at index 0)
        
    count++;
        
    
    
    //cout << "Exiting function MTFL<T>::insert() " << endl;
    
#ifdef DEBUG_MTFL_INSERT
    cout << "Exiting function MTFL<T>::insert() " << endl;
#endif
    
} //END memmber function insert

/****************************************************************************
 *                         member function print                            *
 ****************************************************************************/

template <typename T>
void MTFL<T>::print()
{
    Node<T> *current1;
    current1 = header -> next;
    while (current1 != trailer)
    {
        cout << current1 -> info << endl;
        current1 = current1 -> next;
    }
    current1 = NULL;
}

/****************************************************************************
 *                         member function query                            *
 ****************************************************************************/

template <typename T>
void MTFL<T>::query(T querable)
{
    int removal_ndx = 0;
    Node<T> *current2;
    Node<T> *trailCurrent2;
    
    //for debugging
    //cout << "Looking for the value: " << querable << endl;
    
    current2 = header -> next;
    trailCurrent2 = header;
    
    while(current2 -> info != querable && current2 != trailer)
    {
        //below line used for debugging
        //cout << "current 2's info is: " << current2->info << endl;
        
        current2 = current2 -> next;
        trailCurrent2 = trailCurrent2 -> next;
        traversals++;
        
        //removal_ndx++;
    }
    if (current2 -> info == querable)
    {
        //cout << "The number of traversals is: " << traversals << endl;
        //T infoToMove = current2 -> info;
        
        trailCurrent2 -> next = current2 -> next;
        current2 -> next = header -> next;
        header -> next = current2;
        
        //for debugging
        //cout << "the removal index is: " << removal_ndx << endl;
        
        //this -> remove(removal_ndx);
        //this -> insert(infoToMove);
        
        
        removal_ndx = 0;
        current2 = NULL;
        trailCurrent2 = NULL;
        
        //instead re-arrange pointers don't call remove
    }
    
    else //if (current2 == trailer)
    {
        //for debugging
        //cout << "Element not found in list" << endl;
        //cout << "The number of traversals is: " << traversals << endl;
        
        removal_ndx = 0;
        current2 = NULL;
        
    }
    
}

/****************************************************************************
 *                         member function at const                         *
 ****************************************************************************/
//This method returns a reference to the info data member of the object at the specified index on
// the list. Valid values for the location parameter are zero through count minus one.

//Same purpose as [] overloaded operator but uses different syntax ex) a.at(5) will return the info
//of the 5th node on the list

template <typename T>
T& MTFL<T>::at(unsigned long location) const
{

    if (location < 0 || location > count-1)
    {
        //cout << "out of range" << endl;
        throw out_of_range("location not within range[0,count-1] for at function");
    }//END if
    
    else
    {
        
        Node<T> *current = header->next;

        for ( unsigned long i = 0; i < location && current != trailer; i++ )
        {
            current = current->next;
        }

        //T *infoToreturn = current -> info;

        //return &infoToreturn;
        return current->info;

    }//END else

} //END MTFL::at(int location)


/****************************************************************************
 *                       overloaded operator[] const                        *
 ****************************************************************************/
//Returns a reference to the info data member of the object at the specified index on the list.
//Valid values for the location parameter are zero through count minus one.

//Same purpose as at function but can use different syntax ex) a[5] will return the info of the
//5th node on the list

template <typename T>
T& MTFL<T>::operator[](unsigned long ndx) const
{
    if (ndx < 0 || ndx > count-1)
    {
        //cout << "out of range" << endl;
        throw out_of_range("location not within range[0,count-1] for [] operator");
    }//END if
    
    else
    {
        return this->at(ndx);
    }//END else

} //END overloaded subscript operator


#endif /* MTFL_h */
