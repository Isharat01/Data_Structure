#include <iostream>
#include <string>
#include <cstring>
using namespace std;

struct Song {
    string title;
    string artist;
    Song* next; 

    Song(const string& title, const string& artist)
        : title(title), artist(artist), next(nullptr) {}
};

class Playlist {
private:
    Song* head; 

public:
    Playlist() : head(nullptr) {}

    void addSong(const string& title, const string& artist) {
        Song* newSong = new Song(title, artist);
        if (!head) {
            head = newSong; 
        } else {
            Song* temp = head;
            while (temp->next) { 
                temp = temp->next;
            }
            temp->next = newSong; 
        }
        cout << "Added: " << title << " by " << artist << endl;
    }

    void display() const {
        if (!head) {
            cout << "Playlist is empty." << endl;
            return;
        }
        Song* temp = head;
        while (temp) {
            cout << temp->title << " by " << temp->artist << endl;
            temp = temp->next;
        }
    }

   
    void removeSong(const string& title) {
        if (!head) {
            cout << "Playlist is empty." << endl;
            return;
        }

        if (head->title == title) {
            Song* temp = head;
            head = head->next;
            delete temp;
            cout << "Removed: " << title << endl;
            return;
        }

        Song* current = head;
        Song* previous = nullptr;
        while (current && current->title != title) {
            previous = current;
            current = current->next;
        }

        if (current) {
            previous->next = current->next; 
            delete current;
            cout << "Removed: " << title << endl;
        } else {
            cout << "Song not found: " << title << endl;
        }
    }

    ~Playlist() {
        while (head) {
            Song* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    Playlist playlist;
    int choice;
    string title, artist;

    do {
        cout << "\nPlaylist Management System\n";
        cout << "1. Add Song\n";
        cout << "2. Display Playlist\n";
        cout << "3. Remove Song\n";
        cout << "4. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter song title: ";
                cin.ignore(); 
                getline(cin, title);
                cout << "Enter artist: ";
                getline(cin, artist);
                playlist.addSong(title, artist);
                break;
            case 2:
                playlist.display();
                break;
            case 3:
                cout << "Enter song title to remove: ";
                cin.ignore();
                getline(cin, title);
                playlist.removeSong(title);
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
