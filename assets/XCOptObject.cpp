#include "XCOptObject.h"

#include <stdio.h>
#include <string.h>

XCOptObject::XCOptObject(
    const char* in_option,       ///< [in] option name
    const char* in_description,  ///< [in] description of option's arg
    const int in_hasArg,         ///< [in] has_arg flag
    const int in_indent          ///< [in] indent size
    ):
    m_name(in_option),
    m_description(in_description),
    m_hasArg(in_hasArg),
    m_indent(in_indent),
    m_sizeSpace(0)
{
    m_sizeSpace = m_indent - (strlen(in_option) + 2);
}

XCOptObject::~XCOptObject()
{
}

/**
 * get option parameter.
 */
void XCOptObject::getOption(
    struct option* out_option ///< [out]
    )
{ 
    out_option->name = m_name;
    out_option->has_arg = m_hasArg;
    out_option->flag = nullptr;
    out_option->val = 0;
}

/**
 * show help.
 */
void XCOptObject::help() const
{
    fprintf(stderr,
        "--%s%*c%s\n",
        m_name,
        m_sizeSpace, ' ',
        m_description);
}
