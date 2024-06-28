#include <memory>
#include <doctest.h>

#include "Vbidir.h"

using namespace std;

TEST_SUITE("Bidirectional Module")
{
    static auto dut = make_unique<Vbidir>();

    TEST_CASE("Can Write")
    {
        // Set bidir as ouput
        dut->oe = 1;
        dut->inp = 123;
        dut->clk = 0;
        dut->eval();
        
        // Clock to latch
        dut->clk = 1;
        dut->eval();
        dut->clk = 0;
        dut->eval();

        CHECK(dut->bidir == 123);
    }

    TEST_CASE("Can Read")
    {
        // Set bidir as input
        dut->oe = 0;
        dut->bidir = 101;
        dut->clk = 0;
        dut->eval();
        
        // Clock to latch
        dut->clk = 1;
        dut->eval();
        dut->clk = 0;
        dut->eval();

        CHECK(dut->outp == 101);
    }
}
