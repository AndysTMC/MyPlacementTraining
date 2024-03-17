# 1)-----
# Multiplying or Dividing two numbers with bit manipulation

# 2)-----
# Cannot use a variable as a case constant
# Example:
# Switch(condition)
# case x + 1: -> Error

# 3)-----
# Cannot have duplicates in switch case constants
# Example:
# Switch(condition)
# case 1: //code
# case 1: //code -> Error

# 4)-----
# for(__;con1, con2;__) {}

# 5)-----
# import math
# n = int(input())
# result = 0
# ------------------------
# for i in range(1, n+1):
#     print(i, end=" ")
#     for j in range(1, i // 2 + 1):
#         if i % j == 0 and j % 2 == 1:
#             print(j, end=" ")
#         result += 2*j if i % j == 0 and j % 2 == 1 else 0
#     print()
# if n > 1:
#     result += 1
# -------------------------
# for i in range(1, n+1):
#     count = n // i
#     result += i * count
# print(result)

# 6)-----
# Time Complexity and Space Complexity

# 7)-----
# Balanced Search Tree , Multi Way Search Tree

# 8)-----
# Given an integer, what's the sum of the digits of the integer.
# Ans: Except for the number 9, number % 9 can be used to calculate 
# the sum of digits in the number.

# 9)-----
# Log Arithemic Time Complexity O(log(n))

# 10)-----
# Evaluate the time complexity for the below program.
# for(i = 1; i < n; i++) {
#     for(j = 1;; j <= i; j++) {
#         for(k=1; k <= 100; k++) {
#             printf("#");
#         }
#     }
# }
# Ans: O(n^2)

# 11)-----
# Evaluate the time complexity for the below program.
# for(i = 1 to n) {
#     for(j = 1 to i^2) {
#         for(k = 1 to n/2) {
#             printf("#")
#         }
#     }
# }
# 
# Ans: O(n*n*(n+1)*(2n+1)/6*n/2) ~ O(n^4)

# 12)-----
# Evaluate the time complexity for the below program.
# for(i = n/2; i <=n; i++) {
#     for(j = 1; j <= n/2; j++) {
#         for(k = 1; k <= n; k= k*2) {
#             printf("#");
#         }
#     }
# }
# Ans: O(n/2 * n/2 * log(n)) ~ O(n^2*log(n))

# 13)-----
# Print the number of digits in n Factorial
# import math
# n = int(input())
# factorial = 1
# for i in range(n+1):
#     factorial *= i
# print(math.floor(math.log10(factorial)) + 1)
# --------------------- or (The below method is very useful when doing
# in cpp as it helps in not calculating the large numbers..(Calculating the log of them instead))
# logfactorial = 1
# for i in range(n+1):
#     logfactorial += math.log10(i)
# print(math.floor(logfactorial) + 1)

# 14)-----
# Given an integer, from all the prime numbers upto 50, there are k primes
# which can be formed by sum of consecutive primes. Print k
# n = int(input())
# primes = [True] * (n + 1)
# primes[0] = primes[1] = False
# valid_primes = []
# for i in range(2, n + 1):
#     if primes[i]:
#         valid_primes.append(i)
#         j = 2
#         while j * i <= n:
#             primes[j*i] = False
#             j += 1
# k = len(valid_primes)
# i = j = summ = result = 0
# while j < k and summ <= n:
#     while j < k and summ <= n:
#         if primes[summ] and i != j-1:
#             result += 1
#         summ += valid_primes[j]
#         j += 1
#     while i < j and summ > n:
#         summ -= valid_primes[i]
#         i += 1
# print(result)
# -------------------------- 
# Custom isPrime function
# import math
# def isPrime(n):
#     if n == 1:
#         return 0
#     if n == 2 or n == 3:
#         return 1
#     if n % 2 == 0 or n % 3 == 0:
#         return 0
#     for i in range(5, math.sqrt(n)):
#         if n % i == 0:
#             return 0
#     return 1

