#include <protozero/pbf_reader.hpp>

#include <string>
#include <fstream>
#include <streambuf>
#include <iostream>

int main(int, char*[]) {
    std::ifstream in("out.pbf", std::ios::binary);
    std::string data;

    in.seekg(0, std::ios::end);
    data.reserve(in.tellg());
    in.seekg(0, std::ios::beg);

    data.assign((std::istreambuf_iterator<char>(in)), std::istreambuf_iterator<char>());

    protozero::pbf_reader pbf(data);
    while (pbf.next(1)) {
        protozero::pbf_reader message = pbf.get_message();
        while (message.next()) {
            uint32_t a, b;
            switch (message.tag()) {
                case 1: a = message.get_uint32(); break;
                case 2: b = message.get_uint32(); break;
                default: message.skip();
            }
            std::cout << "message: " << a << ", " << b << std::endl;
        }
    }

    return 0;
}
