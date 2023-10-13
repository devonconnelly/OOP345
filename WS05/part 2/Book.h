#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H

namespace sdds {
class Book {
    std::string m_author{};
    std::string m_title{};
    std::string m_countryP{};
    size_t m_yearP{};
    double m_price{};
    std::string m_desc{};
public:
    Book();
    const std::string& title() const;
    const std::string& country() const;
    const size_t& year() const;
    double& price();
    Book(const std::string& strBook);
    template<typename T>
    void fixSpelling(T& spellChecker) {
        spellChecker(m_desc);
    }
    std::string removeSpaces(std::string& str);
    friend std::ostream& operator<<(std::ostream& os, const Book& book);
};
}


#endif /* Book_h */

