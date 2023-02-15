
#include <Windows.h>
#include <iostream>

#include "Trees.h"

using namespace std;

// List of offenses
const char Offenses[10][120] = { "Over speed", "Parking in a prohibited place", "Drunk driving",
                        "Departure to the side of the road for oncoming traffic",
                        "Handing over a vehicle to a drunk driver", "Violation of the rules for crossing the railway",
                        "Hiding from the scene of an accident", "Lack of health insurance",
                         "Expired driver's license", "Leaving the vehicle at the scene of an accident"};
// List of Cars' numbers
const char Car_numbers[20][9] = {"W012AA77","D015BA78","S017TE77","T015WA18","J115HT75","F021NA78","H885TR77","T042PX78","L987562",
                                "X212TF78","D014BT87","Z005SD78","A555UT77","S154QU73","C075TH29","G734GH48","K014BA78","I043KL48","G666GG66" };

Trees BaseGia;

int main()
{
    srand(time(NULL));
    Car* temp;

    for (int i = 0; i < 20; i++) {
        temp = new Car;
        strcpy_s(temp->Number, Car_numbers[i]);
        for (int i = 0; i < rand() % 7 + 2; i++) {
            temp->count_offenses++;
            strcpy_s(temp->offenses[i].offense, Offenses[rand() % 7 + 2]);
        }
        cout << temp->Number << endl;
        BaseGia.insert(temp);
    }
    
    BaseGia.print_all(NULL);









}

