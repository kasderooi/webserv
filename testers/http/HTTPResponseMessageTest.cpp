#include "HTTPResponseMessageTest.hpp"
#include <iostream>

// clang++ -std=c++17 HTTPResponseMessageTest.cpp ../../srcs/http/HTTPResponseMessage.cpp -I../../srcs/http -I. -o testHTTPResponseMessage && ./testHTTPResponseMessage && rm testHTTPResponseMessage

void HTTPResponseMessageTest::statusCodeMessages() {
    if (HTTPResponseMessage::responseStatusMessages.at(200) != "OK")
        throw std::exception();
    if (HTTPResponseMessage::responseStatusMessages.at(505) != "HTTP Version Not Supported")
        throw std::exception();
}

void HTTPResponseMessageTest::toString() {
    std::string body = "<!doctype html>\n<html>\n<head>\n\t<title>Our Funky HTML Page</title>\n</head>\n</html>";
    HTTPResponseMessage sut;
    sut.addStatus(HTTPResponseMessage::OK)
        .addTypeCat(HTTPResponseMessage::TEXT)
        .addTypeExt("html")
        .addLength(body.length())
        .addBody(body);    
    std::cout << sut.toString();
}

int main() {
    HTTPResponseMessageTest test;

    test.statusCodeMessages();
    test.toString();

    return 0;
}