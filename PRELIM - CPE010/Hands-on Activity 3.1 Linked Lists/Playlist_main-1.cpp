#include <iostream>
#include <string>
#include "Playlist_ll.h"

int main() {
    Playlist<std::string>* header = CreateNewPlaylist(std::string("Tame Impala - The Less I know the better"));
    Playlist<std::string>* second = CreateNewPlaylist(std::string("Neon Trees - Animal"));
    Playlist<std::string>* third = CreateNewPlaylist(std::string("Post Malone - Sunflower"));
    Playlist<std::string>* fourth = CreateNewPlaylist(std::string("The Itchyworms - Beer"));
    Playlist<std::string>* fifth = CreateNewPlaylist(std::string("Cage The Elephant - Social Cues"));

    header->next = second;
    second->prev = header;

    second->next = third;
    third->prev = second;

    third->next = fourth;
    fourth->prev = third;

    fourth->next = fifth;
    fifth->prev = fourth;
    
    //For the loop to function
    fifth->next = header;
    header->prev = fifth;

    //Traversal
    std::cout << "Playlist Traversal: " <<std::endl;
    PlaylistTraversal(header);

    //Insert End
    std::cout << "Inserting Song: " << std::endl;
    PlaylistInsertEnd(std::string("Arctic Monkeys - 505"), header);
    PlaylistTraversal(header);

    //Next Song
    std::cout << "Next Song: " << std::endl;
    header = PlayNextSong(header);
    std::cout << "Now Playing: " << header->data << std::endl;

    //Previous Song
    std::cout << "Previous Song: " << std::endl;
    header = PlayPreviousSong(header);
    std::cout<< "Now Playing: " << header->data << std::endl;

    //Delete Song
    std::cout << "Deleting Song: " << std::endl;
    PlaylistDeleteSong(std::string("Post Malone - Sunflower"), &header);
    PlaylistTraversal(header);

    return 0;
}