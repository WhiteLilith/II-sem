#include "stdafx.h"
#include "msoftcon.h" 
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

const int CPF = 5;
const int maxHorses = 7;
class track;

class horse
{
protected:
	const track* ptrTrack;
	const int horse_number;
	float finish_time;
	float distance_run;
public:
	horse(const int n, const track* ptrT) : horse_number(n), ptrTrack(ptrT)
		the horse
	{
		distance_run = 0.0;
	}
	~horse()
	{

	}
	void display_horse(const float elapsed_time);
};

class track
{
protected:
	horse* hArray[maxHorses];
	int total_horses;
	int horse_count;
	const float track_length;
	float elapsed_time;
public:
	track(float lenT, int nH);
	~track();
	void display_track();
	void run();
	float get_track_len() const;
};

void horse::display_horse(float elapsed_time)
{ 
	set_cursor_pos(1 + int(distance_run * CPF), 2 + horse_number * 2);

	set_color(static_cast<color>(cBLUE + horse_number));

	char horse_char = '0' + static_cast<char>(horse_number);
	_putch(' '); _putch('\xDB'); _putch(horse_char); _putch('\xDB');

	if (distance_run < ptrTrack->get_track_len() + 1.0 / CPF)
	{
		if (rand() % 3)
		{
			distance_run += 0.2F;
		}
		finish_time = elapsed_time;
	}
	else
	{ //display finish time
		int mins = int(finish_time) / 60;
		int secs = int(finish_time) - mins * 60;
		cout << " Time=" << mins << ":" << secs;
	}
}

track::track(float lenT, int nH) :
	track_length(lenT), total_horses(nH),
	horse_count(0), elapsed_time(0.0)
{
	init_graphics();
	total_horses = (total_horses > maxHorses) ? maxHorses : total_horses;
	than 7 horses
		for (int j = 0; j < total_horses; j++)
		{
			hArray[j] = new horse(horse_count++, this);
		}
	time_t aTime;
	srand(static_cast<unsigned>(time(&aTime)));
	display_track();
} 

track::~track()
{
	for (int j = 0; j < total_horses; j++)
	{
		delete hArray[j];
	}
}

void track::display_track()
{
	clear_screen();

	for (int f = 0; f <= track_length; f++)
	{
		for (int r = 1; r <= total_horses * 2 + 1; r++)
		{
			set_cursor_pos(f * CPF + 5, r);
			if (f == 0 || f == track_length)
			{
				cout << '\xDE';
			}
			else
			{
				cout << '\xB3';
			}
		}
	}
}

void track::run()
{
	while (!_kbhit())
	{
		elapsed_time += 1.75;

		for (int j = 0; j < total_horses; j++)
		{
			hArray[j]->display_horse(elapsed_time);
		}
		wait(500);
	}
	_getch();
	cout << endl;
}

float track::get_track_len() const
{
	return track_length;
}

class comhorse : public horse
{
protected:

public:
	comhorse(const int n, const track* ptrT) : horse(n, ptrT)
	{ }
	~comhorse()
	{
		horse::~horse();
	}
	float GetDistance()
	{
		return distance_run;
	}
	void HorseTick()
	{
		set_cursor_pos(1 + int(distance_run * CPF), 2 + horse_number * 2);
		set_color(static_cast<color>(cBLUE + horse_number));
		char horse_char = '0' + static_cast<char>(horse_number);
		cout << ' ' << '\xDB' << horse_char << '\xDB';
		distance_run += 0.2F;
	}
};
class comtrack : public track
{
protected:
	comhorse* hArray[maxHorses];
public:
	comtrack(float lenT, int nH) : track(lenT, nH)
	{
		horse_count = 0;
		for (int j = 0; j < total_horses; j++)
		{
			hArray[j] = new comhorse(horse_count++, this);
		}
	}
	void run()
	{
		while (!_kbhit())
		{
			int horse_leader = 0;
			float delta = 0.0;
			elapsed_time += 1.75;
			for (int i = 0; i < total_horses; i++)
				hArray[i]->display_horse(elapsed_time);
			for (int i = 0; i < total_horses; i++)
			{
				if (hArray[horse_leader]->GetDistance() < hArray[i] -
				>GetDistance())
				{
					horse_leader = i;
				}
			}
			for (int i = 0; i < total_horses; i++)
			{
				if (hArray[horse_leader]->GetDistance() - hArray[i] ->GetDistance() > delta)
				{
					delta = hArray[horse_leader]->GetDistance() - hArray[i] ->GetDistance();
				}
			}
			if ((hArray[horse_leader]->GetDistance() > (track_length + 1.0 / CPF)/ 2) && (hArray[horse_leader]->GetDistance() < (track_length + 1.0 / CPF)) && (delta <= 2.2f))
			{
				hArray[horse_leader]->HorseTick();
			}
			wait(100);
		}
		_getch();
		cout << endl;
	}
};
int main()
{
	float length;
	int total;
	cout << "\nEnter track length (furlongs; 1 to 12): ";
	cin >> length;
	cout << "\nEnter number of horses (1 to 7): ";
	cin >> total;
	cout << endl << endl << endl << endl << endl;
	comtrack theTrack(length, total);
	theTrack.run();
	return 0;
}
