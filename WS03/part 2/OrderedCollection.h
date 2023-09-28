// Devon Connelly
// 105322218
// dconnelly@myseneca.ca
// Sep. 28 2023
#ifndef SDDS_ORDEREDCOLLECTION_H
#define SDDS_ORDEREDCOLLECTION_H
#include <iostream>
#include "Collection.h"
namespace sdds {
template<typename T>
class OrderedCollection : public Collection<T, 72> {
public:
    virtual bool operator+=(const T& newItem) {
        bool flag = Collection<T, 72>::operator+=(newItem);
        for(unsigned i = 0; i < Collection<T, 72>::size() -  1; i++) {
            for(unsigned j = 0; j < Collection<T, 72>::size() - i -  1; j++) {
                if(Collection<T, 72>::operator[](j) > Collection<T, 72>::operator[](j + 1)) {
                    T temp = Collection<T, 72>::operator[](j);
                    Collection<T, 72>::operator[](j) = Collection<T, 72>::operator[](j + 1);
                    Collection<T, 72>::operator[](j + 1) = temp;
                }
            }
            flag = true;
        }
        return flag;
    }
};
}

#endif /* OrderedCollection_h */
