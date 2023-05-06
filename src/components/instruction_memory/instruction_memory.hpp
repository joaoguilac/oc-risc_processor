#include "systemc.h"
#include "sysc/utils/sc_vector.h"

SC_MODULE(instruction_memory)
{
    sc_in<sc_uint<5>> Address;
    sc_in_clk clk;
    sc_out<sc_int<32>> InstructionOut;

    sc_vector<sc_int<32>> InstructionBank[32];

    // methods
    void next_instruction();

    SC_CTOR(instruction_memory)
    {
        SC_METHOD(next_instruction);
        sensitive << clk.pos().pos();
    }
};

void instruction_memory::next_instruction()
{
    InstructionOut.write(InstructionBank[Address.read()]);
}