#include <iostream>
#include "self_list.h"
#include "test/tester.h"
#include <iterator>
using namespace std;

int main(int argc, char const *argv[]) {
    Tester::execute();


    SelfList<int> list(SelfList<int>::Transpose);

    for (int i = 0; i < 100; i++)
        list.insert(i);

    list.find(50);
    list.find(49);
    list.find(50);

    list.print();

    /* list.insert(6);
     list.insert(4);
     list.insert(2);
     list.insert(1);
     list.insert(7);
     list.print();
     list.find(1);
     list.print();
     list.find(2);
     list.print();*/

    /*TraitsList<Integer> integers;
    for(int i=0;i<5;i++){
        integers.insert(4 * i + 3);
        cout<<endl<<endl;
    }
    integers.insert(3);
    integers.insert(2);
    integers.insert(5);
    integers.insert(1);
    integers.print();
    integers.remove(1);
    integers.print();
    integers.remove(11);
    integers.remove(7);
    integers.print();
    cout<<integers.find(2);
    Tester::execute();*/
    return EXIT_SUCCESS;
}

