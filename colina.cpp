#include <iostream>
#include <fstream>

#define NMAX 100000

using namespace std;

int cb(int x, int v[], int st, int dr, int cresc);

int main()
{
	int N, M, i, h[NMAX], gasit, vf, q, poz_st, poz_dr;

	ifstream fin("colina.in");

	fin >> N >> M;

	for (gasit = i = 0; i < N; i++)
	{
		fin >> h[i];

		if (i > 0 && !gasit && h[i] < h[i-1])
		{
			vf = i-1;
			gasit = 1;
		}
		else if (!gasit)
		{
			vf = i;
		}
	}
	
	ofstream fout("colina.out");

	for (i = 0; i < M; i++)
	{
		fin >> q;
		
		poz_st = cb(q, h, 0, vf, 1);
		poz_dr = cb(q, h, vf+1, N-1, 0);
			
		if (poz_st < 0 && poz_dr < 0)
		{
			fout << "NU";
		}
		else
		{
			fout << "DA";

			if (poz_st >= 0)
			{
				fout << ' ' << poz_st+1;
			}

			if (poz_dr >= 0)
			{
				fout << ' ' << poz_dr+1;
			}
		}

		fout << '\n';
	}	

	fin.close();
	fout.close();

	return 0;
}

// caut binar pe x in vectorul sortat v[] in intervalul [st, dr]
// daca cresc == 0 => vectorul este sortat descrescator
// daca cresc == 1 => vectorul este sortat crescator
// returnez pozitia lui x in v[], daca am gasit sau -1 in caz contrar
int cb(int x, int v[], int st, int dr, int cresc)
{
	int mij;

	st--, dr++; 

	while (dr-st > 1)
	{
		mij = st + (dr-st)/2;

		if (v[mij] == x)
		{
			return mij;
		}

		if ((cresc && v[mij] > x) || (!cresc && v[mij] < x))
		{
			dr = mij;
		}
		else
		{
			st = mij;
		}
	}	

	return -1;
}
// scor 100
