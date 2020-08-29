#include <stdlib.h>
#include <iostream>

#include "linked_list.h"

using std::cout;
using std::endl;

/*********************************************************************
** Function: Linked_List()
** Description: Default constructor of Linked list class
** Parameters: none
** Pre-Conditions: Values of linked list unitialized 
** Post-Conditions: Values of linked list initialized 
*********************************************************************/
Linked_List::Linked_List()
{
    cout << "Default constructor of linked list called" << endl;
    this->length = 0;
    this->head = NULL;
}

/*********************************************************************
** Function: get_length()
** Description: Loops through the list and counts each node
** Parameters: none
** Pre-Conditions: Length unknown
** Post-Conditions: Returns length of list
*********************************************************************/
int Linked_List::get_length()
{

    int count = 0; // Counts the nodes
    Node *current = head;
    while (current != NULL)
    {
        count++;
        current = current->next;
    }
    this->length = count;

    return this->length;
}

/*********************************************************************
** Function: print
** Description: Displays each value in the list
** Parameters: none
** Pre-Conditions: List not displayed to console
** Post-Conditions: List displayed to console
*********************************************************************/
void Linked_List::print()
{

    Node *list;
    list = head;

    while (list != NULL)
    {

        cout << " " << list->val;
        list = list->next;
    }
    cout << endl;
}

/*********************************************************************
** Function: clear()
** Description: Clears and deletes nodes in list
** Parameters: none
** Pre-Conditions: List is full of elements
** Post-Conditions: List has been emptied and memory freed
*********************************************************************/
void Linked_List::clear()
{
    Node *temp = head;
    while (temp != NULL)
    {
        delete temp;
        temp = temp->next;
    }
    head = NULL;
}

/*********************************************************************
** Function: push_front()
** Description: Places a value at the start
** Parameters: int
** Pre-Conditions: List is size X
** Post-Conditions: List is size X + 1
*********************************************************************/
void Linked_List::push_front(int addnum)
{

    Node *new_node = new Node();

    new_node->val = addnum;

    new_node->next = head;

    head = new_node;
}

/*********************************************************************
** Function: push_back()
** Description: Pushes a value to the end of the list
** Parameters: int
** Pre-Conditions: List size X
** Post-Conditions: List size X + 1
*********************************************************************/
void Linked_List::push_back(int addnum)
{

    if (head == NULL)
    {
        cout << "previous one was null" << endl;
        return;
    }

    Node *temp = new Node();

    temp->val = addnum;

    temp->next = NULL;

    Node *last = new Node();
    Node *del = last; //Array for deleting the last list
    last = head;

    while (last->next != NULL)
    {
        last = last->next;
    }
    last->next = temp;

    //Free the memory of last
    while (del != NULL)
    {
        delete del;
        del = del->next;
    }

    last = NULL;
}

/*********************************************************************
** Function: insert()
** Description: Inserts a value at a specified index
** Parameters: int, unsigned int
** Pre-Conditions: Value not inserted. List size X
** Post-Conditions: Value inserted. List size X + 1
*********************************************************************/
void Linked_List::insert(int val, unsigned int index)
{

    if (index < 0 || index > this->length)
    {
        cout << "That index is out of bounds, value could not be entered" << endl;
        return;
    }

    //create some nodes and temps
    Node *new_node = new Node();
    Node *curr_pos = head;
    Node *prev = NULL;

    new_node->val = val;
    new_node->next = NULL;

    if (head == NULL)
    {
        //if head is null and position is zero then exit.
        if (index != 0)
        {
            return;
        }
        else
        { //node set to the head.
            head = new_node;
        }
    }

    if (head != NULL && index == 0)
    {
        new_node->next = head;
        head = new_node;
        this->length++;
        return;
    }

    int i = 0;

    while (i < index)
    {
        prev = curr_pos;
        curr_pos = curr_pos->next;

        if (curr_pos == NULL)
        {
            break;
        }

        i++;
    }

    new_node->next = curr_pos;
    prev->next = new_node;
}

