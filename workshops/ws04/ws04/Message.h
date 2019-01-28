//
//  Message.h
//  ws04
//
//  Created by Naim Sakaamini on 2018-09-27.
//  Copyright © 2018 Naim Sakaamini. All rights reserved.
//

#ifndef Message_h
#define Message_h

#include <string>

namespace w5
{
    class Message
    {
        std::string msg;
    public:
        Message(){};
        Message(std::ifstream& in, char c);
        bool empty() const;
        void display(std::ostream&) const;
    };
}


#endif /* Message_hpp */
