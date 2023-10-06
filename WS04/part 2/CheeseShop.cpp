// Devon Connelly
// 105322218
// dconnelly@myseneca.ca
// Oct. 5 2023
#include <iostream>
#include <iomanip>
#include "CheeseShop.h"
using namespace std;
namespace sdds {
CheeseShop::CheeseShop() {
    m_pCheeses = nullptr;
    m_size = 0;
    m_name = "";
}
CheeseShop::~CheeseShop() {
    delete[] m_pCheeses;
//    for (size_t i = 0; i < m_rmSize; i++){
//        delete m_rmCheese[i];
//    }
//    delete[] m_rmCheese;
}
CheeseShop::CheeseShop(const std::string& name) {
    m_name = name;
}
CheeseShop& CheeseShop::addCheese(const Cheese& cheese) {
    m_newCheese = new const Cheese(cheese);
    const Cheese** tmpCheeseArray = new const Cheese*[m_size + 1];
//    addCheeseRm(*m_newCheese);
    for(size_t i = 0; i < m_size; i++) {
        tmpCheeseArray[i] = m_pCheeses[i];
    }
    tmpCheeseArray[m_size++] = m_newCheese;
    delete[] m_pCheeses;
    m_pCheeses = tmpCheeseArray;
    return *this;
}

//void CheeseShop::addCheeseRm(const Cheese& cheese) {
//    const Cheese** tmpCheeseArray = new const Cheese*[m_rmSize + 1];
//    for (size_t i = 0; i < m_size; i++){
//        tmpCheeseArray[i] = m_rmCheese[i];
//    }
//    tmpCheeseArray[m_rmSize++] = &cheese;
//    delete[] m_rmCheese;
//    m_rmCheese = tmpCheeseArray;
//}


CheeseShop::CheeseShop(const CheeseShop& source) {
    *this = source;
}
CheeseShop::CheeseShop(CheeseShop&& source) {
    *this = std::move(source);
}
CheeseShop& CheeseShop::operator=(const CheeseShop& source) {
    if(this != &source) {
        for(size_t i = 0; i < m_size; i++) {
            delete m_pCheeses[i];
        }
        delete[] m_pCheeses;
        m_name = source.m_name;
        m_size = source.m_size;
        m_pCheeses = new const Cheese*[m_size];
        for(size_t i = 0; i < m_size; i++) {
                m_pCheeses[i] = new const Cheese(*(source.m_pCheeses[i]));
            }
        }
    return *this;
}
CheeseShop& CheeseShop::operator=(CheeseShop&& source) {
    if(this != &source) {
        for(size_t i = 0; i < m_size; i++) {
            delete m_pCheeses[i];
        }
        delete[] m_pCheeses;
        m_name = source.m_name;
        m_size = source.m_size;
        m_pCheeses = source.m_pCheeses;
        source.m_name = "";
        source.m_pCheeses = nullptr;
    }
    return *this;
}
std::ostream& operator<<(std::ostream& os, CheeseShop& cheeseShop) {
    os << setfill('-') << setw(26) << '-' << endl;
    os << cheeseShop.m_name << endl;
    os << setfill('-') << setw(26) << '-' << endl;
    os << setfill(' ');
    if(cheeseShop.m_pCheeses) {
        for(size_t i = 0; i < cheeseShop.m_size; i++) {
            if(cheeseShop.m_pCheeses[i]) {
                os << *cheeseShop.m_pCheeses[i];
            }
        }
    }
    else {
        os << "This shop is out of cheese!" << endl;
    }
    os << setfill('-') << setw(26) << '-' << endl;
    os << setfill(' ');
    return os;
}
}

