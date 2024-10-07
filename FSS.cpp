#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Flight {
    string flightNumber;
    string departureTime;
    string arrivalTime;
    string destination;
};

void addFlight(vector<Flight>& schedule) {
    Flight flight;
    cout << "Enter Flight Number: ";
    cin >> flight.flightNumber;
    cout << "Enter Departure Time: ";
    cin >> flight.departureTime;
    cout << "Enter Arrival Time: ";
    cin >> flight.arrivalTime;
    cout << "Enter Destination: ";
    cin >> flight.destination;
    schedule.push_back(flight);
}

void viewFlights(const vector<Flight>& schedule) {
    cout << "\nScheduled Flights:\n";
    for (const auto& flight : schedule) {
        cout << "Flight Number: " << flight.flightNumber 
             << ", Departure: " << flight.departureTime 
             << ", Arrival: " << flight.arrivalTime 
             << ", Destination: " << flight.destination << "\n";
    }
}

void removeFlight(vector<Flight>& schedule) {
    string flightNumber;
    cout << "Enter Flight Number to Remove: ";
    cin >> flightNumber;
    for (auto it = schedule.begin(); it != schedule.end(); ++it) {
        if (it->flightNumber == flightNumber) {
            schedule.erase(it);
            cout << "Flight removed.\n";
            return;
        }
    }
    cout << "Flight not found.\n";
}

int main() {
    vector<Flight> schedule;
    int choice;
    while (true) {
        cout << "\nFlight Scheduling System\n";
        cout << "1. Add Flight\n2. View Flights\n3. Remove Flight\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addFlight(schedule); break;
            case 2: viewFlights(schedule); break;
            case 3: removeFlight(schedule); break;
            case 4: return 0;
            default: cout << "Invalid choice. Try again.\n";
        }
    }
}
