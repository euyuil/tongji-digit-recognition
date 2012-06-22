#ifndef _CHARACTERISTIC_H_
#define _CHARACTERISTIC_H_

#include <cstdio>

using namespace std;

#include <VertScan.h>
#include <HoriScan.h>
#include <NineGrids.h>

struct CHARACTERISTIC
{
    VS_NORM_RESULT vs;
    HS_NORM_RESULT hs;
    NG_RESULT ng;
};

typedef CHARACTERISTIC CHARACTER;

bool foutch(FILE *, const CHARACTER &);
bool finch(FILE *, CHARACTER &);

#endif /* _CHARACTERISTIC_H_ */
