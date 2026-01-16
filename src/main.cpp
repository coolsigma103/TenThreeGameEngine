#include <argparse/argparse.h>
#include <cstdlib>
#include <filesystem>
#include <iostream>
#include <string>

struct argparse_option options[] = {
    OPT_HELP(),
    OPT_END(),
};

namespace fs = std::filesystem;

int main(int argc, const char* argv[])
{
    struct argparse argparse;
    argparse_init(&argparse, options, NULL, 0);
    argparse_parse(&argparse, argc, argv);

    return EXIT_SUCCESS;
}
