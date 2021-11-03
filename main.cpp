#include "DoubleNode.hpp"
#include "DoublyLinkedList.hpp"
#include <iostream>
#include <string>
using namespace std;


int main(){
    /*
    DoubleNode<int>first;
    first.setItem(2);
    std::cout << first.getItem();

    first.setItem(5);
    first.setItem(8);
    first.setItem(22);
    
    */

   //uno dos tres quatro
   DoublyLinkedList<string>mylist;
   
   mylist.insert("uno",1);
   mylist.insert("dos",2);
   mylist.insert("tres",3);
   mylist.insert("quatro",4);
   //mylist.insert(5,5);
   //mylist.insert(6,6);
   mylist.display();

   mylist.remove(1);
   mylist.remove(1);
   //mylist.remove(1);
   mylist.display();
   //mylist.displayBackwards();

   //mylist.display();

   //mylist.clear();
    mylist.invert();
    mylist.display();

    //DoublyLinkedList<int>copylist(mylist);
    //copylist.display();

    

}