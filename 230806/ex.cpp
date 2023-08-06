#include <iostream>
#include <string>

using namespace std;

class ElectronicsMaker
{
protected:
    string name;
    int yearFounded;
    string country;

public:
    ElectronicsMaker(const string &name = "none", int yearFounded = 0, const string &country = "none")
        : name(name), yearFounded(yearFounded), country(country)
    {
    }

    void getName() const { cout << "Name: " << name << endl; }
    void getYearFounded() const { cout << "Year Founded: " << yearFounded << endl; }
    void getCountry() const { cout << "Country: " << country << endl; }

    virtual void showProductFeatures() const = 0; // 파생 클래스에서 오버라이딩 필요한 함수
};

class Samsung : public ElectronicsMaker
{
private:
    string model;
    int numFeatures;

public:
    Samsung(const string &name = "Samsung", int yearFounded = 1938, const string &country = "South Korea", const string &model = "smartphone", int numFeatures = 5)
        : ElectronicsMaker(name, yearFounded, country), model(model), numFeatures(numFeatures)
    {
    }

    void showProductFeatures() const
    {
        cout << "Model: " << model << endl;
        cout << "Number of Features: " << numFeatures << endl;
        cout << "Product Features: 1. High quality display 2. Multi-language support 3. Long battery life 4. Various OS support 5. Affordable price" << endl;
    }
};

class Apple : public ElectronicsMaker
{
private:
    string model;
    int numFeatures;

public:
    Apple(const string &name = "Apple", int yearFounded = 1976, const string &country = "United States", const string &model = "iPhone", int numFeatures = 5)
        : ElectronicsMaker(name, yearFounded, country), model(model), numFeatures(numFeatures)
    {
    }

    void showProductFeatures() const
    {
        cout << "Model: " << model << endl;
        cout << "Number of Features: " << numFeatures << endl;
        cout << "Product Features: 1. High quality display 2. Sturdy design 3. User-friendly interface 4. Seamless integration with Apple ecosystem 5. High price" << endl;
    }
};

int main()
{
    Samsung samsung("Samsung", 1938, "South Korea", "Galaxy S21", 5);
    Apple apple("Apple", 1976, "United States", "iPhone 13", 5);

    samsung.getName();
    samsung.getYearFounded();
    samsung.getCountry();
    samsung.showProductFeatures();

    cout << endl;

    apple.getName();
    apple.getYearFounded();
    apple.getCountry();
    apple.showProductFeatures();

    return 0;
}
