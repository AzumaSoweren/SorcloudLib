#ifndef SORCLOUD_BUS_EXT_INCLUDED
#define SORCLOUD_BUS_EXT_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

typedef void *Bus;

float *Bus_calcFFTWindowed(Bus *aBus);

#ifdef __cplusplus
}
#endif

#endif
