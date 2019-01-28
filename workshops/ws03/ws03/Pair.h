//
//  Pair.h
//  ws03
//
//  Created by Naim Sakaamini on 2018-09-25.
//  Copyright © 2018 Naim Sakaamini. All rights reserved.
//

#ifndef Pair_h
#define Pair_h

    template <class A, class B>
    class Pair
    {
        A var1;
        B var2;
        
    public:
        Pair() //: var1(0), var2(0) //dont know what type
        {
        
        }
        
        
        Pair(const A& val1, const B& val2)
        {
            var1 = val1;
            var2 = val2;
        }
        
        
        const A& getKey() const
        {
            return var1;
        }
        
        
        const B& getValue() const
        {
            return var2;
        }
    };


#endif /* Pair_h */
