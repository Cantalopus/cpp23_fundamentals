#include <fmt/core.h>
#include <zlib.h>
#include <string>
#include <string_view>


#include "utilities.h"

int main() {

    double a = 26.153;
    double b = 46.782;
    std::string c = "Hello, and greetings!";
    std::string_view d = "Goodbye!!!";

    fmt::print("{}\n", c);

    fmt::print("fmt  version : {}\n"
               "ZLIB version : {}\n",
                FMT_VERSION, ZLIB_VERSION);

    fmt::print("{} + {} = {}\n", a, b, add(a,b));

    fmt::print("{}\n", d);
    
}