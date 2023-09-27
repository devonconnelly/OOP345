#include <iostream>
#include "Collection.h"
using namespace std;
namespace sdds {


void Collection<Book, 10>::setSmallestItem(const sdds::Book &smallest) {
    if(smallest < m_smallestItem) {
        m_smallestItem = smallest;
    }
}

void Collection<Book, 10>::setLargestItem(const sdds::Book &largest) {
    if(largest > m_largestItem) {
        m_largestItem = largest;
    }
}

Book& Collection<Book, 10>::getSmallestItem() {
    return m_smallestItem;
}

Book& Collection<Book, 10>::getLargestItem() {
    return m_largestItem;
}

unsigned int Collection<Book, 10>::size() const {
    return m_size;
}

unsigned int Collection<Book, 10>::capacity() const {
    return 10;
}
}

