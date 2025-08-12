# Code That I Reuse a Lot
Some code that I reuse a lot.

## Index (Categorized by Language)
- **[C++23](#c23)**
  - [printing.hpp](#printinghpp) - Custom printout macros for stylized "error", "warning", and "debug" messages
  - [colors.hpp](#colorshpp) - Useful namespace-like structs containing hard-coded ANSI color codes

# C++23
## printing.hpp
This header file gives you three handy macros for printing labelled messages to the console.

Here are some examples of the macros in use:
```C++
// The macros in use:
PRINT_ERROR("You need to run this program as root (trust me, bro)!")
PRINT_WARNING("Looks like you forgot to escape some whitespace in your commandline argument! Don't worry, I'll push through it and fuck up your filesystem :D")
PRINT_DEBUG("crashfucktest34")
// Oh, yeah, all these macros support format strings, since they're just a wrapper around `std::print`
PRINT_DEBUG("line {} is not the crash", 19)
```

And here's what all of that looks like when printed to the console:
<details>
  <summary>Light Color Scheme</summary>
  <img width="1373" height="100" alt="printing_tests_light" src="https://github.com/user-attachments/assets/b12c9db1-1017-42c4-8ed6-3e45f3cd13d7" />
</details>
<details>
  <summary>Dark Color Scheme</summary>
  <img width="1375" height="99" alt="printing_tests_dark" src="https://github.com/user-attachments/assets/517a6dde-88ed-4250-9fb9-ead8da46676d" />
</details>

## colors.hpp
This header file provides useful namespace-like structs that contain hardcoded ANSI color codes; `Color` is the parent struct, containing the ANSI code which resets all text back to normal and two sub-structs. These structs hold the ANSI codes for foreground (`Front`) and background (`Back`) colors, in both bold and normal weights. It's not very modular and it's pretty hardcoded, but I think that makes it more direct and easier to use.

As a bonus, all the colors use `constexpr const char*`, requiring no extra headers to be included!
