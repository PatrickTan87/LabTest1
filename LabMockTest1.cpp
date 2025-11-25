#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
	int roomType, nights;
	double pricePerNight, subtotal, discount = 0, finalTotal, extraDiscount, totalDiscount;
	char promoCode;
	string roomName;

	cout << "=========================================\n\n";
	cout << "     FTMK GRAND HOTEL BOOKING SYSTEM\n\n";
	cout << "=========================================\n\n";
	cout << "1. Standard Room - RM150.00 per night\n";
	cout << "2. Deluxe Room   - RM200.00 per night\n";
	cout << "3. Suite Room    - RM300.00 per night\n\n";
	cout << "-----------------------------------------\n\n";
	cout << "Enter room type (1-3): ";
	cin >> roomType;
	
	switch (roomType)
	{
	case 1:
		pricePerNight = 150.00;
		roomName = "Standard Room";
		break;
	case 2:
		pricePerNight = 200.00;
		roomName = "Deluxe Room";
		break;
	case 3:
		pricePerNight = 300.00;
		roomName = "Suite Room";
		break;
	default:
	{
		cout << "Invalid room type entered!" << endl;
		return 0;
	}
	}

	cout << "Enter number of nights: ";
	cin >> nights;
	cout << endl << endl;
	cout << "You selected " << roomName << ".\n\n";
	cout << "Do you have a promo code? (Y for yes / N for No): ";
	cin >> promoCode;
	
	cout << fixed << setprecision(2);

	subtotal = pricePerNight * nights;

	if (nights >= 1 && nights <= 2)
		discount = 0.0;
	else if (nights >= 3 && nights <= 5)
		discount = subtotal * 0.05;
	else if (nights >= 6)
		discount = subtotal * 0.1;

	if (promoCode == 'Y' || promoCode == 'y')
		extraDiscount = subtotal * 0.1;
	
	totalDiscount = discount + extraDiscount;

	cout << endl << endl;
	cout << "------------------ BOOKING SUMMARY ------------------\n\n";
	cout << "Price per night : RM" << pricePerNight << endl;
	cout << "Nights Stayed   : " << nights << endl;
	cout << "Subtotal        : RM" << subtotal << endl;
	cout << "Discount (" << (discount / subtotal * 100) << "%): RM" << (subtotal * discount / 100) << endl;

	finalTotal = subtotal - discount;

	cout << "\n-----------------------------------------------------\n\n";
	cout << "Final Total     : RM" << finalTotal << endl;
	cout << "\n-----------------------------------------------------\n\n";

	if (finalTotal >= 1200)
		cout << "VIP CUSTOMER: You are eligible for free airport transfer!\n";
	else if (finalTotal < 300)
		cout << "Enjoy your vacation.\n";
	else
		cout << "Thank you for booking with FTMK Grand Hotel.\n";

	cout << "\n======================================================\n";

	return 0;
}