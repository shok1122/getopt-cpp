
#pragma once

#include <XCOptObject.h>

/**
 * Int32 option.
 */
class XCOptInt32: public XCOptObject
{
public:
    XCOptInt32(
        const char* in_name,
        const char* in_description,
        const int in_indent);
    virtual ~XCOptInt32();

    virtual bool load(const char* in_optarg);
    virtual void show() const;

private:
    long m_arg; ///< option's arg
    int m_base; ///< base of integer
};
