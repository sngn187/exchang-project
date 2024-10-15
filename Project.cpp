#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;
//================================================================================================
class Unitconverter
{
private:
public:
    string Length, Area, Temperature, Weight, Speed, Volume, Money;
    double value;
    string fromUnit, toUnit, result;
//================================================================================================
// Function to Length
    void Length1() 
    {
        cout << "Enter the length value: ";
        cin >> value;
        cout << "Enter the 'from' unit (km, hm, dam, m, dm, cm, mm): ";
        cin >> fromUnit;
        cout << "Enter the 'to' unit (km, hm, dam, m, dm, cm, mm): ";
        cin >> toUnit;

        double convertedValue = convertLength(value, fromUnit, toUnit);
        cout << fixed << setprecision(6);
        cout << value << " " << fromUnit << " is " << convertedValue << " " << toUnit << endl;

        // Write the result to the file
        string result = to_string(value) + " " + fromUnit + " is " + to_string(convertedValue) + " " + toUnit;
        WriteUnitconverterToFile(result);
    }

    // Function to convert length between different units
    double convertLength(double value, const string& fromUnit, const string& toUnit) 
    {
        // Conversion factors to meters
        double toMeters = 0.0;
        double fromMeters = 0.0;

        // Conversion factor map
        if (fromUnit == "km") fromMeters = 1000.0;
        else if (fromUnit == "hm") fromMeters = 100.0;
        else if (fromUnit == "dam") fromMeters = 10.0;
        else if (fromUnit == "m") fromMeters = 1.0;
        else if (fromUnit == "dm") fromMeters = 0.1;
        else if (fromUnit == "cm") fromMeters = 0.01;
        else if (fromUnit == "mm") fromMeters = 0.001;
        else 
        {
            cerr << "Unknown 'from' unit: " << fromUnit << endl;
            return 0.0;
        }

        if (toUnit == "km") toMeters = 1000.0;
        else if (toUnit == "hm") toMeters = 100.0;
        else if (toUnit == "dam") toMeters = 10.0;
        else if (toUnit == "m") toMeters = 1.0;
        else if (toUnit == "dm") toMeters = 0.1;
        else if (toUnit == "cm") toMeters = 0.01;
        else if (toUnit == "mm") toMeters = 0.001;
        else 
        {
            cerr << "Unknown 'to' unit: " << toUnit << endl;
            return 0.0;
        }

        // Convert value to meters and then to the target unit
        return value * (fromMeters / toMeters) ;
    }
//================================================================================================
// Function to Area
    void Area1() 
    {
        cout << "Enter the area value: ";
        cin >> value;
        cout << "Enter the 'from' unit (km^2, hm^2, dam^2, m^2, dm^2, cm^2, mm^2): ";
        cin >> fromUnit;
        cout << "Enter the 'to' unit (km^2, hm^2, dam^2, m^2, dm^2, cm^2, mm^2): ";
        cin >> toUnit;

        double convertedValue = convertArea(value, fromUnit, toUnit);
        cout << fixed << setprecision(6);
        cout << value << " " << fromUnit << " is " << convertedValue << " " << toUnit << endl;

        // Write the result to the file
        string result = to_string(value) + " " + fromUnit + " is " + to_string(convertedValue) + " " + toUnit;
        WriteUnitconverterToFile(result);
    }

