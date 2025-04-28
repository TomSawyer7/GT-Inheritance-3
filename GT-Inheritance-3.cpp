#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Beverage {
private:
    string name;
    int volume;
    bool isChilled;

public:
    Beverage(string name, int volume, bool isChilled): name(name), volume(volume), isChilled(isChilled){}

    string getName() const {
        return name;
    }

    int getVolume() const {
        return volume;
    }

    bool getIsChilled() const {
        return isChilled;
    }

    bool isEmpty() const {
        return volume == 0;
    }

    string toString() {
        return name + " (" + to_string(volume) + "mL) is " + (isChilled ? "still chilled" : "not chilled anymore");
    }
};

class Water : public Beverage {
private:
    string type;

public:
    Water(int volume, bool isChilled, string type): Beverage("Water", volume, isChilled), type(type){}

    Water(int volume, bool isChilled): Beverage("Water", volume, isChilled), type("Regular"){}

    string getType() const {
        return type;
    }

    string toString() {
        return "Water (" + to_string(getVolume()) + "mL) is " + (getIsChilled() ? "still chilled" : "not chilled anymore") + " (" + type + ")";
    }
};

class Beer : public Beverage {
private:
    double alcoholicContent;

public:
    Beer(int volume, bool isChilled, double alcoholicContent): Beverage("Beer", volume, isChilled), alcoholicContent(alcoholicContent){}

    double getAlcoholicContent() const {
        return alcoholicContent;
    }

    string getType() const {
        if (alcoholicContent < 0.03) return "Flavored";
        if (alcoholicContent < 0.06) return "Regular";
        return "Strong";
    }

    string toString() {
        string chilledStatus = getIsChilled() ? "still chilled" : "not chilled anymore";
        return "Beer (" + to_string(getVolume()) + "mL) is " + chilledStatus +
               " (" + to_string(alcoholicContent * 100) + "% alcoholic content) | " + getType();
    }
};

int main() {
    int waterVolume;
    string waterType;
    string isChilledInput;
    bool isWaterChilled;

    cout << "Enter water volume (mL): ";
    cin >> waterVolume;

    cout << "Is the water chilled? (yes/no): ";
    cin >> isChilledInput;
    isWaterChilled = (isChilledInput == "yes");

    cout << "Do you want to specify water type? (yes/no): ";
    cin >> isChilledInput;

    Water water(waterVolume, isWaterChilled);
    if (isChilledInput == "yes") {
        cout << "Enter water type (Purified, Regular, Distilled): ";
        cin >> waterType;
        water = Water(waterVolume, isWaterChilled, waterType);
    }

    cout << "Water Details:" << endl;
    cout << water.toString() << endl;

    int beerVolume;
    double alcoholicContent;
    string isBeerChilledInput;
    bool isBeerChilled;

    cout << "Enter beer volume (mL): ";
    cin >> beerVolume;

    cout << "Is the beer chilled? (yes/no): ";
    cin >> isBeerChilledInput;
    isBeerChilled = (isBeerChilledInput == "yes");

    cout << "Enter alcohol content (e.g., 0.045 for 4.5%): ";
    cin >> alcoholicContent;

    Beer beer(beerVolume, isBeerChilled, alcoholicContent);

    cout << "Beer Details:" << endl;
    cout << beer.toString() << endl;

    return 0;
} 