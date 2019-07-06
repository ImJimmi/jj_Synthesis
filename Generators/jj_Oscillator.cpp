//==============================================================================
namespace jj
{
    //==========================================================================
    void Oscillator::prepare(double sr, int bs)
    {
        Generator::prepare(sr, bs);
        sampleRate = sr;
    }

    //==========================================================================
    float Oscillator::incrementPhase(bool incrementAfterReturning)
    {
        auto originalValue = phase;

        phase += 2.f * JJ_PI * frequency / (float)sampleRate;

        while (phase >= 2.f * JJ_PI)
            phase -= 2.f * JJ_PI;

        return incrementAfterReturning ? originalValue : phase;
    }
}