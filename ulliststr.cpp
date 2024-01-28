#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE
//push back function
void ULListStr::push_back(const std::string& val)
{
  //checking to see if there is a head tail
  if(!head_ && !tail_)
  {
    //creating a new node and initializing room
    Item* node = new Item();
    head_ = node;
    tail_ = node;
    node -> val[0] = val;
    node -> last = 1;
  }
  //check if there is room to add a node
  else if(tail_ -> last < ARRSIZE && tail_)
  {
    //adding value to end of node and incrementing
    tail_->val[tail_->last] = val;
    tail_->last++;
  }
  else
  {
    //if there is no room create a new node
    Item* node = new Item();
    tail_->next = node;
    node-> prev = tail_;
    tail_ = node;
    node -> val[0] = val;
    node -> last = 1;
  }
  //increment size of linked list
  size_++;
}

void ULListStr::push_front(const std::string& val)
{
  
  //checking to see if there is a head tail
  if(!head_ && !tail_)
  {
    //create and initialize a new node
    Item* node = new Item();
    head_ = node;
    tail_ = node;
    //add value to the array and change the first and last
    node ->val[ARRSIZE-1] = val;
    node -> first = ARRSIZE-1; 
    node -> last = ARRSIZE;
    
  }
  //check if there is room in the start
  else if (head_ && head_ ->first >0)
  {
    //decrement value and add value to array
    head_ ->first--;
    head_ -> val[head_->first] = val;
  }
  //if the node is full create a new hode
  else
  {
    //create new node update head
    Item* node = new Item();
    head_ -> prev = node;
    node -> next = head_;
    head_ = node;
    node -> val[ARRSIZE-1] = val;
    node -> first = ARRSIZE-1; 
    node -> last = ARRSIZE;
  }
  //increment size of linked list
  size_++;
}

void ULListStr::pop_back()
{
  //checkig if the tail node exists
  if (tail_ && tail_ -> last>0)
  {
    tail_ ->last--;
    //check if tail node is empty
    if (tail_ -> last ==0)
    {
      //store tempory pointer and update tail
      Item* tempNode = tail_;
      tail_ = tail_ -> prev;
      //set new tail to NULL
      if(tail_)
      {
        tail_ ->next = NULL;
      }
      else
      {
        head_ = NULL;
      }
      //deallocate
      delete tempNode;
    }
    //decrement size of linked list

    size_ --;
  } 
}

void ULListStr::pop_front()
{
  //check if head node exists
  if(head_)
  {
    //check if the hode is at the start of the array
    if(head_ ->first == ARRSIZE -1)
    {
      //store temporary node and update list
      Item* tempNode = head_;
      head_ = head_ ->next;
      //check if head exits
      if(head_)
      {
        head_ -> prev = NULL;
      }
      else{
        tail_ = NULL;
      }
      //deallocate memory
      delete tempNode;
    }
    else{
      //remove first item 
      head_ ->first++;
    }
    //decrease size
    size_--;
  }
  
}



std::string const & ULListStr::back() const
{
  //returning value at end
  return tail_ -> val[(tail_ ->last)-1];
}
std::string const & ULListStr::front() const
{
  //returning value at start
  return head_ -> val[(head_ ->first)];
}

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}

std::string* ULListStr::getValAtLoc(size_t loc) const
{
  //seeinf if the locaiton is valid
  if (loc >= size_)
  {
    return NULL;
  }

  //setting a current node
  Item* curr = head_;
  size_t currentSize = curr->last - curr->first;
  //walking the list  to fnd the size
  while (loc >= currentSize)
  {
    curr = curr->next;
    currentSize+= curr->last -curr->first;

  }
  //finding the index
  size_t indexOfNode = loc - (currentSize -(curr->last -curr->first));
  return &(curr->val[curr->first + indexOfNode]);
}

