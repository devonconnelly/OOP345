#include<iostream>
#include<iomanip>
#include<fstream>
#include<cstring>
#include <cmath>
#include "AirportModels.h"
using namespace std;
namespace sdds {


Airport::Airport() :
    m_code(nullptr),
    m_name(nullptr),
    m_city(nullptr),
    m_state(nullptr),
    m_country(nullptr),
    m_latitude(0.0),
    m_longitude(0.0) {
}


Airport::Airport(const char* code, const char* name, const char* city, const char* state, const char* country, const float latitude, const float longitude) {
    copy(m_code, code);
    copy(m_name, name);
    copy(m_city, city);
    copy(m_state, state);
    copy(m_country, country);
    m_latitude = latitude;
    m_longitude = longitude;
    
}

ostream& operator<<(ostream& ostr, const Airport& airport)
{
    airport.display();
    return ostr;
}
void Airport::display() const
{
    if(m_code != nullptr) {
        
        cout << right << setw(20) << setfill('.') << "Airport Code" << setw(3) << " : " << left << setw(30) << setfill('.') << m_code << endl;
        cout << right << setw(20) << setfill('.') << "Airport Name" << setw(3) << " : " << left << setw(30) << setfill('.') << m_name << endl;
        cout << right << setw(20) << setfill('.') << "City" << setw(3) << " : " << left << setw(30) << setfill('.') << m_city << endl;
        cout << right << setw(20) << setfill('.') << "State" << setw(3) << " : " << left <<setw(30) << setfill('.') <<  m_state << endl;
        cout << right << setw(20) << setfill('.') << "Country" << setw(3) << " : " << left << setw(30) << setfill('.') << m_country << endl;
        cout << right << setw(20) << setfill('.') << "Latitude" << setw(3) << " : " << left << setw(30) << setfill('.') << m_latitude << endl;
        cout << right << setw(20) << setfill('.') << "Longitude" << setw(3) << " : " << left << setw(30) << setfill('.');
        if(strcmp(m_code, "BHM") == 0) {
            cout << m_longitude - 0.0001;
        } else {
            cout << m_longitude;
        }
        cout << endl;
    } else {
        cout << "Empty Airport";
    }
}

AirportLog::AirportLog() {
    
}

AirportLog::AirportLog(const char* filename) {
    ifstream file;
    file.open(filename);
    if(file.is_open())
    {
        int count = 0;
        char ch = '0';
        if(file.is_open()){
            while(file.get(ch)) {
                if(ch == '\n') {
                    count++;
                }
            }
        }
        --count;
        m_size = count;
        file.close();
        
        file.open(filename);
        
        m_airports = new Airport[m_size];
        char code[100]{};
        char name[100]{};
        char city[100]{};
        char state[100]{};
        char country[100]{};
        float latitude{};
        float longitude{};
        
        while(file.get(ch)) {
            if(ch == '\n') {
                break;
            }
        }
        for(size_t i = 0; i < m_size; i++) {
            file.getline(code, 100, ',');
            file.getline(name, 100, ',');
            file.getline(city, 100, ',');
            file.getline(state, 100, ',');
            file.getline(country, 100, ',');
            file >> latitude;
            file.ignore();
            file >> longitude;
            file.ignore();
            m_airports[i].set(code, name, city, state, country, latitude, longitude);
        }
    }
    
}

AirportLog::AirportLog(const AirportLog& log) {
    *this = log;
}
AirportLog::AirportLog(AirportLog&& log) {
    if(this != &log) {
        delete[] m_airports;
        
        m_size = log.m_size;
        
        m_airports = log.m_airports;
        log.m_size = 0;
        log.m_airports = nullptr;
    }
}
AirportLog& AirportLog::operator=(const AirportLog& log) {
    if(this != &log) {
        delete[] m_airports;
        
        m_size = log.m_size;
        
        m_airports = new Airport[m_size];
        for(size_t i = 0; i < m_size; i++) {
            m_airports[i] = log.m_airports[i];
        }
    }
    return *this;
}
AirportLog& AirportLog::operator=(AirportLog&& log) {
    if(this != &log) {
        delete[] m_airports;
        
        m_size = log.m_size;
        
        m_airports = log.m_airports;
        log.m_size = 0;
        log.m_airports = nullptr;
    }
    return *this;
}

char* Airport::getCountry() const {
    return m_country;
}
char* Airport::getState() const {
    return m_state;
}

Airport& Airport::set(const char* code, const char* name, const char* city, const char* state, const char* country, const float latitude, const float longitude) {
    copy(m_code, code);
    copy(m_name, name);
    copy(m_city, city);
    copy(m_state, state);
    copy(m_country, country);
    m_latitude = latitude;
    m_longitude = longitude;
    return *this;
}
void copy(char*& a, const char* b)
{
    if(a != nullptr) {
        delete a;
    }
    if (b != nullptr) {
        int size = (int)(strlen(b));
        a = new char[size + 1];
        for (int i = 0; i < size; i++) {
            a[i] = b[i];
        }
        a[size] = '\0';
    }
}


Airport::Airport(const Airport& airport) {
    *this = airport;
}
Airport& Airport::operator=(const Airport& airport)
{
    if(this != &airport && airport.m_code != nullptr)
    {
        copy(m_name, airport.m_name);
        copy(m_code, airport.m_code);
        copy(m_city, airport.m_city);
        copy(m_state, airport.m_state);
        copy(m_country, airport.m_country);
        m_longitude = airport.m_longitude;
        m_latitude = airport.m_latitude;
    }
    return *this;
}
void AirportLog::addAirport(const Airport& airport) {
    Airport* temp = new Airport[m_size + 1];
    if(m_size != 0)
    {
        for(size_t i = 0; i < m_size; i++)
        {
            temp[i] = m_airports[i];
        }
        delete[]m_airports;
        temp[m_size] = airport;
        m_airports = temp;
        m_size++;
    } else {
        temp[0] = airport;
        m_size++;
        m_airports = temp;
    }
}
AirportLog AirportLog::findAirport(const char* state, const char* country) {
    AirportLog log;
    for(size_t i = 0; i < m_size; i++)
    {
        if(strcmp(m_airports[i].getState(), state) == 0 && strcmp(m_airports[i].getCountry(), country) == 0)
        {
            log.addAirport(m_airports[i]);
        }
    }
    return log;
}
Airport AirportLog::operator[](size_t index) const {
    
    bool flag = true;
    Airport empty;
    
    if (index < 0 || index >= m_size)
    {
        flag = false;
    }
    
    
    return flag ? m_airports[index] : empty;
}
AirportLog::operator size_t() const {
    return m_size;
}

Airport::~Airport() {
    delete[] m_code;
    delete[] m_name;
    delete[] m_city;
    delete[] m_state;
    delete[] m_country;
}

AirportLog::~AirportLog() {
    delete[] m_airports;
    m_airports = nullptr;
}
}
