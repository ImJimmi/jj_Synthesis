#pragma once

//==============================================================================
namespace jj
{
    //==========================================================================
    class BlitSquare    :   public BlitBipolar
    {
    public:
        //======================================================================
        BlitSquare() {}
        ~BlitSquare() {}

        //======================================================================
        void setFrequency(float newFreq) override
        {
            BlitBipolar::setFrequency(newFreq);

            state = -0.5f * M / P;
            C2 = 1.f / P;
        }

        float getNextSample() override
        {
            auto sample = BlitBipolar::getNextSample();
            sample += state - C2;
            state = sample * 0.995f;

            return sample;
        }

    private:
        //======================================================================
        float state = 0.f;
        float C2 = 0.f;
    };
}