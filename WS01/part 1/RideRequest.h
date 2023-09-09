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
    void read(std::istream& in);
    void display();
};
}

#endif /* RideRequest_h */
