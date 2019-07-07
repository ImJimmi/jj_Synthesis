#pragma once

//==============================================================================
namespace jj
{
    //==========================================================================
    /** A base for Generator that produces some sort of oscillating sound with a
        frequency.
     */
    class Oscillator    :   public Generator
    {
    public:
        //======================================================================
        Oscillator() = default;

        //======================================================================
        void prepare(double newSampleRate, int expectedBlockSize) override;

        //======================================================================
        /** Resets the phase to 0. */
        void resetPhase() { phase = 0.f; }

        /** Increments the phase based on the current frequency and returns the
            new phase value.

            If the incrementAfterReturning argument is set to true, the original
            phase value will be returned, not the new phase value after the
            increment.
         */
        float incrementPhase(bool incrementAfterReturning = false);

        //======================================================================
        /** Returns the current phase value. */
        float getPhase() { return phase; }

        void setFrequency(float newFreq) { frequency = newFreq; }
        float getFrequency() { return frequency; }

    protected:
        //======================================================================
        float frequency;
        double sampleRate;

    private:
        //======================================================================
        float phase = 0.f;
    };
}