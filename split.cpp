/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"
#include <cstddef>

/* Add a prototype for a helper function here if you need */


void split(Node*& in, Node*& odds, Node*& evens)
{
  /* Add code here */
  // WRITE YOUR CODE HERE
  //Base case for recursion is when list is empty
  if (in == NULL)
  {
    return;
  }
  //current node
  Node* curr = in;
  in = in->next;
  //checking to see if it is even
  if(curr->value%2 == 0)
  {
    curr->next = evens;
    evens = curr;
  }
  //checking if odd
  else
  {
    curr->next = odds;
    odds = curr;
  }
  //recursively calling function
  split(in,odds,evens);
}

/* If you needed a helper function, write it here */
