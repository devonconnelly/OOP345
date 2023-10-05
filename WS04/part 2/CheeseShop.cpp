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
    for(size_t i = 0; i < m_size; i++) {
        delete m_pCheeses[i];
    }
    delete[] m_pCheeses;
    delete m_newCheese;
}
CheeseShop::CheeseShop(const std::string& name) {
    m_name = name;
}
CheeseShop& CheeseShop::addCheese(const sdds::Cheese& cheese) {
    m_newCheese = new const Cheese(cheese);
    const Cheese** tmpCheeseArray = new const Cheese*[m_size + 1];
    for(size_t i = 0; i < m_size; i++) {
        tmpCheeseArray[i] = m_pCheeses[i];
    }
    tmpCheeseArray[m_size++] = m_newCheese;
    delete[] m_pCheeses;
    m_pCheeses = tmpCheeseArray;
    return *this;
}

CheeseShop::CheeseShop(const CheeseShop& source) {
    *this = source;
}
CheeseShop::CheeseShop(CheeseShop&& source) {
    *this = std::move(source);
}
CheeseShop& CheeseShop::operator=(const CheeseShop& source) {
    if(this != &source) {
        m_name = source.m_name;
        m_size = source.m_size;
        delete[] m_pCheeses;
        m_pCheeses = new const Cheese*[m_size];
        for(size_t i = 0; i < m_size; i++) {
            m_pCheeses[i] = source.m_pCheeses[i];
        }
    }
    return *this;
}
CheeseShop& CheeseShop::operator=(CheeseShop&& source) {
    if(this != &source) {
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

