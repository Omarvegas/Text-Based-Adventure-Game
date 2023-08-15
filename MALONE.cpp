#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cstdlib> // For random number generation
#include <ctime>   // For seeding random number generator

using namespace std;

// Define classes for different game elements

class Item {
public:
    string name;
    string description;

    Item(string n, string d) : name(n), description(d) {}
};

class Location {
public:
    string name;
    string description;
    vector<Item> items;

    Location(string n, string d) : name(n), description(d) {}
};

class NPC {
public:
    string name;
    string dialogue;

    NPC(string n, string d) : name(n), dialogue(d) {}
};

class Player {
public:
    string name;
    vector<Item> inventory;

    Player(string n) : name(n) {}
};

// Function to display available locations
void displayLocations(const vector<Location>& locations) {
    cout << "Available Locations:\n";
    for (size_t i = 0; i < locations.size(); ++i) {
        cout << i + 1 << ". " << locations[i].name << "\n";
    }
}

// Function to handle location interactions
void enterLocation(Player& player, Location& location) {
    cout << "You have entered " << location.name << ". " << location.description << "\n";
    // TODO: Implement interactions within the location
}

int main() {
    // Seed the random number generator
    srand(static_cast<unsigned int>(time(0)));

    // Create player
    string playerName;
    cout << "Enter your character's name: ";
    cin >> playerName;
    Player player(playerName);

    // Create locations
    vector<Location> locations;
    locations.push_back(Location("Forest", "A dense forest with tall trees.\n"));
    locations.push_back(Location("Cave", "A dark cave with mysterious echoes.\n"));

    // Set up initial game loop
    bool gameRunning = true;
    while (gameRunning) {
        displayLocations(locations);

        int choice;
        cout << "Enter the number of the location you want to enter (0 to quit): \n";
        cin >> choice;

        if (choice == 0) {
            gameRunning = false;
            break;
        } else if (choice >= 1 && choice <= locations.size()) {
            enterLocation(player, locations[choice - 1]);
        } else {
            cout << "Invalid choice. Please try again.\n";
        }
    }

    cout << "Thank you for playing!\n";
    return 0;
}
