#include"header.hpp"
//przklad uzycia drzewa BST

int main() {
    ofstream zapis("dane.txt");
    zapis<<"coś";
    BST<int> t;
    std::cout<<maks('a','b')<<"\n";
    std::cout<<maks(7.0,0.2)<<"\n";
    BST<int> a{1,3,67,-12};
    zapis<<a;
    BST<char> c{'F','G','A'};
    c.display();
    c.insert('B');
    c.display();
    c.remove('A');
    c.display();
    a.display();
    t.insert(20);
    t.insert(25);
    t.insert(15);
    t.insert(10);
    t.insert(30);
    t.display();
    t.remove(20);
    t.display();
    t.remove(25);
    t.display();
    t.remove(30);
    t.display();
    int opcja, el;
    BST<int> drzewo;
    while(1) {
        std::cout<<"Opcja: ";
        std::cin>>opcja;
        if(opcja==5) break;
        switch(opcja) {
            case 1:
                std::cout<<"Podaj element(int): ";
                std::cin>>el;
                drzewo.insert(el);
                break;
            case 2:
                std::cout<<"Podaj element(int): ";
                std::cin>>el;
                drzewo.remove(el);
                break;
            case 3:
                std::cout<<"drzewo: ";
                drzewo.display();
                break;
            case 4:
                std::cout<<"Podaj element: ";
                std::cin>>el;
                if(drzewo.search(el)!=nullptr) std::cout<<"Element jest w drzewie\n";
                else std::cout<<"Elementu nie ma w drzewie\n";
                break;
        }
    }
    t.~BST();
    a.~BST();
    c.~BST();
    drzewo.~BST();
    return 0;
}
