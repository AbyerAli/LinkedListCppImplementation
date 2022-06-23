#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node(int data)
    {
        this->data = data;
        next = NULL;
    }
};
class linkedList
{
    node *head;
    node *tail;
    bool isEmpty()
    {
        return head == NULL;
    }
    void setHead(node *head)
    {
        this->head = head;
    }

    void setTail(node *tail)
    {
        this->tail = tail;
    }

public:
    linkedList()
    {
        setHead(NULL);
        setTail(NULL);
    }
    node *getHead()
    {
        return head;
    }
    node *getTail()
    {
        return this->tail;
    }
    void addOnTail(node *newNode)
    {
        if (isEmpty())
        {
            addOnHead(newNode);
        }
        else
        {
            getTail()->next = newNode;
            setTail(newNode);
        }
    }
    void addOnHead(node *newNode)
    {
        if (isEmpty())
        {
            setHead(newNode);
            setTail(newNode);
        }
        else
        {
            if (getHead()->next == NULL)
            {
                setTail(newNode);
            }
            newNode->next = getHead()->next;
            getHead()->next = newNode;
        }
    }

    void display()
    {
        cout << "Head: " << getHead()->data << " Tail: " << getTail()->data << endl;
        node *tempNode = getHead();
        while (tempNode != NULL)
        {
            cout << tempNode->data << endl;
            tempNode = tempNode->next;
        }
    }
    void PrintRecursively(node *head)
    {
        if (head == NULL)
        {
            return;
        }

        PrintRecursively(head->next);
        cout << "Data: " << head->data << endl;
    }
};

int main()
{
    linkedList list;
    list.addOnTail(new node(11));
    list.addOnTail(new node(22));
    list.addOnTail(new node(22));
    list.addOnTail(new node(33));
    list.addOnTail(new node(44));
    list.addOnTail(new node(55));
    list.PrintRecursively(list.getHead());
}