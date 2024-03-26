#include "GiString.hpp"
#include <iostream>

void UrlDemo()
{
    GiString s("https://main.gigasoft.com.pl/image/CZŁOWIEK");
    GiString encodedUrl = s.EncodeUrl();

    std::cout << " URL: " << s.getValue() << std::endl;
    std::cout << " Encoded URL: " << encodedUrl.getValue() << std::endl;
}
void toCaseFoldedDemo()
{
        GiString myString("Hello World!");
    GiString loweredString = myString.toCaseFolded();

    std::cout << "toCaseFoldedDemo: " << myString.getValue() << std::endl;
    std::cout << "toCaseFoldedDemo After: " << loweredString.getValue() << std::endl;
}

void demoBits()
{
    GiString s("Hello");

    std::string bits = s.ToBits().getValue();
    std::cout << "Bits: " << bits << std::endl;

    GiString fromBits = GiString::FromBits(bits);
    std::cout << "Text From Bits: " << fromBits.getValue() << std::endl;
}

void HTMLDemo()
{
    GiString myString("Hello, <world> & friends!");
    GiString htmlEscapedString = myString.toHtmlEscaped();

    std::cout << "Original string: " << myString.getValue() << std::endl;
    std::cout << "HTML escaped string: " << htmlEscapedString.getValue() << std::endl;

}
int main()
{

    // Tworzymy obiekt GiString z danym tekstem
    GiString s("Test to hex");
    // Konwertujemy tekst na HEX
    GiString hex = s.ToHex();
    // Wyświetlamy tekst zapisany w HEX
    std::cout << "HEX: " << hex.getValue() << std::endl;
    // Konwertujemy HEX z powrotem na tekst
    GiString decoded = s.FromHex(hex.getValue());
    // Wyświetlamy zdekodowany tekst
    std::cout << "DECODED HEX: " << decoded.getValue() << std::endl;

    demoBits();
    UrlDemo();
    toCaseFoldedDemo();
    HTMLDemo();
    return 0; // Powinno być 0, jeśli program zakończył działanie prawidłowo
}
