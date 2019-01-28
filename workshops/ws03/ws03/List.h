//
//  List.h
//  ws03
//
//  Created by Naim Sakaamini on 2018-09-25.
//  Copyright © 2018 Naim Sakaamini. All rights reserved.
//

#ifndef List_h
#define List_h


    template <class T, int N>
    class List
    {
        T array[N];
        size_t arrSize = 0;
    public:
        //default constructor
        List() //: array[0](0)//how would we know if this is an int or char...
        {
        }
        
        //
        size_t size() const
        {
            //return array.size();
            return arrSize;
        }
        
        //
        const T& operator [](int index) const
        {
            return array[index];
        }
        
        //
        void operator +=(const T& element)
        {
            if (arrSize < N)
            {
                //array.push_back(element);
                array[arrSize] = element;
                arrSize++;
            }
        }
    };


#endif /* List_h */
