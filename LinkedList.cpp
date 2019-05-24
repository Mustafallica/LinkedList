///////////////////////////////////////////////////////////////////////////////////////
/// simple app to explain linked list in c++ { create, insert, delete }              /
/// Mustafa AL-Jaburi                                                                 /
/// 2018                                                                              /
/// University of houston, DATA STRUCTURE Course - COSC 2430                          /
///////////////////////////////////////////////////////////////////////////////////////


#include <iostream>
#include <alloca.h>
using namespace std;
#define null 0


struct node { // structure to define node { store data and address }
    int data;
    node *next;
};

typedef node *nodeptr;  // node of type nodeptr to point( link ) ..

nodeptr getnode(){   // function to allocate memory and create new node.
    nodeptr q;
    q=(nodeptr) malloc(sizeof(node));
    return q;
}

void print(nodeptr list){
    nodeptr temp = list;
    while (temp!=null) {
        cout << temp->data << " ";
        temp=temp->next;
    }
    cout << endl;
}

void insertFirst(nodeptr &list){   // Function to insert node at the beginning
    int n;
    cout << "Enter Data for first node: ";
    cin >> n;
    nodeptr q;
    q = getnode();
    q->data = n;
    q->next = list; // link the inserted new list to the second list.
    list = q;
}

void insertAfter(nodeptr &p2){  // function to insert data after p2
    int n;
    cout << "Enter data of the inserted node: ";
    cin >> n;
    nodeptr q;
    q = getnode();
    q->data = n;
    q->next = p2->next;
    p2->next = q;
}

void insertLast(nodeptr &list){  // function to insert node data at the end of the list.
    int n;
    cout << "Enter data of the last node: ";
    cin >> n;
    nodeptr q, temp;
    q = getnode();
    q->data = n;
    q->next = null;
    
    // for loop to change the link from p3 to the last inserted node.
    for (temp = list; temp->next!=null; temp=temp->next);{
        temp->next=q;
    }
}

void deleteFirst(nodeptr &list){
    nodeptr q;
    q = list;
    cout << q->data << " is deleted" << endl;
    list = q->next; // list is now pointing to p2
    free(q); // freeing the memory allocation
}

void deleteAfter(nodeptr p){
    nodeptr q;
    q = p->next;
    cout << q->data << " is deleted" << endl;
    p->next = q->next;
    free(q);
}

void deleteLast(nodeptr &list){
    nodeptr p,q;
    p = list;
    while (p->next!=null) {
        q=p;
        p=p->next;
    }
    cout << p->data << " is deleted" << endl;
    q->next = null;
    free(p);
}



int main(){
    
    nodeptr p1, p2, p3;
    nodeptr list; /// head
    
    p1 = getnode(); // allocating memory for p1 in the memory
    p2 = getnode(); // allocating memory for p2 in the memory
    p3 = getnode(); // allocating memory for p2 in the memory
    
    list = p1; // pointing on the begginning of the list. HEAD

    p1->data = 10; // assigning data
    p1->next = p2; // linking p1 to p2

    p2->data = 15; // assigning data
    p2->next = p3; // pointing to the end
    
    p3->data = 20; // assigning data
    p3->next = null; // linking p1 to p2
    
    
    
    ////////////////////////////////////////////////////////
    
    
    
    // Printing and calling functions.
    
    print(list); // printing original list
    
    
    
    
    //// Un-comment below lines to call the CREATE and ADD functions ////
    
    /*
    insertFirst(list); // inserting list after inserting node at the begginning
    print(list); // printing list after inserting node at the begginning
    
    insertAfter(p2); // inserting list after inserting node between p2 and p3
    print(list); // printing list after inserting node between p2 and p3
    
    insertLast(list);
    print(list);
    */
    
    
    
    
    //// Delete Node ////
    
    /*
    deleteFirst(list);
    print(list);
    */
    
    
    /// Delete after a node ///
    
    /*
    deleteAfter(p1);
    print(list);
    */
    
    
    /// Delete last node ///
    
    /*
    deleteLast(list);
    print(list);
    */
    
    
}
