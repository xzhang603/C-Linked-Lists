/*  Name: Xin Zhang
 *  USC NetID: xzhang55     USC-ID: 4998-6225-16
 *  CS 455 Sping 2021
 *  Extra credit assignment
 *
 *  ectest.cpp
 *
 *  a non-interactive test program to test the functions described in ecListFuncs.h
 *
 *    to run it use the command:   ectest
 *
 *  Note: this uses separate compilation.  You put your list code ecListFuncs.cpp
 *  Code in this file should call those functions.
 */


#include <iostream>
#include <string>
#include <string.h>
#include <cassert>
#include "ecListFuncs.h"
#include <sstream>

using namespace std;

//Print the Test result of List to String
//Input is String, and I convert String to List in the function.
void Test_ListToStr(string str);

//Print the test result of String to List
//Input is String we want to test
void Test_StrToList(string str);

//Print the actual result of remove last instance function
//Input String we want to test; target
//Output actual result of removed string
string Test_Remove(string str, int target);

//Print the actual result of Split fucntion
//Input: Original List list; index we want to divide; return list a; return list b
void Test_Split(ListType &list, int index, ListType &a, ListType &b);

//Return the element in list as String
//Input: list we want to test
//Output: the String of list
string printList(ListType & list);

//Compare the difference of two string
//Input: string actual, string expect
void compare(string actual, string expect);
   
int main ()
{
   
   cout<<"Test List To String**********************************************************"<< endl;
   Test_ListToStr("");
   Test_ListToStr("3");
   Test_ListToStr("3 4 5");
   
   cout<<"Test String to List**********************************************************"<< endl;
   Test_StrToList("");
   Test_StrToList("-32");
   Test_StrToList("      -32");
   Test_StrToList("1 3 2");
   Test_StrToList("   1 3 2");
   
   cout <<"Test Remove Target**********************************************************"<<endl;
   string remove1 = Test_Remove("1 2 3 4 5 6 5", 5);
   string expect1 = "(1 2 3 4 5 6)";
   cout << "The expect result is: " << expect1<<endl;
   compare(remove1, expect1);
   
   string remove2 = Test_Remove("1 2 3 4", 10);
   string expect2 = "(1 2 3 4)";
   cout << "The expect result is: " << expect2<<endl;
   compare(remove2, expect2);
   
   string remove3 = Test_Remove("1 1 1 2 3", 1);
   string expect3 = "(1 1 2 3)";
   cout << "The expect result is: " << expect3<<endl;
   compare(remove3, expect3);
   
   cout <<"Test Split List*************************************************************"<<endl;
   Node * a = NULL;
   Node * b = NULL;
   
   Node* res1 = buildList("7 4 4 3 9");
   Test_Split(res1, 2, a, b);
   
   Node* res2 = buildList("7 4 2 3 9");
   Test_Split(res2, 0, a, b);
   
   Node* res3 = buildList("1 2 3 3 2");
   Test_Split(res3, 4, a, b);
   
   Node* res4 = buildList("");
   Test_Split(res4, 3, a, b);
   
   Node* res5 = buildList("7 2 3");
   Test_Split(res5, 2, a, b);
   
   Node* res6 = buildList("7 2 3");
   Test_Split(res6, 3, a, b);
   
   Node* res7 = buildList("3");
   Test_Split(res7, 0, a, b);
   
   Node* res8 = buildList("3 5");
   Test_Split(res8, 0, a, b);
   
   Node* res9 = buildList("3 5");
   Test_Split(res9, 1, a, b);

   return 0;
}


//Function for testing ******************************************
//Declared at the begining.

void Test_ListToStr(string str){
   Node* res = buildList(str);
   cout << "The original String is: " << str <<endl;
   
   //Get Expected Result
   istringstream my_stream(str);
   string in;
   string expect = "(";
   while(my_stream >> in){
      assert(strspn( in.c_str(), "-.0123456789" ) == in.size());
      int value = stoi(in);
      expect += to_string(value) + " ";
   }
   if (expect.length() > 1){
      expect.erase(expect.begin()+expect.length()-1);
   }
   expect += ")";
   
   //Get Actual Result
   string actual = listToString(res);
   cout << "The expect result is: " << expect <<endl;
   cout << "The actual result is: " << actual <<endl;
   
   if (expect != actual){
      cout << "Error: The result is false." << endl;
   }
   else{
      cout << "Correct!" << endl;
   }
   cout<<endl;
   
}


void Test_StrToList(string str){
   Node* res = buildList(str);
   cout << "The original String is: " << str <<endl;
   
   //Print expect Result
   istringstream my_stream(str);
   string in;
   string expect = "";
   while(my_stream >> in){
      assert(strspn( in.c_str(), "-.0123456789" ) == in.size());
      int value = stoi(in);
      expect += to_string(value) + " ";
   }
   
   cout << "The expect result is: " << expect <<endl;
   
   //Print actual result
   string actual = printList(res);
   cout << "The actual result is: " << actual <<endl;
   
   if (expect != actual){
      cout << "Error: The result is false." << endl;
   }
   else{
      cout << "Correct!" << endl;
   }
   cout<<endl;
}


string Test_Remove(string str, int target){
   Node* res = buildList(str);
   cout << "The original String is: " << str <<endl;
   cout << "The target we want to remove is: " << target <<endl;
   removeLastInstance(res, target);
   string actual = listToString(res);
   cout << "The actual result is: " << actual << endl;
   return actual;
}


void Test_Split(ListType &list, int index, ListType &a, ListType &b){
   string org = listToString(list);
   cout << "The original list is: " << org << "    " << "Index is: " << index << endl;
   
   splitAtIndex(list, index, a, b);
   string sa = listToString(a);
   string sb = listToString(b);
   string slist = listToString(list);

   cout << "The actual list a is: " << sa <<endl;
   cout << "The actual list b is: " << sb <<endl;
   cout << "The actual list list is: " << slist <<endl;
   cout << endl;
} 


void compare(string actual, string expect){
   if (expect != actual){
      cout << "Error: The result is false." << endl;
   }
   else{
      cout << "Correct!" << endl;
   }
   cout<<endl;
}


string printList(ListType & list){
   Node *cur_list = list;
   string res = "";
   while (cur_list != NULL){
      res += to_string(cur_list->data) + " ";
      cur_list = cur_list->next;
   }
   return res;
}
