#ifndef GISTRING_HPP
#define GISTRING_HPP

#include <string>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <regex>
#include <random>
#include <chrono>
#include <cctype>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <map>
#include <any>
#include <cmath>
#include <iterator>
#include <numeric>
class GiString {
private:
    std::string internalString;
    bool Status;

public:
    // Constructor
    explicit GiString(const std::string &str);

    // Getter
    std::string getValue() const;

    // Setter
    GiString &setValue(const std::string &value);

    // String Operations
    GiString &append(const std::string &value);
    GiString &insert(size_t index, const std::string &value);
    GiString &replace(const std::string str1, std::string str2);

    // Substring Operations
    GiString &substr(const std::string str);
    GiString &substr(const size_t index, const size_t endIndex);

    // Comparison Operations
    GiString &compare(const std::string &str);

    // Erase Operations
    GiString &erase(char ch);
    GiString &erase(const std::string &str);
    GiString &erase(const char *str);

    // Find Operations
    GiString &find(const std::string &str);
    GiString &rfind(const std::string &str);
    GiString &find_first_of(char c);
    GiString &find_last_not_of(char c);
    GiString &find_last_of(char c);
    GiString &find_first_not_of(char c);

    GiString &toUpperCase();

    GiString &trim();

    // Case Conversion
    GiString toLowerCase() const;

    // Size and Clear
    size_t Size() const;
    void Clear();

    // Boolean Conversion
    GiString &toBool(const bool &v);

    GiString &trimLeft();
    GiString &trimRight();

    GiString &operator+=(const char *cstr);
    GiString operator+(const char *cstr) const;
    GiString join(const std::vector<GiString> &collection, const std::string &separator) const;
    GiString reverse() const;
    bool is_numeric() const;
    bool is_alpha() const;
    bool is_alphanumeric() const;
    bool is_whitespace() const;
    bool is_valid_email() const;
    bool is_palindrome() const;
    size_t count(const std::string &substring) const;
    GiString replace_char(char to_replace, char replacement);
    GiString remove_char(char to_remove);
    static GiString random(size_t length);
    GiString shuffle() const;
    GiString squeeze() const;
    bool starts_with(const std::string &prefix) const;
    bool ends_with(const std::string &suffix) const;
    GiString left(size_t n) const;
    GiString right(size_t n) const;

    bool operator==(const char *cstr) const;
    bool operator!=(const char *cstr) const;

    bool empty() const;
    GiString unicode_encode() const;
    GiString unicode_decode() const;
    int to_int() const;
    float to_float() const;
    double to_double() const;
    int hex_to_int() const;
    GiString int_to_hex(int value) const;
    GiString format(const std::string &fmt, ...) const;
    static GiString read_from_file(const std::string &file_path);
    void write_to_file(const std::string &file_path) const;
    void to_stream(std::ostream &os) const;
    static GiString from_stream(std::istream &is);
    std::wstring to_wstring() const;
    static GiString from_wstring(const std::wstring &wstr);
    char char_at(size_t index) const;
    GiString &set_char_at(size_t index, char c);

   
    GiString &ljust(size_t width, char pad = ' ');
    GiString &rjust(size_t width, char pad = ' ');
    GiString &center(size_t width, char pad = ' ');
    GiString &repeat(size_t times);
    GiString &swapcase();
    GiString &capitalize();
    GiString &title();
    bool is_upper() const;
    bool is_lower() const;
    bool is_title() const;
    bool is_casefold_equal(const GiString &other) const;
    GiString &expand_tabs(size_t tabsize = 4);
    GiString &slice(size_t start, size_t end);
    std::map<char, size_t> element_count() const;
    GiString &swap(GiString &other);
    GiString &copy();
    GiString &at_base(int base_from, int base_to);
    GiString &from_int(int value);
    GiString &from_float(float value, int precision = 6);
    GiString &unique();
    GiString &pad_left(size_t total_width, char pad = ' ');
    GiString &pad_right(size_t total_width, char pad = ' ');
    GiString &from_char(char c);
    GiString &substring_before(const std::string &delimiter);
    GiString &substring_after(const std::string &delimiter);
    size_t levenshtein_distance(const GiString &other) const;
    size_t hamming_distance(const GiString &other) const;
    GiString &concat(const GiString &other);
    GiString &stringify(const std::any &value);
    GiString &zfill(size_t width);
    GiString &truncate(size_t length, const std::string &trailing = "...");
    bool to_bool() const;
    bool matches_regex(const std::string &pattern) const;
    size_t count_words() const;
    void Demo();
};

#endif // GISTRING_HPP

// Function Declaration
std::string bl(const bool &v);
