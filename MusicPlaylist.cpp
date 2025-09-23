#include <iostream>
#include <string>
using namespace std;


struct Node {
    string songName;
    Node* prev;
    Node* next;

    Node(string name) {
        songName = name;
        prev = next = nullptr;
    }
};

class MusicPlaylist {
private:
    Node* head;
    Node* tail;

public:
    MusicPlaylist() {
        head = tail = nullptr;
    }

    
    void addSongAtBeginning(string song) {
        Node* newNode = new Node(song);
        if (!head) { 
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        cout << "Song \"" << song << "\" added at the beginning.\n";
    }

    
    void addSongAtEnd(string song) {
        Node* newNode = new Node(song);
        if (!tail) { 
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        cout << "Song \"" << song << "\" added at the end.\n";
    }

   
    void deleteSong(string song) {
        if (!head) {
            cout << "Playlist is empty.\n";
            return;
        }

        Node* temp = head;
        while (temp && temp->songName != song) {
            temp = temp->next;
        }

        if (!temp) {
            cout << "Song \"" << song << "\" not found in playlist.\n";
            return;
        }

        if (temp == head && temp == tail) { 
            head = tail = nullptr;
        } 
        else if (temp == head) { 
            head = head->next;
            head->prev = nullptr;
        } 
        else if (temp == tail) {
            tail = tail->prev;
            tail->next = nullptr;
        } 
        else { 
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
        }

        delete temp;
        cout << "Song \"" << song << "\" deleted.\n";
    }

    
    void displayPlaylist() {
        if (!head) {
            cout << "Playlist is empty.\n";
            return;
        }

        cout << "\n Current Playlist:\n";
        Node* temp = head;
        while (temp) {
            cout << " - " << temp->songName << "\n";
            temp = temp->next;
        }
    }
};


int main() {
    MusicPlaylist playlist;
    int choice;
    string song;

    do {
        cout << "\n--- Music Playlist Menu ---\n";
        cout << "1. Add Song at Beginning\n";
        cout << "2. Add Song at End\n";
        cout << "3. Delete Song\n";
        cout << "4. Display Playlist\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); 

        switch (choice) {
            case 1:
                cout << "Enter song name: ";
                getline(cin, song);
                playlist.addSongAtBeginning(song);
                break;
            case 2:
                cout << "Enter song name: ";
                getline(cin, song);
                playlist.addSongAtEnd(song);
                break;
            case 3:
                cout << "Enter song name to delete: ";
                getline(cin, song);
                playlist.deleteSong(song);
                break;
            case 4:
                playlist.displayPlaylist();
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 5);

    return 0;
}