/*********************************************************************
** Function: MergeSort()
** Description: Recursively sorts through the list and splits nodes then merges
** Parameters: Node **
** Pre-Conditions: List not sorted or split
** Post-Conditions: List split and sorted
*********************************************************************/
//Sort the linked list and split. Recursively sort through until done
void Linked_List::MergeSort(Node **headRef)
{
    Node *head = *headRef;
    Node *a;
    Node *b;

    /* Base case -- length 0 or 1 */
    if ((head == NULL) || (head->next == NULL))
    {
        return;
    }

    /* Split head into 'a' and 'b' sublists */
    FrontBackSplit(head, &a, &b);

    /* Recursively sort the sublists */
    MergeSort(&a);
    MergeSort(&b);

    /* answer = merge the two sorted lists together */
    *headRef = SortedMerge(a, b);
}

Node *Linked_List::SortedMerge(Node *a, Node *b)
{
    Node *result = NULL;

    /* Base cases */
    if (a == NULL)
        return (b);
    else if (b == NULL)
        return (a);

    /* Pick either a or b, and recur */
    if (a->val <= b->val)
    {
        result = a;
        result->next = SortedMerge(a->next, b);
    }
    else
    {
        result = b;
        result->next = SortedMerge(a, b->next);
    }
    return (result);
}

/*********************************************************************
** Function: FrontBackSplit()
** Description: Splits the nodes
** Parameters: Node *, Node **, Node **
** Pre-Conditions: Nodes not split
** Post-Conditions: Nodes are split
*********************************************************************/
//Split the nodes using the Front/Back split method
void Linked_List::FrontBackSplit(Node *source, Node **frontRef, Node **backRef)
{
    Node *fast;
    Node *slow;
    slow = source;
    fast = source->next;

    /* Advance 'fast' two nodes, and advance 'slow' one node */
    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }

    /* 'slow' is before the midpoint in the list, so split it in two  
    at that point. */
    *frontRef = source;
    *backRef = slow->next;
    slow->next = NULL;
}

/*********************************************************************
** Function: sort_ascending()
** Description: Sorts the list by values in ascending order
** Parameters: none
** Pre-Conditions: List unsorted
** Post-Conditions: List sorted in ascending order
*********************************************************************/
void Linked_List::sort_ascending()
{
    //Create a temp list
    Node *temp;
    //Set temp linked list to equal head
    temp = head;

    //Use MergeSort to sort linked list
    MergeSort(&temp);

    //Set our original list to the new organized one
    head = temp;
}

/*********************************************************************
** Function: sort_descending()
** Description: Sorts the list by values in descending orders
** Parameters: none
** Pre-Conditions: List unsorted
** Post-Conditions: List sorted in descending order
*********************************************************************/
void Linked_List::sort_descending()
{
    //Sort it in ascending first
    //Create a temp list
    Node *temp;
    //Set temp linked list to equal head
    temp = head;

    //Use MergeSort to sort linked list
    MergeSort(&temp);
    head = temp;
    //Then reverse the list
    // Initialize current, previous and
    // next pointers
    Node *current = head;
    Node *prev = NULL, *next = NULL;

    while (current != NULL)
    {
        // Store next
        next = current->next;

        // Reverse current node's pointer
        current->next = prev;

        // Move pointers one position ahead.
        prev = current;
        current = next;
    }
    head = prev;
}

/*********************************************************************
** Function: get_value
** Description: Returns the value of a specified index
** Parameters: int
** Pre-Conditions: Value of index unknown
** Post-Conditions: Value of index known
*********************************************************************/
//Get the value from index
int Linked_List::get_value(int index)
{
    Node *temp = head;
    // cout << "index " << index << endl;
    if (index == 0)
    {
        return temp->val;
    }
    else
    {
        for (int i = 0; i < index; i++)
        {
            temp = temp->next;
        }
        return temp->val;
    }
}