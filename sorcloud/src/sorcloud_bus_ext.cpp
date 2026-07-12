#include "../include/soloud_bus.h"
#include "../include/soloud_fft.h"

#define PI 3.141592653589793
// float * Bus::calcFFT()
// 	{
// 		if (mInstance && mSoloud)
// 		{
// 			mSoloud->lockAudioMutex_internal();
// 			float temp[1024];
// 			int i;
// 			for (i = 0; i < 256; i++)
// 			{
// 				temp[i*2] = mInstance->mVisualizationWaveData[i];
// 				temp[i*2+1] = 0;
// 				temp[i+512] = 0;
// 				temp[i+768] = 0;
// 			}
// 			mSoloud->unlockAudioMutex_internal();
// 
// 			SoLoud::FFT::fft1024(temp);
// 
// 			for (i = 0; i < 256; i++)
// 			{
// 				float real = temp[i * 2];
// 				float imag = temp[i * 2 + 1];
// 				mFFTData[i] = (float)sqrt(real*real+imag*imag);
// 			}
// 		}
// 
// 		return mFFTData;
// 	}

using namespace SoLoud;

extern "C" {

float *Bus_calcFFTWindowed(void *aClassPtr) {
    Bus *cl = (Bus *)aClassPtr;

    if (cl->mInstance && cl->mSoloud) {
        cl->mSoloud->lockAudioMutex_internal();
        float temp[1024];
        int i;
        for (i = 0; i < 256; i++) {
            temp[i*2] = cl->mInstance->mVisualizationWaveData[i] * (float)(0.54 - 0.46 * cos(2*PI*i/255));
            temp[i*2+1] = 0;
            temp[i+512] = 0;
            temp[i+768] = 0;
        }
        cl->mSoloud->unlockAudioMutex_internal();

        SoLoud::FFT::fft1024(temp);

        for (i = 0; i < 256; i++) {
            float real = temp[i * 2];
            float imag = temp[i * 2 + 1];
            cl->mFFTData[i] = (float)sqrt(real*real+imag*imag);
        }
    }

    return cl->mFFTData;
}

}
