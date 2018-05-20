#include <XCOptString.h>

#include <stdio.h>
#include <stdlib.h>

XCOptString::XCOptString(
    const char* in_option,      ///< [in] option name
    const char* in_description, ///< [in] description of option's arg
    const int in_indent         ///< [in] indent size
    ):
    XCOptObject(in_option, in_description, required_argument, in_indent),
    m_arg(0)
{
}

XCOptString::~XCOptString()
{
}

/**
 * load optarg.
 */
void XCOptString::load(
    const char* in_optarg ///< [in] optarg
    )
{
    if (nullptr == in_optarg)
    {
        return;
    }

    m_arg = in_optarg;
}

/**
 * show optarg.
 */
void XCOptString::show() const
{
    fprintf(stderr, "--%s%*c%s\n",
        m_name,
        m_sizeSpace, ' ',
        m_arg);
}
