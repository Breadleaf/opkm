#ifndef OPKM_MAIN_H
#define OPKM_MAIN_H

// unused below, guard clauses, check GitRoot/CMakeLists.txt
#ifndef OPKM_MAJOR
#define OPKM_MAJOR 0
#endif

#ifndef OPKM_MINOR
#define OPKM_MINOR 0
#endif

#ifndef OPKM_PATCH
#define OPKM_PATCH 0
#endif

#ifndef OPKM_VERSION_STR
#define OPKM_VERSION_STR ""
#endif
// unused above, guard clauses, check GitRoot/CMakeLists.txt

int
main(int argc, char* argv[]);

#endif // OPKM_MAIN_H