# 15)-----
# Given an integer k, and an array of integers A.
# A transmitter can cover another transmitter if they are within the range of k
# Example 4 can cover 7 transmitter with a k value of 3
# Print the minimum number of transmitters required to cover all the transmitters
# Complexity is restricted to O(n^2)
# k = 3, A = {1, 9, 3, 7, 4, 2, 10, 13, 11, 14}
# print("Input: ")
# k = int(input())
# A = list(map(int, input().split()))
# A.sort()
# n = len(A)
# result = 0
# prev = A[0]
# for i in range(1, n):
#     if A[i] > prev + k:
#         prev = A[i]
#         result += 1
# print("Output: ")
# print(result)


# a)-----
# Initializing the 'struct' data structure
# #include <stdio.h>
# typedef struct test{int a, b;} Test;
# int main() {
#    Test t = {1, 2}; 
#    t = {1, 2}; //Error
#    Test t = {.b=1, .a=2};  // Designated Initializer
#    printf("%d %d", t.a, t.b);
# -----------------------------(Working with Structuer Pointer)
#    Test *t;
#    t->a = 1, t->b = 2; // Error, as the pointer is not initialized or the pointer cannot be dereferenced
#    t = (Test *)malloc(sizeof(Test)); // Melloc is used to allocate memory
#    t = (Test *)calloc(1, sizeof(Test)); // Calloc is used to allocate memory
#    t->a = 1, t->b = 2; // Works fine
#    printf("%d %d", t->a, t->b);
#    free(t);
#    return 0;
# }

# b)-----
# Playing with Linked List using 'struct' data structure
# struct node {
#     int data;
#     struct node *next; // Pointer to the next node
# }Node; // This is a self referential structure, where the structure is referring to itself
# Node *head = NULL; // Only memory for the pointer is allocated and not for the structure
# Node *head = (Node *)malloc(sizeof(Node)); // The pointer is allocated the memory from the stack and the address it stores is
# the address of the memory allocated from the heap.
# head->data = 1;
# Node *second = (Node *)malloc(sizeof(Node));
# second->data = 2;
# head->next = second;
# // or simply head->next = (Node *)malloc(sizeof(Node));

# c)-----
# Using functions to make operations on Linked List Data Structure
# struct node {
#     int data;
#     struct node *next;
# } Node;
# ---------------------
# Node insertAtBegin(Node *head, int data) {
#     Node *new_node = (Node *)malloc(sizeof(Node));
#     new_node->data = data;
#     new_node->next = head;
#     head = new_node;
#     return head;
# }
# ---------------------
# Node insertAtEnd(Node *head, int data) {
#     Node *new_node = (Node *)malloc(sizeof(Node));
#     new_node->data = data;
#     new_node->next = NULL;
#     if(head == NULL) {
#         head = new_node;
#         return head;
#     }
#     Node *temp = head;
#     while(temp->next != NULL) {
#         temp = temp->next;
#     }
#    temp->next = new_node;
#    return head;
# }
# ---------------------
# Node insertAtPosition(Node *head, int data, int position) {
#     Node *new_node = (Node *)malloc(sizeof(Node));
#     new_node->data = data;
#     if(position == 1) {
#         new_node->next = head;
#         head = new_node;
#         return head;
#     }
#     Node *temp = head;
#     for(int i = 1; i < position - 1; i++) {
#         temp = temp->next;
#     }
#     new_node->next = temp->next;
#     temp->next = new_node;
#     return head;
# }
# ---------------------
# Node deleteAtBegin(Node *head) {
#     if(head == NULL) {
#         return head;
#     }
#     Node *temp = head;
#     head = head->next;
#     free(temp);
#     return head;
# }
# ---------------------
# Node deleteAtEnd(Node *head) {
#     if(head == NULL) {
#         return head;
#     }
#     if(head->next == NULL) {
#         free(head);
#         return NULL;
#     }
#     Node *temp = head;
#     while(temp->next->next != NULL) {
#         temp = temp->next;
#     }
#     free(temp->next);
#     temp->next = NULL;
#     return head;
# }
# ---------------------
# Node deleteAtPosition(Node *head, int position) {
#     if(head == NULL) {
#         return head;
#     }
#     if(position == 1) {
#         Node *temp = head;
#         head = head->next;
#         free(temp);
#         return head;
#     }
#     Node *temp = head;
#     for(int i = 1; i < position - 1; i++) {
#         temp = temp->next;
#     }
#     Node *temp1 = temp->next;
#     temp->next = temp1->next;
#     free(temp1);
#     return head;
# }
# ---------------------
# Node reverseList(Node *head) {
#     Node *prev = NULL, *current = head, *next = NULL;
#     while(current != NULL) {
#         next = current->next;
#         current->next = prev;
#         prev = current;
#         current = next;
#     }
#     head = prev;
#     return head;
# }
# ---------------------(Detecting the loop in the Linked List)
# int detectLoop(Node *head) {
#     Node *slow = head, *fast = head;
#     while(slow && fast && fast->next) {
#         slow = slow->next;    
#         fast = fast->next->next;
#         if(slow == fast) {    
#             return 1;
#         }
#     }
#     return 0;
# }
# ---------------------

