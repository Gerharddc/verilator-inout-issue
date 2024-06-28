#define DOCTEST_CONFIG_IMPLEMENT

#include <doctest.h>
#include <verilated.h>

int main(int argc, char **argv, char **env)
{
    // Inspired by https://github.com/bmacneil/verilator-template/blob/master/PROJECT/tb_MODULENAME.cpp

    // Initialize Verilator
    Verilated::commandArgs(argc, argv);

    // Doctest initialization
    doctest::Context context;
    context.applyCommandLine(argc, argv);
    int res = context.run();  // run queries, or run tests unless --no-run is specified
    if (context.shouldExit()) // important - query flags (and --exit) rely on the user doing this
        return res;           // propagate the result of the tests

    return res;
}