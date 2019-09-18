#ifndef SELF_LIST_H
#define SELF_LIST_H

#include "node.h"

template <typename T>
class SelfList {
    public:
    enum Method {
        Move, Count, Transpose
    };

    protected:
        Node<T>* head;
        Node<T>* tail;
        Method method;
        int Size= 0;

    public:
        SelfList(Method method) : head(nullptr),method(method) {};

        bool insert(T data) {
            Node<T> *temp = new Node<T>(data);
            if (Size == 0){
                head = temp;
                tail = head;
                Size++;
                return true;
            }else{
                Node<T> *iterador = head;
                for (int i = 0; i <this->size() ; i++) {
                    if(iterador->data == data){
                        return true;
                    }else{
                        iterador = iterador->next;
                    }
                }
                tail->next = temp;
                tail=temp;
                Size++;
                return false;
            }
            // TODO
        }
             
        bool remove(T data) {
            Node<T>** temp = &head;
            for (int i = 0; i <Size ; i++) {
                if((*temp)->data==data){
                    auto toDelete = (*temp);
                    (*temp) = (*temp)->next;
                    delete toDelete;
                    Size--;
                    return true;
                } else{
                    temp = &((*temp)->next);
                }
            }
            return false;
            // TODO
        }  

        bool find(T data) {
            Node<T> **before = &head;
            Node<T> **iterador = &head;
            for (int i = 0; i < Size; i++) {
                if ((*iterador)->data == data){
                    if((*iterador) != head){
                        Node<T> **actual = &head;
                        Node<T> *previo = (*iterador);
                        if(method = Move){
                            previo->Rp++;
                            while ((previo->Rp)<((*actual)->Rp)){
                                before = &((*actual));
                                actual = &((*actual)->next);
                            }
                            (*iterador) = (*iterador)->next;
                            if (before!= &head){
                                (*actual)->next = previo->next;
                                previo->next = (*before)->next;
                                (*before) = previo;

                            }else{
                                if (actual == &head) {
                                    previo->next = head;
                                    head = previo;
                                }else{
                                    previo->next = (*actual);
                                    (*before)->next = previo;
                                }
                            }
                            return true;
                            }
                            else if(method = Transpose){
                                (*iterador) = (*iterador)->next;
                                previo->next = head;
                                head = previo;
                                return true;}

                    }else {
                        (head)->Rp++;
                        return true;
                    }

                } else{
                    iterador = &((*iterador)->next);
                }
            }
            return false;
            // TODO
        }

        T operator [] (int index) {
            Node<T> * temp = head;
            for (int i = 0; i <index ; i++) {
                temp = temp->next;
            }
            return temp->data;
            // TODO
        }
             
        int size() {
            return Size;
            // TODO
        }

        void print() {
            Node<T>* temp = head;
            for (int i = 0; i < Size; i++) {
                std::cout<<temp->data<<" ";
                temp = temp->next;
            }
            std::cout<<std::endl;
            // TODO
        }
        ~SelfList() {
            head->killSelf();
            // TODO
        }  
};

#endif