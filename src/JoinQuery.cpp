#include "JoinQuery.hpp"
#include <assert.h>
#include <fstream>
#include <thread>
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <utility>

using namespace std;
//---------------------------------------------------------------------------
JoinQuery::JoinQuery(std::string lineitem, std::string order,
                     std::string customer)
{
  plineitem = lineitem;
  porder = order;
  pcustomer = customer;



}
//---------------------------------------------------------------------------
size_t JoinQuery::avg(std::string segmentParam)
{
  uint64_t avg2;
  ReadCustomer(segmentParam);
  ReadOrder();

  avg2 = ReadLineitem();




    /*unordered_map <int, orderrecord>::iterator iter5;
    for(iter5 = ordersht.begin(); iter5 != ordersht.end(); iter5++)
    {

      orderrecord ww5 = iter5->second;
      unordered_set<int>::const_iterator got = fck.find (ww5.custkey);

       if ( got != fck.end() )
       {
         fok.insert(iter5->first);

      }
    }*/


    //print unordered_set
    /*unordered_set<int>::iterator it = fok.begin();

    // Iterate till the end of set
    while (it != fok.end())
    {
    	// Print the element
    	cout << (*it) << " , ";
    	//Increment the iterator
    	it++;
    }*/



  //print the vector that has the orderkey of o_custkey == c_custkey
  /*for (vector<int>::iterator i = fok.begin() ; i != fok.end(); ++i)
  {

    cout<<*i<<endl;

  }*/










 return avg2;
}

//---------------------------------------------------------------------------
size_t JoinQuery::lineCount(std::string rel)
{
   std::ifstream relation(rel);
   assert(relation);  // make sure the provided string references a file
   size_t n = 0;
   for (std::string line; std::getline(relation, line);) n++;
   return n;
}

//unordered_map <int, JoinQuery::custrecord>
inline uint64_t JoinQuery::ReadCustomer(string sParam)
{
  string value="";

  ifstream in(pcustomer);
  string line;
  //unsigned sum=0;
  while (getline(in,line)) {
    value.clear();

     const char* data=line.data(),*limit=data+line.length(),*last=data;
     unsigned field=0;
     //unsigned field2=0;
     for (const char* iter=data;iter!=limit;++iter) {
        if ((*iter)=='|') {
           if (++field==1) {
              unsigned v=0;
              for (const char* iter2=last;iter2!=iter;++iter2)
                 //k=(*iter2);
                 //cout<<(*iter2)<<endl;
                 value.push_back(*iter2);

                 //v=10*v+(*iter2)-'0';
                 //cout<<v<<endl;
              //sum+=v;
              //cout<<value<<endl;
              fck.insert(stoi(value));
              break;
           }
           else
             {
              last=iter+1;
           }



        }
     }

  }





  while (getline(myFileStream2, line2)){
    stringstream ss2(line2);
    getline(ss2, custkey, '|');
    getline(ss2, name, '|');
    getline(ss2, address, '|');
    getline(ss2, nationkey, '|');
    getline(ss2, phone, '|');
    getline(ss2, acctbal, '|');
    getline(ss2, mktsegment, '|');
    //getline(ss2, comment, '|');


    if(mktsegment==sParam)
    {
      fck.insert(stoi(custkey));
    }


}




    //insert records of table customer into hashtable, key is the primary key of the table
    //and value is type struct which includes the rest of the attributes(eg custkey,name..)
    customerht.insert(pair<int, custrecord>(stoi(custkey), l2));


  }




  myFileStream2.close();




  return 1;

}

//unordered_map <int, JoinQuery::orderrecord>
inline uint64_t JoinQuery::ReadOrder()
{

  string value="";

  ifstream in(porder);
  string line;
  unsigned sum=0;
  while (getline(in,line)) {
    value.clear();

     const char* data=line.data(),*limit=data+line.length(),*last=data;
     unsigned field=0;
     //unsigned field2=0;
     for (const char* iter=data;iter!=limit;++iter) {
        if ((*iter)=='|') {
           if (++field==4) {
              unsigned v=0;
              for (const char* iter2=last;iter2!=iter;++iter2)
                 //k=(*iter2);
                 //cout<<(*iter2)<<endl;
                 value.push_back(*iter2);

                 //v=10*v+(*iter2)-'0';
                 //cout<<v<<endl;
              //sum+=v;
              cout<<value<<endl;
              break;
           }
           else
             {
              last=iter+1;
           }



        }
     }

  }



  while (getline(myFileStream, line)){
    stringstream ss(line);
    getline(ss, okey, '|');
    getline(ss, ckey, '|');


    unordered_set<int>::const_iterator got = fck.find (stoi(ckey));

     if ( got != fck.end() )
     {
       fok.insert(stoi(okey));
     }

   }
    /*getline(ss, ostatus, '|');
    getline(ss, tprice, '|');
    getline(ss, odate, '|');
    getline(ss, opriority, '|');
    getline(ss, clerk, '|');
    getline(ss, shippriority, '|');
    getline(ss, comment, '|');

    //update l
    l.orderkey = stoi(okey);
    l.custkey = stoi(ckey);
    l.orderstatus = ostatus;
    l.totalprice = stod(tprice);
    l.orderdate = odate;
    l.orderpriority = opriority;
    l.clerk = clerk;
    l.shippriority = stoi(shippriority);
    l.comment = comment;

    //to be removed
    //pr = make_pair(stoi(okey), l );
    //cout<<pr.first<<endl;
    //cout<<pr.second.orderkey<<endl;

    //insert records of table orders into hashtable, key is the primary key of the table
    //and value is type struct which includes the rest of the attributes(eg orderkey,custkey,..)
    ordersht.insert(pair<int, orderrecord>(stoi(okey), l));


  }


  myFileStream.close();




  return 1;

}




  myFileStream3.close();


//sum*100/k
  fck.clear();
  fok.clear();
  return (sum*100)/k;


}

//---------------------------------------------------------------------------
