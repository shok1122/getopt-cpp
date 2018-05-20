#include <XCOptInt32.h>

#include <stdio.h>
#include <stdlib.h>

XCOptInt32::XCOptInt32(
    const char* in_name,        ///< [in] option name
    const char* in_description, ///< [in] description of option's arg
    const int in_indent         ///< [in] indent size
    ):
    XCOptObject(in_name, in_description, required_argument, in_indent),
    m_arg(0),
    m_base(10)
{
}

XCOptInt32::~XCOptInt32()
{
}

/**
 * load optarg.
 */
bool XCOptInt32::load(
    const char* in_optarg ///< [in] optarg
    )
{
    if (nullptr == in_optarg)
    {
        return false;
    }

    m_arg = strtol(in_optarg, nullptr, m_base);

    return true;
}

/**
 * show optarg.
 */
void XCOptInt32::show() const
{
    fprintf(stderr, "--%s%*c%ld\n",
        m_name,
        m_sizeSpace, ' ',
        m_arg);
}
