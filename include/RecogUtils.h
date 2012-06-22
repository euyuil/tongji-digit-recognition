#ifndef _RECOG_UTILS_H_
#define _RECOG_UTILS_H_

bool GetMatrixBound(const char *c, unsigned int w, unsigned int h,
    unsigned int &w1, unsigned int &w2, unsigned int &h1, unsigned int &h2);

bool MatrixHasContent(const char *c, unsigned int w, unsigned int h);

#endif /* _RECOG_UTILS_H_ */
