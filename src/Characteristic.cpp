#include <cstdio>
#include <utility>

using namespace std;

#include <Characteristic.h>

bool foutch(FILE *f, const CHARACTER &c)
{
    fprintf(f, "%u", c.vs.size());
    for (unsigned int i = 0; i < c.vs.size(); ++i)
        fprintf(f, " %lf %u", c.vs[i].first, c.vs[i].second);
    fprintf(f, "\n");

    fprintf(f, "%u", c.hs.size());
    for (unsigned int i = 0; i < c.hs.size(); ++i)
        fprintf(f, " %lf %u", c.hs[i].first, c.hs[i].second);
    fprintf(f, "\n");

    return true;
}

bool finch(FILE *f, CHARACTER &c)
{
    unsigned int n;

    fscanf(f, "%u", &n);
    c.vs.clear();
    for (unsigned int i = 0; i < n; ++i)
    {
        double s; unsigned int t;
        fscanf(f, "%lf %u", &s, &t);
        c.vs.push_back(make_pair(s, t));
    }

    fscanf(f, "%u", &n);
    c.hs.clear();
    for (unsigned int i = 0; i < n; ++i)
    {
        double s; unsigned int t;
        fscanf(f, "%lf %u", &s, &t);
        c.hs.push_back(make_pair(s, t));
    }

    return true;
}
