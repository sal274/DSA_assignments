/*
playlist_management.cpp

Demonstrate how the Playlist Management functions work:
    1 - Playlist reordering (using function Playlist::move_song)
    2 - Playlist sorting (using functions Playlist::sort_title,
        Playlist::sort_artist, Playlist::sort_album,
        Playlist::sort_duration, Playlist::sort_genre)
*/


#include <iostream>

#include "Playlist.h"

using std::cout;

void init_playlist(Playlist&);
void print_playlist(Playlist&);

int main()
{
    Playlist l;  // Create empty playlist
    init_playlist(l);  // Fill empty playlist with sample data
    print_playlist(l);

    // Example of reordering playlist by moving the first song to the
    // third place
    l.move_song(1, 3);
    cout << "MAKE SONG 1 THE 3RD SONG\n\n";
    print_playlist(l);

    // Playlist sorting
    // Sort based on the song's title
    l.sort_title();
    cout << "SORT BASED ON TITLE\n\n";
    print_playlist(l);

    // Sort based on the song's title in reverse order (this works for
    // all sorting functions)
    l.sort_title(false);
    cout << "SORT BASED ON TITLE (REVERSE)\n\n";
    print_playlist(l);

    // Sort based on the song's artist
    l.sort_artist();
    cout << "SORT BASED ON ARTIST\n\n";
    print_playlist(l);

    // Sort based on the song's album
    l.sort_album();
    cout << "SORT BASED ON ALBUM\n\n";
    print_playlist(l);

    // Sort based on the song's duration
    l.sort_duration();
    cout << "SORT BASED ON DURATION\n\n";
    print_playlist(l);

    // Sort based on the son's genre
    l.sort_genre();
    cout << "SORT BASED ON GENRE\n\n";
    print_playlist(l);

    return 0;
}

// Fill empty playlist with sample data
void init_playlist(Playlist& l)
{
    l.clear();
    l.add_song("Heroes", "David Bowie", "Heroes", "371", "Rock");
    l.add_song("Famous Blue Raincoat", "Leonard Cohen",
        "Songs Of Love And Hate", "310", "Blues");
    l.add_song("American Pie", "Don McLean", "American Pie", "516", "Rock");
    l.add_song("Diamonds And Rust", "Joan Baez", "Diamonds & Rust", "286",
        "Blues");
    l.add_song("Enfants d'hiver", "Jane Birkin", "Enfants d'hiver", "224",
        "Rock");
    l.add_song("Knockin' On Heaven's Door", "Bob Dylan",
        "Pat Garrett & Billy The Kid", "149", "Rock");
    l.add_song("Changing of the Guards", "Bob Dylan", "Street-Legal", "397",
        "Rock");
}

// Traverse over the list and print each song's information
void print_playlist(Playlist& l)
{
    std::size_t counter = 1;
    for (auto& song : l)
    {
        cout << "Song " << counter
            << "\nTitle: " << song[0]
            << "\nArtist: " << song[1]
            << "\nAlbum: " << song[2]
            << "\nDuration: " << song[3] << " seconds"
            << "\nGenre: " << song[4] << "\n\n";
        ++counter;
    }
    cout << '\n';
}