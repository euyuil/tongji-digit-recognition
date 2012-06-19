#include <algorithm>

using namespace std;

#include <VertScan.h>

/**
 * Vertical scanning algorithm for digital recognizing.
 * TODO Test this function.
 * @author EUYUIL
 * @date 2012-06-19
 */

VS_RESULT VertScan(const char *c, unsigned int w, unsigned int h)
{
    VS_RESULT result(h, 0);

    for (unsigned int i = 0; i < h; ++i)
    {
        const char *q = c + i * w;
        char last = ' ';

        for (unsigned int j = 0; j < w; ++j)
        {
            const char *p = q + j;
            if (*p != last)
                ++result[i];
            last = *p;
        }
    }

    return result;
}

/**
 * Vertical scanning normalizing algorithm for digital recognizing.
 * TODO Test this function.
 * @author EUYUIL
 * @date 2012-06-19
 */

VS_NORM_RESULT VertScanNormalize(const VS_RESULT &r)
{
    VS_NORM_RESULT result;

    if (r.size() == 1)
    {
        result.push_back(make_pair(1.0, r[0]));
    }
    else if (r.size() > 1)
    {
        unsigned int last = r[0];
        unsigned int cnt = 0; bool flag = true;

        for (unsigned int i = 1; i <= r.size(); ++i)
        {
            if (i < r.size())
            {
                if (r[i] == last)
                    ++cnt;
                else
                    flag = false;
            }
            else
                flag = false;

            if (!flag)
            {
                flag = true;
                result.push_back(
                    make_pair(double(cnt) / double(r.size()), r[i - 1]));
                cnt = 0;
            }
        }

        return result;
    }

    return result;
}

/**
 * Vertical scanning comparing algorithm for digital recognizing.
 * TODO Test this function.
 * @author EUYUIL
 * @date 2012-06-19
 */

VS_COMP_RESULT VertScanCompare(const VS_NORM_RESULT &a, const VS_NORM_RESULT &b)
{
    VS_COMP_RESULT result = 0.0;
    double last = 0.0, x = 0.0, y = 0.0;
    unsigned int i = 0, j = 0;

    do {
        double nx = x + a[i].first;
        double ny = y + b[j].first;
        double nm = min(nx, ny);

        if (a[i].second == b[j].second)
            result += nm - last;

        if (nx < ny) ++i;
        else ++j;

        last = nm;

    } while (i < a.size() && j < b.size());

    return result;
}
