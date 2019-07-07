#pragma once

//==============================================================================
namespace jj
{
    //==========================================================================
    class BlitBipolar   :   public Blit
    {
    public:
        //======================================================================
        BlitBipolar() {}
        ~BlitBipolar() {}

        //======================================================================
        float getNextSample() override
        {
            auto result = std::sinf(M * phase) / (M * std::sinf(phase));

            if (std::isnan(result))
                result = 1.f;

            auto invertedPhase = phase + JJ_PI * phaseOffsetAmount;
            result -= std::sinf(M * invertedPhase) / (M * std::sinf(invertedPhase));

            if (std::isnan(result))
                result = 1.f;

            incrementPhase();

            return result;
        }

        virtual void setPhaseOffsetAmount(float newOffset)
        {
            phaseOffsetAmount = newOffset;
        }

        virtual const float getPhaseOffsetAmount() { return phaseOffsetAmount; }

    private:
        //======================================================================
        float phaseOffsetAmount = 0.5f;
    };
}