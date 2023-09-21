// Devon Connelly
// 105322218
// dconnelly@myseneca.ca
// Sep. 20 2023
#ifndef SDDS_AIRPORTMODELS_H
#define SDDS_AIRPORTMODELS_H
namespace sdds {
class Airport {
    char* m_code = nullptr;
    char* m_name = nullptr;
    char* m_city = nullptr;
    char* m_state = nullptr;
    char* m_country = nullptr;
    float m_latitude{};
    float m_longitude{};
    
public:
    void display() const;
    Airport& operator=(const Airport& airport);
    Airport();
    Airport(const Airport& airport);
    Airport(const char* code, const char* name, const char* city, const char* state, const char* country, const float latitude, const float longitude);
    char* getCountry() const;
    char* getState() const;
    Airport& set(const char* code, const char* name, const char* city, const char* state, const char* country, const float latitude, const float longitude);
    ~Airport();
};

std::ostream& operator<<(std::ostream& ostr, const Airport& airport);
void copy(char*& a, const char* b);

class AirportLog {
    Airport* m_airports = nullptr;
    size_t m_size{};
public:
    AirportLog();
    AirportLog(const AirportLog& log);
    AirportLog(AirportLog&& log);
    AirportLog& operator=(const AirportLog& log);
    AirportLog& operator=(AirportLog&& log);
    AirportLog(const char* filename);
    void addAirport(const Airport& airport);
    AirportLog findAirport(const char* state, const char* country);
    Airport operator[](size_t index) const;
    operator size_t() const;
    ~AirportLog();
};
}


#endif /* AirportModels_h */
