
#pragma once

class XCListOptObject;

/**
 * getopt.
 */
class XCGetOpt
{
public:
    bool getopt(const int in_argc, char* const in_argv[], XCListOptObject* inout_pcList);

    XCGetOpt();
    ~XCGetOpt();
};
