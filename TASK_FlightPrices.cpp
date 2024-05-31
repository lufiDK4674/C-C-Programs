#include <iostream>
using namespace std;
void FlightPrices(string Source, string Dest)
{
    if(Source == "Delhi" && Dest == "Jaipur") 
    {
        cout<<"Air India :- Rs. 1899"<<endl;
        cout<<"Vistara :- Rs. 2999"<<endl;
        cout<<"AirAsia :- Rs. 1973"<<endl;
        cout<<"Indigo :- Rs. 1499"<<endl;
    }
    else if(Source == "Delhi" && Dest == "Bangalore")
    {
        cout<<"Air India :- Rs. 2340"<<endl;
        cout<<"Vistara :- Rs. 5646"<<endl;
        cout<<"AirAsia :- Rs. 3256"<<endl;
        cout<<"Indigo :- Rs. 2015"<<endl;
    }
    else if(Source == "Bangalore" && Dest == "Ranchi")
    {
        cout<<"Air India :- Rs. 2469"<<endl;
        cout<<"Vistara :- Rs. 5894"<<endl;
        cout<<"AirAsia :- Rs. 3216"<<endl;
        cout<<"Indigo :- Rs. 2264"<<endl;
    }
    else if(Source == "Delhi" && Dest == "Ranchi")
    {
        cout<<"Air India :- Rs. 1647"<<endl;
        cout<<"Vistara :- Rs. 3258"<<endl;
        cout<<"AirAsia :- Rs. 2964"<<endl;
        cout<<"Indigo :- Rs. 1532"<<endl;
    }
    else
    cout<<"No Flights Found ";

}
int main()
{
    string src, dest;
    cout<<"Enter the source :- ";
    cin>>src;
    cout<<"Enter the Destination :- ";
    cin>>dest;
    FlightPrices(src, dest);

    return 0;

}