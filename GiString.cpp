#include "GiString.hpp"
#include <cstdarg>
#include <unordered_set>

GiString::GiString(const std::string &str) : internalString(str)
{
}

GiString GiString::toLowerCase() const
{
    std::string lowerCaseString = internalString;
    std::transform(lowerCaseString.begin(), lowerCaseString.end(),
                   lowerCaseString.begin(),
                   [](unsigned char c)
                   { return std::tolower(c); });
    return GiString(lowerCaseString);
}

size_t GiString::Size() const
{
    return internalString.size();
}
void GiString::Clear()
{
    internalString.clear();
}

std::string GiString::getValue() const
{
    return internalString;
}
GiString &GiString::setValue(const std::string &value)
{
    internalString = value;
    return *this;
}
GiString &GiString::append(const std::string &value)
{
    internalString += value;
    return *this;
}

GiString &GiString::insert(size_t index, const std::string &value)
{
    if (index > internalString.size())
    {
        std::cerr << "Error: Insertion index exceeded.\n";
        return *this;
    }

    internalString.insert(index, value);

    return *this;
}

GiString &GiString::toBool(const bool &v)
{
    if (v)
    {
        setValue("true");
    }
    else
    {
        setValue("false");
    }
    return *this;
}
GiString &GiString::erase(char ch)
{
    internalString.erase(
        std::remove(internalString.begin(), internalString.end(), ch),
        internalString.end());
    return *this;
}

GiString &GiString::erase(const std::string &str)
{
    auto pos = internalString.find(str);
    if (pos != std::string::npos)
    {
        internalString.erase(pos, str.length());
    }
    return *this;
}

GiString &GiString::erase(const char *str)
{
    if (str)
    {
        auto pos = internalString.find(str);
        if (pos != std::string::npos)
        {
            internalString.erase(pos, std::strlen(str));
        }
    }
    return *this;
}
GiString &GiString::replace(const std::string str1, std::string str2)
{
    internalString.replace(internalString.find(str1), str1.length(), str2);
    return *this;
}

GiString &GiString::substr(const std::string str)
{
    auto pos = internalString.find(str);
    if (pos != std::string::npos)
    {
        internalString.erase(pos, str.length());
    }
    return *this;
}
GiString &GiString::substr(const size_t index, const size_t endIndex)
{
    if (index > internalString.size())
    {
        std::cerr << "Error: Substring index exceeded.\n";
        return *this;
    }

    if (endIndex > internalString.size())
    {
        std::cerr << "Error: Substring end index exceeded.\n";
        return *this;
    }

    internalString.erase(index, endIndex - index);
    return *this;
}
GiString &GiString::compare(const std::string &str)
{
    Status = (internalString == str);
    return *this;
}
GiString &GiString::find(const std::string &str)
{
    Status = (internalString.find(str) != std::string::npos);
    return *this;
}
GiString &GiString::rfind(const std::string &str)
{
    Status = (internalString.rfind(str) != std::string::npos);
    return *this;
}
GiString &GiString::find_first_of(char c)
{
    Status = (internalString.find_first_of(c) != std::string::npos);
    return *this;
}

GiString &GiString::find_last_not_of(char c)
{
    Status = (internalString.find_last_not_of(c) != std::string::npos);
    return *this;
}
GiString &GiString::find_last_of(char c)
{
    Status = (internalString.find_last_of(c) != std::string::npos);
    return *this;
}
GiString &GiString::find_first_not_of(char c)
{
    Status = (internalString.find_first_not_of(c) != std::string::npos);
    return *this;
}
GiString &GiString::toUpperCase()
{
    std::transform(internalString.begin(), internalString.end(),
                   internalString.begin(),
                   [](unsigned char c)
                   { return std::toupper(c); });
    return *this;
}
GiString &GiString::trim()
{
    internalString.erase(0, internalString.find_first_not_of(" \t\n\r\f\v"));

    internalString.erase(internalString.find_last_not_of(" \t\n\r\f\v") + 1);

    return *this;
}

GiString &GiString::trimLeft()
{
    internalString.erase(internalString.find_first_not_of(" \t\n\r\f\v"));

    return *this;
}

GiString &GiString::trimRight()
{
    internalString.erase(internalString.find_last_not_of(" \t\n\r\f\v") + 1);

    return *this;
}
GiString &GiString::operator+=(const char *cstr)
{
    internalString += cstr;
    return *this;
}

GiString GiString::operator+(const char *cstr) const
{
    GiString result = *this;
    result.internalString += cstr;
    return result;
}

