#ifndef TOL_UTF8CONVERTER_H
#define TOL_UTF8CONVERTER_H

#include <string>
#include <vector>

using namespace std;

class Utf8Converter {
public:
    vector<string> Run(const string& input);

private:
    string input;
    long long getCharacterLength(long long position);
};


#endif //TOL_UTF8CONVERTER_H
