#ifndef TOL_UTF8CONVERTER_H
#define TOL_UTF8CONVERTER_H

#include <string>
#include <vector>

using namespace std;

class Utf8Converter {
public:
    vector<string> run(const string& input);

private:
    string input;
    int getCharacterLength(int position);
};


#endif //TOL_UTF8CONVERTER_H
