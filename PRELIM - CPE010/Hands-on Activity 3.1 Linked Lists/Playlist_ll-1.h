#ifndef PLAYLIST_LL_H
#define PLAYLIST_LL_H

#include <iostream>
#include <string>

template <typename P>
class Playlist {
    public:
    P data;

    Playlist<P>* prev = nullptr;
    Playlist<P>* next = nullptr;

};

// Node Creation
template <typename P>
Playlist<P>* CreateNewPlaylist(P newSong) {

    Playlist<P> *CreateNewPlaylist = new Playlist<P>;

    CreateNewPlaylist->data = newSong;
    CreateNewPlaylist->next = nullptr;
    CreateNewPlaylist->prev = nullptr;

    return CreateNewPlaylist;
}

// List Traversal
template <typename P>
void PlaylistTraversal(Playlist<P>* head) {
    if(head == nullptr) {
        std::cout << "The Playlist is currently empty." << std::endl;
        return;
    }
    std::cout << "Current Playlist: " << std::endl;

    Playlist<P>* currentSong = head;
    int SongPlaying = 1;

    do
    {
    std::cout << "Now Playing: | " << SongPlaying << " | " << currentSong->data << std::endl;
    currentSong = currentSong->next;
    ++SongPlaying;

    } while (currentSong != head);
    std::cout << "Playlist has finished. Looping back to the start." << std::endl;
    std::cout << "[1]" << " " << head->data << std::endl;
}


//Insert End
template <typename P>
void PlaylistInsertEnd(P newSong, Playlist<P>* currentHead) {
    Playlist<P>* newNode = CreateNewPlaylist(newSong);
    Playlist<P>* Last = currentHead->prev;

    newNode->next = currentHead;
    newNode->prev = Last;

    Last->next = newNode;
    currentHead->prev = newNode;
    
}


// Play Next Song
template <typename P>
    Playlist<P>* PlayNextSong(Playlist<P>* currentSong) {
        if (currentSong == nullptr) {
            std::cout << "The Playlist is currently Empty. Please try again." << std::endl;
            return nullptr;
        }
        return currentSong->next;
    }

//Play Previous Song
template <typename P>
    Playlist<P>* PlayPreviousSong(Playlist<P>* currentSong) {
    if (currentSong == nullptr) {
            std::cout << "The Playlist is currently Empty. Please try again." << std::endl;
            return nullptr;
        }
        return currentSong->prev;
    }

//Delete Song
template <typename P>
void PlaylistDeleteSong(P findSong, Playlist<P>** currentSong) {
    if (*currentSong == nullptr) {
        std::cout << "The Playlist is currently Empty. Redirecting to next song" << std::endl;
        return;
    }

    Playlist<P>* newPlaying = *currentSong;

    while(newPlaying != nullptr && newPlaying->data !=findSong) {
        newPlaying = newPlaying->next;
    }

    if(newPlaying == nullptr) {
        std::cout << "Song was not found." << std::endl;

        return;
    }

    std::cout << newPlaying->data << std::endl;

    if(newPlaying->prev != nullptr) {
        newPlaying->prev->next = newPlaying->next;
    }
    else {
        *currentSong = newPlaying->next;
    }

    if(newPlaying->next !=nullptr) {
        newPlaying->next->prev = newPlaying->prev;
    }

    delete newPlaying;
}

#endif