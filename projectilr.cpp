
#include <iostream>
#include <cmath>
using namespace std;

class Projectile
{
private:
    float theta, u;
    float g = 9.8;

public:
    // Input function
    void getData()
    {
        cout << "Enter the value of theta and initial velocity: ";
        cin >> theta >> u;
    }

    // Calculate maximum height
    float maxHeight()
    {
        float rad = theta * (3.14159 / 180.0);
        return (u * u * sin(rad) * sin(rad)) / (2 * g);
    }

    // Calculate horizontal range
    float horizontalRange()
    {
        float rad = theta * (3.14159 / 180.0);
        return (u * u * sin(2 * rad)) / g;
    }

    // Calculate time of flight
    float timeOfFlight()
    {
        float rad = theta * (3.14159 / 180.0);
        return (2 * u * sin(rad)) / g;
    }

    // Display results
    void display()
    {
        cout << "Maximum height: " << maxHeight() << endl;
        cout << "Horizontal range: " << horizontalRange() << endl;
        cout << "Time of flight: " << timeOfFlight() << endl;
    }
};

int main()
{
    Projectile p;

    p.getData();
    p.display();

    return 0;
}

