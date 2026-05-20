//
// Created by Yassine Hentati on 26/02/2024.
//

#include <filesystem>
#include <iostream>
#include <magic.h>

using recursive_directory_iterator = std::filesystem::recursive_directory_iterator;

void solve_challenge_3() {
    magic_t magic_cookie = magic_open(MAGIC_MIME_TYPE);
    magic_load(magic_cookie, NULL);

    std::string file_path = "/path/to/file";
    std::string file_type = magic_file(magic_cookie, file_path.c_str());
    std::cout << "File type of " << file_path << " is: " << file_type << std::endl;

    magic_close(magic_cookie);
    const char *path_to_datafile = R"(C:\Users\hente\Downloads\Data\Data)";
    for (const auto& dirEntry : recursive_directory_iterator(path_to_datafile))
        if (dirEntry.is_regular_file()) {
            std::cout << dirEntry << std::endl;
        }

}