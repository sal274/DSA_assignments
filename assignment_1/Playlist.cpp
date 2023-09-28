/*
Playlist.cpp

Playlist class specification
*/

#include "Playlist.h"

void Playlist::add_song(const std::string& title, const std::string& artist,
        const std::string& album, const std::string& duration,
        const std::string& genre)
{
    // Create an array of five strings
    DArray<std::string> song;
    
    song.push_back(title);
    song.push_back(artist);
    song.push_back(album);
    song.push_back(duration);
    song.push_back(genre);

    // Add song (array of strings) to playlist array
    playlist.push_back(std::move(song));
}

void Playlist::add_song(std::string&& title, std::string&& artist,
        std::string&& album, std::string&& duration,
        std::string&& genre)
{
    // Create an array of five strings
    DArray<std::string> song;
    
    song.push_back(std::move(title));
    song.push_back(std::move(artist));
    song.push_back(std::move(album));
    song.push_back(std::move(duration));
    song.push_back(std::move(genre));

    // Add song (array of strings) to playlist array
    playlist.push_back(std::move(song));
}

void Playlist::delete_song(std::size_t pos)
{
    DArray<DArray<std::string>>::iterator itr = &playlist[pos - 1];
    playlist.erase(itr);
}

void Playlist::sort_title(bool ascending)
{
    if (ascending) sort(0, false);
    else sort(0, true);
}

void Playlist::sort_artist(bool ascending)
{
    if (ascending) sort(1, false);
    else sort(1, true);
}

void Playlist::sort_album(bool ascending)
{
    if (ascending) sort(2, false);
    else sort(2, true);
}

void Playlist::sort_duration(bool ascending)
{
    if (ascending) sort(3, false);
    else sort(3, true);
}

void Playlist::sort_genre(bool ascending)
{
    if (ascending) sort(4, false);
    else sort(4, true);
}

void Playlist::sort(int parameter, bool reverse)
{
    std::size_t sz = playlist.size();
    bool sorted = false;
    if (parameter == 3)
    {
        // Sorting based on duration; convert strings to ints
        while (!sorted)
        {
            sorted = true;

            for (std::size_t i = 0; i < sz - 1; ++i)
            {
                if (!reverse)
                {
                    if (std::stoi(playlist[i][3])
                            > std::stoi(playlist[i + 1][3]))
                    {
                        sorted = false;

                        DArray<std::string> temp = std::move(playlist[i]);
                        playlist[i] = std::move(playlist[i + 1]);
                        playlist[i + 1] = std::move(temp);
                    }
                }
                else
                {
                    if (std::stoi(playlist[i][3])
                            < std::stoi(playlist[i + 1][3]))
                    {
                        sorted = false;

                        DArray<std::string> temp = std::move(playlist[i]);
                        playlist[i] = std::move(playlist[i + 1]);
                        playlist[i + 1] = std::move(temp);
                    }
                }
            }
        }
    }
    else
    {
        while (!sorted)
        {
            sorted = true;

            for (std::size_t i = 0; i < sz - 1; ++i)
            {
                if (!reverse)
                {
                    if (playlist[i][parameter] > playlist[i + 1][parameter])
                    {
                        sorted = false;

                        DArray<std::string> temp = std::move(playlist[i]);
                        playlist[i] = std::move(playlist[i + 1]);
                        playlist[i + 1] = std::move(temp);
                    }
                }
                else
                {
                    if (playlist[i][parameter] < playlist[i + 1][parameter])
                    {
                        sorted = false;

                        DArray<std::string> temp = std::move(playlist[i]);
                        playlist[i] = std::move(playlist[i + 1]);
                        playlist[i + 1] = std::move(temp);
                    }
                }
            }
        }
    }
}
