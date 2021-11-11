#include <iostream>
using namespace std;

template<typename type>
struct MyNode
{
    type data = NULL;
    MyNode *next = NULL;
};

template<typename type>
struct MyLinkedList
{
    MyNode<type> *head = NULL,*tail = NULL;
    int length = 0;

    void add(type n)
    {
        auto *tmp = new MyNode<type>;
        tmp->data = n;
        tmp->next = NULL;

        if(head == NULL)
        {
            head = tmp;
            tail = tmp;
        }
        else
        {
            tail->next = tmp;
            tail = tail->next;
        }
        length++;
    }

    void reverse(){
        MyNode<type> *node = head;
        auto *nodes = new MyNode<type>*[length];
        int index = 0;

        while (node->next != NULL) {
            nodes[index] = node;
            node = node->next;
            index++;
        }index--;

        head = nodes[0];
        tail = nodes[index];
        tail->next = NULL;

        for (int i = index; i <= 0; --i) {
            nodes[i]->next = nodes[i-1];
        }
    }

    string toString(){
        MyNode<type> *node = head;
        string str;

        while (node->next != NULL) {
            str = node->data+", ";
            node = node->next;
        }
        return str;
    }
};