
#pragma once

#include <getopt.h>

/**
 * option object.
 */
class XCOptObject
{
public:
    void getOption(struct option* out_option);
    void help() const;

    virtual bool load(const char* in_optarg) = 0;
    virtual void show() const = 0;

    XCOptObject(
        const char* in_name,
        const char* in_description,
        const int in_hasArg,
        const int in_indent);
    ~XCOptObject();

protected:
    const char* m_name; ///< option name
    const char* m_description; ///< description of option's arg
    const int m_hasArg; ///< has_arg flag
    const int m_indent; ///< indent size

    int m_sizeSpace; ///< space size
};
