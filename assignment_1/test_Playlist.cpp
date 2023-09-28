/*
test_Playlist.cpp

Tests for Playlist class
*/

#include <iostream>

#include "Playlist.h"

using std::cout;

bool test_add_song(Playlist&);
bool test_get_song(Playlist&);
bool test_edit_song_title(Playlist&);
bool test_edit_song_artist(Playlist&);
bool test_edit_song_album(Playlist&);
bool test_edit_song_duration(Playlist&);
bool test_edit_song_genre(Playlist&);
bool test_delete_song(Playlist&);
bool test_size(Playlist&);
bool test_move_song(Playlist&);
bool test_sort_title(Playlist&);
bool test_sort_artist(Playlist&);
bool test_sort_album(Playlist&);
bool test_sort_duration(Playlist&);
bool test_sort_genre(Playlist&);

void print_playlist(Playlist&);
void init_playlist(Playlist&);

int main()
{
    Playlist l;

    cout << "TESTING PLAYLIST CLASS FUNCTIONALITY\n\n";

    cout << "-----------------------------------------\n";
    cout << "TESTING add_song\n\n";
    init_playlist(l);
    if (test_add_song(l)) cout << "PASSED\n";
    else cout << "FAILED\n";

    cout << "-----------------------------------------\n";
    cout << "TESTING get_song\n\n";
    init_playlist(l);
    if (test_get_song(l)) cout << "PASSED\n";
    else cout << "FAILED\n";

    cout << "-----------------------------------------\n";
    cout << "TESTING edit_song_title\n\n";
    init_playlist(l);
    if (test_edit_song_title(l)) cout << "PASSED\n";
    else cout << "FAILED\n";

    cout << "-----------------------------------------\n";
    cout << "TESTING edit_song_artist\n\n";
    init_playlist(l);
    if (test_edit_song_artist(l)) cout << "PASSED\n";
    else cout << "FAILED\n";

    cout << "-----------------------------------------\n";
    cout << "TESTING edit_song_album\n\n";
    init_playlist(l);
    if (test_edit_song_album(l)) cout << "PASSED\n";
    else cout << "FAILED\n";

    cout << "-----------------------------------------\n";
    cout << "TESTING edit_song_duration\n\n";
    init_playlist(l);
    if (test_edit_song_genre(l)) cout << "PASSED\n";
    else cout << "FAILED\n";

    cout << "-----------------------------------------\n";
    cout << "TESTING edit_song_genre\n\n";
    init_playlist(l);
    if (test_edit_song_genre(l)) cout << "PASSED\n";
    else cout << "FAILED\n";

    cout << "-----------------------------------------\n";
    cout << "TESTING delete_song\n\n";
    init_playlist(l);
    if (test_delete_song(l)) cout << "PASSED\n";
    else cout << "FAILED\n";

    cout << "-----------------------------------------\n";
    cout << "TESTING size\n\n";
    init_playlist(l);
    if (test_size(l)) cout << "PASSED\n";
    else cout << "FAILED\n";

    cout << "-----------------------------------------\n";
    cout << "TESTING move_song\n\n";
    init_playlist(l);
    if (test_move_song(l)) cout << "PASSED\n";
    else cout << "FAILED\n";

    cout << "-----------------------------------------\n";
    cout << "TESTING sort_title\n\n";
    init_playlist(l);
    if (test_sort_title(l)) cout << "PASSED\n";
    else cout << "FAILED\n";

    cout << "-----------------------------------------\n";
    cout << "TESTING sort_artist\n\n";
    init_playlist(l);
    if (test_sort_artist(l)) cout << "PASSED\n";
    else cout << "FAILED\n";

    cout << "-----------------------------------------\n";
    cout << "TESTING sort_album\n\n";
    init_playlist(l);
    if (test_sort_album(l)) cout << "PASSED\n";
    else cout << "FAILED\n";

    cout << "-----------------------------------------\n";
    cout << "TESTING sort_duration\n\n";
    init_playlist(l);
    if (test_sort_duration(l)) cout << "PASSED\n";
    else cout << "FAILED\n";

    cout << "-----------------------------------------\n";
    cout << "TESTING sort_genre\n\n";
    init_playlist(l);
    if (test_sort_genre(l)) cout << "PASSED\n";
    else cout << "FAILED\n";

    cout << "-----------------------------------------\n";
    return 0;
}

