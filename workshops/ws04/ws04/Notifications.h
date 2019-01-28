//
//  Notifications.h
//  ws04
//
//  Created by Naim Sakaamini on 2018-09-27.
//  Copyright © 2018 Naim Sakaamini. All rights reserved.
//

#ifndef Notifications_h
#define Notifications_h
#include "Message.h"

namespace w5
{
    class Notifications
    {
        Message *msg;
        int arrSize;
public:
        Notifications();
        Notifications(const Notifications&);
        Notifications& operator=(const Notifications&);
        Notifications(Notifications&&);
        Notifications& operator=(Notifications&&);
        ~Notifications();
        void operator+=(const Message& msg);
        void display(std::ostream& os) const;
    };
    
}


#endif /* Notifications_h */
