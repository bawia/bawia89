#ifndef DLList_H
#define DLList_H

using namespace std;
template<class D> class DLList;
template<class D>
class Node{
    friend class DLList<D>;

private: D data;
         Node<D>* previous;                 //data member for Node class
         Node<D>* next;

public:  Node();                        //constructor
         Node(D);

};

template<class D>
Node<D>::Node(){
    data = 0;                           // define the data, and two pointers
    previous = nullptr;
    next = nullptr;
}

template<class D>
Node<D>::Node(D value){
    data = value;
    previous = nullptr;
    next = nullptr;
}

// separate line


template<class D>
class DLList{

private: Node<D>* head;
         Node<D>* tail;               // data member
         int size;

public: DLList();
        DLList(D);
        DLList(const DLList<D>&);
//        Node<D> *searchNode(D);
        void insertNode(D);
        void insertNode(D,int);//  constructor for DLLlist
        void insert_front(D);
        D removeNode(int);
        int getSize();
        D getElement(int);
        bool isEmpty();
        void makeEmpty();
         ~DLList();
        DLList<D>& operator=(DLList<D>&);
        D& operator[] (int);

};

template <class D>
DLList<D>::DLList(){
        head = nullptr;
        tail = nullptr;           //          define two pointers' pointing location and size of Linked List.
        size = 0;
}

template <class D>
DLList<D>::DLList(D value){
        head = nullptr;
        tail = nullptr;
        size = 1;
}

template<class D>
DLList<D>::DLList(const DLList<D>& dList){
        head = nullptr;
        tail = nullptr;
        size = dList.getSize();
}

template <class D>
DLList<D>::~DLList(){               // destructor

        Node<D> * Temp = head;
        for (int i = 0; i < size; i++)
        {
            Temp = Temp -> next;
            delete head;
            head = Temp;
        }
}

//template<class D>
//Node<D> *DLList<D>::searchNode(D val){
//    if(head==nullptr)                           // if linked list is empty,
//        cout << " My Linked-List is empty " << endl;    // then print out statement
//        return nullptr;
//    else{
//            for(Node<D> *ptr=head; ptr!=tail->next; ptr=ptr->next){
//                if(val==ptr->data)                                          // when value == data, return ptr
//                    return ptr;
//            }
//    }   cout << val << " Do not exist in DLList " << endl;
//        return nullptr;
//}

template<class D>
void DLList<D>::insertNode(D inVal){
        Node<D>* Curr = new Node<D>;                    // dynamically allocated a node
        Curr->data = inVal;                             // new node pointing the data which I pass the value as parameter
        if(head==nullptr){
            head=Curr;                                 // when linked list is empty, insertion.
            tail=Curr;
         }
        else if (head == tail){
            head->next = Curr;
            Curr->previous = head;                  // insertion when list is only one head == tail case.
            Curr->next = nullptr;
            tail = Curr;
        }
        else{
            tail->next = Curr;
            Curr->previous = tail;
            Curr->next = nullptr;                          // other cases, insertion at last
            tail = Curr;
        }
        size++;
}

template<class D>
void DLList<D>::insertNode(D val, int idx)
{
        if (idx == size - 1)
        {
            insertNode(val);
        }
        else{
        Node<D>* Curr = head;
        Node<D>* Temp = new Node<D>;                // insertion at middle
        Temp->data = val;
        for (int i = 0; i < idx; i++)
        {
            Curr = Curr->next;
        }
        Temp->previous=Curr;
        Temp->next = Curr->next;
        Curr->next=Temp;

        Temp->next->previous=Temp;
        size++;
        }

}

template<class D>
void DLList<D>::insert_front(D value){

        Node<D>* Curr = new Node<D>;
        Curr->data = value;                             // dynamically allocated a node and assign the value

        head->previous = Curr;
        Curr->previous = nullptr;                          // insertion at the back
        Curr->next = head;
        head = Curr;
        size++;
}

template<class D>
D DLList<D>::removeNode(int index){

        Node<D>* Curr = head;
        for (int i = 0; i<index; i++){
            Curr = Curr->next;
        }

        if(Curr!=head){
            Curr->previous->next = Curr->next;
        }
        else{
            head = head->next;
        }
        if(Curr!=tail){
            Curr->next->previous = Curr->previous;
        }
        else{
            tail = tail->previous;
        }

        delete Curr;
        Curr = nullptr; // for safe, dangling pointer, but since it is temporary data, so it would't be problem though.
        size--;
}

template<class D>
int DLList<D>::getSize(){
//    Node* temp = head;                              // temp pointer points to head
//    while(temp)                                     // iterate, and measure the size
//    {
//        size++;                                             //while part can be commendted in case of performance sensitive.
//        temp = temp->next;
//    }
        return size;
}

template<class D>
D DLList<D>::getElement(int idx){
        Node<D> * Temp = head;
        for (int i = 0; i < size && i < idx; i ++ ){
            Temp = Temp -> next;
        }
        return Temp->data;
}



template<class D>
void DLList<D>::makeEmpty(){
        Node<D> * Temp = head;
        for (int i =0; i < size; i++)
        {
            Temp = Temp -> next;
            delete head;
            head = Temp;
        }
}

template<class D>
bool DLList<D>::isEmpty(){
        return (head == nullptr && tail == nullptr);
}



template<class D>
D& DLList<D>::operator[] (int pos){
        Node<D>* Temp = new Node<D>;
        int i = 0;

        for (Temp = head; Temp != nullptr; Temp = Temp->next){
            if (i == pos){
                return Temp -> data;
            }
            i++;
        }
}

template<class D>
DLList<D>& DLList<D>::operator=(DLList<D>& d){
        if (size > 0)
           d.makeEmpty();
        Node<D> * Copy = d.copy;

        for (int i = 0; i < d.size; i++){
            D obj = Copy->data;
            insertNode(obj);
            Copy = Copy ->data;
        }
}

#endif // DLList_H
//DLList();
//        DLList(D);
//        DLList(const DLList<D>&);
//        Node<D> *searchNode(D);
//        void insertNode(D);
//        void insertNode(D,int);//  constructor for DLLlist
//        void insert_back(D);
//        D removeNode(int);
//        int getSize();
//        bool isEmpty();
//         ~DLList();
//        DLList<D>& operator=(DLList<D>&);
  //      D& operator[] (int);
