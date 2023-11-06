#ifndef SDDS_STATION_H
#define SDDS_STATION_H
#include <iostream>
namespace sdds {
class Station {
    size_t m_id;
    std::string m_name;
    std::string m_description;
    size_t m_serialNum;
    size_t m_numStock;
    static size_t m_widthField;
    static size_t id_generator;
public:
    Station(const std::string&);
    const std::string& getItemName() const;
    size_t getNextSerialNumber();
    size_t getQuantity() const;
    void updateQuantity();
    void display(std::ostream& os, bool full) const;
};
}

#endif /* Station_h */
