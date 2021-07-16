#ifndef ABC_H
#define ABC_H
#include <ostream>
class Abc
{
 public:
  virtual ~Abc(){ };
  virtual void view() = 0;
};
// Base Class Using DMA
class baseDMA : public Abc
{
 private:
  char * label;
  int rating;

 public:
  baseDMA(const char * l = "null", int r = 0);
  baseDMA(const baseDMA & rs);
  virtual ~baseDMA();

  // get methods
  // --------------------------------------------------
  virtual void view();
  friend std::ostream & operator<<(std::ostream & os,
				   const baseDMA & rs);
  // --------------------------------------------------

  // set methods
  // --------------------------------------
  baseDMA & operator=(const baseDMA & rs);
  // --------------------------------------
};

// derived class without DMA
// uses implicit copy constructor
// uses implict assignment operator
class lacksDMA : public baseDMA
{
  private:
  enum {COL_LEN = 40};
  char color[COL_LEN];

 public:
  lacksDMA(const char * c = "blank", const char * l = "null",
	   int r = 0);
  lacksDMA(const char * c, const baseDMA & rs);
  virtual ~lacksDMA();

  // get methods
  // ---------------------------------------------------
  virtual void view();
  friend std::ostream & operator<<(std::ostream & os,
				   const lacksDMA & rs);
  // ---------------------------------------------------
};

// derived class with DMA
class hasDMA : public lacksDMA
{
 private:
  char * style;

 public:
  hasDMA(const char * s = "none", const char * c = "blank", const char * l = "null",
	 int r = 0);
  hasDMA(const char * s, const lacksDMA & rs);
  hasDMA(const hasDMA & hs);
  virtual ~hasDMA();

  // get methods
  // -------------------------------------------------
  virtual void view();
  friend std::ostream & operator<<(std::ostream & os,
				   const hasDMA & rs);
  // -------------------------------------------------

  //set methods
  // -------------------------------------------------
  hasDMA & operator=(const hasDMA & rs);
  // -------------------------------------------------


};
#endif // ABC_H