    // Function to convert area between different units
    double convertArea(double value, const string& fromUnit, const string& toUnit) 
    {
        // Conversion factors to meters
        double toMeters = 0.0;
        double fromMeters = 0.0;

        // Conversion factor map
        if (fromUnit == "km^2") fromMeters = 1000000.0;
        else if (fromUnit == "hm^2") fromMeters = 10000.0;
        else if (fromUnit == "dam^2") fromMeters = 100.0;
        else if (fromUnit == "m^2") fromMeters = 1.0;
        else if (fromUnit == "dm^2") fromMeters = 0.01;
        else if (fromUnit == "cm^2") fromMeters = 0.0001;
        else if (fromUnit == "mm^2") fromMeters = 0.000001;
        else 
        {
            cerr << "Unknown 'from' unit: " << fromUnit << endl;
            return 0.0;
        }

        if (toUnit == "km^2") toMeters = 1000000.0;
        else if (toUnit == "hm^2") toMeters = 10000.0;
        else if (toUnit == "dam^2") toMeters = 100.0;
        else if (toUnit == "m^2") toMeters = 1.0;
        else if (toUnit == "dm^2") toMeters = 0.01;
        else if (toUnit == "cm^2") toMeters = 0.0001;
        else if (toUnit == "mm^2") toMeters = 0.000001;
        else 
        {
            cerr << "Unknown 'to' unit: " << toUnit << endl;
            return 0.0;
        }

        // Convert value to meters and then to the target unit
        return value * (fromMeters / toMeters);
    }
//================================================================================================
// Function to Temperature
    void Temperature1() 
    {
        int i = 0; 
        float fahrenheit, celsius;
        cout << "1. Convert Fahrenheit to Celsius" << endl;
        cout << "2. Convert Celsius to Fahrenheit" << endl;
        cout << "Enter the temperature value: ";
        cin >> i;
        switch (i)
        {
            case 1:
                cout << "Input the temperature in Fahrenheit: ";
                cin >> fahrenheit;
                // Convert Fahrenheit to Celsius using the formula (F - 32) * 5/9
                celsius = (fahrenheit - 32) * 5 / 9;
                cout << fahrenheit << " F " <<  " is " << celsius << "  *C" <<  endl;
                result = to_string(fahrenheit) + " F " + " is " + to_string(celsius) + "  *C";
                WriteUnitconverterToFile(result);
                break;
            case 2:
                cout << "Input the temperature in Celsius: ";
                cin >> celsius;
                // Convert Fahrenheit to Celsius using the formula (F - 32) * 5/9
                fahrenheit = (celsius * 9 / 5) +32;
                cout << celsius << " *C " <<  " is " << fahrenheit << "  F" <<  endl;
                result = to_string(celsius) + " *C " + " is " + to_string(celsius) + "  *C";
                WriteUnitconverterToFile(result);
                break;
            default:
                cout<< "Sorry try again" << endl;
                break;
        }
    }
//================================================================================================
// Function to Weigth
    void Weight1() 
    {
        cout << "Enter the wiegth value: ";
        cin >> value;
        cout << "Enter the 'from' unit (kg, hg, dag, g, dg, cg, mg): ";
        cin >> fromUnit;
        cout << "Enter the 'to' unit (kg, hg, dag, g, dg, cg, mg): ";
        cin >> toUnit;

        double convertedValue = convertWeight(value, fromUnit, toUnit);
        cout << fixed << setprecision(6);
        cout << value << " " << fromUnit << " is " << convertedValue << " " << toUnit << endl;

        string result = to_string(value) + " " + fromUnit + " is " + to_string(convertedValue) + " " + toUnit;
        WriteUnitconverterToFile(result);
    }

