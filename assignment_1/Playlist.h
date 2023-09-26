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

        Playlist() {}  // Empty array is initialized in DArray object

        void add_song(std::string title, std::string artist, std::string album,
            std::string duration);

        const DArray<std::string>& get_song(std::size_t pos) const;
    
        void edit_song_title(std::size_t pos, std::string new_title);
        void edit_song_artist(std::size_t pos, std::string new_artist);
        void edit_song_album(std::size_t pos, std::string new_album);
        void edit_song_duration(std::size_t pos, std::string new_duration);

        void delete_song(std::size_t pos);

        void swap_songs(std::size_t pos_a, std::size_t pos_b);

        void sort_title(bool ascending = true);
        void sort_artist(bool ascending = true);
        void sort_album(bool ascending = true);
        void sort_duration(bool ascending = true);

    private:
        
        /*
        The internal representation of Playlist objects is a
        two-dimensional dynamic array; an array of array of strings:
        
        {
            { <title>, <artist>, <album>, <duration> },  // Song 1
            { <title>, <artist>, <album>, <duration> },  // Song 2
            { <title>, <artist>, <album>, <duration> },  // Song 3
            { <title>, <artist>, <album>, <duration> },  // Song 4
            ....                                         // etc
        }

        The declaration below, DArray<DArray<std::string>> playlist,
        represents this two-dimensional dynamic array
        */
        DArray<DArray<std::string>> playlist;
};

#endif
