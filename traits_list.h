#ifndef TRAITS_LIST_H
#define TRAITS_LIST_H

#include "node.h"

template <typename Tr>
class TraitsList {
    public:
    typedef typename Tr::T T;
    typedef typename Tr::Operation Operation;

    private:
        Node<T>* head;
        Operation cmp;
        int Size=0;

        bool find(T data, Node<T> **&pointer) {
            for (int i = 0; i < this->  size(); i++) {
                if ((*pointer)->data == data){
                    return true;
                } else if(cmp(data, (*pointer)->data)) {
                    return false;
                }
                (pointer) = &((*pointer)->next);
            }
            return false;
            // TODO
        }

    public:
        TraitsList() : head(nullptr) {};

        bool insert(T data) {
            Node<T>** puntero = &head;
            Node<T>* temporal = new Node<T>(data);
            if (!find(data, puntero)) {


                Size++;
                temporal->next = *puntero;
                *puntero = temporal;
                return true;
            }
            cout << endl;
            return false;
            // TODO
        }

        bool remove(T data) {
            Node<T>** temp = &head;
            if (find(data,temp)){
                auto toDelete = *temp;
                (*temp) = (*temp)->next;
                delete toDelete;
                Size--;
                return true;
            }else return false;
            // TODO
        }

        bool find(T data) {
            Node<T>** temp=&head;
            return(find(data,temp));
            // TODO
        }

        T operator [] (int index) {
            if (index>=Size or index<0){
                throw out_of_range("Fuera de rango");
            }
            auto temp=head;
            while(index--){
                temp=temp->next;
            }
            return temp->data;
            // TODO
        }

        int size() {
            return Size;
            // TODO
        }

        void print() {
            auto temp=head;
            for(int i=0;i<this->Size;i++){
                cout<<temp->data<<" ";
                temp=temp->next;
            }
            std::cout<<std::endl;
            // TODO
        }

        ~TraitsList() {
            head->killSelf();
            // TODO
        }
};

#endif