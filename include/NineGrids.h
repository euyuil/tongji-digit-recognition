#ifndef _NINE_GRIDS_H_
#define _NINE_GRIDS_H_

typedef double NINE_GRIDS[3][3];
typedef NINE_GRIDS NG_RESULT;
typedef double NG_COMP_RESULT;

bool NineGridScan(const char *, unsigned int w, unsigned int h, NG_RESULT &);
NG_COMP_RESULT NineGridCompare(const NG_RESULT &, const NG_RESULT &);

#endif /* _NINE_GRIDS_H_ */
