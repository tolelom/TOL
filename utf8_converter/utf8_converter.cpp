#include "utf8_converter.h"

// vector<string> 복사하는 게 맞나..?
vector<string> Utf8Converter::Run(const string& input) {
    this->input = input;
    vector<string> characters;

    for (long long position = 0, length; position < input.size(); position += length) {
        length = getCharacterLength(position);
        characters.push_back(this->input.substr(position, length));
        // Warning: length가 길이를 초과할 수도 있다.
    }

    return characters;
}

long long Utf8Converter::getCharacterLength(long long position) {
    long long length = 0;

    if (input[position] & 0x80) {
        length++;
        if (input[position] & 0x40) {
            length++;
            if (input[position] & 0x20) {
                length++;
                if (input[position] & 0x10) {
                    length++;
                }
            }
        }
    }

    return (length == 0) ? 1 : length;
}