#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "cpp-httplib/httplib.h"

const std::string load_static(const std::string& path) {

    std::ifstream static_file(path.c_str(), std::ios::in);

    std::stringstream stream;

    stream << static_file.rdbuf();
    static_file.close();

    return stream.str();
}

int main() {
    std::cout << "C++ GAE/FE is up!" << std::endl;

    httplib::Server svr;

    const std::string html = load_static("static/index.html"); 

    const std::string js = load_static("static/index.js");

    svr.Get("/", [&](const httplib::Request& req, httplib::Response& res){
        std::cout << "GET: routes '/'" << std::endl;
        res.set_content(html, "text/html");
    });

    svr.Get("/index.js", [&](const httplib::Request& req, httplib::Response& res){
        std::cout << "GET: routes '/'" << std::endl;
        res.set_content(js, "text/javascript");
    });

    svr.listen("0.0.0.0", 8080);
}