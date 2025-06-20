#include <iostream>
using namespace std;

class ListNode
{
    public:
    int value;
    ListNode* next;
    ListNode(int val)
    {
        value = val;
        next = nullptr;
    }
};

void insertAtHead(ListNode*& head, int val)
{
    ListNode* newNode = new ListNode(val);
    newNode->next = head;
    head = newNode;
}

void insertAtTail(ListNode*& head, int val)
{
    ListNode* newNode = new ListNode(val);

    if(!head)
    {
        head = newNode;
        return;
    }

    ListNode* currNode = head;
    while(currNode->next) currNode=currNode->next;
    currNode->next = newNode;
}

void insertAtPos(ListNode*& head, int val, int pos)
{
    if(pos==0)
    {
        insertAtHead(head, val);
        return;
    }

    ListNode* currNode = head;
    for(int i=0;i < pos - 1; i++)
    {
        currNode= currNode->next;
    }
    if(!currNode) return;

    ListNode* newNode = new ListNode(val);
    newNode->next = currNode->next;
    currNode->next = newNode;
}

void deleteAtHead(ListNode*& head)
{
    if(!head) return;
    ListNode* temp = head;
    head= head->next;
    delete temp;
}

void deleteAtPos(ListNode*& head, int pos)
{
    if(pos==0)
    {
        deleteAtHead(head);
        return;
    }
    ListNode* currNode = head;
    ListNode* prevNode;
    for(int i = 0; i < pos-1 && currNode && currNode->next; i++)
    {
        currNode = currNode->next;
    }
    if(!currNode) return;

    ListNode* temp = currNode->next;

    currNode->next = temp->next;
    delete temp;

}

ListNode* reverseLinkedList(ListNode*& head)
{
    ListNode* curr = head;
    ListNode* prev = nullptr;

    while(curr)
    {
        ListNode* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev;
}

int main()
{
    ListNode* Node = nullptr;

    insertAtHead(Node, 3);
    insertAtTail(Node, 5);
    insertAtPos(Node, 4, 1); // List: 3 -> 4 -> 5

    Node = reverseLinkedList(Node); // List: 5 -> 4 -> 3

    // Optional: print the list
    ListNode* temp = Node;
    while (temp) {
        cout << temp->value << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;

    return 0;
}