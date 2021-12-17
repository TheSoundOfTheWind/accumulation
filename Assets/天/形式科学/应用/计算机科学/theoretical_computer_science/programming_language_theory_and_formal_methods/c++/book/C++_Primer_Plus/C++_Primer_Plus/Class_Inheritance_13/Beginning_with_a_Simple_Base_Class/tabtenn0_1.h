// tabtenn0_1.h -- a table-tennis base class
#ifndef TABTENN0_1_H_
#define TABTENN0_1_H_
#include <string>

using std::string;
// simple base class
class TableTennisPlayer
{
 private:
  string firstname;
  string lastname;
  bool hasTable;
 public:
  TableTennisPlayer (const string & fn = "none",
		     const string & ln = "node",
		     bool ht = false);
  void Name() const;
  bool HasTable() const {return hasTable;};
  void ResetTable(bool v) {hasTable = v;}
};
#endif // TABTENN0_1_H_
