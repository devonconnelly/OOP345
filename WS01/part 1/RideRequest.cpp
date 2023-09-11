#include <iostream>
#include <iomanip>
#include "RideRequest.h"

using namespace std;

double g_taxrate = 0.0;
double g_discount = 0.0;

namespace sdds{
RideRequest::RideRequest(){
    m_name[0] = '\0';
    m_desc[0] = '\0';
    m_price = 0;
    m_discount = false;
}
std::istream& RideRequest::read(std::istream& in) {
    if(in) {
        char discount;
        in.getline(m_name, 10, ',');
        in.getline(m_desc, 25, ',');
        in >> m_price;
        in.ignore();
        in >> discount;
        in.ignore();
        if(discount == 'Y')
        {
            m_discount = true;
        }
        else if(discount == 'N')
        {
            m_discount = false;
        }
    }
    return in;
}
void RideRequest::display() const {
    static int counter = 0;
    counter++;
    cout << left << setw(2) << counter << ". ";
    if(m_name[0] != '\0') {
        cout << left << setw(10) << m_name << "|";
        cout << left << setw(25) << m_desc << "|";
        cout << left << setw(12) << setprecision(2) << fixed << m_price + (m_price * g_taxrate) << "|";
        if(m_discount)
            cout << right << setw(13) << m_price + (m_price * g_taxrate) - g_discount;
    }
    else {
        cout << "No Ride Request" << endl;
    }
    cout << endl;
}
}
