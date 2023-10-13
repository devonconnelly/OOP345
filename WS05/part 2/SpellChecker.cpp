#include <iostream>
#include <fstream>
#include <iomanip>
#include "SpellChecker.h"
using namespace std;
namespace sdds {
size_t SpellChecker::m_numReplaced[SIZE]{};
SpellChecker::SpellChecker(const char *filename) { 
    ifstream file(filename);
    if(file) {
        for(size_t i = 0; i < SIZE; i++)
        {
            string buffer;
                getline(file, buffer);
            int j = 0;
            while(buffer[j] != ' ') {
                m_badWords[i] += buffer[j];
                j++;
            }
            while(j < buffer.length()) {
                if(buffer[j] != ' ') {
                    m_goodWords[i] += buffer[j];
                }
                j++;
            }
        }
    }
    else {
        throw "Bad file name!";
    }
}

void SpellChecker::operator()(std::string &text) { 
    for(size_t i = 0; i < SIZE; i++) {
        size_t found = text.find(m_badWords[i]);
        if(found != string::npos) {
            text.replace(found, m_badWords[i].length(), m_goodWords[i]);
            m_numReplaced[i]++;
        }
        found = text.find(m_badWords[i]);
        if(found != string::npos) {
            --i;
        }
    }
}

void SpellChecker::showStatistics(std::ostream &out) const {
    out << "Spellchecker Statistics" << endl;
    for(size_t i = 0; i < SIZE; i++) {
        out << setw(15) << right << m_badWords[i] << ": " << m_numReplaced[i] << " replacements" << endl;
    }
}
}
