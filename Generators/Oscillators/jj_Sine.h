#pragma once

//==============================================================================
namespace jj
{
    //==========================================================================
    class Sine  :   public Oscillator
    {
    public:
        //======================================================================
        float getNextSample() override
        {
            return std::sinf(incrementPhase(true));
        }
    };
}