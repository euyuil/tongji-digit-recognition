#include <cstdio>
#include <algorithm>

using namespace std;

#include <VertScan.h>
#include <RecogUtils.h>

/**
 * Vertical scanning algorithm for digital recognizing.
 * @author EUYUIL
 * @date 2012-06-19
 */

VS_RESULT VertScan(const char *c, unsigned int w, unsigned int h)
{
    VS_RESULT result;

    unsigned int w1, w2, h1, h2;

    if (GetMatrixBound(c, w, h, w1, w2, h1, h2))
    {
        for (unsigned int i = h1; i < h2; ++i)
        {
            const char *q = c + i * w;
            char last = ' ';
            result.push_back(0);

            for (unsigned int j = w1; j < w2; ++j)
            {
                const char *p = q + j;
                if (*p != last && *p != ' ')
                    ++result.back();
                last = *p;
            }
        }
    }

    fprintf(stderr, "VertScan:");
    for (unsigned int i = 0; i < result.size(); ++i)
        fprintf(stderr, " %u", result[i]);
    fprintf(stderr, "\n");

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

        for (unsigned int i = 0; i <= r.size(); ++i)
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
                cnt = 1;
            }

            if (i < r.size())
                last = r[i];
        }
    }

    fprintf(stderr, "VertScanNormalize:");
    for (unsigned int i = 0; i < result.size(); ++i)
        fprintf(stderr, " %lf:%u", result[i].first, result[i].second);
    fprintf(stderr, "\n");

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

        if (nx < ny) ++i, x = nx;
        else ++j, y = ny;

        last = nm;

    } while (i < a.size() && j < b.size());

    return result;
}
