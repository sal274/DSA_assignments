/*
Playlist.cpp

Playlist class specification
*/

#include "Playlist.h"

void Playlist::add_song(std::string title, std::string artist,
        std::string album, std::string duration)
{}

const DArray<std::string>& Playlist::get_song(std::size_t pos) const
{}

void Playlist::edit_song_title(std::size_t pos, std::string new_title)
{}

void Playlist::edit_song_artist(std::size_t pos, std::string new_artist)
{}

void Playlist::edit_song_album(std::size_t pos, std::string new_album)
{}

void Playlist::edit_song_duration(std::size_t pos, std::string new_duration)
{}

void Playlist::delete_song(std::size_t pos)
{}

void Playlist::swap_songs(std::size_t pos_a, std::size_t pos_b)
{}

void Playlist::sort_title(bool ascending)
{}

void Playlist::sort_artist(bool ascending)
{}

void Playlist::sort_album(bool ascending)
{}

void Playlist::sort_duration(bool ascending)
{}
