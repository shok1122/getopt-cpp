#include <XCGetOpt.h>

#include <XCListOptObject.h>

XCGetOpt::XCGetOpt()
{
}

XCGetOpt::~XCGetOpt()
{
}

/**
 * exec getopt.
 */
bool XCGetOpt::getopt(
    const int in_argc,            ///< [in] num of runtime args
    char* const in_argv[],        ///< [in] runtime args
    XCListOptObject* inout_pcList ///< [in,out] list of optobject
)
{
    struct option* option = inout_pcList->getOptions();
    int opt = 0;
    int longindex = 0;
    bool bIsFailure = false;
    while ((opt = getopt_long(in_argc, in_argv, "h", option, &longindex)) != -1) 
    {
        switch(opt)
        {
            case 0:
                if (false == inout_pcList->load(longindex, optarg))
                {
                    bIsFailure = true;
                }
                break;
            default:
                inout_pcList->help();
                break;
        }
    }

    return !bIsFailure;
}
