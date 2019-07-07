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
        float getNextSample() override
        {
            const juce::ScopedLock lockForReading(alphaLock);

            auto blit = Blit::getNextSample();
            auto sample = blit + lastSample * alpha;

            lastSample = sample;

            return sample;
        }

        /** Alpha controls the tone of the Sawtooth by changing the cutoff of
            the 1 pole low-pass filter. The default is 0.95 which produces a
            decent Sawtooth sound.

            (See source for getNextSample()).
        */
        void setAlpha(float newAlpha)
        {
            // alpha should be between 0 and 1 to keep the filter stable!
            jassert(newAlpha >= 0.f && newAlpha < 1.f);

            const juce::ScopedLock lockForWriting(alphaLock);
            alpha = newAlpha;
        }

        const float getAlpha() { return alpha; }

    private:
        //======================================================================
        float lastSample = 0.f;

        juce::CriticalSection alphaLock;
        float alpha = 0.95f;
    };
}