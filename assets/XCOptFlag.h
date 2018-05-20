
#pragma once

#include <XCOptObject.h>

/**
 * flag option.
 */
class XCOptFlag: public XCOptObject
{
public:
    XCOptFlag(
        const char* in_name,
        const char* in_description,
        const int in_indent);
    virtual ~XCOptFlag();

    virtual bool load(const char* in_optarg);
    virtual void show() const;

private:
    bool m_arg; ///< option's arg
};
