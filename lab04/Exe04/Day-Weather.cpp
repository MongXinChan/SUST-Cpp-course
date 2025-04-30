#include <iostream>
using namespace std;
enum Day{
    Monday = 1, Tuesday = 2, Wednesday = 3, Thursday = 4, 
    Friday = 5, Saturday = 6, Sunday = 7
};
enum Weather{    SUNNY = 0, RAINY = 1, CLOUDY = 2, SNOWY = 3};

int main() {
    int d = 0;
    int w = 0;

    // 提示用户输入星期值
    cout << "Input the Day value: Monday(1), Tuesday(2), Wednesday(3), Thursday(4), "
         << "Friday(5), Saturday(6), Sunday(7)\n";
    cin >> d;

    // 根据输入的星期值输出对应的星期名称
    cout << "This is ";
    switch (d) {
        case Monday:    cout << "Monday"; break;
        case Tuesday:   cout << "Tuesday"; break;
        case Wednesday: cout << "Wednesday"; break;
        case Thursday:  cout << "Thursday"; break;
        case Friday:    cout << "Friday"; break;
        case Saturday:  cout << "Saturday"; break;
        case Sunday:    cout << "Sunday"; break;
        default:        cout << "Invalid Day"; break;
    }
    cout << endl;

    // 提示用户输入天气值
    cout << "Input the Weather value: SUNNY(0), RAINY(1), CLOUDY(2), SNOWY(3)\n";
    cin >> w;

    // 根据输入的天气值输出对应的天气名称
    cout << "The weather is: ";
    switch (w) {
        case SUNNY:   cout << "Sunny"; break;
        case RAINY:   cout << "Rainy"; break;
        case CLOUDY:  cout << "Cloudy"; break;
        case SNOWY:   cout << "Snowy"; break;
        default:      cout << "Invalid Weather"; break;
    }
    cout << endl;

    // 判断是否适合出行
    if ((d >= Monday && d <= Friday && w == SUNNY) || (d == Saturday && w != RAINY) || (d == Sunday && w != RAINY)) {
        cout << "Can travel\n";
    } else {
        cout << "Not suitable for travelling\n";
    }

    return 0;
}