bool test_add_song(Playlist& l)
{
    l.add_song("Test song", "Foo", "Bar", "100", "Baz");
    DArray<std::string> song = l.get_song(8);
    if (song[0] != "Test song") return false;
    if (song[1] != "Foo") return false;
    if (song[2] != "Bar") return false;
    if (song[3] != "100") return false;
    if (song[4] != "Baz") return false;
    return true;
}

bool test_get_song(Playlist& l)
{
    DArray<std::string> song = l.get_song(2);
    if (song[0] != "Famous Blue Raincoat") return false;
    if (song[1] != "Leonard Cohen") return false;
    if (song[2] != "Songs Of Love And Hate") return false;
    if (song[3] != "310") return false;
    if (song[4] != "Blues") return false;
    return true;
}

bool test_edit_song_title(Playlist& l)
{
    l.edit_song_title(1, "TEST TITLE");
    DArray<std::string> song = l.get_song(1);
    if (song[0] != "TEST TITLE") return false;
    return true;
}

bool test_edit_song_artist(Playlist& l)
{
    l.edit_song_artist(4, "TEST ARTIST");
    DArray<std::string> song = l.get_song(4);
    if (song[1] != "TEST ARTIST") return false;
    return true;
}

bool test_edit_song_album(Playlist& l)
{
    l.edit_song_album(2, "TEST ALBUM");
    DArray<std::string> song = l.get_song(2);
    if (song[2] != "TEST ALBUM") return false;
    return true;
}

bool test_edit_song_duration(Playlist& l)
{
    l.edit_song_duration(6, "TEST DURATION");
    DArray<std::string> song = l.get_song(6);
    if (song[3] != "TEST DURATION") return false;
    return true;
}

bool test_edit_song_genre(Playlist& l)
{
    l.edit_song_genre(1, "TEST GENRE");
    DArray<std::string> song = l.get_song(1);
    if (song[4] != "TEST GENRE") return false;
    return true;
}

bool test_delete_song(Playlist& l)
{
    DArray<std::string> old_song = l.get_song(3);
    if (old_song[0] != "American Pie") return false;
    if (old_song[1] != "Don McLean") return false;
    if (old_song[2] != "American Pie") return false;
    if (old_song[3] != "516") return false;
    if (old_song[4] != "Rock") return false;
    l.delete_song(3);
    DArray<std::string> song = l.get_song(3);
    if (song[0] == "American Pie") return false;
    if (song[1] == "Don McLean") return false;
    if (song[2] == "American Pie") return false;
    if (song[3] == "516") return false;
    if (song[4] == "Rock") return false;
    return true;
}

bool test_size(Playlist& l)
{
    if (l.size() != 7) return false;
    l.add_song("a", "b", "c", "d", "e");
    if (l.size() != 8) return false;
    l.delete_song(1);
    if (l.size() != 7) return false;
    return true;
}

bool test_move_song(Playlist& l)
{
    l.move_song(2, 6);

    DArray<std::string> moved_song = l.get_song(6);
    if (moved_song[0] != "Famous Blue Raincoat") return false;
    if (moved_song[1] != "Leonard Cohen") return false;
    if (moved_song[2] != "Songs Of Love And Hate") return false;
    if (moved_song[3] != "310") return false;
    if (moved_song[4] != "Blues") return false;

    DArray<std::string> replaced = l.get_song(2);
    if (replaced[0] != "Knockin' On Heaven's Door") return false;
    if (replaced[1] != "Bob Dylan") return false;
    if (replaced[2] != "Pat Garrett & Billy The Kid") return false;
    if (replaced[3] != "149") return false;
    if (replaced[4] != "Rock") return false;
    return true;
}

bool test_sort_title(Playlist& l)
{
    return true;
}

bool test_sort_artist(Playlist& l)
{
    return true;
}

bool test_sort_album(Playlist& l)
{
    return true;
}

bool test_sort_duration(Playlist& l)
{
    return true;
}

bool test_sort_genre(Playlist& l)
{
    return true;
}

void print_playlist(Playlist& l)
{
    std::size_t counter = 1;
    for (auto& song : l)
    {
        cout << "Song " << counter
            << "\nTitle: " << song[0]
            << "\nArtist: " << song[1]
            << "\nAlbum: " << song[2]
            << "\nDuration: " << song[3]
            << "\nGenre: " << song[4] << "\n\n";
        ++counter;
    }
    cout << '\n';
}

void init_playlist(Playlist& l)
{
    // Set Playlist l to a set of values to prepare for testing
    l.clear();
    l.add_song("Heroes", "David Bowie", "Single", "371", "Rock");
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