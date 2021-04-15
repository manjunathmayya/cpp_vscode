#include <iostream>
#include <string>

using namespace std;

template <class T>
struct Node
{
    T data;
    Node<T> * link;
};

template <class T>
class Stack
{
    public:
    Node<T> * top;

    Stack()
    {
        top = NULL;
    }

    void push(T data)
    {
        Node<T> * temp = new Node<T>();
        temp->data = data;
        temp->link = NULL;

        if (top == NULL)
        {
            top = temp;
        }
        else
        {
            temp->link = top;
            top = temp;
        }
    }

    T pop()
    {
        T data = top->data;
        cout << "Pop              : "<< data << endl;

        top = top->link;
        return data;
    }

    void print()
    {
        Node<T> * temp = top;
        while(temp != NULL)
        {
            cout << temp->data << "    ";
            temp = temp->link;
        }
    }
    
    void print_reverse(Node<T> * node)
    {
        while(node == NULL)
            return;
        
        print_reverse(node->link);
        cout << node->data << "    ";        
    }
};

int main()
{
    Stack<int> stack;
    for(int index = 0; index < 15; index++)
    {
        stack.push(index);
    }
    
    stack.pop();
    stack.pop();
    cout << "Printing stack   : ";   stack.print();                    cout << endl;
    cout << "Printing reverse : ";   stack.print_reverse(stack.top);   cout << endl;
}