#include <iostream>
#include <iomanip>
#include <string.h>
#include "RideRequest.h"

using namespace std;

double g_taxrate = 0.0;
double g_discount = 0.0;

namespace sdds{
RideRequest::RideRequest(){
    m_name[0] = '\0';
    m_desc = nullptr;
    m_price = 0;
    m_discount = false;
}

RideRequest::RideRequest(const RideRequest& other){
    m_desc = nullptr;
    *this = other;
}
RideRequest& RideRequest::operator=(const RideRequest& other){
    if(this != &other) {
        delete[] m_desc;
        strcpy(m_name, other.m_name);
        m_price = other.m_price;
        m_discount = other.m_discount;
        m_desc = new char[strlen(other.m_desc) + 1];
        for(int i = 0; i < strlen(other.m_desc); i++){
            m_desc[i] = other.m_desc[i];
        }
    }
    return *this;
}
std::istream& RideRequest::read(std::istream& in) {
    if(in) {
        char discount;
        char desc[100];
        in.getline(m_name, 10, ',');
        in.getline(desc, 100, ',');
        delete[] m_desc;
        m_desc = new char[strlen(desc) + 1];
        for (int i = 0; i < strlen(desc); i++){
            m_desc[i] = desc[i];
        }
        m_desc[strlen(desc)] = '\0';
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
RideRequest::~RideRequest() {
    delete[] m_desc;
}
}
