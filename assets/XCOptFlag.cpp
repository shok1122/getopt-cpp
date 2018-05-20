#include "XCOptFlag.h"

#include <stdio.h>
#include <stdlib.h>

XCOptFlag::XCOptFlag(
    const char* in_option,      ///< [in] option name
    const char* in_description, ///< [in] description of option's arg
    const int in_indent         ///< [in] indent size
    ):
    XCOptObject(in_option, in_description, no_argument, in_indent),
    m_arg(false)
{
}

XCOptFlag::~XCOptFlag()
{
}

/**
 * load optarg.
 */
void XCOptFlag::load(
    const char* in_optarg ///< [in] optarg
    )
{
    if (nullptr == in_optarg)
    {
        return;
    }

    m_arg = true;
}

/**
 * show optarg.
 */
void XCOptFlag::show() const
{
    fprintf(stderr, "--%s%*c%s",
        m_name,
        m_sizeSpace, ' ',
        (true == m_arg) ? "enable" : "disable");
}