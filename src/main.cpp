#include <chrono>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include "JoinQuery.hpp"

//---------------------------------------------------------------------------
int main(int argc, char *argv[])
{
   //string lineitem, orders, customer;
   using namespace std;
   if (argc != 4) {
      cout << "Usage: " << argv[0]
           << " <lineitem.tbl> <order.tbl> <customer.tbl>";
      exit(1);
   }

   string lineitem(argv[1]);
   string orders(argv[2]);
   string customer(argv[3]);

   //char *orders;
   //orders=argv[2];

   //cout<<"test"<<endl;
   //cout<<"lineitem:"<< lineitem<< "orders:"<< orders << "customer: "<< customer <<endl;
   vector<string> segments;
   //cout<<"heree"<<endl;
   // get segments from standard input
   for (string segment; getline(cin, segment);)segments.push_back(segment);
   //{
     //if (segment.length() == 0) break;
    //segments.push_back(segment);
//}
    // print vector segments
   /*for (vector<string>::iterator i = segments.begin() ; i != segments.end(); ++i)
   {

     cout<<*i<<endl;

   }*/

   JoinQuery q(lineitem, orders, customer);
   // run a query for each retrieved segment
   //cout<<"orders"<<orders<<endl;
  // q.ReadOrder();
  // q.ReadCustomer();
  // q.ReadLineitem();

   for (auto &segment : segments) cout << q.avg(segment) << "\n";

   // flush output buffer
   cout.flush();
}
//---------------------------------------------------------------------------
