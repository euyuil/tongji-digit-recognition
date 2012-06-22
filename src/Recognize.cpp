#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

#include <VertScan.h>
#include <HoriScan.h>
#include <NineGrids.h>
#include <Recognize.h>
#include <RecogUtils.h>
#include <Characteristic.h>

static const char LEARNING_FILE_PATH[] = "res/learning.txt";

static vector<CHARACTER> chs[10];

bool SaveLearning()
{
    FILE *fo = fopen(LEARNING_FILE_PATH, "w");
    if (!fo) return false;

    for (unsigned int i = 0; i < 10; ++i)
    {
        for (unsigned int j = 0; j < chs[i].size(); ++j)
        {
            fprintf(fo, "%u\n", i);
            foutch(fo, chs[i][j]);
        }
    }

    fclose(fo);
    return true;
}

bool LoadLearning()
{
    FILE *fi = fopen(LEARNING_FILE_PATH, "r");
    if (!fi) return false;

    unsigned int p;
    while (fscanf(fi, "%u", &p) != EOF)
    {
        chs[p].push_back(CHARACTER());
        finch(fi, chs[p].back());
    }

    fclose(fi);
    return true;
}

bool LearnPattern(char r, const char *c, unsigned int w, unsigned int h)
{
    if (r < '0' || r > '9')
        return false;

    if (!MatrixHasContent(c, w, h))
        return false;

    unsigned int idx = r - '0';

    chs[idx].push_back(CHARACTER());
    chs[idx].back().vs = VertScanNormalize(VertScan(c, w, h));
    chs[idx].back().hs = HoriScanNormalize(HoriScan(c, w, h));

    fprintf(stderr, "Pattern for %c was learnt.\n", r);

    return true;
}

char Recognize(const char *c, unsigned int w, unsigned int h)
{
    if (!MatrixHasContent(c, w, h))
        return false;

    VS_NORM_RESULT vsr = VertScanNormalize(VertScan(c, w, h));
    HS_NORM_RESULT hsr = HoriScanNormalize(HoriScan(c, w, h));
    NG_RESULT ngr; NineGridScan(c, w, h, ngr);

    double mxr = 0.0; char mxc = '\0';

    for (unsigned int i = 0; i < 10; ++i)
    {
        fprintf(stderr, "%u:", i);

        for (unsigned int j = 0; j < chs[i].size(); ++j)
        {
            VS_COMP_RESULT v = VertScanCompare(vsr, chs[i][j].vs);
            HS_COMP_RESULT h = HoriScanCompare(hsr, chs[i][j].hs);
            NG_COMP_RESULT g = NineGridCompare(ngr, chs[i][j].ng);

            double r = v * h * g;

            if (r > mxr)
            {
                mxr = r;
                mxc = i + '0';
            }

            fprintf(stderr, " %lf", r);
        }

        fprintf(stderr, "\n");
    }

    fprintf(stderr, "Pattern recognized, mxr = %lf, mxc = %c.\n", mxr, mxc);

    return mxc;
}

static bool RecogPossiLessThan(
    const pair<char, double> &a, const pair<char, double> &b)
{
    return a.second > b.second;
}

vector<pair<char, double> > RecognizePossibility(
    const char *c, unsigned int w, unsigned int h)
{
    vector<pair<char, double> > result;

    if (!MatrixHasContent(c, w, h))
        return result;

    VS_NORM_RESULT vsr = VertScanNormalize(VertScan(c, w, h));
    HS_NORM_RESULT hsr = HoriScanNormalize(HoriScan(c, w, h));
    NG_RESULT ngr; NineGridScan(c, w, h, ngr);

    result.resize(10);

    for (unsigned int i = 0; i < 10; ++i)
    {
        fprintf(stderr, "%u:", i);

        result[i].first = '0' + i;

        double mxr = 0.0;

        for (unsigned int j = 0; j < chs[i].size(); ++j)
        {
            VS_COMP_RESULT v = VertScanCompare(vsr, chs[i][j].vs);
            HS_COMP_RESULT h = HoriScanCompare(hsr, chs[i][j].hs);
            NG_COMP_RESULT g = NineGridCompare(ngr, chs[i][j].ng);

            double r = v * h * g;

            if (r > mxr)
                mxr = r;

            fprintf(stderr, " %lf", r);
        }

        result[i].second = mxr;

        fprintf(stderr, "\n");
    }

    fprintf(stderr, "Batch pattern recognized.\n");

    sort(result.begin(), result.end(), RecogPossiLessThan);

    return result;
}
