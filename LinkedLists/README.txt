
Name: Katie Blickenstaff
ONID: blickenk
CS 162 Section 01
Assignment #4

Description: A program that creates a linked list and asked us to implement several functions. 
The test_linked_list.cpp file contains the main function of the program that will be used to create our linked list and test each function. 


Instructions: 
1. Compile the program with make
2. Run the program with ./test_linked_list command
3. Hit enter to conduct each test
4. Program ends once each test is done

Limitations:

Complexity Analysis: 
    a) sort_ascending()
        This function uses the merge sort algorithm for linked lists. This algorithm has a time complexity of O(n*log n)
    b) sort_descending()
        This function will also utilize the merge sort algorithm to first sort the list by ascending order and then it will reverse the order of the entire list. 
        This algorithm has a time complexity of O(n*log n)
    c) count_prime()
        This algorithm will loop through each node in the list and check to see if it's a prime number. The time complexity would be O(N*sqrt(p))