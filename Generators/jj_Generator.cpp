//==============================================================================
namespace jj
{
    //==========================================================================
    void Generator::prepare(double, int bs)
    {
        blockSize = bs;
    }

    const float* Generator::getNextBlock()
    {
        auto block = new float[blockSize];

        for (int i = 0; i < blockSize; i++)
            block[i] = getNextSample();

        return block;
    }
}
