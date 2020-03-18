#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

int main ()
{

	string start, finish;
	cin >> start >> finish;
	int srow = start[1] - '1';
	int scol = start[0] - 'a';
	int frow = finish[1] - '1';
	int fcol = finish[0] - 'a';

	int const infinity = 99;
	vector <vector <int> > dist (8, vector <int> (8, infinity));
	dist[srow][scol] = 0;

	queue <pair <int, int> > q;
	q.push ({srow, scol});

	vector <int> const drow = {-2, -1, +1, +2, +2, +1, -1, -2};
	vector <int> const dcol = {-1, -2, -2, -1, +1, +2, +2, +1};

	while (!q.empty ())
	{
		int row = q.front ().first;
		int col = q.front ().second;
		q.pop ();

		for (int dir = 0; dir < 8; dir++)
		{
			int nrow = row + drow[dir];
			int ncol = col + dcol[dir];
			if (0 <= nrow && nrow <= 7 && 0 <= ncol && ncol <= 7)
			{

				if (dist[nrow][ncol] == infinity)
				{
					dist[nrow][ncol] = dist[row][col] + 1;
					q.push ({nrow, ncol});
				}
			}
		}
	}

	for (int row = 7; row >= 0; row--)
	{
		for (int col = 0; col < 8; col++)
		{
			cerr << dist[row][col] << " ";
		}
		cerr << endl;
	}

	cout << dist[frow][fcol] << endl;
	return 0;
}
