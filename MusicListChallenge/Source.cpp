/*
	In this challenge you will create a menu driven application that will simulate
	a user playing songs from a playlist

	We will use a list to simulate the user selecting the first song in the playlist
	then selecting next and previous to play forward or backwards through the playlist

	We will also allow users to add new songs to the playlist and they will be added prior to the current song

	The menu will look as follows:

	F - Play First Song
	N - Play Next Song
	P - Play Previous Song
	A - Add and Play a New Song at the Current Location
	L - List the Current Playlist
	=================================
	Enter a selection (Q to quit):

	Following are the songs in the playlist

	God's Plan			Drake						5
	Never be the Same	Camila Cabello				5
	Pray for Me			The weekend and K. Lamar	4
	The Middle			Zedd, Maren Morris & Grey	5
	Wait				Maroon 5					4
	Whatever it Takes	Imagine Dragons				3
*/

#include <iostream>
#include <list>
#include <string>
#include <cctype>
#include <iomanip>
#include <limits>

class Song
{
	friend std::ostream& operator<<(std::ostream& os, const Song& s);
	std::string name;
	std::string artist;
	int rating;
public:
	Song() = default;
	Song(std::string name, std::string artist, int rating)
		: name{ name }, artist{ artist }, rating{ rating } {}
	std::string get_name() const
	{
		return name;
	}
	std::string get_artist() const
	{
		return artist;
	}
	int get_rating() const
	{
		return rating;
	}

	bool operator<(const Song& rhs) const
	{
		return this->name < rhs.name;
	}

	bool operator==(const Song& rhs) const
	{
		return this->name == rhs.name;
	}
};

std::ostream& operator<<(std::ostream& os, const Song& s)
{
	os << std::setw(20) << std::left << s.name
		<< std::setw(30) << std::left << s.artist
		<< std::setw(2) << std::left << s.rating;
	return os;
}

void display_menu()
{
	std::cout << "\nF - Play First Song" << std::endl;
	std::cout << "N - Play Next song" << std::endl;
	std::cout << "P - Play Previous song" << std::endl;
	std::cout << "A - Add and play a new Song at current location" << std::endl;
	std::cout << "L - List the current playlist" << std::endl;
	std::cout << "===============================================" << std::endl;
	std::cout << "Enter a selection (Q to quit): ";
}

void play_current_song(const Song& song)
{
	std::cout << "\nPlaying:" << std::endl;
	std::cout << song << std::endl;
}

void display_playlist(const std::list<Song>& playlist, const Song& current_song)
{
	std::cout << std::setw(20) << std::left << "\nSong"
		<< std::setw(30) << std::left << "Artist"
		<< std::setw(2) << std::left << "Rating"
		<< std::endl;

	std::cout << std::setw(55) << std::setfill('-') << "" << std::endl;
	std::cout << std::setfill(' ');

	for (const auto& song : playlist)
		std::cout << song << std::endl;

	std::cout << "\nCurrent song: " << std::endl;
	std::cout << current_song << std::endl;
}

int main()
{
	std::list<Song> playlist{
			{"God's Plan",        "Drake",                     5},
			{"Never Be The Same", "Camila Cabello",            5},
			{"Pray For Me",       "The Weekend and K. Lamar",  4},
			{"The Middle",        "Zedd, Maren Morris & Grey", 5},
			{"Wait",              "Maroone 5",                 4},
			{"Whatever It Takes", "Imagine Dragons",           3}
	};

	std::list<Song>::iterator current_song = playlist.begin();
	char selection{ NULL };

	do
	{
		display_menu();
		std::cin >> selection;

		switch (std::toupper(selection))
		{
			case 'F':
				{
					current_song = playlist.begin();
					play_current_song(*current_song);
					break;
				}

			case 'N':
				{
					if (current_song == --playlist.end())
					{
						current_song = playlist.begin();
						play_current_song(*current_song);
					}
					else
					{
						++current_song;
						play_current_song(*current_song);
					}
					break;
				}

			case 'P':
				{
					if (current_song == playlist.begin())
					{
						current_song = playlist.end();
						--current_song;
						play_current_song(*current_song);
					}
					else
					{
						--current_song;
						play_current_song(*current_song);
					}
					break;
				}

			case 'A':
				{
					std::string song{ NULL };
					std::string artist{ NULL };
					int rating{ 0 };

					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

					std::cout << "\nAdding and playing a song" << std::endl;
					std::cout << "\nEnter song name: ";
					getline(std::cin, song);
					std::cout << "\nEnter song artist: ";
					getline(std::cin, artist);
					std::cout << "Enter your rating (1-5): ";
					std::cin >> rating;

					playlist.emplace(current_song, song, artist, rating);
					current_song--;
					play_current_song(*current_song);

					break;
				}

			case 'L':
				{
					display_playlist(playlist, *current_song);
					break;
				}

			default:
				break;
		}

	} while (selection != 'Q' && selection != 'q');

	std::cout << "Thanks for listening!" << std::endl;
}