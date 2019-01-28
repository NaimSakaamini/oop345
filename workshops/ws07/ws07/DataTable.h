//
//  DataTable.h
//  ws07
//
//  Created by Naim Sakaamini on 2018-10-30.
//  Copyright © 2018 Naim Sakaamini. All rights reserved.
//

#ifndef DataTable_h
#define DataTable_h

#include<iostream>
#include<fstream>
#include<vector>
#include<iterator>
#include<algorithm>
#include<functional>
#include<numeric>
#include<math.h>
#include<iomanip>

using namespace std;

namespace w7
{
    template <class T>
    class DataTable
    {
        vector<T> X;
        vector<T> Y;
        int width;
        int decimals;
        
    public:
        DataTable(ifstream& fs, int wid, int dec)
        {
            width = wid;
            decimals = dec;
            T x, y;
            while(fs.good())
            {
                fs >> x >> y;
                X.push_back(x);
                Y.push_back(y);
            }
            fs.close();
        }
        
        
        
        T mean() const
        {
            T sum = accumulate(Y.begin(), Y.end(), 0.0);
            return sum / Y.size();
        }
        
        
        
        T sigma() const
        {
            vector<T> vec(Y.begin(), Y.end());
            T ssd;
            transform (vec.begin(), vec.end(), vec.begin(), [&](T i){ return i - mean(); } );
            ssd = inner_product(vec.begin(), vec.end(), vec.begin(), 0.0);
            return sqrt(ssd/(Y.size() - 1));
            
            /*
             T result = 0;
            
            for (auto i : Y)
            {
                result += pow(i - mean(), 2);
            }
           
            result /= Y.size() -1;
            
            result = sqrt(result);
            return result;
            */
         
        }
                       
        
        T median()
        {
            sort(Y.begin(), Y.end());
            T median;
            if (Y.size() % 2 == 0)
            {
                 median = Y[(Y.size()/2)];
            }
            else
            {
                median = (Y[Y.size() / 2] + Y[(Y.size() / 2) - 1]) / 2;
            }
            return median;
        }
        
        
        
        void regression(T& slope, T& Y_intercept) const
        {
            T Xsum = accumulate(X.begin(), X.end(), 0.0);
            T Ysum = accumulate(Y.begin(), Y.end(), 0.0);
            
            T XXsum = inner_product(X.begin(), X.end(), X.begin(), 0.0);
            T XYsum = inner_product(X.begin(), X.end(), Y.begin(), 0.0);
            
            slope = ((X.size() * XYsum) - (Xsum * Ysum)) / ((X.size() * XXsum) - pow(Xsum,2));
            Y_intercept = (Ysum - slope * Xsum) / X.size();
        }
    
    
    
        void display(ostream& os) const
        {
            os << setw(width) << "X";
            os << setw(width) << "Y" << endl;
            os << setprecision(decimals);
            for (auto i : X)
            {
                os << X[i];
                os << Y[i];
            }
        }
        
    };
    template<class T>
    ostream& operator<<(std::ostream& os, const DataTable<T>& table)
    {
        table.display(os);
        return os;
    }
   
}

#endif /* DataTable_h */
