//
// Created by Yassine Hentati.
//
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

std::string solve_challenge_2()
{
    std::string line_content;
    const char *name = "Mark David";
    std::ifstream datafile;
    datafile.open(R"(C:\Users\hente\Downloads\credentials.txt)");
    if (datafile.fail()) {
        raise(1);
    }
    while (datafile.good()) {
        const unsigned int specified_age = 20;
        std::getline(datafile, line_content);
        if (line_content.contains(name)) {
            std::stringstream string_stream_of_line_content(line_content);
            std::string substring_of_string_stream;
            std::vector<std::string> data_points = {};
            while (std::getline(string_stream_of_line_content, substring_of_string_stream, ',')) {
                data_points.push_back(substring_of_string_stream);
            }
            unsigned int age_lower_limit = std::stoi(data_points.at(3).substr(0, 2));
            unsigned int age_upper_limit = std::stoi(data_points.at(3).substr(3, 2));
            if (specified_age >= age_lower_limit) {
                if (specified_age <= age_upper_limit) {
                    datafile.close();
                    return data_points.back();
                }
            }
        }
    }
    datafile.close();
    return "[KEY NOT FOUND]";
}
