
#include <XCGetOpt.h>
#include <XCListOptObject.h>

#include <stdio.h>

static XCGetOpt s_cGetOpt;
static XCListOptObject s_cList;

int main(int argc, char** argv)
{
  s_cGetOpt.getopt(argc, argv, &s_cList);
  s_cList.help();
  s_cList.show();

  return 0;
}