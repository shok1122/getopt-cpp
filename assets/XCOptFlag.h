
#pragma once

#include <XCOptObject.h>

/**
 * flag option.
 */
class XCOptFlag: public XCOptObject
{
public:
    XCOptFlag(
        const char* in_option,
        const char* in_description,
        const int in_indent);
    virtual ~XCOptFlag();

    virtual void load(const char* in_optarg);
    virtual void show() const;

private:
    bool m_arg; ///< option's arg
};
