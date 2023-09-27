#ifndef SDDS_COLLECTION_H
#define SDDS_COLLECTION_H
#include "Book.h"
namespace sdds {
template<typename T, unsigned C>
class Collection {
    T m_items[C];
    static T m_smallestItem;
    static T m_largestItem;
    unsigned m_size = 0;
protected:
    void setSmallestItem(const T& smallest) {
        if(smallest < m_smallestItem) {
            m_smallestItem = smallest;
        }
    }
    void setLargestItem(const T& largest) {
        if(largest > m_largestItem) {
            m_largestItem = largest;
        }
    }
public:
    T getSmallestItem() {
        return m_smallestItem;
    }
    T getLargestItem() {
        return m_largestItem;
    }
    unsigned size() const {
        return m_size;
    }
    unsigned capacity() const {
        return C;
    }
    bool operator+=(const T& newItem) {
        bool flag = false;
        if(size() < capacity()) {
            setSmallestItem(newItem);
            setLargestItem(newItem);
            m_items[m_size++] = newItem;
            flag = true;
        }
        return flag;
        
    }
    void print(std::ostream& os) const {
        os << "[";
        for(unsigned i = 0; i < size(); i++) {
            os << m_items[i];
            if(i < m_size -1) {
                os << ",";
            }
        }
        os << "]" << std::endl;
    }
};
    template<>
    class Collection<Book, 10> {
        Book m_items[10];
        Book m_smallestItem = {"", 1, 10000};
        Book m_largestItem = {"", 10000, 1};
        unsigned m_size = 0;
    protected:
        void setSmallestItem(const sdds::Book &smallest) {
            if(smallest < m_smallestItem) {
                m_smallestItem = smallest;
            }
        }

        void setLargestItem(const sdds::Book &largest) {
            if(largest > m_largestItem) {
                m_largestItem = largest;
            }
        }
    public:
        Book& getSmallestItem() {
            return m_smallestItem;
        }

        Book& getLargestItem() {
            return m_largestItem;
        }

        unsigned size() const {
            return m_size;
        }

        unsigned capacity() const {
            return 10;
        }

    };
    
    template <typename T, unsigned C>
    T Collection<T, C>::m_smallestItem = 9999;
    template <typename T, unsigned C>
    T Collection<T, C>::m_largestItem = -9999;
}


#endif /* Collection_h */
