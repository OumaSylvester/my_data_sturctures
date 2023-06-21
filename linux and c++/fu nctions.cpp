#include <iostream>
using namespace std;

const double Pi = 3.14159265;

// Function Declarations (prototypes)
double Area(double radius);
double Circumference(double radius);
double SurfaceArea(double radius, double height);

int main()
{
    cout <<"Enter radius: ";
    double radius =0;
    cin >>radius;
    cout << "Enter the height of the cylinder: ";
    double height = 0;
    cin >>height;
    cout << "Surface area of the cylinder: "<<SurfaceArea(radius, height)<<endl;

    // Call function "Area"
    cout<<"Area of the circle: "<<Area(radius)<<endl;

    // Call functio "Circumferance"
    cout <<"Circumference is: "<<Circumference(radius)<<endl;
    return 0;
}

// Function definitiona(implementations)
double Area(double radius)
{
    return Pi * radius *radius;
}

double Circumference(double radius)
{
    return 2 * Pi *radius;
}
double SurfaceArea(double radius, double height)
{
    double SurfaceArea = 2 * Pi * radius *radius + 2 *Pi * radius*height; //this is unnecessary
    return SurfaceArea;
}