    // Function to convert weight between different units
    double convertWeight(double value, const string& fromUnit, const string& toUnit) 
    {
        // Conversion factors to meters
    double toMeters = 0.0;
    double fromMeters = 0.0;

    // Conversion factor map
    if (fromUnit == "kg") fromMeters = 1000.0;
    else if (fromUnit == "hg") fromMeters = 100.0;
    else if (fromUnit == "dag") fromMeters = 10.0;
    else if (fromUnit == "g") fromMeters = 1.0;
    else if (fromUnit == "dg") fromMeters = 0.1;
    else if (fromUnit == "cg") fromMeters = 0.01;
    else if (fromUnit == "mg") fromMeters = 0.001;
    else 
    {
        cerr << "Unknown 'from' unit: " << fromUnit << endl;
        return 0.0;
    }

    if (toUnit == "kg") toMeters = 1000.0;
    else if (toUnit == "hg") toMeters = 100.0;
    else if (toUnit == "dag") toMeters = 10.0;
    else if (toUnit == "g") toMeters = 1.0;
    else if (toUnit == "dg") toMeters = 0.1;
    else if (toUnit == "cg") toMeters = 0.01;
    else if (toUnit == "mg") toMeters = 0.001;
    else 
    {
        cerr << "Unknown 'to' unit: " << toUnit << endl;
        return 0.0;
    }

    // Convert value to meters and then to the target unit
    return value * (fromMeters / toMeters);
    }
//================================================================================================
// Function to Speed
    void Speed1()
    {
        cout << "Enter the Speed value: ";
        cin >> value;
        cout << "Enter the 'from' unit ( km/s, hm/s, dam/s, m/s, dm/s, cm/s, mm/s " << endl;
        cout << "                        km/mn, hm/mn, dam/mn, m/mn, dm/mn, cm/mn, mm/mn " << endl;
        cout << "                        km/h, hm/h, dam/h, m/h, dm/h, cm/h, mm/h ) :  ";
        cin >> fromUnit;
        cout << "Enter the 'to' unit ( km/s, hm/s, dam/s, m/s, dm/s, cm/s, mm/s " << endl;
        cout << "                      km/mn, hm/mn, dam/mn, m/mn, dm/mn, cm/mn, mm/mn " << endl;
        cout << "                      km/h, hm/h, dam/h, m/h, dm/h, cm/h, mm/h ) :  ";
        cin >> toUnit;

        double convertedValue = convertSpeed(value, fromUnit, toUnit);
        cout << fixed << setprecision(6);
        cout << value << " " << fromUnit << " is " << convertedValue << " " << toUnit << endl;
    }
    // Function to convert speed between different units
    double convertSpeed(double value, const string& fromUnit, const string& toUnit) 
    {
        // Conversion factors to meters
        double toMeters = 0.0;
        double fromMeters = 0.0;

        // Conversion factor map
        if (fromUnit == "km/s") fromMeters = 1000.0;
        else if (fromUnit == "hm/s") fromMeters = 100.0;
        else if (fromUnit == "dam/s") fromMeters = 10.0;
        else if (fromUnit == "m/s") fromMeters = 1.0;
        else if (fromUnit == "dm/s") fromMeters = 0.1;
        else if (fromUnit == "cm/s") fromMeters = 0.01;
        else if (fromUnit == "mm/s") fromMeters = 0.001;
        else if (fromUnit == "km/mn") fromMeters = (1000.0/60.0);
        else if (fromUnit == "hm/mn") fromMeters = (100.0/60.0);
        else if (fromUnit == "dam/mn") fromMeters = (10.0/60.0);
        else if (fromUnit == "m/mn") fromMeters = (1.0/60.0);
        else if (fromUnit == "dm/mn") fromMeters = (0.1/60.0);
        else if (fromUnit == "cm/mn") fromMeters = (0.01/60.0);
        else if (fromUnit == "mm/mn") fromMeters = (0.001/60.0);
        else if (fromUnit == "km/h") fromMeters = (1000.0/3600.0);
        else if (fromUnit == "hm/h") fromMeters = (100.0/3600.0);
        else if (fromUnit == "dam/h") fromMeters = (10.0/3600.0);
        else if (fromUnit == "m/h") fromMeters = (1.0/3600.0);
        else if (fromUnit == "dm/h") fromMeters = (0.1/3600.0);
        else if (fromUnit == "cm/h") fromMeters = (0.01/3600.0);
        else if (fromUnit == "mm/h") fromMeters = (0.001/3600.0);
        else 
        {
            cerr << "Unknown 'from' unit: " << fromUnit << endl;
            return 0.0;
        }

        if (toUnit == "km/s") toMeters = 1000.0;
        else if (toUnit == "hm/s") toMeters = 100.0;
        else if (toUnit == "dam/s") toMeters = 10.0;
        else if (toUnit == "m/s") toMeters = 1.0;
        else if (toUnit == "dm/s") toMeters = 0.1;
        else if (toUnit == "cm/s") toMeters = 0.01;
        else if (toUnit == "mm/s") toMeters = 0.001;
        else if (toUnit == "km/mn") toMeters = (1000.0/60.0);
        else if (toUnit == "hm/mn") toMeters = (100.0/60.0);
        else if (toUnit == "dam/mn") toMeters = (10.0/60.0);
        else if (toUnit == "m/mn") toMeters = (1.0/60.0);
        else if (toUnit == "dm/mn") toMeters = (0.1/60.0);
        else if (toUnit == "cm/mn") toMeters = (0.01/60.0);
        else if (toUnit == "mm/mn") toMeters = (0.001/60.0);
        else if (toUnit == "km/h") toMeters = (1000.0/3600.0);
        else if (toUnit == "hm/h") toMeters = (100.0/3600.0);
        else if (toUnit == "dam/h") toMeters = (10.0/3600.0);
        else if (toUnit == "m/h") toMeters = (1.0/3600.0);
        else if (toUnit == "dm/h") toMeters = (0.1/3600.0);
        else if (toUnit == "cm/h") toMeters = (0.01/3600.0);
        else if (toUnit == "mm/h") toMeters = (0.001/3600.0);
        else 
        {
            cerr << "Unknown 'to' unit: " << toUnit << endl;
            return 0.0;
        }

        // Convert value to meters and then to the target unit
        return value * (fromMeters / toMeters);
    }
   
//================================================================================================
// Function to Volume
    void Volume1() 
    {
        cout << "Enter the volume value: ";
        cin >> value;
        cout << "Enter the 'from' unit (km^3, hm^3, dam^3, m^3, dm^3, cm^3, mm^3, l): ";
        cin >> fromUnit;
        cout << "Enter the 'to' unit (km^3, hm^3, dam^3, m^3, dm^3, cm^3, mm^3, l): ";
        cin >> toUnit;

        double convertedValue = convertVolume(value, fromUnit, toUnit);
        cout << fixed << setprecision(10);
        cout << value << " " << fromUnit << " is " << convertedValue << " " << toUnit << endl;

        string result = to_string(value) + " " + fromUnit + " is " + to_string(convertedValue) + " " + toUnit;
        WriteUnitconverterToFile(result);
    }

