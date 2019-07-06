#pragma once

//==============================================================================
namespace jj
{
    //==========================================================================
    class Sine  :   public Oscillator
    {
    public:
        //======================================================================
        Sine() {}

        //======================================================================
        float getNextSample() override
        {
            return std::sinf(incrementPhase(true));
        }
    };
}