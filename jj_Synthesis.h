/*******************************************************************************
    BEGIN_JUCE_MODULE_DECLARATION

    ID:               jj_Synthesis
    vendor:           James Johnson
    version:          0.1.0
    name:             jj_Synthesis
    description:      A simple synthesis module.
    dependencies:     juce_audio_basics, juce_core, juce_dsp

    END_JUCE_MODULE_DECLARATION
*******************************************************************************/

#pragma once
#define JJ_SYNTHESIS_H_INCLUDED

#ifndef JJ_PI
    #define JJ_PI 3.141592653589793238f
#endif

// JUCE includes
#include <juce_audio_basics/juce_audio_basics.h>
#include <juce_core/juce_core.h>
#include <juce_dsp/juce_dsp.h>

// jj_Synthesis includes
#include "Generators/jj_Generator.h"

#include "Generators/Oscillators/jj_Oscillator.h"
#include "Generators/Oscillators/jj_Blit.h"
#include "Generators/Oscillators/jj_BlitBipolar.h"
#include "Generators/Oscillators/jj_BlitSaw.h"
#include "Generators/Oscillators/jj_BlitSquare.h"
#include "Generators/Oscillators/jj_Sine.h"
