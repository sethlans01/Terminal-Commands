#include <iostream>
#include <string>

std::string exec(std::string cmd) {
    std::string comm = cmd;
    comm.append(" 2>&1");
    std::shared_ptr<FILE> pipe(_popen(comm.c_str(), "r"), _pclose);
    if (!pipe) return "ERROR";
    char buffer[10000];
    std::string result = "";
    while (!feof(pipe.get())) {
        if (fgets(buffer, 10000, pipe.get()) != NULL)
            result += buffer;
    }
    return result;
}