bool GiString::operator==(const char *cstr) const
{
    return internalString == cstr;
}

bool GiString::operator!=(const char *cstr) const
{
    return internalString != cstr;
}

bool GiString::empty() const
{
    return internalString.empty();
}
GiString GiString::join(const std::vector<GiString> &collection, const std::string &separator) const
{
    std::string result;
    for (size_t i = 0; i < collection.size(); ++i)
    {
        result += collection[i].internalString;
        if (i < collection.size() - 1)
            result += separator;
    }
    return GiString(result);
}

GiString GiString::reverse() const
{
    std::string reversed = internalString;
    std::reverse(reversed.begin(), reversed.end());
    return GiString(reversed);
}

bool GiString::is_numeric() const
{
    return std::all_of(internalString.begin(), internalString.end(), ::isdigit);
}

bool GiString::is_alpha() const
{
    return std::all_of(internalString.begin(), internalString.end(), ::isalpha);
}

bool GiString::is_alphanumeric() const
{
    return std::all_of(internalString.begin(), internalString.end(), ::isalnum);
}

bool GiString::is_whitespace() const
{
    return std::all_of(internalString.begin(), internalString.end(), ::isspace);
}

bool GiString::is_valid_email() const
{
    const std::regex email_pattern(R"((\w+)(\.\w+)*@(\w+)(\.\w+))");
    return std::regex_match(internalString, email_pattern);
}
bool GiString::is_palindrome() const
{
    std::string str_no_spaces = internalString;
    str_no_spaces.erase(std::remove(str_no_spaces.begin(), str_no_spaces.end(), ' '), str_no_spaces.end());
    return std::equal(str_no_spaces.begin(), str_no_spaces.begin() + str_no_spaces.size() / 2, str_no_spaces.rbegin());
}

size_t GiString::count(const std::string &substring) const
{
    size_t count = 0;
    size_t pos = internalString.find(substring);
    while (pos != std::string::npos)
    {
        ++count;
        pos = internalString.find(substring, pos + substring.length());
    }
    return count;
}

GiString GiString::replace_char(char to_replace, char replacement)
{
    std::string result = internalString;
    std::replace(result.begin(), result.end(), to_replace, replacement);
    return GiString(result);
}

GiString GiString::remove_char(char to_remove)
{
    std::string result = internalString;
    result.erase(std::remove(result.begin(), result.end(), to_remove), result.end());
    return GiString(result);
}

GiString GiString::random(size_t length)
{
    static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";

    std::string result;
    result.reserve(length);

    // Use a random device to seed a Mersenne Twister generator
    std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<> dist(0, sizeof(alphanum) - 2);

    for (size_t i = 0; i < length; ++i)
    {
        result += alphanum[dist(rng)];
    }

    return GiString(result);
}

GiString GiString::shuffle() const
{
    std::string shuffled = internalString;
    auto rng = std::default_random_engine{};
    std::shuffle(shuffled.begin(), shuffled.end(), rng);
    return GiString(shuffled);
}

GiString GiString::squeeze() const
{
    std::string squeezed = internalString;
    auto new_end = std::unique(squeezed.begin(), squeezed.end());
    squeezed.erase(new_end, squeezed.end());
    return GiString(squeezed);
}

bool GiString::starts_with(const std::string &prefix) const
{
    if (internalString.length() < prefix.length())
    {
        return false;
    }
    return std::equal(prefix.begin(), prefix.end(), internalString.begin());
}

bool GiString::ends_with(const std::string &suffix) const
{
    if (internalString.length() < suffix.length())
    {
        return false;
    }
    return std::equal(suffix.rbegin(), suffix.rend(), internalString.rbegin());
}

GiString GiString::left(size_t n) const
{
    if (n > internalString.size())
    {
        n = internalString.size();
    }
    return GiString(internalString.substr(0, n));
}

GiString GiString::right(size_t n) const
{
    if (n > internalString.size())
    {
        n = internalString.size();
    }
    return GiString(internalString.substr(internalString.size() - n));
}
GiString GiString::unicode_encode() const
{
    std::ostringstream oss;
    for (unsigned char c : internalString)
    {
        oss << "\\u" << std::hex << std::setw(4) << std::setfill('0') << static_cast<int>(c);
    }
    return GiString(oss.str());
}

GiString GiString::unicode_decode() const
{
    std::ostringstream oss;
    std::istringstream iss(internalString);
    char ch;
    while (iss >> ch)
    {
        if (ch == '\\' && iss.get() == 'u')
        {
            std::string hexCode;
            for (int i = 0; i < 4 && iss >> ch; ++i)
            {
                hexCode += ch;
            }
            oss << static_cast<char>(std::stoi(hexCode, nullptr, 16));
        }
        else
        {
            oss << ch;
        }
    }
    return GiString(oss.str());
}

