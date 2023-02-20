#include <iostream>
#include <iomanip>
using namespace std;

const double OPTION_ONE_DELIVERY = 5000; // First option. Payment to author following delivery, constant
const double OPTION_ONE_PUBLISH = 20000; // First option. Payment to author following publishing, constant
const double OPTION_TWO_RATE = 12.5; // Second option. Percentage of each book sold, constant
const double OPTION_THREE_FIRSTRATE = 10; // Third option. Percentage of each book sold up to 4000, constant
const double OPTION_THREE_SECONDRATE = 14; // Third option. Percentage of each book sold after 4000, constant


int main() {
  double price; // net price of the novel, input
  int copies; // estimated numbers of copies to be sold, input
  double royaltiesOne; // royalties gained from option one, output
  double royaltiesTwo; // royalties gained from option two, output
  double royaltiesThree; // royalties gained from option three, output

  cout << fixed << setprecision(2);

  // Input price and copies variables
  cout << "Enter the price of the novel: ";
  cin >> price;
  cout << endl << "Enter the expected number of copies to be sold: ";
  cin >> copies;
  cout << endl;

  // Calculate Option One
  royaltiesOne = OPTION_ONE_DELIVERY + OPTION_ONE_PUBLISH;
  
  // Calculate Option Two
  royaltiesTwo = price * copies * OPTION_TWO_RATE / 100;
  
  // Calculate Option Three
  if(copies <= 4000) {
    royaltiesThree = price * copies * OPTION_THREE_FIRSTRATE / 100;
  }
  else
    royaltiesThree = (price * 4000 * OPTION_THREE_FIRSTRATE / 100) + (price * (copies - 4000) * OPTION_THREE_SECONDRATE / 100);
  
  // Output different options 
  cout << left << setw(14) << "First Option:" << right << setw(12) << royaltiesOne << endl;
  cout << left << setw(14) << "Second Option:" << right << setw(12) << royaltiesTwo << endl;
  cout << left << setw(14) << "Third Option:" << right <<setw(12) << royaltiesThree << endl << endl;

  // Identify the best choice (the option that makes the most amount of money)
  if(royaltiesOne > royaltiesTwo && royaltiesOne > royaltiesThree)
    cout << "The best option is option #1.";
  else if(royaltiesTwo > royaltiesOne && royaltiesTwo > royaltiesThree)
    cout << "The best option is option #2.";
  else
    cout << "The best option is option #3.";
}
