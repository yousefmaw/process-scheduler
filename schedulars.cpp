#include<iostream>
#include <string>
#include <queue>
using namespace std;

int main()
{
	cout << "enter the scheduler's type :" << endl;
	string type;
	int nprocess;
	cin >> type;
	cout << "enter number of processes:" << endl;
	cin >> nprocess;
	if (type == "FCFS")
	{
		int** ary = new int*[nprocess];
		for (int i = 0; i < nprocess; ++i)
			ary[i] = new int[3];

		for (int i = 0; i < nprocess; i++)
		{
			ary[i][0] = i;
			cout << "enter process number " << i + 1 << " burst time:";
			cin >> ary[i][1];
			cout << "enter process number " << i + 1 << " arrival time:";
			cin >> ary[i][2];
		}
		int temp;
		for (int i = 0; i < nprocess - 1; i++)
		{
			for (int j = 0; j < nprocess - i - 1; j++)
			{

				if (ary[j][2] >ary[j + 1][2])
				{
					for (int k = 0; k<3; k++) //swap
					{

						temp = ary[j][k];
						ary[j][k] = ary[j + 1][k];
						ary[j + 1][k] = temp;
					}
				}

			}

		}
		int time = ary[0][2]; cout << time; float wtime = 0;
		for (int k = 0; k<nprocess; k++)   //typing
		{

			if (ary[k][2]>time)
			{
				cout << "---nop" << "---" << ary[k][2];
				cout << "---p" << ary[k][0] + 1 << "---";
				cout << ary[k][2] + ary[k][1];
				time = ary[k][2] + ary[k][1];
			}
			else
			{
				cout << "---p" << ary[k][0] + 1 << "---";
				wtime = wtime + (time - ary[k][2]);
				cout << time + ary[k][1];
				time = time + ary[k][1];

			}

		}
		cout << endl;
		cout << wtime / nprocess << endl;
	}
	else if (type == "SJFNON")
	{
		int** ary = new int*[nprocess];
		for (int i = 0; i < nprocess; i++)
			ary[i] = new int[3];

		for (int i = 0; i < nprocess; i++)
		{
			ary[i][0] = i;
			cout << "enter process number " << i + 1 << " burst time:";
			cin >> ary[i][1];
			cout << "enter process number " << i + 1 << " arrival time:";
			cin >> ary[i][2];
		}
		int temp;
		for (int i = 0; i < nprocess - 1; i++) // sorting
		{
			for (int j = 0; j < nprocess - i - 1; j++)
			{

				if (ary[j][2] >ary[j + 1][2])
				{
					for (int k = 0; k<3; k++) //swap
					{

						temp = ary[j][k];
						ary[j][k] = ary[j + 1][k];
						ary[j + 1][k] = temp;
					}
				}

			}

		}
		int k = 1; int btime = 0; int min = 0;
		for (int j = 0; j < nprocess - 1; j++) //sorting the sorted
		{
			btime = btime + ary[j][1];
			min = ary[k][1];
			for (int i = k; i < nprocess; i++)
			{
				if (btime >= ary[i][2] && ary[i][1] < min)
				{
					for (int f = 0; f<3; f++) //swap
					{

						temp = ary[k][f];
						ary[k][f] = ary[i][f];
						ary[i][f] = temp;
					}
				}
			}
			k++;
		}
		int time = ary[0][2]; cout << time; float wtime = 0;
		for (int k = 0; k<nprocess; k++)   //typing
		{

			if (ary[k][2]>time)
			{
				cout << "---nop" << "---" << ary[k][2];
				cout << "---p" << ary[k][0] + 1 << "---";
				cout << ary[k][2] + ary[k][1];
				time = ary[k][2] + ary[k][1];
			}
			else
			{
				cout << "---p" << ary[k][0] + 1 << "---";
				wtime = wtime + (time - ary[k][2]);
				cout << time + ary[k][1];
				time = time + ary[k][1];

			}

		}
		cout << endl;
		cout << wtime / nprocess << endl;
	}
	else if (type == "SJFPRE")
	{
		int** ary = new int*[nprocess];
		for (int i = 0; i < nprocess; i++)
			ary[i] = new int[3];

		for (int i = 0; i < nprocess; i++)
		{
			ary[i][0] = i;
			cout << "enter process number " << i + 1 << " burst time:";
			cin >> ary[i][1];
			cout << "enter process number " << i + 1 << " arrival time:";
			cin >> ary[i][2];
		}
		int temp;
		for (int i = 0; i < nprocess - 1; i++) // sorting
		{
			for (int j = 0; j < nprocess - i - 1; j++)
			{

				if (ary[j][2] >ary[j + 1][2])
				{
					for (int k = 0; k<3; k++) //swap
					{

						temp = ary[j][k];
						ary[j][k] = ary[j + 1][k];
						ary[j + 1][k] = temp;
					}
				}

			}

		}
		int k = 1; int btime = 0; int min = 0;
		for (int j = 0; j < nprocess - 1; j++) //sorting the sorted
		{
			btime = btime + ary[j][1];
			min = ary[k][1];
			for (int i = k; i < nprocess; i++)
			{
				if (btime >= ary[i][2] && ary[i][1] < min)
				{
					for (int f = 0; f<3; f++) //swap
					{

						temp = ary[k][f];
						ary[k][f] = ary[i][f];
						ary[i][f] = temp;
					}
				}
			}
			k++;
		}
		int time = ary[0][2]; cout << time; float wtime = 0;  int flag = 0; int flag1 = 0;
		while (1)
		{

			for (int k = 0; k < nprocess ; k++)   //typing
			{
				if (ary[k][1]>0)
				{
					for (int i = 0; i<nprocess; i++)
					{
						if (((time + ary[k][1]) > ary[i][2]) && (ary[i][1] < ary[k][1]) && (ary[i][1] >0) && (ary[i][2]>ary[k][2]))
						{
							int time2 = time;
							cout << "---p" << ary[k][0] + 1 << "---";
							cout << ary[i][2];
							time = ary[i][2];
							ary[k][1] = ary[k][1] - (time - time2);
							flag1 = 1;
							ary[k][2] = time;
							break;
						}
						if (((time + ary[k][1]) > ary[i][2]) && (ary[i][1] < ary[k][1]) && (ary[i][1] >0) && (ary[i][2]<ary[k][2]))
						{
							flag1 = 1; break;
						}
						
					}
					if (flag1 == 1)
					{
						flag1 = 0;
						continue;
					}
					else
					{
						flag++;
						cout << "---p" << ary[k][0] + 1 << "---";
						wtime = wtime + (time - ary[k][2]);
						cout << time + ary[k][1];
						time = time + ary[k][1];
						ary[k][1] = 0;
					}
				}
				else
					continue;

			}
			if (flag == nprocess)
				break;
		}
		cout << endl;
		cout << "average waiting time is: " << wtime / nprocess << endl;

	}
	else if (type == "PRINON")
	{
		int** ary = new int*[nprocess];
		for (int i = 0; i < nprocess; i++)
			ary[i] = new int[4];

		for (int i = 0; i < nprocess; i++)
		{
			ary[i][0] = i;
			cout << "enter process number " << i + 1 << " burst time:";
			cin >> ary[i][1];
			cout << "enter process number " << i + 1 << " arrival time:";
			cin >> ary[i][2];
			cout << "enter process number " << i + 1 << " Priority:";
			cin >> ary[i][3];
		}
		int temp;
		for (int i = 0; i < nprocess - 1; i++) // sorting
		{
			for (int j = 0; j < nprocess - i - 1; j++)
			{

				if (ary[j][2] >ary[j + 1][2])
				{
					for (int k = 0; k < 4; k++) //swap
					{

						temp = ary[j][k];
						ary[j][k] = ary[j + 1][k];
						ary[j + 1][k] = temp;
					}
				}

			}

		}
		int k = 1; int btime = 0; int min = 0;
		for (int j = 0; j < nprocess - 1; j++)
		{
			btime = btime + ary[j][1];
			min = ary[k][3];
			for (int i = k; i < nprocess; i++)
			{
				if (btime >= ary[i][2] && ary[i][3] < min)
				{
					for (int f = 0; f < 4; f++) //swap
					{

						temp = ary[k][f];
						ary[k][f] = ary[i][f];
						ary[i][f] = temp;
					}
				}
			}
			k++;
		}
		int time = ary[0][2]; cout << time; float wtime = 0;
		for (int k = 0; k<nprocess; k++)   //typing
		{

			if (ary[k][2]>time)
			{
				cout << "---nop" << "---" << ary[k][2];
				cout << "---p" << ary[k][0] + 1 << "---";
				cout << ary[k][2] + ary[k][1];
				time = ary[k][2] + ary[k][1];
			}
			else
			{
				cout << "---p" << ary[k][0] + 1 << "---";
				wtime = wtime + (time - ary[k][2]);
				cout << time + ary[k][1];
				time = time + ary[k][1];

			}

		}
		cout << endl;
		cout << "average waiting time is: " << wtime / nprocess << endl;
	}
	else if (type == "PRIPRE")
	{
		int** ary = new int*[nprocess];
		for (int i = 0; i < nprocess; i++)
			ary[i] = new int[4];

		for (int i = 0; i < nprocess; i++)
		{
			ary[i][0] = i;
			cout << "enter process number " << i + 1 << " burst time:";
			cin >> ary[i][1];
			cout << "enter process number " << i + 1 << " arrival time:";
			cin >> ary[i][2];
			cout << "enter process number " << i + 1 << " Priority:";
			cin >> ary[i][3];
		}
		int temp;
		for (int i = 0; i < nprocess - 1; i++) // sorting
		{
			for (int j = 0; j < nprocess - i - 1; j++)
			{

				if (ary[j][2] >ary[j + 1][2])
				{
					for (int k = 0; k < 4; k++) //swap
					{

						temp = ary[j][k];
						ary[j][k] = ary[j + 1][k];
						ary[j + 1][k] = temp;
					}
				}

			}

		}
		int k = 1; int btime = 0; int min = 0;
		for (int j = 0; j < nprocess - 1; j++)
		{
			btime = btime + ary[j][1];
			min = ary[k][3];
			for (int i = k; i < nprocess; i++)
			{
				if (btime >= ary[i][2] && ary[i][3] < min)
				{
					for (int f = 0; f < 4; f++) //swap
					{

						temp = ary[k][f];
						ary[k][f] = ary[i][f];
						ary[i][f] = temp;
					}
				}
			}
			k++;
		}
		int time = ary[0][2]; cout << time; float wtime = 0;  int flag = 0; int flag1 = 0;
		while (1)
		{

			for (int k = 0; k < nprocess; k++)   //typing
			{
				if (ary[k][1]>0)
				{
					for (int i = 0; i<nprocess; i++)
					{
						if (((time + ary[k][1]) > ary[i][2]) && (ary[i][3] < ary[k][3]) && (ary[i][1] >0) && (ary[i][2]>ary[k][2]))
						{
							int time2 = time;
							cout << "---p" << ary[k][0] + 1 << "---";
							cout << ary[i][2];
							time = ary[i][2];
							ary[k][1] = ary[k][1] - (time - time2);
							flag1 = 1;
							ary[k][2] = time;
							break;
						}
						if (((time + ary[k][1]) > ary[i][2]) && (ary[i][3] < ary[k][3]) && (ary[i][1] >0) && (ary[i][2]<ary[k][2]))
						{
							flag1 = 1; break;
						}

					}
					if (flag1 == 1)
					{
						flag1 = 0;
						continue;
					}
					else
					{
						flag++;
						cout << "---p" << ary[k][0] + 1 << "---";
						wtime = wtime + (time - ary[k][2]);
						cout << time + ary[k][1];
						time = time + ary[k][1];
						ary[k][1] = 0;
					}
				}
				else
					continue;

			}
			if (flag == nprocess)
				break;
		}
		cout << endl;
		cout << "average waiting time is: " << wtime / nprocess << endl;
		
	}
	else if (type == "RR")
	{
		int** ary = new int*[nprocess]; int qt;
		for (int i = 0; i < nprocess; i++)
			ary[i] = new int[3];

		for (int i = 0; i < nprocess; i++)
		{
			ary[i][0] = i;
			cout << "enter process number " << i + 1 << " burst time:";
			cin >> ary[i][1];
			cout << "enter process number " << i + 1 << " arrival time:";
			cin >> ary[i][2];

		}
		cout << "enter the Time Quantum: ";
		cin >> qt;
		int temp;
		for (int i = 0; i < nprocess - 1; i++) // sorting
		{
			for (int j = 0; j < nprocess - i - 1; j++)
			{

				if (ary[j][2] >ary[j + 1][2])
				{
					for (int k = 0; k < 4; k++) //swap
					{

						temp = ary[j][k];
						ary[j][k] = ary[j + 1][k];
						ary[j + 1][k] = temp;
					}
				}

			}

		}
		int time = ary[0][2]; cout << time; float wtime = 0;  int flag = 0;
		while (1)
		{

			for (int k = 0; k < nprocess; k++)   //typing
			{
				if (ary[k][1]>0)
				{

					cout << "---p" << ary[k][0] + 1 << "---";
					if (ary[k][1] <= qt)
					{
						flag++;
						cout << time + ary[k][1];
						time = time + ary[k][1];
						ary[k][1] = ary[k][1] - qt;
						wtime = wtime + (time - ary[k][2]);
					}
					else
					{
						cout << time + qt;
						time = time + qt;
						ary[k][1] = ary[k][1] - qt;
					}
				}
				else
					continue;

			}
			if (flag == nprocess)
				break;
		}
		cout << endl;
		cout << "average waiting time is: " << wtime / nprocess << endl;

	}
	else
		cout << "ERROR" << endl;
	return 0;


}