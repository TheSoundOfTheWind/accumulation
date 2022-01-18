#ifndef MOVE_H_
#define MOVE_H_
class Move{
 private:
  double x;
  double y;
 public:
  Move(double a = 0, double b = 0);    // sets x, y to a, b
  void showmove() const;
  Move add(const Move & m) const;
  void reset(double a = 0, double b = 0);
  void set_x(double x);
  double get_x() const;
  void set_y(double y);
  double get_y() const;
};
#endif /* MOVE_H_ */
