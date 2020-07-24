CMSIS 2.0 DSP Library
=====================
This project provides a number of different build configurations
for ARM's CMSIS v2.0 DSP Library.

This project is only intended to be used if you want to produce
modified versions of the supplied CMSISv2p00_DSPLIB_CM3,
CMSISv2p00_DSPLIB_CM4 and CMSISv2p00_DSPLIB_CM4_NoFP projects,
which contain pre-built libraries, built with optimization level
-O3.

In additon, if you import this project into a workspace where you
are using one of the pre-built DSP library projects, then you will
be able to carry out source level debugging of the DSP functions.
Note however that debugging code built at -O3 will give a 
sub-optimal debug view.



