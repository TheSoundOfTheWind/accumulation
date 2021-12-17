#ifndef NS_H_
#define NS_H_
namespace SALES
{
  const int QUARTERS = 4;

  class Sales
  {
  private:
    double m_sales[QUARTERS];
    double m_average;
    double m_max;
    double m_min;
  public:
    Sales(Sales & s);
    Sales(const double sales[], int n);
    const double * get_sales();
    const double get_average();
    const double get_max();
    const double get_min();
    void showSales();

  };
};
#endif /* NS_H_ */
