// bank_12.cpp -- using the Queue interface
// compile with queue.cpp
#include <iostream>
#include <cstdlib>   // for rand() and srand()
#include <ctime>     // for time()
#include "queue_10.h"
const int SEC_PER_HR = 3600;

bool newcustomer(double x);  // is there a new customer?

int main()
{
  using std::cin;
  using std::cout;
  using std::endl;
  using std::ios_base;
  // setting things up
  std::srand(std::time(0));          // random initializing of rand()

  cout << "Case Study: Bank of Heather Automatic Teller\n";
  cout << "Enter maximum size of queue: ";
  int qs;
  cin >> qs;
  Queue line(qs);                       // line queue holds up to qs people

  cout << "Enter the number of simulation hours: ";
  int hours;                               // hours of simulation
  cin >> hours;
  // simulation will run 1 cycle per minute
  long cyclelimit = SEC_PER_HR * hours;    // # of cycles

  Item temp;                            // new xustomer data
  long turnaways = 0;               // new customer data
  long customers = 0;               // joined the queue
  long served = 0;                    // served during the simulation
  long sum_line = 0;                 // cumulative line length
  long wait_time = 0;                // time until autoteller is free
  long line_wait = 0;                 // cumulative time in line

  int perhour = 1;
  int sec_per_cust = 0;
  bool b_break = false;
  while(1) {
    if (true == b_break) {
      break;
    }
    line.clean();
    turnaways = 0;               // new customer data
    customers = 0;               // joined the queue
    served = 0;                    // served during the simulation
    sum_line = 0;                 // cumulative line length
    wait_time = 0;                // time until autoteller is free
    line_wait = 0;                 // cumulative time in line
    
    if (true == b_break) {
      break;
    }
    sec_per_cust = SEC_PER_HR / perhour;
    // runnning the simulation
    for (int cycle = 0; cycle < cyclelimit; cycle++)
      {
	// Are there any new customers in the queue at this time
	if (newcustomer(sec_per_cust))  // have newcomer
	  {
	    // The new queue is full and the customer turns away
	    if (line.isfull()) {
	      turnaways++;
	    }
	    // The queue is not full, the customer enters the queue
	    else
	      {
		customers++;                   // Process customer add one
		temp.set(cycle);               // Customers arrive at this moment
		line.enqueue(temp);            // add new customer to queue
	      }
	  }
	// There are customers in the queue and there is no need to wait
	if (wait_time <= 0 && !line.isempty())
	  {
	    line.dequeue(temp);                 // The customer at the head of the queue is processing
	    wait_time = temp.ptime();           // Waiting time increased by 60 to 180 seconds
	    line_wait += cycle - temp.when();   // Cumulative queuing time increases
	    served++;                           // Number of customers processed in simulation time
	  }
	// Wait time reduced by one second
	if (wait_time > 0)
	  wait_time--;
	sum_line += line.queuecount();           // Adds the queue length per second
      }
    if ((line_wait/served)>60) {
      b_break = true;
    } else {
      ++perhour;
    }
  }
  
  // reporting results
  if (customers > 0)
    {
      cout << "customers accepted: " << customers << endl;
      cout << "  customers served: "  << served << endl;
      cout << "         turnaways: " << turnaways << endl;
      cout << "average queue size: ";
      cout.precision(2);
      cout.setf(ios_base::fixed, ios_base::floatfield);
      cout << (double) sum_line / cyclelimit << endl;
      cout << " average wait time: "
	   << (double) line_wait / served << " second\n";
      cout << "num of customers per hours: " << perhour << endl;
    }
  else
    cout << "No customers!\n";
  cout << "Done!\n";

  return 0;
}

// x = average time, in minutes, between customers
// return value is true if customer shows up this minute
bool newcustomer(double x)
{
  return (std::rand() * x/ RAND_MAX < 1);
}
