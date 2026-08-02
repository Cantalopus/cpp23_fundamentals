/*
    Entire translation unit: utilities.cppm
    │
    ├── Global module fragment — optional
    │   │
    │   ├── module;
    │   ├── #include <string_view>
    │   └── #include <fmt/format.h>
    │
    ├── Module declaration
    │   │
    │   └── export module utilities;
    │
    └── Remaining module purview
        │
        ├── imports
        ├── exported declarations
        ├── exported definitions
        └── non-exported declarations and definitions*/
    

// utilities.cppm

/*==============================================================================
    ├── Global module fragment — optional
    │   │
    │   ├── module;
    │   ├── #include <string_view>
    │   └── #include <fmt/format.h>
==============================================================================*/

module;

//#include <string_view>
#include <fmt/format.h>


/*==============================================================================
    ├── Module declaration
    │   │
    │   └── export module utilities;
==============================================================================*/

export module utilities;

/*==============================================================================
        └── Remaining module purview
        │
        ├── imports
        ├── exported declarations
        ├── exported definitions
        └── non-exported declarations and definitions
==============================================================================*/

// Imports are part of the module purview.

// import fmt;
// import std;
// import other;
// import another_module;

// export import another_public_module;

// Exported interface
//export void print_msg(std::string_view message)
//{
//    fmt::println("{}", message);
//}

// Non-exported module declarations may also appear here.