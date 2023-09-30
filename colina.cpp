#include <iostream>
#include <fstream>

#define NMAX 100000

using namespace std;

int main()
{
	ifstream fin("colina.in");

	int N, M, vf, i, h[NMAX], q, st, dr, mij, poz_st, poz_dr;

	fin >> N >> M;

	for (vf = i = 0; i < N; i++)
	{
		fin >> h[i];

		if (i > 0 && vf == 0 && h[i] < h[i-1])
		{
			vf = i-1;
		}
	}

	ofstream fout("colina.out");

	for (i = 0; i < M; i++)
	{
		fin >> q;

		poz_st = poz_dr = -1;

		st = -1, dr = vf+1;

		while (dr-st > 1)
		{
			mij = st + (dr-st)/2;

			if (h[mij] < q)
			{
				st = mij;
			}
			else
			{
				dr = mij;
			}
		}

		if (h[dr] == q)
		{
			poz_st = dr+1;
		}

		st = vf, dr = N;

		while (dr-st > 1)
		{
			mij = st + (dr-st)/2;

			if (h[mij] > q)
			{
				st = mij;
			}
			else
			{
				dr = mij;
			}
		}

		if (h[dr] == q)
		{
			poz_dr = dr+1;
		}

		if (poz_st < 0 && poz_dr < 0)
		{
			fout << "NU";
		}
		else
		{
			fout << "DA";

			if (poz_st >= 0)
			{
				fout << ' ' << poz_st;
			}

			if (poz_dr >= 0)
			{
				fout << ' ' << poz_dr;
			}
		}

		fout << '\n';
	}	

	fin.close();
	fout.close();

	return 0;
}
// scor 85
