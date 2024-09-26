//#define KFC
#define BBQ

#ifdef KFC
#define MAC
#else
#undef BBQ
#undef MAC
#endif

#ifndef MAC
#define MOMS
#endif

#ifdef MOMS
HAHA;
#endif