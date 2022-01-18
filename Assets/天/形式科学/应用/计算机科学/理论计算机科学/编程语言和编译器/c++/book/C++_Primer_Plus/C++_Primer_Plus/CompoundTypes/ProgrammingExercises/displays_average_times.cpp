#include <iostream>
int main() {
  using std::cout;
  using std::cin;
  using std::endl;
  
  int num = 0;
  cout << "enter number of times for the 40-yd: ";
  cin >> num ;
  double * times_array = new double[num];
  cout << "enter three times for the 40-yd dash: ";
  for(int i  =0;i < num;i++) {
    cin >> times_array[i];
  }

  double sum_times = 0;
  for(int i = 0;i < num; i++) {
    sum_times += times_array[i];
    cout << "times " << i+1 << " is " << times_array[i] << endl;
  }
  
  cout << "average time is " << sum_times/num << endl;
  
  return 0;
}
