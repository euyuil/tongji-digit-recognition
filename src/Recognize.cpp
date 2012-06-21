#include <cstdio>
#include <vector>

using namespace std;

#include <VertScan.h>
#include <Recognize.h>

static const char LEARNING_FILE_PATH[] = "learning";

static vector<VS_NORM_RESULT> vsnr[10];

bool SaveLearning()
{
    FILE *fo = fopen(LEARNING_FILE_PATH, "w");
    if (!fo) return false;

    for (unsigned int i = 0; i < 10; ++i)
    {
        for (unsigned int j = 0; j < vsnr[i].size(); ++j)
        {
            if (vsnr[i][j].size() > 0)
            {
                fprintf(fo, "%u %u\n", i, vsnr[i][j].size());
                fprintf(fo, "%lf", vsnr[i][j][0]);
                for (unsigned int k = 1; k < vsnr[i][j].size(); ++k)
                    fprintf(fo, " %lf", vsnr[i][j][k]);
                fputs("", fo);
            }
        }
    }

    fclose(fo);
    return true;
}

bool LoadLearning()
{
    FILE *fi = fopen(LEARNING_FILE_PATH, "r");
    if (!fi) return false;

    unsigned int p, n;
    while (fscanf(fi, "%u %u", &p, &n))
    {
        if (n > 0)
        {
            vsnr[p].push_back(VS_NORM_RESULT());
            for (unsigned int i = 0; i < n; ++i)
            {
                double r;
                fscanf(fi, "%lf", &r);
                vsnr[p].back().push_back(r);
            }
        }
    }

    fclose(fi);
    return true;
}

bool LearnPattern(char r, const char *c, unsigned int w, unsigned int h)
{
    if (r < '0' || r > '9')
        return false;

    VS_RESULT vsr = VertScan(c, w, h);
    if (vsr.size() == 0)
        return false;

    VS_NORM_RESULT vnr = VertScanNormalize(vsr);
    if (vnr.size() == 0)
        return false;

    vsnr[r - '0'].push_back(vnr);

    return true;
}

char Recognize(const char *c, unsigned int w, unsigned int h)
{
    VS_NORM_RESULT inr = VertScanNormalize(VertScan(c, w, h));
    VS_COMP_RESULT mxr = 0.0;
    char mxc = '\0';

    for (unsigned int i = 0; i < 10; ++i)
    {
        for (unsigned int j = 0; j < vsnr[i].size(); ++j)
        {
            VS_COMP_RESULT r = VertScanCompare(inr, vsnr[i][j]);

            if (r > mxr)
            {
                mxr = r;
                mxc = i + '0';
            }
        }
    }

    return mxc;
}