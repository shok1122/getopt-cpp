
#pragma once

#include <XCOptObject.h>

class XCOptString: public XCOptObject
{
public:
    XCOptString(
        const char* in_name,
        const char* in_description,
        const int in_indent);
    virtual ~XCOptString();

    virtual bool load(const char* in_optarg);
    virtual void show() const;

private:
    const char* m_arg; ///< option's arg
};