int GiString::to_int() const
{
    return std::stoi(internalString);
}

float GiString::to_float() const
{
    return std::stof(internalString);
}

double GiString::to_double() const
{
    return std::stod(internalString);
}

int GiString::hex_to_int() const
{
    return std::stoi(internalString, nullptr, 16);
}

GiString GiString::int_to_hex(int value) const
{
    std::ostringstream oss;
    oss << std::hex << value;
    return GiString(oss.str());
}

GiString GiString::format(const std::string &fmt, ...) const
{
    va_list args;
    va_start(args, fmt);
    size_t size = std::vsnprintf(nullptr, 0, fmt.c_str(), args) + 1; // Extra space for '\0'
    std::unique_ptr<char[]> buf(new char[size]);
    std::vsnprintf(buf.get(), size, fmt.c_str(), args);
    va_end(args);
    return GiString(std::string(buf.get(), buf.get() + size - 1)); // We don't want the '\0' inside
}

GiString GiString::read_from_file(const std::string &file_path)
{
    std::ifstream file(file_path);
    std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    return GiString(content);
}

void GiString::write_to_file(const std::string &file_path) const
{
    std::ofstream file(file_path);
    file << internalString;
}

void GiString::to_stream(std::ostream &os) const
{
    os << internalString;
}

GiString GiString::from_stream(std::istream &is)
{
    std::string content((std::istreambuf_iterator<char>(is)), std::istreambuf_iterator<char>());
    return GiString(content);
}

std::wstring GiString::to_wstring() const
{
    return std::wstring(internalString.begin(), internalString.end());
}

GiString GiString::from_wstring(const std::wstring &wstr)
{
    return GiString(std::string(wstr.begin(), wstr.end()));
}

char GiString::char_at(size_t index) const
{
    if (index >= internalString.size())
    {
        throw std::out_of_range("Index out of range");
    }
    return internalString[index];
}

GiString &GiString::set_char_at(size_t index, char c)
{
    if (index >= internalString.size())
    {
        throw std::out_of_range("Index out of range");
    }
    internalString[index] = c;
    return *this;
}
GiString &GiString::ljust(size_t width, char pad)
{
    if (width > internalString.size())
    {
        internalString.append(width - internalString.size(), pad);
    }
    return *this;
}

GiString &GiString::rjust(size_t width, char pad)
{
    if (width > internalString.size())
    {
        internalString.insert(0, width - internalString.size(), pad);
    }
    return *this;
}

GiString &GiString::center(size_t width, char pad)
{
    size_t padding = width > internalString.size() ? width - internalString.size() : 0;
    size_t pad_left = padding / 2;
    size_t pad_right = padding - pad_left;
    internalString.insert(0, pad_left, pad);
    internalString.append(pad_right, pad);
    return *this;
}

GiString &GiString::repeat(size_t times)
{
    std::string temp = internalString;
    internalString.clear();
    for (size_t i = 0; i < times; ++i)
    {
        internalString += temp;
    }
    return *this;
}

GiString &GiString::swapcase()
{
    std::transform(internalString.begin(), internalString.end(), internalString.begin(),
                   [](unsigned char c)
                   { return std::isupper(c) ? std::tolower(c) : std::toupper(c); });
    return *this;
}

GiString &GiString::capitalize()
{
    if (!internalString.empty())
    {
        internalString[0] = std::toupper(internalString[0]);
        std::transform(internalString.begin() + 1, internalString.end(), internalString.begin() + 1,
                       [](unsigned char c)
                       { return std::tolower(c); });
    }
    return *this;
}

GiString &GiString::title()
{
    bool newWord = true;
    std::transform(internalString.begin(), internalString.end(), internalString.begin(),
                   [&newWord](unsigned char c) -> unsigned char
                   {
                       if (std::isspace(c))
                       {
                           newWord = true;
                           return c;
                       }
                       if (newWord)
                       {
                           newWord = false;
                           return std::toupper(c);
                       }
                       return std::tolower(c);
                   });
    return *this;
}

bool GiString::is_upper() const
{
    return std::all_of(internalString.begin(), internalString.end(), ::isupper);
}

bool GiString::is_lower() const
{
    return std::all_of(internalString.begin(), internalString.end(), ::islower);
}

