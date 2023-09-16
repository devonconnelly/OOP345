// Devon Connelly
// 105322218
// dconnelly@myseneca.ca
// Sep. 15 2023
#ifndef SDDS_RIDEREQUEST_H
#define SDDS_RIDEREQUEST_H

extern double g_taxrate;
extern double g_discount;

namespace sdds{
class RideRequest {
private:
    char m_name[10];
    char* m_desc;
    double m_price;
    bool m_discount;
public:
    RideRequest();
    RideRequest(const RideRequest& other);
    RideRequest& operator=(const RideRequest& other);
    std::istream& read(std::istream& in);
    void display() const;
    ~RideRequest();
};
}

#endif /* RideRequest_h */
