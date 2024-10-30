#include <stdio.h>
#include "bbq.h"

#define _ABC_

#ifdef _ABC_
#define BBQ
#define KFC
#endif // _ABC_

#ifndef _ABC_
#define _ABC_
#endif // !_ABC_

#ifndef KFC
#define KFC
#endif // !KFC

#ifdef BBQ
int main() {
	printf("정재호");
	return 0;
}
#endif // BBQ



