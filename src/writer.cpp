#include <protozero/pbf_writer.hpp>

#include <fstream>
#include <iostream>

int main(int, char*[]) {
    std::ofstream out("out.pbf", std::ios::binary);

    std::string message;
    protozero::pbf_writer parent(message);
    for (int i = 0; i < 100; i++) {
        message.clear();
        {
            protozero::pbf_writer pbf(parent, 1);
            pbf.add_uint32(1, 19583);
            pbf.add_uint32(2, 98620093);
        }
        out << message;
    }

    return 0;
}
