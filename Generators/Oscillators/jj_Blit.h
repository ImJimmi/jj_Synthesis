#pragma once

//==============================================================================
namespace jj
{
    //==========================================================================
    class Blit  :   public Oscillator
    {
    public:
        //======================================================================
        Blit() {}
        ~Blit() {}

        //======================================================================
        void setFrequency(float newFreq) override
        {
            // You MUST call prepare() before setting the frequency!
            jassert(sampleRate != 0.0);

            frequency = newFreq;

            P = (float)sampleRate / frequency;
            M = 2 * (int)std::floor(P / 2.f) + 1;
        }

        float getNextSample() override
        {
            auto result = std::sinf(M * phase) / (M * std::sinf(phase));
            incrementPhase();

            return result;
        }

    private:
        //======================================================================
        float incrementPhase(bool incrementAfterReturning = false) override
        {
            auto originalValue = phase;

            phase += JJ_PI / P;

            if (phase >= JJ_PI)
                phase -= JJ_PI;

            return incrementAfterReturning ? originalValue : phase;
        }

        float sincM(float x)
        {
            return std::sinf(JJ_PI * x) / (M * std::sinf(JJ_PI * x / M));
        }

        //======================================================================
        float P = 0.f;
        int M = 1;
    };
}