#include <iostream>
int main() {
    using namespace std;
    const int DAY_TO_HOURS = 24;
    const int HOURS_TO_MINUTES = 60;
    const int MINUTES_TO_SECONDS = 60;

    long long seconds;
    cout << "Enter the number of seconds: ";
    cin >> seconds;
    long long days = seconds / (DAY_TO_HOURS*HOURS_TO_MINUTES*MINUTES_TO_SECONDS);
    long long hours = (seconds % (DAY_TO_HOURS*HOURS_TO_MINUTES*MINUTES_TO_SECONDS)) / (HOURS_TO_MINUTES*MINUTES_TO_SECONDS);
    long long minutes = (seconds % (HOURS_TO_MINUTES*MINUTES_TO_SECONDS)) / (MINUTES_TO_SECONDS);
    long long seconds_out = seconds%MINUTES_TO_SECONDS;
    cout << seconds << " seconds = " << days << " days, " << hours <<
    " hours, " << minutes << " minutes, " << seconds_out << " seconds" <<
    std::endl;
    
    return 0;
}
