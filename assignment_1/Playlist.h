/*
Playlist.h

Playlist class interface

(Playlist data structure internally manages a two-dimensional dynamic
array. The dynamic array data structure is implemented in DArray.h as
a class template called DArray)
*/

#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <string>

#include "DArray.h"

class Playlist
{
    public:

        // Create new song with rvalue reference
        void add_song(const std::string& title, const std::string& artist,
            const std::string& album, const std::string& duration,
            const std::string& genre);

        // Create new song with lvalue reference
        void add_song(std::string&& title, std::string&& artist,
            std::string&& album, std::string&& duration,
            std::string&& genre);

        const DArray<std::string>& get_song(std::size_t pos) const
            { return playlist[pos - 1]; }
    
        void edit_song_title(std::size_t pos, std::string new_title)
            { playlist[pos - 1][0] = new_title; } // Index 0 stores title
        
        void edit_song_artist(std::size_t pos, std::string new_artist)
            { playlist[pos - 1][1] = new_artist; }  // Index 1 stores artist

        void edit_song_album(std::size_t pos, std::string new_album)
            { playlist[pos - 1][2] = new_album; }  // Index 2 stores album
        
        void edit_song_duration(std::size_t pos, std::string new_duration)
            { playlist[pos - 1][3] = new_duration; }  // Index 3 stores duration
        
        void edit_song_genre(std::size_t pos, std::string new_genre)
            { playlist[pos - 1][4] = new_genre; }  // Index 4 stores genre

        void delete_song(std::size_t pos);

        std::size_t size() const { return playlist.size(); }
        bool is_empty() const { return playlist.empty(); }

        // Playlist reordering
        void move_song(std::size_t from, std::size_t to)
            { std::swap(playlist[from - 1], playlist[to - 1]); }

        // Playlist sorting
        void sort_title(bool ascending = true);
        void sort_artist(bool ascending = true);
        void sort_album(bool ascending = true);
        void sort_duration(bool ascending = true);
        void sort_genre(bool ascending = true);

        void clear() { playlist.resize(0); }

        typedef DArray<std::string>* iterator;
        typedef const DArray<std::string>* const_iterator;

        iterator begin() { return playlist.begin(); }
        const_iterator begin() const { return playlist.begin(); }

        iterator end() { return playlist.end(); }
        const_iterator end() const { return playlist.end(); }

    private:
        
        /*
        The internal representation of Playlist objects is a
        two-dimensional dynamic array; an array of array of strings:
        
        {
            { <title>, <artist>, <album>, <duration>, <genre>},  // Song 1
            { <title>, <artist>, <album>, <duration>, <genre>},  // Song 2
            { <title>, <artist>, <album>, <duration>, <genre>},  // Song 3
            { <title>, <artist>, <album>, <duration>, <genre>},  // Song 4
            ....                                                 // etc
        }

        The declaration below, DArray<DArray<std::string>> playlist,
        represents this two-dimensional dynamic array
        */
        DArray<DArray<std::string>> playlist;

        /*
        This helper function sorts the playlist based on the value
        of <parameter>.

        parameter = 0 sorts the playlist based on the title
        parameter = 1 sorts the playlist based on the artist
        parameter = 2 sorts the playlist based on the album
        parameter = 3 sorts the playlist based on the duration
        parameter = 4 sorts the playlist based on the genre

        All sorts are done lexicographically, except for sorting based
        on the duration
        */
        void sort(int parameter, bool reverse);
};

#endif  // PLAYLIST_H