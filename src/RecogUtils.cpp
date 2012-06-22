#include <climits>
#include <algorithm>

using namespace std;

#include <RecogUtils.h>

bool MatrixHasContent(const char *c, unsigned int w, unsigned int h)
{
    for (unsigned int i = 0; i < h; ++i)
    {
        const char *q = c + i * w;

        for (unsigned int j = 0; j < w; ++j)
        {
            const char *p = q + j;

            if (*p != ' ')
                return true;
        }
    }

    return false;
}

bool GetMatrixBound(const char *c, unsigned int w, unsigned int h,
    unsigned int &w1, unsigned int &w2, unsigned int &h1, unsigned int &h2)
{
    w1 = h1 = INT_MAX; w2 = h2 = 0;

    for (unsigned int i = 0; i < h; ++i)
    {
        const char *q = c + i * w;

        for (unsigned int j = 0; j < w; ++j)
        {
            const char *p = q + j;

            if (*p != ' ')
                w1 = min(w1, j), h1 = min(h1, i),
                w2 = max(w2, j), h2 = max(h2, i);
        }
    }

    if (w1 > w2 || h1 > h2)
        return false;
    ++w2; ++h2;
    return true;
}
