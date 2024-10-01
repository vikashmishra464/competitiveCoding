// Question Link:https://www.geeksforgeeks.org/problems/multiply-two-linked-lists/1

// Question :
// Multiply two linked lists
// Difficulty: EasyAccuracy: 46.33%Submissions: 65K+Points: 2
// Given elements as nodes of the two singly linked lists. The task is to multiply these two linked lists, say L1 and L2.

// Note: The output could be large take modulo 10^9+7.

// Examples :

// Input: LinkedList L1 : 3->2 , LinkedList L2 : 2
// Output: 64
// Explanation: 

// Multiplication of 32 and 2 gives 64.
// Input: LinkedList L1: 1->0->0 , LinkedList L2 : 1->0
// Output: 1000
// Explanation: 

// Multiplication of 100 and 10 gives 1000.
// Expected Time Complexity: O(max(n,m))
// Expected Auxilliary Space: O(1)
// where n is the size of L1 and m is the size of L2

// Constraints:
// 1 <= number of nodes <= 105
// 1 <= node->data <= 103

// Soltion:

class solution {
  public:
    long long multiplyTwoLists(Node *first, Node *second) {
        long long mod=1e9+7;
        long long a=0;
        long long mul=10;
        while(first){
            a=(((a*10)%mod)+(first->data)%mod)%mod;
            first=first->next;
        }
        long long b=0;
        while(second){
            b=(((b*10)%mod)+(second->data)%mod)%mod;
            second=second->next;
        }
        long long ans=((a%mod)*(b%mod))%mod;
        return ans;
    }
};