    // Function to convert volume between different units
    double convertVolume(double value, const string& fromUnit, const string& toUnit) 
    {
        // Conversion factors to meters
        double toMeters = 0.0;
        double fromMeters = 0.0;

        // Conversion factor map
        if (fromUnit == "km^3") fromMeters = 1000000000.0;
        else if (fromUnit == "hm^3") fromMeters = 1000000.0;
        else if (fromUnit == "dam^3") fromMeters = 1000.0;
        else if (fromUnit == "m^3") fromMeters = 1.0;
        else if (fromUnit == "dm^3") fromMeters = 0.001;
        else if (fromUnit == "l") fromMeters = 0.001;
        else if (fromUnit == "cm^3") fromMeters = 0.000001;
        else if (fromUnit == "mm^3") fromMeters = 0.000000001;
        else 
        {
            cerr << "Unknown 'from' unit: " << fromUnit << endl;
            return 0.0;
        }

        if (toUnit == "km^3") toMeters = 1000000000.0;
        else if (toUnit == "hm^3") toMeters = 1000000.0;
        else if (toUnit == "dam^3") toMeters = 1000.0;
        else if (toUnit == "m^3") toMeters = 1.0;
        else if (toUnit == "dm^3") toMeters = 0.001;
        else if (toUnit == "l") toMeters = 0.001;
        else if (toUnit == "cm^3") toMeters = 0.000001;
        else if (toUnit == "mm^3") toMeters = 0.000000001;
        else 
        {
            cerr << "Unknown 'to' unit: " << toUnit << endl;
            return 0.0;
        }

        // Convert value to meters and then to the target unit
        return value * (fromMeters / toMeters);
    }
//================================================================================================
// Function to Money
    void Money1() 
    {
        float usdToKHRRate = 4100.0; // Example exchange rate: 1 USD = 4100 KHR
        float amount;
        int choice;

        cout << "Currency Converter" << endl;
        cout << "1. Convert USD to KHR" << endl;
        cout << "2. Convert KHR to USD" << endl;
        cout << "Enter your choice (1 or 2): ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter amount in USD: ";
            cin >> amount;
            cout << fixed << setprecision(4);
            cout << amount << " USD is " << usdToKHR(amount, usdToKHRRate) << " KHR." << endl;
            result = to_string(amount) + " USD is " + to_string(usdToKHR(amount, usdToKHRRate)) + " KHR.";
            WriteUnitconverterToFile(result);
            break;
        case 2:
            cout << "Enter amount in KHR: ";
            cin >> amount;
            cout << fixed << setprecision(4);
            cout << amount << " KHR is " << khrToUSD(amount, usdToKHRRate) << " USD." << endl;
            result = to_string(amount) + " KHR is " + to_string(khrToUSD(amount, usdToKHRRate)) + " USD.";
            WriteUnitconverterToFile(result);
            break;
        default:
            cout << "Invalid choice. Please select 1 or 2." << endl;
            break;
        }
    }

    double usdToKHR(double usd, double exchangeRate)
    {
        return usd * exchangeRate;
    }

    double khrToUSD(double khr, double exchangeRate)
    {
        return khr / exchangeRate;
    }
