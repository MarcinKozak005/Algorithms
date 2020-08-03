#include <iostream>

using namespace std;

template <class T>
class DoublyLinkedList
{
    template <class E>
    class Node
    {
        E data;
        Node<E>* next = NULL;
        Node<E>* prev = NULL;

        public:
        Node(E data): data(data) {}
        E getData() {return this->data;}
        bool hasNext() {return next;}
        Node<E>* getNext() {return this->next;}
        void setNext(Node<E>* next) {this->next = next;}
        void setPrev(Node<E>* prev) {this->prev = prev;}
        Node<E>* getPrev() {return this->prev;}
    };

    Node<T>* head = NULL;
    Node<T>* last = NULL;
    int size = 0;

    public:
    void printList()
    {
        if(size == 0 )
        {
            cout<<"Empty list"<<endl;
            return;
        }
        Node<T>* current = head;
        while(current != NULL)
        {
            cout<<(current->getData())<<" ";
            current = current->getNext();
        }
        cout<<endl;
    }

    bool add(T elem)
    {
        if(head == NULL)
        {
            head = new Node<T>(elem);
            last = head;
        }
        else
        {
            Node<T>* newNode = new Node<T>(elem);
            Node<T>* current = head;
            while (current->hasNext()) current  = current->getNext();
            current->setNext(newNode);
            newNode->setPrev(current);
            last = newNode;
        }
        size++;
        return true;
    }

    void add (int index, T elem)
    {
        if(index < 0 || index > this->size) throw std::out_of_range ("DoublyLinkedList:add(int,T) Invalid index");
        else if (index == 0)
        {
            Node<T>* newNode = new Node<T>(elem);
            newNode->setNext(head);
            head->setPrev(newNode);
            head = newNode;
        }
        else if( index == this->size) this->add(elem);
        else
        {
            Node<T>* newNode = new Node<T>(elem);
            Node<T>* elemBefore = head;
            Node<T>* elemAfter;
            for(int i=0; i<index-1; i++) elemBefore = elemBefore->getNext();
            elemAfter = elemBefore->getNext();

            elemBefore->setNext(newNode);
            newNode->setPrev(elemBefore);
            if (index != this->size)
            {
                newNode->setNext(elemAfter);
                elemAfter->setPrev(newNode);
            }
        }
        size++;
    }

    void clear()
    {
        if(this->size == 0) return;

        Node<T>* tmp;
        while(last != NULL)
        {
            tmp = last->getPrev();
            delete last;
            last = tmp;
        }
        head = NULL;
        size = 0;
        
    }

    bool contains(T elem)
    {
        Node<T>* current = head;
        while(current != NULL)
        {
            if(current->getData() == elem) return true;
            current = current->getNext();
        }
        return false;
    }

    T get(int index)
    {
        if(index<0 || index >= this->size) throw std::out_of_range("DoublyLinkedList:get(int) Index out of range!");
        Node<T>* current = head;
        for(int i=0; i<index; i++) current = current->getNext();
        return current->getData();
    }
};


int main()
{
    DoublyLinkedList<int> x;
    x.add(12);
    x.add(2000);
    x.add(199);
    x.printList();
    x.add(1,23);
    x.printList();
    cout<<x.get(4)<<endl;
       
}