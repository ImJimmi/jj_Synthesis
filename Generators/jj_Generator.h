#pragma once

//==============================================================================
namespace jj
{
    //==========================================================================
    /** A base for classes that generate some sort of sound. */
    class Generator
    {
    public:
        //======================================================================
        Generator() = default;

        //======================================================================
        /** Should be called before playback starts. */
        virtual void prepare(double newSampleRate, int expectedBlockSize);

        /** Render the next block of audio samples. */
        virtual const float* getNextBlock();
        
        /** Render the next sample. */
        virtual float getNextSample() = 0;

        //======================================================================
        int getBlockSize() { return blockSize; }

    private:
        //======================================================================
        int blockSize = 0;
    };
}
