//
// Created by Yassine Hentati.
//

#include <fstream>
#include <iostream>
#include <algorithm>

std::string solve_challenge_1() {
    std::string line_content;
    std::ifstream datafile;
    datafile.open(R"(C:\Users\hente\Downloads\dataset.txt)");
    if (datafile.fail())
        raise(1);
    while (!datafile.eof()) {
        std::getline(datafile, line_content);
        if (line_content.contains("Panda King") ) {
            if (std::count(line_content.begin(), line_content.end(), ',') == 3) {
                datafile.close();
                return line_content.substr(0, line_content.find(','));
            }
        }
    }
    datafile.close();
    return "[INSTITUTION NOT FOUND]";
}