//================================================================================================
// Function to close the application
    void CloseApp() 
    {
        cout << "Program is shutting down." << endl;
    }
//===============================================================================================
    void Input() 
    {
        int Choice = 0;
    // Program Executes
        while (Choice != -1) 
        {
        // Show Data on Monitor
            cout << "============================   Welcome user >_<     ===========================" << endl;
            cout << "=============================   1. Length           ===========================" << endl;
            cout << "=============================   2. Area             ===========================" << endl;
            cout << "=============================   3. Temperature      ===========================" << endl;
            cout << "=============================   4. Weight           ===========================" << endl;
            cout << "=============================   5. Speed            ===========================" << endl;
            cout << "=============================   6. Volume           ===========================" << endl;
            cout << "=============================   7. Money            ===========================" << endl;
            cout << "=============================   8. Watch History    ===========================" << endl;
            cout << "=============================   9. Clear History    ===========================" << endl;
            cout << "============================   -1. Exit             ===========================" << endl;
            cout << "Enter your choice: ";
            cin >> Choice;
            switch (Choice) 
            {
                case 1:
                    Length1();
                    break;
                case 2:
                    Area1();
                    break;
                case 3:
                    Temperature1();
                    break;
                case 4:
                    Weight1();
                    break;
                case 5:
                    Speed1();
                    break;
                case 6:
                    Volume1();
                    break;
                case 7:
                    Money1();
                    break;
                case 8:
                    ReadUnitconverterFromFile();
                    break;
                case 9:
                    ClearFile();
                    break;
                case -1:
                    CloseApp();
                    break;
                default:
                    cout  << "Invalid choice, please try again.  >_< " << endl;

                    break;
            }
        } // Exit While
    }
//==============================================================================================================
    // Function to write conversion results to a file
    void WriteUnitconverterToFile(const string& result) 
    {
        ofstream outFile("project.txt", ios::app);
        if (outFile.is_open()) 
        {
            outFile << result << endl;
            outFile.close();
        } 
        else 
        {
            cerr << "Unable to open file for writing." << endl;
        }
    }
//====================================================================================================
    // Function to read conversion results from a file
    void ReadUnitconverterFromFile() 
    {
        ifstream inFile("project.txt");
        string line;

        if (inFile.is_open()) 
        {
            cout << "Previous Conversion Results:" << endl;
            while (getline(inFile, line)) 
            {
                cout << line << endl;
            }
            inFile.close();
        } 
        else 
        {
            cerr << "Unable to open file for reading." << endl;
        }
    }
//================================================================================================
    void ClearFile() 
    {
        ofstream file("project.txt", ios::out | ios::trunc);
        if (file.is_open()) 
        {
            // The file is now empty
            file.close();
            cout << "File  cleared successfully!" << endl;
        } 
        else 
        {
            cerr << "Unable to open the file: " << endl;
        }
    }
};
//================================================================================================
int main() 
{
    Unitconverter converter;
    converter.Input();
    return 0;
}