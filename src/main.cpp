#include "editor/editor.hpp"
#include "editor/project_manager.hpp"
#include <argparse/argparse.h>
#include <cstdlib>
#include <filesystem>
#include <iostream>
#include <string>

const char* project_dir = NULL;

struct argparse_option options[] = {
    OPT_HELP(),
    OPT_STRING('p', "project-dir", &project_dir, "project directory"),
    OPT_END(),
};

namespace fs = std::filesystem;

int main(int argc, const char* argv[])
{
    struct argparse argparse;
    argparse_init(&argparse, options, NULL, 0);
    argparse_parse(&argparse, argc, argv);

    if (project_dir == NULL)
    {
        Project_manager* project_manager = new Project_manager(project_dir);
        delete project_manager;
    }
    if (project_dir == NULL)
        exit(EXIT_SUCCESS);

    if (!fs::exists(project_dir) || !fs::is_directory(project_dir))
    {
        std::cerr << "No directory found: " << project_dir << '\n';
        exit(EXIT_FAILURE);
    }

    Editor editor = Editor(project_dir);
    editor.start();

    return EXIT_SUCCESS;
}
