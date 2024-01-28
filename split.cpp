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

  //initialzing the lists to be empty
  odds = NULL;
  evens = NULL;

  //while their is values in the input list
  while(in != NULL)
  {
    //pointer that keeps track of the current node
    Node* curr = in;
    in = in->next;

    //checking if val is even
    if (curr->value % 2 == 0)
    {
      //add to correct list
      curr->next = evens;
      evens = curr;

    }
    //checking if odd
    else
    {
      //adding to list
      curr->next = odds;
      odds = curr;
    }
  }
  
}

/* If you needed a helper function, write it here */