bool GiString::is_title() const
{
    bool newWord = true;
    for (char c : internalString)
    {
        if (std::isspace(c))
        {
            newWord = true;
        }
        else if (newWord)
        {
            if (!std::isupper(c))
                return false;
            newWord = false;
        }
        else
        {
            if (!std::islower(c))
                return false;
        }
    }
    return true;
}

bool GiString::is_casefold_equal(const GiString &other) const
{
    if (internalString.size() != other.internalString.size())
        return false;
    for (size_t i = 0; i < internalString.size(); ++i)
    {
        if (std::tolower(internalString[i]) != std::tolower(other.internalString[i]))
            return false;
    }
    return true;
}

GiString &GiString::expand_tabs(size_t tabsize)
{
    size_t pos = 0;
    while ((pos = internalString.find('\t', pos)) != std::string::npos)
    {
        internalString.replace(pos, 1, std::string(tabsize, ' '));
        pos += tabsize;
    }
    return *this;
}

GiString &GiString::slice(size_t start, size_t end)
{
    if (start > internalString.size())
        start = internalString.size();
    if (end > internalString.size())
        end = internalString.size();
    internalString = internalString.substr(start, end - start);
    return *this;
}

std::map<char, size_t> GiString::element_count() const
{
    std::map<char, size_t> counts;
    for (char c : internalString)
    {
        ++counts[c];
    }
    return counts;
}

GiString &GiString::swap(GiString &other)
{
    std::swap(internalString, other.internalString);
    return *this;
}

GiString &GiString::copy()
{
    return *this;
}

GiString &GiString::from_int(int value)
{
    internalString = std::to_string(value);
    return *this;
}

GiString &GiString::from_float(float value, int precision)
{
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(precision) << value;
    internalString = oss.str();
    return *this;
}

GiString &GiString::unique()
{
    std::string result;
    std::unordered_set<char> seen;
    for (char c : internalString)
    {
        if (seen.insert(c).second)
        {
            result += c;
        }
    }
    internalString = result;
    return *this;
}

GiString &GiString::pad_left(size_t total_width, char pad)
{
    if (total_width > internalString.size())
    {
        internalString.insert(0, total_width - internalString.size(), pad);
    }
    return *this;
}

GiString &GiString::pad_right(size_t total_width, char pad)
{
    if (total_width > internalString.size())
    {
        internalString.append(total_width - internalString.size(), pad);
    }
    return *this;
}

GiString &GiString::from_char(char c)
{
    internalString = c;
    return *this;
}

GiString &GiString::substring_before(const std::string &delimiter)
{
    size_t pos = internalString.find(delimiter);
    if (pos != std::string::npos)
    {
        internalString = internalString.substr(0, pos);
    }
    return *this;
}

GiString &GiString::substring_after(const std::string &delimiter)
{
    size_t pos = internalString.find(delimiter);
    if (pos != std::string::npos)
    {
        internalString = internalString.substr(pos + delimiter.size());
    }
    return *this;
}

GiString &GiString::concat(const GiString &other)
{
    internalString += other.internalString;
    return *this;
}

GiString &GiString::truncate(size_t length, const std::string &trailing)
{
    if (internalString.size() > length)
    {
        internalString = internalString.substr(0, length) + trailing;
    }
    return *this;
}

bool GiString::to_bool() const
{
    std::string lower = internalString;
    std::transform(lower.begin(), lower.end(), lower.begin(), ::tolower);
    return lower == "true" || lower == "1";
}

GiString &GiString::at_base(int base_from, int base_to)
{
    long long int number = std::stoll(internalString, nullptr, base_from);
    std::string result;
    while (number > 0)
    {
        int remainder = number % base_to;
        result = (remainder < 10 ? char('0' + remainder) : char('A' + remainder - 10)) + result;
        number /= base_to;
    }
    internalString = result.empty() ? "0" : result;
    return *this;
}

size_t GiString::levenshtein_distance(const GiString &other) const
{
    const std::string &s1 = internalString;
    const std::string &s2 = other.internalString;
    const size_t len1 = s1.size(), len2 = s2.size();
    std::vector<size_t> col(len2 + 1), prevCol(len2 + 1);

    for (size_t i = 0; i < prevCol.size(); i++)
    {
        prevCol[i] = i;
    }

    for (size_t i = 0; i < len1; i++)
    {
        col[0] = i + 1;
        for (size_t j = 0; j < len2; j++)
        {
            col[j + 1] = std::min({prevCol[1 + j] + 1, col[j] + 1, prevCol[j] + (s1[i] == s2[j] ? 0 : 1)});
        }
        col.swap(prevCol);
    }
    return prevCol[len2];
}

