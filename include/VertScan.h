#ifndef _VERT_SCAN_H_
#define _VERT_SCAN_H_

/**
 * Vertical scanning algorithms for Digit Recognizing.
 * @author EUYUIL
 * @date 2012-06-16
 */

#include <vector>
#include <utility>

using namespace std;

typedef vector<unsigned int> VS_RESULT;
typedef vector<pair<double, unsigned int> > VS_NORM_RESULT;
typedef double VS_COMP_RESULT;

VS_RESULT VertScan(const char *c, unsigned int w, unsigned int h);
VS_NORM_RESULT VertScanNormalize(const VS_RESULT &r);
VS_COMP_RESULT VertScanCompare(const VS_COMP_RESULT &, const VS_COMP_RESULT &);

#endif /* _VERT_SCAN_H_ */
