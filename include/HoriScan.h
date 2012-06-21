#ifndef _HORI_SCAN_H_
#define _HORI_SCAN_H_

/**
 * Horizontal scanning algorithms for Digit Recognizing.
 * @author EUYUIL
 * @date 2012-06-16
 */

#include <vector>
#include <utility>

using namespace std;

typedef vector<unsigned int> HS_RESULT;
typedef vector<pair<double, unsigned int> > HS_NORM_RESULT;
typedef double HS_COMP_RESULT;

HS_RESULT HoriScan(const char *c, unsigned int w, unsigned int h);
HS_NORM_RESULT HoriScanNormalize(const HS_RESULT &r);
HS_COMP_RESULT HoriScanCompare(const HS_NORM_RESULT &, const HS_NORM_RESULT &);

#endif /* _HORI_SCAN_H_ */
