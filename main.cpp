#include <iostream>
#include "cpp-httplib/httplib.h"

int main() {
    std::cout << "C++ GAE/FE is up!" << std::endl;

    httplib::Server svr;

    svr.Get("/", [&](const httplib::Request& req, httplib::Response& res){
        std::cout << "GET: routes '/'" << std::endl;
        res.set_content("Hello World!", "text/plain");
    });

    svr.listen("0.0.0.0", 8080);
}