//
//  Text.h
//  ws02
//
//  Created by Naim Sakaamini on 2018-09-18.
//  Copyright © 2018 Naim Sakaamini. All rights reserved.
//

#ifndef Text_h
#define Text_h

namespace w2
{
    class Text
    {
        std::string* strings;
        size_t ssize;
    public:
        Text();
        Text(const std::string&);
        Text(Text&);
        Text& operator=(Text&);
        Text(Text&&);
        Text& operator=(Text&&);
        ~Text();
        size_t size() const;
    };
}

#endif /* Text_h */
