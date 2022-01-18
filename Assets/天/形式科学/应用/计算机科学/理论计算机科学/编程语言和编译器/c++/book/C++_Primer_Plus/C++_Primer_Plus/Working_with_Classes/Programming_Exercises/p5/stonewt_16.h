// stonewt_16.h -- definition for the Stonewt class
#ifndef STONEWT_H_
#define STONEWT_H_
enum FORM {STONE, INT_POUNDS, FLOAT_POUNDS};
class Stonewt
{
public:
private:
  enum {Lbs_per_stn = 14};        // pounds per stone
  int stone;                      // whole stones
  double pds_left;                // fractional pounds
  double pounds;                  // entire weight in pounds
  FORM m_form;
 public:
  Stonewt(double lbs, FORM form = STONE);   // constructor for double pounds
  Stonewt(int stn, double lbs, FORM form = STONE);   // constructor for stone, lbs
  Stonewt(FORM form = STONE);     // default constructor
  ~Stonewt();

  Stonewt operator+(const Stonewt & s) const;
  Stonewt operator-(const Stonewt & s) const;
  Stonewt operator*(const double & d) const;
  friend Stonewt operator*(const double & d, const Stonewt & s);
  friend std::ostream & operator<<(std::ostream & os, const Stonewt & s);
};
#endif
