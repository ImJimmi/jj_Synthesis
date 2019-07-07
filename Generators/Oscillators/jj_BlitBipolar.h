#pragma once

//==============================================================================
namespace jj
{
    //==========================================================================
    class BlitBiPolar   :   public Blit
    {
    public:
        //======================================================================
        BlitBiPolar() {}
        ~BlitBiPolar() {}

        //======================================================================
        float getNextSample() override
        {
            auto result = std::sinf(M * phase) / (M * std::sinf(phase));

            if (std::isnan(result))
                result = 1.f;

            auto phaseOffset = phase + JJ_PI / 2.f;
            result -= std::sinf(M * phaseOffset) / (M * std::sinf(phaseOffset));

            if (std::isnan(result))
                result = 1.f;

            incrementPhase();

            return result;
        }
    };
}