size_t GiString::hamming_distance(const GiString &other) const
{
    if (internalString.size() != other.internalString.size())
    {
        throw std::invalid_argument("Strings must be of equal length to compute Hamming distance.");
    }

    size_t distance = 0;
    for (size_t i = 0; i < internalString.size(); ++i)
    {
        if (internalString[i] != other.internalString[i])
        {
            ++distance;
        }
    }
    return distance;
}

GiString &GiString::stringify(const std::any &value)
{
    if (value.type() == typeid(int))
    {
        internalString = std::to_string(std::any_cast<int>(value));
    }
    else if (value.type() == typeid(float))
    {
        internalString = std::to_string(std::any_cast<float>(value));
    }
    else if (value.type() == typeid(double))
    {
        internalString = std::to_string(std::any_cast<double>(value));
    }
    else if (value.type() == typeid(std::string))
    {
        internalString = std::any_cast<std::string>(value);
    }
    else
    {
        throw std::invalid_argument("Unsupported type for stringify.");
    }
    return *this;
}

GiString &GiString::zfill(size_t width)
{
    if (width > internalString.size())
    {
        internalString.insert(0, width - internalString.size(), '0');
    }
    return *this;
}
size_t GiString::count_words() const
{
    std::istringstream iss(internalString);
    return std::distance(std::istream_iterator<std::string>{iss}, std::istream_iterator<std::string>{});
}

bool GiString::matches_regex(const std::string &pattern) const
{
    std::regex regex_pattern(pattern);
    return std::regex_match(internalString, regex_pattern);
}

std::string bl(const bool &v)
{
    return v ? "True" : "False";
}

void GiString::Demo()
{
    GiString myString("Hello World!");
    std::cout << "Constructed with std::string: " << myString.getValue() << std::endl;

    // toLowerCase
    std::cout << "Lower case: " << myString.toLowerCase().getValue() << std::endl;

    // Size
    std::cout << "Size: " << myString.Size() << std::endl;

    // Clear
    myString.Clear();
    std::cout << "Clear: " << myString.getValue() << " (size: " << myString.Size() << ")" << std::endl;

    // setValue
    myString.setValue("Fresh Start");
    std::cout << "SetValue: " << myString.getValue() << std::endl;

    // append
    myString.append(" Again");
    std::cout << "Append: " << myString.getValue() << std::endl;

    // insert
    myString.insert(6, "<Inserted>");
    std::cout << "Insert: " << myString.getValue() << std::endl;

    // toBool
    myString.toBool(true);
    std::cout << "toBool (true): " << myString.getValue() << std::endl;

    // erase (overloads)
    myString.setValue("This is a test.");
    myString.erase('i'); // Removes all 'i' from the string
    std::cout << "Erase character 'i': " << myString.getValue() << std::endl;
    myString.setValue("This is a test.");
    myString.erase("is"); // Removes first occurrence of "is"
    std::cout << "Erase substring 'is': " << myString.getValue() << std::endl;

    // replace
    myString.setValue("This is a test.");
    myString.replace("is", "XX");
    std::cout << "Replace 'is' with 'XX': " << myString.getValue() << std::endl;

    // substr
    myString.setValue("This is a test.");
    myString.substr(5, 7); // Warning: this actually erases from index 5 to 7, not returning substring!
    std::cout << "Substring (incorrect function, it erases instead): " << myString.getValue() << std::endl;

    // compare
    std::cout << "Compare 'ThXXX a test.': " << myString.compare("ThXXX a test.").Status << std::endl;

    // find
    myString.setValue("Find the character sequence.");
    std::cout << "Find 'the': " << myString.find("the").Status << std::endl;

    //  more complex operations:
    std::cout << "Reversed: " << myString.reverse().getValue() << std::endl;
    std::cout << "Is numeric: " << bl(myString.is_numeric()) << std::endl; // Podobnie jak poprzednio, bl() jest funkcją poza klasą
    std::cout << "Is alphanumeric: " << bl(myString.is_alphanumeric()) << std::endl;

    GiString email("example@example.com");
    bool isEmail = email.matches_regex(R"((\w+)(\.\w+)*@(\w+)(\.\w+))");
    std::cout << "Is valid email (" << email.getValue() << "): " << bl(isEmail) << std::endl;

    GiString other1("1");
    GiString other2("1");
    
std::cout<<"Other = " << other1.append(other2.getValue()).getValue() << std::endl;



    std::cout << "End of GiString Demo." << std::endl;


}
