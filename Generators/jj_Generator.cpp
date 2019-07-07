//==============================================================================
namespace jj
{
    //==========================================================================
    void Generator::prepare(double, int bs)
    {
        blockSize = bs;
    }

    const juce::AudioBuffer<float> Generator::getNextBlock()
    {
        juce::AudioBuffer<float> buffer(1, blockSize);

        for (int i = 0; i < blockSize; i++)
            buffer.getWritePointer(0)[i] = getNextSample();

        return buffer;
    }
}
