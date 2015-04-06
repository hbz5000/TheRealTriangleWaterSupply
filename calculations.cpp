#include "global.h"

using namespace std;

void make_PDF(double* data1, double* data2, int length, int** pdf, double size1, double size2)
{	
	int ycount;
	int zcount;
	int size2AsInt;
	size2AsInt = int(size2);

	//debug_display_1d(data1, length);
		
	for (int x = 0; x < length; x++)
	{
		ycount = 0;
		for (double y = (-1.0*(size1/4.0) + 0.5); y < ((size1/4.0)+0.5); y = y+0.5)
		{
			if (data1[x] < y && data1[x] >= (y-0.5))
			{
				zcount = 0;
				for (double z = (-1*(size2/4) + 0.5); z < ((size2/4)+.5); z = z+0.5)
				{
					if (data2[x] < z && data2[x] >= (z-0.5))
					{
						pdf[ycount][zcount] += 1;
						pdf[ycount][size2AsInt] += 1;
						//removed +1 (zero indexing)
					}
					zcount++;
				}
			}
			ycount++;
		}
	}
	return;
}


