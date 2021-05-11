/*  Name: Xin Zhang
 *  USC NetID: xzhang55     USC-ID:4998-6225-16
 *  CS 455 Sping 2021
 *
 *  See ecListFuncs.h for specification of each function.
 *
 *  NOTE: remove the print statements below as you implement each function
 *  or you will receive no credit for that function
 *
 */

#include <string>
#include <string.h>
#include <cassert>

// for istringstream
#include <sstream>

// iostream only needed for the "not implemented yet" messages in starter code
#include <iostream>

#include "ecListFuncs.h"

using namespace std;

// *********************************************************
// Node constructors: do not change
Node::Node(int item) { 
   data = item;
   next = NULL;
}

Node::Node(int item, Node *n) {
   data = item;
   next = n;
}
// *********************************************************


ListType buildList(const string & listString) {
   
   ListType list = NULL;
   Node *cur_list = list;
   
   istringstream my_stream(listString);
   string in;
   int count = 0;
   
   while(my_stream >> in){
      assert(strspn( in.c_str(), "-.0123456789" ) == in.size());

      int value = stoi(in);
      Node *newNode = new Node(value);
      if (count == 0){
         list = newNode;
         cur_list = list;
         count ++;
         continue;
      }
      cur_list->next = newNode;
      cur_list = cur_list->next;
   }

   return list;  
}


string listToString(ListType list) {
   string start = "(";
   string end = ")";
   
   Node *cur_list = list;
   
   while (cur_list != NULL){
      start += to_string(cur_list->data) + " ";
      cur_list = cur_list->next;
   }
   if (start.length() > 1){
      start.erase(start.begin()+start.length()-1);
   }
   start += end;
   
   return start;  
}


void removeLastInstance(ListType & list, int target) {
   Node * cur_list = list;
   int count = 0;
   int pos = -1;
   while (cur_list != NULL){
      if (cur_list->data == target){
         pos = count;
      }
      cur_list = cur_list->next;
      count ++;
   }
   
   if (pos == -1){
      return;
   }
    
   Node *left = list;
   if(pos == 0){
      list = list->next;
      delete left;
      return;
   }
   
   for (int i=0; i<pos-1; i++){
      left = left->next;
   }
   Node *del = left->next;
   left->next = left->next->next;
   delete del;
}



void splitAtIndex(ListType &list, int index, ListType &a, ListType &b) {

   assert(index >= 0);
   
   if (index == 0){
      a = NULL;
      b = list->next;
      list->next = NULL;
      list = NULL;
      delete list;
      return;
   }
   
   a = list;
   b = NULL;
   int count = 0;
   
   while (list != NULL){
      if (count == index-1){
         if(list->next != NULL){    
            b = list->next->next;
         }
         Node * del_node = list->next;
         list->next = NULL;
         delete del_node;
      }
      list = list->next;
      count ++;
   }
  
}

