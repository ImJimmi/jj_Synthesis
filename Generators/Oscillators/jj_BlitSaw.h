#pragma once

//==============================================================================
namespace jj
{
    //==========================================================================
    class BlitSaw   :   public Blit
    {
    public:
        //======================================================================
        BlitSaw() {}
        ~BlitSaw() {}

        //======================================================================
        void setFrequency(float newFreq) override
        {
            Blit::setFrequency(newFreq);

            state = -0.5f * M / P;
            C2 = 1.f / P;
        }

        float getNextSample() override
        {
            auto sample = Blit::getNextSample();
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