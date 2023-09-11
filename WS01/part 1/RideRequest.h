#ifndef SDDS_RIDEREQUEST_H
#define SDDS_RIDEREQUEST_H

extern double g_taxrate;
extern double g_discount;

namespace sdds{
class RideRequest {
private:
    char m_name[10];
    char m_desc[25];
    double m_price;
    bool m_discount;
public:
    RideRequest();
    std::istream& read(std::istream& in);
    void display() const;
};
}

#endif /* RideRequest_h */