# d)-----
# Some Important Points
# * If for an algorithm time complexity is given by O(1) then complexityof it is {answer: constant}
# * The complexity of Fibonacci series {answer: O(2^n)}
# * What does it mean when we say that an algorithm X is asymptotically more efficient than Y? {answer: X will always be a better choice for large inputs }
# * The worst case occur in quick sort when {answer: Pivot is the smallest element}

# e)-----
# Given a person's name, and his/her friend's name
# Return the only friend's name where they have most of the characters in common.(If there are multiple such answers, return the lexicographically 
# smallest name)
# Example: person = "Sagar", friends = ["Sahara", 'Sumith', 'Karthik', 'Sarah', 'Senthil']
# from collections import Counter
# person = input()
# friends = input().split()
# pfreq = Counter(person)
# pset = set(person)
# counts = []
# for friend in friends:
#     counts.append(0)
#     ffreq = Counter(friend)
#     for letter in ffreq:
#         if letter in pset:
#             counts[-1] += min(ffreq[letter], pfreq[letter])
# tresults = []
# maxcount = max(counts)
# for i in range(len(counts)):
#     if counts[i] == maxcount:
#         tresults.append(friends[i]) 
# print(tresults[0])

# f)-----
# Given an array of integers where there are equal number of even and odd integers, place the even integers in the 
# even indices and the odd integers in the odd indices without interrupting their original order of elements,
# Example, Input: A[] = {8, 4, 6, 3, 1, 5, 2, 7}, Output: {}
# n = int(input())
# A = list(map(int, input().split()))
# i = j = 0
# k = 0
# while k < n:
#     if A[k] % 2 == k % 2:
#         continue
#     i = k + 1
#     if k % 2 == 0:
#         while A[i] % 2 != 0:
#             i += 1
#         temp = A[i]
#         j = k
#         while j < i:
#             A[j], A[j+1] = A[j+1], A[j]
#         A[k] = temp
#     else:
#         while A[i] % 2 == 0:
#             i += 1
#         temp = A[i]
#         j = k
#         while j < i:
#             A[j], A[j+1] = A[j+1], A[j]
#         A[k] = temp
# print(A)

# g)-----
# Evaluation by Substitution
# A(n) {
#     if(n > 1)
#         return (A(n-1))
# }
# The recursive equation is T(n) = 1 + T(n-1) ~ O(n)
# A(n) {
#     for(i = 1 to n) 
#     return A(n-1)
# }
# T(n) = n + T(n-1) = n + (n - 1) + T(n-2) =... = O(n*n)
# int fun(int n, int m, int 9) {
#     if (n <= 0) {
#         ...
#     }
#     else {
#         fun(n-1, m + 1, -o);
#         fun(n-1, m, o+1);
#     }
# }
# The recursive equation is T(n) = 1 + T(n-1) + T(n-1) ~ O(2^n)
# Some other equation is T(n) = 1 + T(n/2) ~ O(nlog(n))

# h)-----
# * Do while loop is referred to as the exit control loop
# * While loop is referred to as the entry control loop

