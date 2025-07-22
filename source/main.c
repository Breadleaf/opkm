#include "main.h"

#include <curl/curl.h>
#include <git2.h>
#include <stdio.h>

int
main(int argc, char* argv[])
{
  printf("opkm version: %s\n", OPKM_VERSION_STR);

  git_libgit2_init();
  int major = 0, minor = 0, rev = 0;
  git_libgit2_version(&major, &minor, &rev);
  printf("libgit2 version: %d.%d.%d\n", major, minor, rev);
  git_libgit2_shutdown();

  curl_global_init(CURL_GLOBAL_DEFAULT);
  const curl_version_info_data *vi = curl_version_info(CURLVERSION_NOW);
  printf("libcurl version: %s\n", vi->version);
  curl_global_cleanup();

  return 0;
}
